# DMayGetChar



NAME

    DMayGetChar - return a char iff present, but don't block
SYNOPSIS

```c
    flagChar = DMayGetChar()
    D0
```
FUNCTION

    return either a -1, saying that there is no char present, or
    the char that was waiting
