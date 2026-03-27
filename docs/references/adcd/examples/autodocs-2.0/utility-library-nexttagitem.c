/* Source: ADCD 2.1
 * Section: utility-library-nexttagitem
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/utility-library-nexttagitem.md
 */

    Iterates through a (chained) array of [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) structures,
    skipping and chaining as dictated by system tags.  TAG_SKIP
    will cause it to skip the entry and the next, TAG_IGNORE ignores
    that single entry, and TAG_MORE has a pointer to another array
    of tags (and terminates the current array!)  TAG_DONE also
    terminates the current array.  Each call returns either the next
    tagitem you should examine, or NULL at the end.
