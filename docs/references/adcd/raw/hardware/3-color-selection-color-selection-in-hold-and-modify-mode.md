# 3 / Color Selection / Color Selection in Hold-And-Modify Mode


In hold-and-modify mode, the color register contents are changed as shown
in Table 3-19.  This mode is in effect only if bit 10 of  [BPLCON0](../Hardware_Manual_guide/node0092.html)  = 1.


  Bitplane 6  Bitplane 5                Result
  ----------  ----------                ------

```c
      0           0      Normal operation     (use color register itself)
      0           1      Hold green and red   B = Bitplane 4-1 contents
      1           0      Hold green and blue  R = Bitplane 4-1 contents
      1           1      Hold blue and red    G = Bitplane 4-1 contents

      Table 3-19: Color Selection in Hold-and-modify Mode
```
