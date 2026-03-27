/* Source: ADCD 2.1
 * Section: b-rootclass-new-methods-om-update
 * Library: libraries
 * ADCD reference: libraries/b-rootclass-new-methods-om-update.md
 */

    struct opUpdate {  /* the OM_NOTIFY method also uses this structure */
        ULONG             MethodID;           /* OM_UPDATE              */
        struct TagItem    *opu_AttrList;      /* tag list of attributes */
        struct GadgetInfo *opu_GInfo;         /*   that changed.        */
        ULONG             opu_Flags;          /* The extra field        */
    };

    #define OPUF_INTERIM    (1<<0)
