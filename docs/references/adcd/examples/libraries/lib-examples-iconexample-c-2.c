/* Source: ADCD 2.1
 * Section: lib-examples-iconexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-iconexample-c.md
 */

    {
    struct DiskObject *dobj;
    char *olddeftool;
    char **oldtooltypes;
    BOOL success = FALSE;

    if(dobj=GetDiskObject(name))
        {
        /* If file already has an icon, we will save off any fields we
         * need to update, update those fields, put the object, restore
         * the old field pointers and then free the object.  This will
         * preserve any custom imagery the user has, and the user's
         * current placement of the icon.  If your application does
         * not know where the user currently keeps your application,
         * you should not update his dobj->do_DefaultTool.
         */
         oldtooltypes = dobj->do_ToolTypes;
         olddeftool = dobj->do_DefaultTool;

         dobj->do_ToolTypes = newtooltypes;
         dobj->do_DefaultTool = newdeftool;

         success = PutDiskObject(name,dobj);

         /* we must restore the original pointers before freeing */
         dobj->do_ToolTypes = oldtooltypes;
         dobj->do_DefaultTool = olddeftool;
         FreeDiskObject(dobj);
         }
    /* Else, put our default icon */
    if(!success)  success = PutDiskObject(name,&projIcon);
    return(success);
    }
