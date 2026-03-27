# 37 / / Advanced Tag Usage / Random Access of Tag Lists


The [GetTagData()](../Includes_and_Autodocs_2._guide/node03D8.html) function will return the data for the specified
attribute.  If there isn't a tag that matches, then the default value is
returned.


```c
    APTR sound;

    /* Get the sound data that our function will use. */
    sound = (APTR) GetTagData (MGA_Sound, (ULONG) DefaultSound, attrs);
```
