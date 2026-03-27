# potgo.resource/FreePotBits



NAME

    FreePotBits -- Free allocated bits in the potgo register.
SYNOPSIS

```c
    FreePotBits(allocated)
                D0

    void FreePotBits( UWORD );
```
FUNCTION

```c
    The FreePotBits routine frees previously allocated bits in the
    hardware potgo register that the application had allocated via
    [AllocPotBits](../Includes_and_Autodocs_2._guide/node053D.html) and no longer wishes to use.  It accepts the
    return value from [AllocPotBits](../Includes_and_Autodocs_2._guide/node053D.html) as its argument.
```
