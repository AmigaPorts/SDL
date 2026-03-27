/* Source: ADCD 2.1
 * Section: 28-animation-with-gels-animation-data-structures
 * Library: libraries
 * ADCD reference: libraries/28-animation-with-gels-animation-data-structures.md
 */

    struct AnimOb
    {
        struct AnimOb    *NextOb, *PrevOb;
        LONG Clock;
        WORD AnOldY, AnOldX;            /* old y,x coordinates          */
        WORD AnY, AnX;                  /* y,x coordinates of the AnimOb*/
        WORD YVel, XVel;                /* velocities of this object    */
        WORD YAccel, XAccel;            /* accelerations of this object */
        WORD RingYTrans, RingXTrans;    /* ring translation values      */
        WORD (*AnimORoutine)();         /* address of user procedure    */
        struct AnimComp  *HeadComp;     /* pointer to first component   */
        AUserStuff AUserExt;            /* AnimOb user extension        */
    };
