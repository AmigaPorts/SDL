/* Source: ADCD 2.1
 * Section: devices-modules-copychunks-c
 * Library: devices
 * ADCD reference: devices/devices-modules-copychunks-c.md
 */

    {
    struct Chunk *chunk;
    long size, error = 0;

    D(bug("writechunklist: first chunk pointer = $%lx\n",first));

    for(chunk=first; chunk && (!error); chunk=chunk->ch_Next)
