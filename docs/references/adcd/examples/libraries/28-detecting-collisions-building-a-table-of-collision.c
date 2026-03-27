/* Source: ADCD 2.1
 * Section: 28-detecting-collisions-building-a-table-of-collision
 * Library: libraries
 * ADCD reference: libraries/28-detecting-collisions-building-a-table-of-collision.md
 */

    ULONG            num;
    VOID           (*routine)();
    struct GelsInfo *GInfo;

    VOID myCollisionRoutine(GELA, GELB)   /* sample collision routine */
    struct VSprite *GELA;
    struct VSprite *GELB;
    {
        /* process gels here - GELA and GELB point to the base VSprites */
        /* of the gels, you can use the user extensions to identify what */
        /* hit (if you need the info). */
    }

    /* GelsInfo must be allocated and initialized */

    routine = myCollisionRoutine;

    SetCollision(num, routine, GInfo)
