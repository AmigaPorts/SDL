# 33 / Context Functions / Context-Specific Data: LocalContextItems


[ContextNode](../Libraries_Manual_guide/node0446.html)s can contain application data specific to that context.  These
data objects are called [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line77)s.  LocalContextItems (LCIs) are a
grey-box structure which contain a type, ID and identification field.
LCIs are used to store context-sensitive data.  The format of this data is
application-defined.  A ContextNode can contain as many LCIs as you want.



        __________________
       |                  |
       |   ContextNode    |
       |   -----------    |
       |  Type - ID_ILBM  |
       |  ID   - ID_BODY  |
       |__________________|
                |
        ________|_________      _______________________________
       |                  |    |                               |
       |   ContextNode    |    |       LocalContextItem        |
       |   -----------    |____|       ----------------        |
       |  Type - ID_ILBM  |    |  Type  - ID_ILBM              |
       |  ID   - ID_FORM  |    |  ID    - ID_BMHD              |
       |__________________|    |  Ident - IFFLCI_PROP          |
                |              |_______________________________|
        ________|_________      _______________________________
       |                  |    |                               |
       |   ContextNode    |    |       LocalContextItem        |
       |   -----------    |    |       ----------------        |
       |  Type - ID_ZOID  |____|  Type  - ID_ILBM              |
       |  ID   - ID_LIST  |    |  ID    - ID_BMHD              |
       |__________________|    |  Ident - IFFLCI_ENTRYHANDLER  |
                |              |_______________________________|
        ________|______________________________________________
       |                                                       |
       |                   I F F H a n d l e                   |
       |_______________________________________________________|


                 Figure 33-3: IFFParse Context Stack
Figure 33-3 shows the relationship between the [IFFHandle](../Libraries_Manual_guide/node042C.html), the
[ContextNode](../Libraries_Manual_guide/node0446.html)s, and the LCIs.  The IFFHandle is the root of the tree, so to
speak.  ContextNodes "grow" out of the IFFHandle.  In turn, LCIs "grow"
out of the ContextNodes.  What grows out of an LCI is client-defined.

 [AllocLocalItem()](../Libraries_Manual_guide/node044B.html)    [LocalItemData()](../Libraries_Manual_guide/node044C.html) 

