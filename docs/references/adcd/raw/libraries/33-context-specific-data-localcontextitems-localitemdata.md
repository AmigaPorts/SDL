# 33 / / Context-Specific Data: LocalContextItems / LocalItemData()


To get a pointer to an [LCI](../Libraries_Manual_guide/node044A.html)s data buffer, you use [LocalItemData()](../Includes_and_Autodocs_2._guide/node01CD.html):


```c
    buf = LocalItemData (lci);
```
You may read and write the buffer to your heart's content; it is yours.
You should not, however, write beyond the end of the buffer.  The size of
the buffer is what you asked for when you called [AllocLocalItem()](../Libraries_Manual_guide/node044B.html).

