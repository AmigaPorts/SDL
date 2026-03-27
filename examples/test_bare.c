/* Bare test -- no SDL, just printf. Tests if the binary runs at all on FS-UAE. */
#include <stdio.h>

static const char *verstag = "$VER: test_bare 0.1 (27.03.2026)";
long __stack = 65536;

int main(int argc, char *argv[])
{
    (void)argc; (void)argv; (void)verstag;
    printf("BARE TEST: printf works!\n");
    printf("argc=%d\n", argc);
    return 0;
}
