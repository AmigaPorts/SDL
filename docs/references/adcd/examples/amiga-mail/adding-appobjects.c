/* Source: ADCD 2.1
 * Section: adding-appobjects
 * Library: amiga-mail
 * ADCD reference: amiga-mail/adding-appobjects.md
 */

    struct AppWindow *AddAppWindow( unsigned long myID,
        unsigned long userdata, struct Window *mywindow,
        struct MsgPort *mymsgport, Tag tag1, ...);

    struct AppIcon *AddAppIcon( unsigned long myID,
        unsigned long userdata, UBYTE *mytext,
        struct MsgPort *mymsgport, struct FileLock *mylock,
        struct DiskObject *diskobj, Tag tag1, ... );

    struct AppMenuItem *AddAppMenuItem( unsigned long myid,
         unsigned long userdata, UBYTE *menutext,
         struct MsgPort *mymsgport, Tag tag1, ... );

    BOOL RemoveAppWindow( struct AppWindow *appWindow );

    BOOL RemoveAppIcon( struct AppIcon *appIcon );

    BOOL RemoveAppMenuItem( struct AppMenuItem *appMenuItem );
