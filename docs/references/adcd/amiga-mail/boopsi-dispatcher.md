---
title: Boopsi Dispatcher
manual: amiga-mail
chapter: amiga-mail
section: boopsi-dispatcher
functions: []
libraries: []
---

# Boopsi Dispatcher

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Now all you need to do is implement a dispatcher routine.  When the
dispatcher is in operation, Intuition passes method IDs to it.  The
dispatcher will either execute code corresponding to the a method ID (the
code is usually part of the dispatcher) or delegate processing the method
to the superclass (or it can do a little of both).

The following fragment provides an example of what a dispatcher for a
boopsi class looks like (Note that __saveds (Save DS) is used to insure
that register A4 is set up properly for indirect addressing with the SASC
compiler):


   ULONG __saveds dispatchmyTextLabel (Class *cl, Object *o, Msg msg)
   {
```c
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
```
   }

