/* Source: ADCD 2.1
 * Section: 5-intuition-gadgets-gadget-pointer-movements
 * Library: libraries
 * ADCD reference: libraries/5-intuition-gadgets-gadget-pointer-movements.md
 */

        -----                          -----
        imsg=GetMsg(win->UserPort);    imsg=GetMsg(win->UserPort);
        class=imsg->Class;             class=imsg->Class;
        code=imsg->Code;               code=imsg->Code;
        /* OK */                       /* ILLEGAL ! */
        iaddress=imsg->IAddress;       gadid=((struct Gadget *)
                                               imsg->IAddress)->GadgetID;
        ReplyMsg(imsg);                ReplyMsg(imsg);


    Using the code in the left column, it is acceptable to get the
    address of a gadget with gadid=((struct Gadget *)iaddress)->GadgetID
    but only after you have checked to make sure the message is an
    [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) or [IDCMP_GADGETDOWN](../Libraries_Manual_guide/node01DD.html).
