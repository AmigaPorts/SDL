/* Source: ADCD 2.1
 * Section: iv-125-newgadgets-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-125-newgadgets-c.md
 */

    NewList (DaList);

    for (i = 0; names[i] != NULL && okay == TRUE; i++)
    {
      if (DaListNode = AllocMem (sizeof (struct Node), MEMF_FAST))
      {
        DaListNode->ln_Name = names[i];
        DaListNode->ln_Type = 100L;
        DaListNode->ln_Pri = 0;
        AddTail (DaList, DaListNode);
      }
      else
      {
        printf ("Could not allocate memory for node\n");
        okay = FALSE;
      }
    }
