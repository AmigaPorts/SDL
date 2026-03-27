# 33 / Advanced Topics / Freeing LCIs


Ordinarily, the parser will automatically delete [LCI](../Libraries_Manual_guide/node044A.html)s you have allocated
and installed.  However, you may have a case where simply [FreeMem()](../Libraries_Manual_guide/node02A7.html#line11)ing
your LCI is not enough; you may need to free some ancillary memory, or
decrement a counter, or send a signal, or something.  This is where
[SetLocalItemPurge()](../Includes_and_Autodocs_2._guide/node01D8.html) comes in.  It is called as follows:


```c
    SetLocalItemPurge (lci, hookptr);
```
When the parser is ready to delete your [LCI](../Libraries_Manual_guide/node044A.html), your purge handler code will
be called through the [Hook](../Libraries_Manual_guide/node04A3.html) you supplied.  You can then perform all your
necessary operations.  One of these operations should be to free the LCI
itself.  This is done with [FreeLocalItem()](../Includes_and_Autodocs_2._guide/node01C6.html):


```c
    FreeLocalItem (lci);
```
This deallocates the memory used to store the [LCI](../Libraries_Manual_guide/node044A.html) and the client buffer
allocated with it.  [FreeLocalItem()](../Includes_and_Autodocs_2._guide/node01C6.html) is only called as part of a custom
purge handler.

As with custom chunk handlers, your purge handler executes in the same
environment as the mainline code that called [ParseIFF()](../Libraries_Manual_guide/node0432.html).  It is
recommended that you keep purge handlers short and to the point; super
clever stuff should be reserved for custom chunk handlers, or for the
client's mainline code.  Custom purge handlers must always work; failures
will be ignored.

