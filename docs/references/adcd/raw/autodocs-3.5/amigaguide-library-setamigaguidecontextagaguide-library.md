# amigaguide.library/SetAmigaGuideContextAgaguide.library/SetAmigaGuideContextA



   NAME
```c
        SetAmigaGuideContextA - Set the context ID for an AmigaGuide system.
                                                               (V34)
```
   SYNOPSIS

```c
        success = SetAmigaGuideContextA ( handle, context, attrs );
        d0                                 a0       d0      d1

        [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetAmigaGuideContextA (AMIGAGUIDECONTEXT, ULONG,
                                    struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

        success = SetAmigaGuideContext (handle, context, tag1, ...);

        [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SetAmigaGuideContext (AMIGAGUIDECONTEXT, ULONG, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);
```
   FUNCTION

```c
        This function, and the SendAmigaGuideContext() function, are used to
        provide a simple way to display a node based on a numeric value,
        instead of having to build up a slightly more complex command
        string.
```
   INPUTS

        handle -- Handle to an AmigaGuide system.

        context -- Index value of the desired node to display.

        future -- Future expansion, must be set to NULL for now.
   EXAMPLE


```c
        /* sample context table */
        [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) ContextArray[] =
        {
            "MAIN",
            "FILEREQ",
            "PRINT",
            "ABOUT",
            NULL
        };

        /* quickie defines */
        #define HELP_MAIN      0
        #define HELP_FILEREQ   1
        #define HELP_PRINT     2
        #define HELP_ABOUT     3

        ...

        struct [NewAmigaGuide](../Includes_and_Autodocs_3._guide/node05D2.html#line102) nag = {NULL};

        /* initialize the context table */
        nag.nag_Context = ContextArray;

        ...

        /* bring up help on a particular subject */
        SetAmigaGuideContext(handle, HELP_ABOUT, NULL);
```
   RETURNS

        success - Returns TRUE if a valid context ID was passed,
            otherwise returns FALSE.
   SEE ALSO

```c
        [SendAmigaGuideContextA()](../Includes_and_Autodocs_3._guide/node0013.html), [SendAmigaGuideCmdA()](../Includes_and_Autodocs_3._guide/node0012.html)
```
