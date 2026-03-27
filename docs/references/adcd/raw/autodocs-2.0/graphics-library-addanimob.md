# graphics.library/AddAnimOb



NAME

```c
    AddAnimOb  --  Add an [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) to the linked list of AnimObs.
```
SYNOPSIS

```c
    AddAnimOb(anOb, anKey, rp)
              A0    A1     A2

    void AddAnimOb(struct [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) *,struct [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) **, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    Links this [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) into the current list pointed to by animKey.
    Initializes all the Timers of the AnimOb's components.
    Calls [AddBob](../Includes_and_Autodocs_2._guide/node040F.html) with each component's [Bob](../Includes_and_Autodocs_2._guide/node00C3.html#line140).
    rp->GelsInfo must point to an initialized [GelsInfo](../Includes_and_Autodocs_2._guide/node00AF.html#line40) structure.
```
INPUTS

```c
    anOb  = pointer to the [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) structure to be added to the list
    anKey = address of a pointer to the first [AnimOb](../Includes_and_Autodocs_2._guide/node00C3.html#line204) in the list
            (anKey = NULL if there are no AnimObs in the list so far)
    rp    = pointer to a valid [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
RESULT

BUGS

SEE ALSO

```c
    [Animate()](../Includes_and_Autodocs_2._guide/node0415.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html) [graphics/gels.h](../Includes_and_Autodocs_2._guide/node00C3.html)
```
