/* Source: ADCD 2.1
 * Section: iffparse-library-collectionchunk
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-collectionchunk.md
 */

    Installs an entry handler for chunks with the given type and id so
    that the contents of those chunks will be stored as they are
    encountered.  This is like [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html) except that more than one
    chunk of this type can be stored in lists which can be returned by
    [FindCollection()](../Includes_and_Autodocs_2._guide/node01C1.html).  The storage of these chunks still follows the
    property chunk scoping rules for IFF files so that at any given
    point, stored collection chunks will be valid in the current context.
