# graphics.library/Animate



NAME

```c
    Animate  --  Processes every [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) in the current animation list.
```
SYNOPSIS

```c
    Animate(anKey, rp)
            A0     A1

    void Animate(struct [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) **, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    For every [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) in the list
        - update its location and velocities
        - call the AnimOb's special routine if one is supplied
        - for each component of the [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204)
            - if this sequence times out, switch to the new one
            - call this component's special routine if one is supplied
            - set the sequence's VSprite's y,x coordinates based
              on whatever these routines cause
```
INPUTS

```c
    ankey = address of the variable that points to the head [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204)
    rp    = pointer to the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
```
RESULT

BUGS

SEE ALSO

```c
    [AddAnimOb()](../Includes_and_Autodocs_2._guide/node040E.html) [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
