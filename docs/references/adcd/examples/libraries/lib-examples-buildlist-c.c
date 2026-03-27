/* Source: ADCD 2.1
 * Section: lib-examples-buildlist-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-buildlist-c.md
 */

    struct  List    *NameList;    /* Note that a MinList would also work */

    if (!( NameList = AllocMem(sizeof(struct List),MEMF_CLEAR)) )
        printf("Out of memory\n");
    else {
        NewList(NameList);        /* Important: prepare header for use */

        AddName(NameList,"Name7");   AddName(NameList,"Name6");
        AddName(NameList,"Name5");   AddName(NameList,"Name4");
        AddName(NameList,"Name2");   AddName(NameList,"Name0");

        AddName(NameList,"Name7");   AddName(NameList,"Name5");
        AddName(NameList,"Name3");   AddName(NameList,"Name1");

        DisplayName(NameList,"Name5");
        DisplayNameList(NameList);

        FreeNameNodes(NameList);
        FreeMem(NameList,sizeof(struct List));  /* Free list header */
    }
