# reaction.lib/GetCode



   NAME

       GetCode -- return the true IDCMP message code
   SYNOPSIS

```c
       code = GetCode( imsg )

       [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) GetCode( struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) * )
```
   FUNCTION

```c
       Returns the true [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) code field. Layout.gadget replaces
       the IDCMP_GADGETUP message with an IDCMP_IDCMPUPDATE. This function
       will return the "gadgetup code" from the IDCMPUPDATE taglist if it
       is found there, and otherwise the normal imsg->Code.
```
   INPUTS

```c
       imsg -- a pointer to an [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762)
```
   RESULTS

       The message's code field
