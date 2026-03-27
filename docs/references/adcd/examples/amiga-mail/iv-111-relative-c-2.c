/* Source: ADCD 2.1
 * Section: iv-111-relative-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-111-relative-c.md
 */

    if ( retval = (ULONG)(newobj = (Object *) DoSuperMethodA( cl, o, msg )) )
    {
      /* Set custom relativity */
      ((struct Gadget *)newobj)->Flags |= GFLG_RELSPECIAL;

      /* Tell Intuition this gadget supports gadget help */
      SetAttrs(newobj, GA_GadgetHelp, TRUE, TAG_DONE, NULL);

      /* Attempt to allocate a frame.  If I can't, then
       * delete myself and fail.
       */
      if ( ! ( ((struct Gadget *)newobj)->GadgetRender =
          NewObject( NULL, "frameiclass",
                     IA_FrameType, FRAME_BUTTON,
                     TAG_DONE ) ) )
      {
        CoerceMethod( cl, o, OM_DISPOSE );
        retval = NULL;
      }
    }
    break;
