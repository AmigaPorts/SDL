# LISTs, CATs, and Shared Properties (Advanced topics) / Group PROP


[PROP](../Devices_Manual_guide/node01CA.html#line49) [chunk](../Devices_Manual_guide/node01DD.html)s may appear in [LIST](../Devices_Manual_guide/node01CA.html#line49)s (not in [FORM](../Devices_Manual_guide/node01C7.html#line52)s or CATs).  They supply
shared properties for the FORMs in that LIST.  This ability to elevate
some property settings to shared status for a list of forms is useful for
both indirection and compaction.  E.g., a list of images with the same
size and colors can share one "size" property and one "color map"
property.  Individual FORMs can override the shared settings.

The contents of a [PROP](../Devices_Manual_guide/node01CA.html#line49) is like a FORM with no data [chunk](../Devices_Manual_guide/node01DD.html)s:

	PROP	::= "PROP" #{ FormType Property* }

It means, "Here are the shared properties for [FORM](../Devices_Manual_guide/node01C7.html#line52) type <FormType>".

A [LIST](../Devices_Manual_guide/node01CA.html#line49) may have at most one [PROP](../Devices_Manual_guide/node01CA.html#line49) of a [FORM](../Devices_Manual_guide/node01C7.html#line52) type, and all the [PROP](../Devices_Manual_guide/node01CA.html#line49)s must
appear before any of the FORMs or nested LISTs and [CAT](../Devices_Manual_guide/node01CA.html#line2) s.  You can have
subsequences of FORMs sharing properties by making each subsequence a LIST.

Scoping: Think of property settings as variable bindings in nested blocks
of a programming language.  In C this would look like:


```c
    #define Roman           0
    #define Helvetica       1

    void main()
            {
            int font=Roman; /* The global default */
                    {
                    printf("The font number is %d\n",font);
                    }
                    {
                    int font=Helvetica;     /* local setting */
                    printf("The font number is %d\n",font);
                    }
                    {
                    printf("The font number is %d\n",font);
                    }
            }


    /*
    * Sample output:       The font number is 0
    *                      The font number is 1
    *                      The font number is 0
    */




    An IFF file could contain:

    LIST {
            PROP TEXT {
                    FONT {TimesRoman}       /* shared setting       */
                    }

            FORM TEXT {
                    FONT {Helvetica}        /* local setting        */
                    CHRS {Hello }           /* uses font Helvetica  */
                    }

            FORM TEXT {
                    CHRS {there.}           /* uses font TimesRoman */
                    }
            }
```
The shared property assignments selectively override the reader's global
defaults, but only for [FORM](../Devices_Manual_guide/node01C7.html#line52)s within the group.  A FORM's own property
assignments selectively override the global and group-supplied values.  So
when reading an IFF file, keep property settings on a stack.  They are
designed to be small enough to hold in main memory.

Shared properties are semantically equivalent to copying those properties
into each of the nested [FORM](../Devices_Manual_guide/node01C7.html#line52)s right after their FORM type IDs.

