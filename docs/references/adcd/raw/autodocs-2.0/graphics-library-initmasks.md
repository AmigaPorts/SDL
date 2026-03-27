# graphics.library/InitMasks



NAME

```c
    InitMasks -- Initialize the BorderLine and CollMask masks of a [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73).
```
SYNOPSIS

```c
    InitMasks(vs)
              A0

    void InitMasks(struct [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) *);
```
FUNCTION

```c
    Creates the appropriate BorderLine and CollMask masks of the [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73).
    Correctly detects if the [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) is actually a [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140) definition, handles
    the image data accordingly.
```
INPUTS

```c
    vs = pointer to the [VSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line73) structure
```
RESULT

BUGS

SEE ALSO

```c
    [InitGels()](../Includes_and_Autodocs_2._guide/node0451.html)  [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)
```
