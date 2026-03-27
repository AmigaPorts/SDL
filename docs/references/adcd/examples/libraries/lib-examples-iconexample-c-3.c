/* Source: ADCD 2.1
 * Section: lib-examples-iconexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-iconexample-c.md
 */

    {
    struct DiskObject *dobj;
    char **toolarray;
    char *s;
    BOOL success = FALSE;

    fprintf(conwin,"\nWBArg Lock=0x%lx, Name=%s\n",
                           wbarg->wa_Lock,wbarg->wa_Name);

    if((*wbarg->wa_Name) && (dobj=GetDiskObject(wbarg->wa_Name)))
        {
        fprintf(conwin,"  We have read the DiskObject (icon) for this arg\n");
        toolarray = (char **)dobj->do_ToolTypes;

        if(s=(char *)FindToolType(toolarray,"FILETYPE"))
            {
            fprintf(conwin,"    Found tooltype FILETYPE with value %s\n",s);
            }
        if(s=(char *)FindToolType(toolarray,"FLAGS"))
            {
            fprintf(conwin,"    Found tooltype FLAGS with value %s\n",s);
            if(MatchToolValue(s,"BOLD"))
                fprintf(conwin,"      BOLD flag requested\n");
            if(MatchToolValue(s,"ITALICS"))
                fprintf(conwin,"      ITALICS flag requested\n");
            }
        /* Free the diskobject we got */
        FreeDiskObject(dobj);
        success = TRUE;
        }
    else if(!(*wbarg->wa_Name))
        fprintf(conwin,"  Must be a disk or drawer icon\n");
    else
        fprintf(conwin,"  Can't find any DiskObject (icon) for this WBArg\n");
    return(success);
    }
