/* Source: ADCD 2.1
 * Section: lib-examples-rkmmodel-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rkmmodel-c.md
 */

    struct RKMModData *mmd;
    APTR retval = NULL;  /* A generic return value used by this class's methods.  The            */
                         /* meaning of this field depends on the method.  For example,           */
                         /* OM_GET uses this a a boolean return value, while OM_NEW              */
                         /* uses it as a pointer to the new object.                              */
    geta4();    /* SAS/C and Manx function - makes sure A4 contains global data pointer.         */

    switch (msg->MethodID)
    {
        case OM_NEW:     /* Pass message onto superclass first so it can set aside the memory    */
                         /* for the object and take care of superclass instance data.            */
            if (retval = (APTR)DoSuperMethodA(cl, o, msg))
            {            /************************************************************************/
                         /* For the OM_NEW method, the object pointer passed to the dispatcher   */
                         /* does not point to an object (how could it? The object doesn't exist  */
                         /* yet.)  DoSuperMethodA() returns a pointer to a newly created         */
                         /* object. INST_DATA() is a macro defined in <intuition/classes.h>      */
                         /* that returns a pointer to the object's instance data that is local   */
                         /* to this class. For example, the instance data local to this class    */
                         /* is the RKMModData structure defined above.                           */
                         /************************************************************************/
                mmd = INST_DATA(cl, retval);
                mmd->currval = GetTagData(RKMMOD_CurrVal, 0L, /* initialize object's attributes. */
                                          ((struct opSet *)msg)->ops_AttrList);
                mmd->vallimit = GetTagData(RKMMOD_Limit, DEFAULTVALLIMIT,
                                           ((struct opSet *)msg)->ops_AttrList);
            }
            break;
        case OM_SET:
        case OM_UPDATE:
            mmd = INST_DATA(cl, o);
            DoSuperMethodA(cl, o, msg);   /* Let the superclasses set their attributes first.    */
            {
                struct TagItem *tstate, *ti;    /* grab some temp variables off of the stack.    */

                ti = ((struct opSet *)msg)->ops_AttrList;
                tstate = ti;

                        /* Step through all of the attribute/value pairs in the list.  Use the   */
                        /* utility.library tag functions to do this so they can properly process */
                        /* special tag IDs like TAG_SKIP, TAG_IGNORE, etc.                       */

                while (ti = NextTagItem(&tstate))    /* Step through all of the attribute/value  */
                {                 /* pairs in the list. Use the utility.library tag functions    */
                                  /* to do this so they can properly process special tag IDs     */
                                  /* like TAG_SKIP, TAG_IGNORE, etc.                             */
                    switch (ti->ti_Tag)
                    {
                        case RKMMOD_CurrVal:
                            if ((ti->ti_Data) > mmd->vallimit) ti->ti_Data =
                                    mmd->vallimit;
                            mmd->currval = ti->ti_Data;
                            NotifyCurrVal(cl, o, msg, mmd);
                            retval = (APTR)1L;  /* Changing RKMMOD_CurrVal can cause a visual    */
                            break;              /* change to gadgets in the rkmmodel's broadcast */
                                                /* list.  The rkmmodel has to tell the applica-  */
                                                /* tion by returning a value besides zero.       */
                        case RKMMOD_Up:
                            mmd->currval++;

                                 /* Make sure the current value is not greater than value limit. */
                            if ((mmd->currval) > mmd->vallimit) mmd->currval = mmd->vallimit;
                            NotifyCurrVal(cl, o, msg, mmd);
                            retval = (APTR)1L;  /* Changing RKMMOD_Up can cause a visual         */
                            break;              /* change to gadgets in the rkmmodel's broadcast */
                                                /* list.  The rkmmodel has to tell the applica-  */
                                                /* tion by returning a value besides zero.       */
                        case RKMMOD_Down:
                            mmd->currval--;
                                    /* Make sure currval didn't go negative. */
                            if ((LONG)(mmd->currval) == -1L)
                                mmd->currval = 0L;
                            NotifyCurrVal(cl, o, msg, mmd);
                            retval = (APTR)1L;  /* Changing RKMMOD_Down can cause a visual       */
                            break;              /* change to gadgets in the rkmmodel's broadcast */
                                                /* list.  The rkmmodel has to tell the applica-  */
                                                /* tion by returning a value besides zero.       */
                        case RKMMOD_Limit:
                            mmd->vallimit = ti->ti_Data; /* Set the limit.  Note that this does  */
                            break;                       /* not do bounds checking on the        */
                                                         /* current RKMModData.currval value.    */
                    }
                }
            }
            break;
        case OM_GET:                     /* The only attribute that is "gettable" in this        */
            mmd = INST_DATA(cl, o);      /* class or its superclasses is RKMMOD_CurrVal.         */
            if ((((struct opGet *)msg)->opg_AttrID) == RKMMOD_CurrVal)
            {
                *(((struct opGet *)msg)->opg_Storage) = mmd->currval;
                retval = (Object *)TRUE;
            }
            else retval = (APTR)DoSuperMethodA(cl, o, msg);
            break;
        default:       /* rkmmodelclass does not recognize the methodID, so let the superclass's */
                       /* dispatcher take a look at it.                                          */
            retval = (APTR)DoSuperMethodA(cl, o, msg);
            break;
    }
    return((ULONG)retval);
