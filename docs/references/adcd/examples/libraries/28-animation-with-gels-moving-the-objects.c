/* Source: ADCD 2.1
 * Section: 28-animation-with-gels-moving-the-objects
 * Library: libraries
 * ADCD reference: libraries/28-animation-with-gels-moving-the-objects.md
 */

    struct AnimOb **myAnimKey;
    struct RastPort *rp;
    struct ViewPort *vp;

    /* ... setup of graphics elements and objects */

    Animate(myAnimKey, rp);       /* "move" objects per instructions */
    SortGList(rp);                /*  put them in order */
    DoCollision(rp);              /*  software collision detect/action */
    SortGList(rp);                /*  put them back into right order */
    DrawGList(vp, rp);            /*  draw into current RastPort */
