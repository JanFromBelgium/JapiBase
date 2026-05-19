/* Minimal seam proof: uses only japi_base.h symbols, builds on the simulator.
   Step 2 = it compiles & links. Real demo content arrives in later steps. */
#include "japi_base.h"

int main(void) {
    japi_init();
    vga_clear(VGA_WHITE, VGA_DARK_BLUE);
    vga_print(0, 0, "Japi Base simulator skeleton OK", VGA_YELLOW, VGA_DARK_BLUE);
    return 0;
}
