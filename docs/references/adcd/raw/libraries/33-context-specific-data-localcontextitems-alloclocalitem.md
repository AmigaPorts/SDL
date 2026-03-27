# 33 / / Context-Specific Data: LocalContextItems / AllocLocalItem()


To create an [LCI](../Libraries_Manual_guide/node044A.html), you use the function [AllocLocalItem()](../Includes_and_Autodocs_2._guide/node01B9.html):


```c
    lci = AllocLocalItem (type, id, ident, datasize);
```
If successful, you will be returned a pointer to an [LCI](../Libraries_Manual_guide/node044A.html) having the
specified type, ID, and identification values; and with datasize bytes of
buffer space for your application to use.

