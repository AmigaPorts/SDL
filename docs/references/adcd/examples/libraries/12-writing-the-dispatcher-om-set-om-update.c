/* Source: ADCD 2.1
 * Section: 12-writing-the-dispatcher-om-set-om-update
 * Library: libraries
 * ADCD reference: libraries/12-writing-the-dispatcher-om-set-om-update.md
 */

    #define OPUF_INTERIM    (1<<0)

    /* the OM_NOTIFY method uses the same structure */

    struct opUpdate {
        ULONG             MethodID;
        struct TagItem    *opu_AttrList;
        struct GadgetInfo *opu_GInfo;
        ULONG             opu_Flags;      /* The extra field */
    };
