/* Source: ADCD 2.1
 * Section: b-rootclass-new-methods-om-addmember
 * Library: libraries
 * ADCD reference: libraries/b-rootclass-new-methods-om-addmember.md
 */

    #define  opAddMember opMember
    struct opMember {
        ULONG  MethodID;     /* OM_ADDMEMBER (or OM_REMMEMBER) */
        Object *opam_Object; /* add (or remove) this object    */
    };                       /* to (from) personal list.       */
