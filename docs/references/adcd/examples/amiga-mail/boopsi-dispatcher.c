/* Source: ADCD 2.1
 * Section: boopsi-dispatcher
 * Library: amiga-mail
 * ADCD reference: amiga-mail/boopsi-dispatcher.md
 */

       struct localObjData *lod;
       Object *newobj;
       ULONG retval;

       switch (msg->MethodID)
       {
           /* Create a new object */
           case OM_NEW:
               /* Have our superclass create it.  DSM() passes on the
                * message to the superclass, where msg is the structure
                * containing the message specific parameters.
                */
               if (newobj = (Object *) DSM (cl, o, msg))
               {
                   /* Set the attributes */
                   setmyTextLabelAttrs(cl, newobj, (struct opSet *) msg);
               }

               retval = (ULONG) newobj;
               break;

           /* Obtain information on an attribute */
           case OM_GET:
               retval = getmyTextLabelAttrs (cl, o, (struct opGet *) msg);
               break;

           /* Set attributes */
           case OM_UPDATE:
           case OM_SET:
               /* Let the superclass set the attributes that it
                * knows about. */
               retval = DSM (cl, o, msg);

               /* Set the attributes that we care about */
               retval |= setmyTextLabelAttrs (cl, o, (struct opSet *) msg);
               break;

           /* Draw the various states that the image supports */
           case IM_DRAW:
           case IM_DRAWFRAME:
               retval = drawmyTextLabel (cl, o, (struct impDraw *) msg);
               break;

           /* Let the superclass handle everything else */
           default:
               retval = (ULONG) DSM (cl, o, msg);
               break;
       }

       return (retval);
