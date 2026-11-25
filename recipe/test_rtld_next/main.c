#include <stdio.h>
int chained_fn(void);
int main(void)
{
    if (chained_fn()) {
        fprintf(stderr, "FAIL: dlsym(RTLD_NEXT) under MangoHud returned the caller's own symbol\n");
        return 1;
    }
    printf("OK: dlsym(RTLD_NEXT) resolved from the caller\n");
    return 0;
}
