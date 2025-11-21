#include <time.h>
#include <stdio.h>
#include "int_stress.h"

double intrate_alu() {


    // Prevent optimization removing work
    static volatile uint64_t intrate_sink = 0;
    printf("CPS is %lu\n", CLOCKS_PER_SEC);

    uint64_t a = 1;
    uint64_t b = 2;
    uint64_t c = 3;
    uint64_t d = 4;

    clock_t start = clock();

    uint64_t iterations = 3ULL * 1000ULL * 1000ULL * 1000ULL;
    for (uint64_t i = 0; i < iterations; i++) {
        a += 3;
        b ^= a;
        c *= b;
        d = (d << 2) + (c >> 1);
        a ^= (d * 3);
        c += (a >> 3);
    }

    clock_t end = clock();

    intrate_sink = a + b + c + d;


    double seconds = (end - start) / CLOCKS_PER_SEC;


    return seconds;
}
