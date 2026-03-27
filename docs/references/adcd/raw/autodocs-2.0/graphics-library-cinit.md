# graphics.library/CINIT



NAME

    CINIT -- Initialize user copperlist to accept intermediate
             user copper instructions.
SYNOPSIS

```c
    cl = CINIT( ucl , n )

    cl = UCopperListInit( ucl , n )
                          a0    d0

    struct [CopList](../Includes_and_Autodocs_2._guide/node00AD.html#line62) *UCopperListInit( struct [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) *, UWORD );
```
FUNCTION

```c
    Allocates and/or initialize copperlist structures/buffers
    internal to a [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) structure.

    This is a macro that calls UCopListInit. You must pass a
    (non-initialized) [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) to CINIT (CINIT will NOT allocate
    a new [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) if ucl==0 ). If (ucl != 0) it will initialize the
    intermediate data buffers internal to a [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82).

    The maximum number of intermediate copper list instructions
    that these internal [CopList](../Includes_and_Autodocs_2._guide/node00AD.html#line62) data buffers contain is specified
    as the parameter n.
```
INPUTS

```c
    ucl - pointer to [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) structure
    n - number of instructions buffer must be able to hold
```
RESULTS

```c
    cl- a pointer to a buffer which will accept n intermediate copper
        instructions.

    NOTE: this is NOT a [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) pointer, rather a pointer to the
          UCopList's->FirstCopList sub-structure.
```
BUGS

```c
    CINIT will not actually allocate a new [UCopList](../Includes_and_Autodocs_2._guide/node00AD.html#line82) if ucl==0.
    Instead you must allocate a block MEMF_PUBLIC|MEMF_CLEAR, the
    sizeof(struct UCopList) and pass it to this function.

    The system's [FreeVPortCopLists](../Includes_and_Autodocs_2._guide/node0444.html) function will take care of
    deallocating it if they are called.

    Prior to release V36 the  CINIT macro had { } braces surrounding
    the definition, preventing the proper return of the result value.
    These braces have been removed for the V36 include definitions.
```
SEE ALSO

```c
    CINIT [CMOVE](../Includes_and_Autodocs_2._guide/node0430.html) [CEND](../Includes_and_Autodocs_2._guide/node0426.html) [graphics/copper.h](../Includes_and_Autodocs_2._guide/node00AD.html)
```
