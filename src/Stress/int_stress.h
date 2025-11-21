#pragma once

#include <stdint.h>


/* ============================
   ALU-ONLY INTEGER STRESSOR
   ============================

   High IPC, independent arithmetic operations.
   Intended to saturate ADD/XOR/MUL/SHL ALUs.

   Parameters:
       iterations  - number of loop iterations

   Returns:
       elapsed seconds (double)
*/
double intrate_alu();


/* ===========================================
   ALU + MEMORY + LATENCY CHAIN STRESSOR
   ===========================================

   Mixes:
       - Large memory array (DRAM pressure)
       - Random-ish access (cache miss pressure)
       - ALU arithmetic dependent on memory values
       - Latency chain between loop iterations

   Parameters:
       iterations       - loop count
       array_size_bytes - total array size in bytes

   Returns:
       elapsed seconds (double)
*/
double intrate_alu_mem(uint64_t iterations, uint64_t array_size_bytes);

