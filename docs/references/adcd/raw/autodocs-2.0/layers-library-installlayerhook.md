# layers.library/InstallLayerHook



NAME                                                              (V36)

    InstallLayerHook -- safely install a new Layer->BackFill hook.
SYNOPSIS

```c
    oldhook = InstallLayerHook( layer, hook )
    d0                          a0     a1

    struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *InstallLayerHook( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *, struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *);
```
FUNCTION

```c
    Installs a new Layer->Backfill [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23), waiting until it is safe to do
    so. Locks the layer while substituting the new [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) and removing the
    old one. If a new [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) is not provided, will install the default layer
    BackFill [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23).
```
INPUTS

```c
    layer - pointer to the layer in which to install the Backfill [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23).
    hook -  pointer to layer callback [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) which will be called
            with object == (struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *) result->RastPort
            and message == [ (Layer *) layer, (struct Rectangle) bounds,
                           (WORD) offsetx, (WORD) offsety ]

            This hook should fill the [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
            with the BackFill pattern appropriate for offset x/y.

            If this hook pointer is NULL, the function installs
            the "default" Layers BackFill [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) into this [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33).
```
RESULTS

```c
    oldhook - pointer to the Layer->BackFill [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) that was previously
              active.
```
BUGS

SEE ALSO

```c
    [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html) [utility/hooks.h](../Includes_and_Autodocs_2._guide/node012D.html)
```
