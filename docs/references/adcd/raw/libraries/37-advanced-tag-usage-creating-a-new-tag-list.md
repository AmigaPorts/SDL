# 37 / / Advanced Tag Usage / Creating a New Tag List


The [AllocateTagItems()](../Includes_and_Autodocs_2._guide/node03CE.html) function can be used to create a new tag array
ready for use.  The tag array should be passed to [FreeTagItems()](../Includes_and_Autodocs_2._guide/node03D7.html) when the
application is done with it.


```c
    struct TagItem *tags;
    ULONG tags_needed;

    /* Indicate how many tags we need */
    tags_needed = 10;

    /* Allocate a tag array */
    if (tags = AllocateTagItems(tags_needed))
    {
        /* ...do something with the array... */

        /* Free the array when your done with it */
        FreeTagItems (tags);
    }
```
