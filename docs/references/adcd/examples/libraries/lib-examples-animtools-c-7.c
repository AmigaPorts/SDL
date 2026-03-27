/* Source: ADCD 2.1
 * Section: lib-examples-animtools-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-c.md
 */

        {
        nextSeq = curSeq->NextComp;
        freeSeq(curSeq, rasdepth);
        curSeq = nextSeq;
        }
