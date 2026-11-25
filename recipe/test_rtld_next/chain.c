// A library that chains to the "next" definition of its own symbol, the way
// Intel OpenMP's ompt_start_tool() does. dlsym(RTLD_NEXT, ...) must resolve
// relative to this library, so it must never return chained_fn itself.
#define _GNU_SOURCE
#include <dlfcn.h>

int chained_fn(void)
{
    void *next = dlsym(RTLD_NEXT, "chained_fn");
    if (next == (void *)chained_fn)
        return 1;  // RTLD_NEXT resolved from the wrong origin
    return 0;
}
