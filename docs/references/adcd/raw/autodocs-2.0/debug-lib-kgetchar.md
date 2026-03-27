# debug.lib/KGetChar



NAME

```c
    KGetChar - get a character from the console
               (defaults to the serial port at 9600 baud)
```
SYNOPSIS

```c
    char = KGetChar()
    D0
```
FUNCTION

    busy wait until a character arrives from the console.
    KGetChar is the assembly interface, _KGetChar and _kgetc
    are the C interfaces.
