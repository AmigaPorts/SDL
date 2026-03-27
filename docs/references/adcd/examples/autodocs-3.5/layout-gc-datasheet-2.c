/* Source: ADCD 2.1
 * Section: layout-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/layout-gc-datasheet.md
 */

      Attributes global to the whole layout group. Pass all of these
      BEFORE adding child objects:

      GA_ReadOnly (BOOL)
          Disables input to the entire layout group and its chidren.
          This tag is NOT propagated to children. The input blocking
          occurs within the layout object itself.

          Defaults to FALSE

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      GA_Disabled (BOOL)
          Disables entire layout group and its chidren. This tag
          is propagated all children. When setting/clearing this
          tag, take care to re-set/re-clear any children you want
          included from this mass disabling ability.

          Defaults to FALSE

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      GA_TextAttr (struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *)
          The font that will be used for the group label.

          Defaults to NULL (uses rastport default font).

          Applicability is (OM_NEW)

      LAYOUT_Orientation (ULONG)
          Whether the objects of this group are arranged horizontally or
          vertically. Possible values are LORIENT_HORIZONTAL and
          LORIENT_VERTICAL.

          Defaults to LORIENT_HORIZONTAL.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_FixedHoriz (BOOL)
          Whether the width of this layout group is fixed to the width
          assigned by the window or parent layout group. If set to FALSE,
          the gadget will minimize its width to the smallest possible
          value. Generally you will have to also set LAYOUT_ShrinkWrap
          (below) to TRUE also. It is recommended that this tag is used
          only in the top layout group. Using a weighted width of 0 gives
          more predictable results elsewhere.

          Defaults to TRUE.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_FixedVert (BOOL)
          Whether the height of this layout group is fixed to the height
          assigned by the window or parent layout group. If set to FALSE,
          the gadget will minimize its height to the smallest possible
          value. Generally you will have to also set LAYOUT_ShrinkWrap
          (below) to TRUE also. It is recommended that this tag is used
          only in the top layout group. Using a weighted height of 0 gives
          more predictable results elsewhere.

          Defaults to TRUE.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_HorizAlignment (ULONG)
          The horizontal alignment of the objects in this layout group.
          Possible values are LALIGN_LEFT, LALIGN_RIGHT, and
          LALIGN_CENTER.

          Defaults to LALIGN_LEFT.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_VertAlignment (ULONG)
          The vertical alignment of the objects in this layout group.
          Possible values are LALIGN_TOP, LALIGN_BOTTOM, and
          LALIGN_CENTER.

          Defaults to LALIGN_TOP.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_ShrinkWrap (BOOL)
          If set to TRUE, the layout group will shrink the interspacing
          of the child objects to minimum. Normally all extra space (if
          the total maximum size of the child objects is less than the
          size of the layoutgroup) is evenly distributed between the
          gadgets.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_EvenSize (BOOL)
          If TRUE, the layout group will try to reserve enough space to
          make the minimum size of each child object equal to the minimum
          of the largest child. Using this attribute makes it possible to
          have neatly arranged horizontal rows or grids of gadgets. This
          can take quite a bit of room, however, depending on the gadgets.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_SpaceInner (BOOL)
         Should layout leave space between objects or not. Set to FALSE
         if objects in a group should be put immediately beside each
         other.

         Defaults to TRUE.

         Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_SpaceOuter (BOOL)
         Should layout leave space around the group's objects or not.
         Set to TRUE if the objects should not be laid out using the
         whole group container box (for example if the group has a
         bevel around it).

         Defaults to FALSE.

         Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_InnerSpacing (ULONG)
          The minimum space left between objects. The value is in "virtual
          pixels", ie absolute pixels assuming bevel is configured for
          thin lines. If bevel configuration is something else, the value
          will be adjusted accordingly.

          Please avoid using this tag, if you do not require absolute
          control over the spacing. The LAYOUT_SpaceInner boolean is
          provided to tell whether there should be spacing or whether
          objects should be immediately connected to each other.

          Defaults to INTERSPACING.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_TopSpacing
      LAYOUT_BottomSpacing
      LAYOUT_LeftSpacing
      LAYOUT_RightSpacing (ULONG)
          The minimum space left to the top, bottom, left and right of
          the group, respectively. This value is in "virtual pixels", see
          LAYOUT_Spacing above.

          Please avoid using this tag, if you do not require absolute
          control over the spacing. The LAYOUT_SpaceOuter boolean is
          provided to tell whether there should be spacing or whether
          objects should be immediately connected to each other.

          If you use one of these tags to override a LAYOUT_SpaceOuter,
          pass this tag AFTER the LAYOUT_SpaceOuter tag.

          Defaults to 0.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_BevelStyle (ULONG)
          The style of the bevel drawn around the group. This value is
          passed to bevel.image.

          Defaults to BVS_NONE.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_BevelState (ULONG)
          The state of the bevel drawn around the group. Used to
          [DrawImageState()](../Includes_and_Autodocs_3._guide/node03AA.html) the bevel.image.

          Defaults to IDS_NORMAL.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      LAYOUT_Label (STRPTR)
          The label drawn in the group bevel. This value is passed to
          bevel.image. Note that if LAYOUT_BevelStyle is set to BVS_NONE,
          no bevel will be rendered, and thus this label will not be used
          either.

          No default (bevel.image default used)

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_LabelImage (Object *)
          The BOOPSI image to use as the group bevel label. Passed to
          bevel.image.

          See LAYOUT_Label.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_LabelPlace (ULONG)
          The position of the label (See LAYOUT_Label).

          Applicability is (OM_NEW, OM_SET, OM_UPDATE, OM_GET)

      LAYOUT_RemoveChild (Object *)
          Pointer to an object you wish to remove from the layout
          hierarchy. The object will be disposed of, so after using this
          tag, the pointer will be invalid.

          Applicability is (OM_SET)

      LAYOUT_AddChild (Object *)
          Pointer to an object you wish to add to the list of gadgets for
          this layout hierarchy level.

          Applicability is (OM_NEW)

      LAYOUT_AddImage (Object *)
          Same as LAYOUT_AddChild, but will mark the object as an
          imageclass subclass (meaning that IM_DRAW will be used instead
          of GM_RENDER to display it, and that none of the gadgetclass
          methods apply to it).

          Applicability is (OM_NEW)

      LAYOUT_ModifyChild (Object *)
          Inform layout gadget that the following child specific tags in
          the taglist apply to the specified object. LAYOUT_AddChild will
          do this automatically for new objects.

          Applicability is (OM_SET)

      LAYOUT_RelVerify (BOOL)
          When a gadget returns a code that normally makes Intuition send
          an IDCMP_GADGETUP message to the application, layout.gadget
          will send a notification message (OM_NOTIFY, IDCMP_IDCMPUPDATE)
          with the essential information of the gadgetup message. This is
          because in certain situations the IDCMP_GADGETUP message can
          not be sent (in particular, when tab cycling between gadgets).
          The notification will consist of GA_ID set to the ID of the
          gadget in question, this LAYOUT_RelVerify tag set to TRUE, and
          the LAYOUT_RelCode tag (below) set to the gadget's return code
          (IntuiMessage.Code field of the IDCMP_GADGETUP).

          Applicability is (OM_NOTIFY)

      LAYOUT_RelCode (UWORD)
          A copy of the IntuiMessage.Code field of the IDCMP_GADGETUP in
          question, sent via OM_NOTIFY (ie. received as OM_UPDATE or
          IDCMP_IDCMPUPDATE).

          Applicability is (OM_NOTIFY)

      LAYOUT_TabVerify (BOOL)
          If the gadget release was triggered by tab cycling, this
          attribute will be TRUE in the release verify IDCMPUPDATE. This
          lets you distinguish, for example, between pressing tab and
          enter in a string gadget.

          Applicability is (OM_NOTIFY)

      LAYOUT_RelAddress (struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *)
          Address of the gadget that sent the gadgetup is provided in the
          gadgetup notification using this tag.

          Applicability is (OM_NOTIFY)

      LAYOUT_HelpHit (UWORD)
          When a gadget returns a hit for helptest, the return code, along

          with GA_ID, is notified using this tag.

          Applicability is (OM_NOTIFY)

      LAYOUT_Parent (Object *)
          Set automatically by layout.gadget for all child objects, this
          attribute points to the parent layout object. If NULL, the
          layout object is the window's topmost layout.
          When an object is added to the layout hierarchy, it will
          receive this tag in OM_SET. If you so wish, you may use this to
          let the gadget talk to its parent layout group.
          Any group gadget that should work with layout.gadget must
          support this attribute.

          Applicability is (OM_SET, OM_GET)

      LAYOUT_DeferLayout (BOOL)
          By setting this tag to TRUE in your window's top layout, you
          can defer the layout and refresh process off the input.device
          context to your application. This will make input.device more
          responsive, and drop the (possibly quite heavy) process of
          recalculating the display to normal application priority
          instead of the priority 20
          of input.device. [Input](../Includes_and_Autodocs_3._guide/node017F.html) handling will be retained in input.device
          context, to keep the GUI responsive.
          If you use this tag, you must listen to LAYOUT_RequestLayout
          and LAYOUT_RequestRefresh notifications and process them in
          prompt manner, or your GUI will not display properly, if at all.

          Applicability is (OM_NEW, OM_SET)

      LAYOUT_RequestLayout (Object *)
          If the above LAYOUT_DeferLayout tag is set to TRUE, the gadget
          will defer GM_LAYOUT methods invoked by input.device and notify
          its IC target with this tag. You should be listening to it in
          your application IDCMP handler (IDCMP_IDCMPUPDATE) and calling
          [RethinkLayout](../Includes_and_Autodocs_3._guide/node043D.html) with FALSE for refresh flag when receiving one.

          Defaults to FALSE.

          Applicability is (OM_NOTIFY)

      LAYOUT_RequestRefresh (Object *)
          If the above LAYOUT_DeferLayout tag is set to TRUE, the gadget
          will defer GM_RENDER methods invoked by input.device and notify
          its IC target with this tag. You should be listening to it in
          your application IDCMP handler (IDCMP_IDCMPUPDATE) and calling
          [RefreshGList](../Includes_and_Autodocs_3._guide/node03DD.html) when receiving one.

          Defaults to FALSE.

          Applicability is (OM_NOTIFY)

      LAYOUT_TextPen (WORD)
          The pen that will be used for group label text. See bevel.image.

          Applicability is (OM_NEW)

      LAYOUT_FillPen (WORD)
          The pen that will be used for the group fill pattern. See
          bevel.image.

          Applicability is (OM_NEW)

      LAYOUT_FillPattern (UWORD *)
          The fill pattern for the group. See bevel.image.

          Defaults to none.

          Applicability is (OM_NEW)

      GA_BackFill (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *)
          A layer backfill hook to use in the group to provide a more
          complex background pattern.

          Defaults to clear for the main layout, and none for sublayouts.

          Applicability is (OM_NEW)

      LAYOUT_LabelColumn (ULONG)
          The side where the on which side of the gadget the label will
          be placed in the group. Valid values are PLACETEXT_LEFT and
          PLACETEXT_RIGHT. See CHILD_Label.

          Defaults to PLACETEXT_LEFT.

          Applicability is (OM_NEW, OM_SET, OM_NOTIFY)

      LAYOUT_LabelWidth (ULONG)
          The width of the label column in a vertical group. This attribute
          may be used to justify several layout groups.

          Applicability is (OM_SET, OM_GET)

      LAYOUT_AlignLabels (Object *)
          A pointer to another layout instance that should have equal
          label width with this one. Set to a cycle between all the
          groups, these will automatically justify their labels with each
          other. This attribute should be set as soon as possible, ie. in
          OM_NEW or OM_SET directly afterwards, before the layout size is
          calculated.

          Applicability is (OM_NEW, OM_SET)

      LAYOUT_Inversed (BOOL) (V42.27)
          Causes children to be added to the layout group via
          [AddHead()](../Includes_and_Autodocs_3._guide/node01D9.html) vs [AddTail()](../Includes_and_Autodocs_3._guide/node01E1.html).

          Applicability is (OM_NET, OM_SET)


      Attributes referring to the "current" child object:

      CHILD_MinWidth, CHILD_MinHeight (ULONG)
          The minimum width and height of the object, in pixels. Setting
          this attribute means that GM_DOMAIN is not respected in that
          direction.

          Defaults to ~0, which means that the layout gadget will ask the
          object, using GM_DOMAIN.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      CHILD_MaxWidth, CHILD_MaxHeight (ULONG)
          As above, for the maximum size.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      CHILD_NominalSize (BOOL)
          If this attribute is TRUE, layout will use GDOMAIN_NOMINAL
          instead of GDOMAIN_MINIMUM when requesting the minimum size of
          the gadget. This is useful when the minimum size of a gadget
          looks unattractive, but the gadget will return a more attractive
          size with GDOMAIN_NOMINAL.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      CHILD_WeightedWidth (ULONG)
          The relative width of the child object. See the DESCRIPTION
          above for the layout method. If set to 0, the child will always
          be rendered in the minimum size (specified by either GM_DOMAIN
          or CHILD_MinWidth). Use CHILD_MinWidth and a weighted with of 0
          instead of CHILD_MinWidth and CHILD_MaxWidth. The latter method
          will also work, but will slow down the layout. As a special
          rule, many BOOPSI images using bitmap data can not be resized
          from the initial size. Fix their size by setting MinWidth and
          MinHeight, and the weight to 0.

          Defaults to 100.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      CHILD_WeightedHeight (ULONG)
          The relative height of the child object. See CHILD_WeightedWidth.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      CHILD_WeightMinimum (BOOL)
          Setting this tag to TRUE will make the layout group set the
          weighted width and height to the minimum values set with
          CHILD_MinWidth and CHILD_MinHeight or returned by GM_DOMAIN. This
          allows creating layout groups where the relative size of the
          objects always remains the same. Be warned that if the object
          does not support GM_DOMAIN and minimum size is not set manually,
          the weight will be set to 2 (the default minimum size of an
          object). Normally you would want to set this tag for every
          resizable object in a layout group.

          Defaults to FALSE.

          Applicability is (OM_NEW)

      CHILD_ReplaceObject
          CHILD_ReplaceImage (Object *)
          Replace the current child object with the one specified. The
          current object will be disposed of. See LAYOUT_AddChild,
          LAYOUT_AddImage, LAYOUT_RemoveChild, LAYOUT_ModifyChild.

          Applicability is (OM_SET)

      CHILD_CacheDomain (BOOL)
          To speed up resizing, layout gadget will normally cache the
          first values returned by GM_DOMAIN and use that cache for
          subsequent relayouts, instead of calling GM_DOMAIN again.
          Normally this will have the same results all the time. If you
          have a custom gadget that might return varying values between
          calls to GM_DOMAIN (ie the minimum or maximum size of it could
          vary during runtime), set this tag to FALSE for that object and
          all its parent groups. Note that since layout groups are aware
          of their parent layouts, they can disable caching in the
          hierarchy above them automatically,  if you SetAttr this
          attribute _AFTER_ creating the whole layout hierarchy.

          Defaults to TRUE.

          Applicability is (OM_NEW, OM_SET) (OM_SET preferred)

      CHILD_Label (Object *)
          The imageclass object, preferably label.image, to use as the
          object's label. These labels are supported only left or right
          aligned groups, and will be placed in the left or right of the
          gadget even in horizontal groups. All the labels will take the
          space of the widest label. Label-less objects will be laid out
          in full width; if you want to leave the label column empty, use
          the special value LCLABEL_NOLABEL. Every object in a group gets
          the same amount of space reserved for a label, whether they have
          a label or not. This also (or in particular) applies to
          horizontal groups; usually the correct effect is reached by
          putting the label on the group itself instead of one of the
          objects in it. See LAYOUT_LabelColumn.

          Defaults to NULL.

          Applicability is (OM_NEW, OM_SET)

      CHILD_NoDispose (BOOL)
          By setting this attribute, you inform the layout object that
          this child object should not be automatically disposed when
          the layout object itself is disposed. This attribute allows
          sharing objects between layouts.

          Default is FALSE.

          Applicability is (OM_NEW, OM_SET)

      CHILD_ScaledWidth (UWORD) (V42.27)
          Scales the child minimum domain size to a larger value;

          minwidth = minwidth + ((minsize * scalewidth)/100)

          Default is 0.

          Applicability is (OM_NEW, OM_SET)

      CHILD_ScaledHeight (UWORD) (V42.27)
          Scales the child minimum domain size to a larger value;

          minheight = minheight + ((minsize * scaleheight)/100)

          Default is 0.

          Applicability is (OM_NEW, OM_SET)
