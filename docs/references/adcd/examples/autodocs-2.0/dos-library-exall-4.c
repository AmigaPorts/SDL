/* Source: ADCD 2.1
 * Section: dos-library-exall
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-exall.md
 */

    lock    - Lock on directory to be examined.
    buffer  - Buffer for data returned (MUST be at least word-aligned,
              preferably long-word aligned).
    size    - Size in bytes of 'buffer'.
    type    - Type of data to be returned.
    control - Control data structure (see notes above).  MUST have been
              allocated by AllocDosObject!
