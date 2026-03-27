/* Source: ADCD 2.1
 * Section: intuition-library-openscreentaglist
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-openscreentaglist.md
 */

    The version using a variable number of arguments must be
    created for each particular compiler, and may not have
    an analogue in all versions.  For vanilla, 32-bit C
    parameter passing conventions, this works (and will
    appear in amiga.lib):

    struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97)      *
    OpenScreenTags( ns, tag1 )
    struct [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309)  *ns;
    ULONG                   tag1;
    {
        struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97)  *OpenScreenTagList();

        return ( OpenScreenTagList( ns, (struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *) &tag1 ) );
    }
