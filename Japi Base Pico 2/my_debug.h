#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#include <stdio.h>
#include "pico/stdlib.h"

// Print helpers (route everything to stdio printf).
#define DBG_PRINTF(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define debug_print(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define debug_init() ((void)0)

// Fatal-error assert: report file/line and halt.
#ifndef myASSERT
#define myASSERT(cond) if(!(cond)) { \
    printf("\n--- ASSERT FAILED ---\nFile: %s\nLine: %d\n", __FILE__, __LINE__); \
    while(1) { tight_loop_contents(); } \
}
#endif

#endif