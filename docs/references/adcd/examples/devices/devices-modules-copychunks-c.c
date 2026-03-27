/* Source: ADCD 2.1
 * Section: devices-modules-copychunks-c
 * Library: devices
 * ADCD reference: devices/devices-modules-copychunks-c.md
 */

    {
    struct Chunk *chunk, *first=NULL, *prevchunk = NULL;
    struct StoredProperty *sp;
    struct CollectionItem *ci, *cii;
    long error;
    int k, kk, bk;

    if(!iff)	return(NULL);

    /* Copy gathered property chunks */
    error = 0;
    for(k=0; (!error) && (propchks) && (propchks[k] != TAG_DONE); k+=2)
