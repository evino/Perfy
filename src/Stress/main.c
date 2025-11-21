#include <stdio.h>
#include "int_stress.h"

int main(int argc, char **argv) {
    printf("Hello world\n");

    uint64_t iterations = 3ULL * 1000ULL * 1000ULL * 1000ULL; // 3 billion
    double ticks = intrate_alu(iterations);
    printf("ALU stress took %lu ticks in cpu-time.\n", ticks);

    return 0;
}
