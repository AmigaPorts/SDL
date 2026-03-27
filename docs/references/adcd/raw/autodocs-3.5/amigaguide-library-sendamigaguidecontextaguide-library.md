# amigaguide.library/SendAmigaGuideContextAguide.library/SendAmigaGuideContextA



   NAME
        SendAmigaGuideContextA - Align an AmigaGuide system on the context ID
.
```c
                                                               (V34)
```
   SYNOPSIS

```c
        success = SendAmigaGuideContextA (handle, attrs);
        d0                                 a0      d0

        [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SendAmigaGuideContextA (AMIGAGUIDECONTEXT, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

        success = SendAmigaGuideContext (handle, tag1, ...);

        [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) SendAmigaGuideContext (AMIGAGUIDECONTEXT, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);
```
   FUNCTION

```c
        This function is used to send a message to an AmigaGuide system to
        align it on the current context ID.

        This function effectively does a:

            SendAmigaGuideCmd(handle 'LINK ContextArray[contextID]', NULL);
```
   INPUTS

        handle - Handle to an AmigaGuide system.
        future - Future expansion, must be set to NULL for now.
   EXAMPLE


```c
        struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *imsg;

        ...

        case RAWKEY:
            switch (imsg->Code)
            {
                case 95:
                    /* bring up help on a particular subject */
                    SendAmigaGuideContext(handle, NULL);
                    break;
                ...
            }
            break;

        ...
```
   RETURNS

        success -- Returns TRUE if the message was sent, otherwise returns
            FALSE.
   SEE ALSO

```c
        [SetAmigaGuideContextA()](../Includes_and_Autodocs_3._guide/node0015.html), [SendAmigaGuideCmdA()](../Includes_and_Autodocs_3._guide/node0012.html)
```
