/* Source: ADCD 2.1
 * Section: 27-the-rastport-structure-rastport-area-fill-information
 * Library: libraries
 * ADCD reference: libraries/27-the-rastport-structure-rastport-area-fill-information.md
 */

    #define AREA_SIZE 200

    register USHORT i;
    WORD areaBuffer[AREA_SIZE];
    struct AreaInfo areaInfo = {0};

    /*  Clear areaBuffer before calling InitArea().  */
    for (i=0; i<AREA_SIZE; i++)
        areaBuffer[i] = 0;

    InitArea(&areaInfo, areaBuffer, (AREA_SIZE*2)/5);
