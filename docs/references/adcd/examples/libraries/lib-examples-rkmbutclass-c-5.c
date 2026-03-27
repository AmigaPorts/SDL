/* Source: ADCD 2.1
 * Section: lib-examples-rkmbutclass-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmbutclass-c.md
 */

                    SetAPen(rp, pens[BACKGROUNDPEN]);
                    SetDrMd(rp, JAM1);                            /* Erase the old gadget.       */
                    RectFill(rp, x, y, x+w, y+h);

                    inst->midX = g->LeftEdge + ( (g->Width) / 2); /* Recalculate where the       */
                    inst->midY = g->TopEdge + ( (g->Height) / 2); /* center of the gadget is.    */

                                                                  /* Rerender the gadget.        */
                    DoMethod(o, GM_RENDER, ((struct opSet *)msg)->ops_GInfo, rp, GREDRAW_REDRAW);
                    ReleaseGIRPort(rp);
                }
            }
            else
                retval = DoSuperMethodA(cl, o, msg);
            break;
        default:          /* rkmmodelclass does not recognize the methodID, let the superclass's */
                          /* dispatcher take a look at it.                                       */
            retval = DoSuperMethodA(cl, o, msg);
            break;
    }
    return(retval);
