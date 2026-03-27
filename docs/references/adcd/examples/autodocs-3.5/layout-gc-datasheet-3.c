/* Source: ADCD 2.1
 * Section: layout-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/layout-gc-datasheet.md
 */

      Setting the attributes via SetGadgetAttrs() (OM_SET) will not
      automatically rerender the display! Call [RethinkLayout()](../Includes_and_Autodocs_3._guide/node043D.html) to
      relayout and refresh display after SetGadgetAttrs().

      In this document, the terms layout, group, and object are used
      intermixed. Most of the time, layout and group are used as
      synonyms. Virtually any object referred to could also be a
      layout group.

      To make defining layout hierarchies easier, the reaction_macros.h
      include file defines a set of macros that hide [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html)
      calls. This will clean up the rather large tag lists for the
      creation of layout groups. See the ReAction examples for use of
      these macros, and layout.gadget in general.

      In relation to above, remember that in AmigaOS (as of V40), the
      stack size is restricted. During the beta test period, the
      average size of a layout group for a whole window seemed to
      average at approximately 1 KB. Building as large tag lists as
      this on stack is rather slow, as well as easily overflowing the
      small default stacks of AmigaOS. For windows with relatively
      static layouts that are opened often, consider building tag
      lists as static data and passing a pointer to them for
      NewObjectA(). If this is too much work, make sure that your
      program's stack is large enough to hold  the tag list. If it is
      too small, you can use the V37 Exec [StackSwap()](../Includes_and_Autodocs_3._guide/node023E.html) call to replace
      it with a larger one, or simply set the global variable long
      __stack to a large enough value, if the startup code you link
      with provides stack swap support, as for example the c.o of
      SAS/C 5.x and above does.

      Due to Intuition limitations, IDCMP_GADGETUP messages are not
      fully supported. The IAddress will always point to the root
      layout object of the window, not the actual gadget the message
      originates from. Use GadgetID to distinguish between gadgets.
      When using tab cycle, GADGETUP messages will be lost
      altogether. However, layout.gadget sends a notification for all
      gadgetups, containing the tags GA_ID, LAYOUT_RelVerify and
      LAYOUT_RelCode, containing, respectively, the ID, TRUE, and the
      IntuiMessage.Code value it returned. Additionally a
      LAYOUT_TabVerify tag will be TRUE or FALSE depending on whether
      the gadget release was triggered by tab cycle.
      Use of models and/or IDCMP_IDCMPUPDATE is encouraged.
