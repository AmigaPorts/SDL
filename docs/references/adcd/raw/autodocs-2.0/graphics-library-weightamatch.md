# graphics.library/WeighTAMatch



NAME

```c
    WeighTAMatch -- Get a measure of how well two fonts match. (V36)
```
SYNOPSIS

```c
    weight = WeighTAMatch(reqTextAttr, targetTextAttr, targetTags)
    D0                    A0           A1              A2

    WORD WeighTAMatch(struct [TTextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line73) *, struct [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) *,
         struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);
```
FUNCTION

```c
    This function provides a metric to describe how well two fonts
    match.  This metric ranges from MAXFONTMATCHWEIGHT (perfect match)
    through lower positive numbers to zero (unsuitable match).
```
INPUTS

```c
    reqTextAttr    - the text attributes requested.
    targetTextAttr - the text attributes of a potential match.
    targetTags     - tags describing the extended target attributes, or
                     zero if not available.

    The [t]ta_Name fields of the [T]TextAttr structures are not used.

    The tags affect the weight only when both a) the reqTextAttr
    has the FSF_TAGGED bit set in ta_Style, and b) targetTags is
    not zero.  To fairly compare two different weights, the inclusion
    or exclusion of tags in the weighing must be the same for both.
```
RESULTS

    weight -- a positive weight describes suitable matches, in
          increasing desirability.  MAXFONTMATCHWEIGHT is a perfect
          match.  A zero weight is an unsuitable match.
SEE ALSO

```c
    [OpenFont()](../Includes_and_Autodocs_2._guide/node0462.html)
```
