/* Source: ADCD 2.1
 * Section: iffparse-library-propchunk
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/iffparse-library-propchunk.md
 */

    Installs an entry handler for chunks with the given type and ID so
    that the contents of those chunks will be stored as they are
    encountered.  The storage of these chunks follows the property chunk
    scoping rules for IFF files so that at any given point, a stored
    property chunk returned by [FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html) will be the valid property for
    the current context.
