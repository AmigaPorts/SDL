/* Source: ADCD 2.1
 * Section: listbrowser-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-datasheet.md
 */

     NAME
        listbrowser_gc -- For browsing linked lists in various ways.

     SUPERCLASS
        gadgetclass

     DESCRIPTION
        This gadget is very similar to the LISTVIEW_KIND gadget in
        gadtools.library, with numerous enhancements.  It displays a list in
        a scrolling view so that you can browse through it an select items
        in various ways.

        Advantages that this class provides:

         > Allows the user to select multiple items (either by dragging or
           shift-key selection).

         > Displays items in multiple columns.

         > Displays items as a mixture of text and images in different.
           colours.

         > Items can have checkboxes that can be toggled on and off.

         > [Text](../Includes_and_Autodocs_3._guide/node0332.html) items can be edited in place.

         > Hierarchical display of items supported.

         > Can displays column headers.

         > Allows allows horizontal scrolling of the list.

         > Supports window relativity.

         > Supports OS 3.0 BOOPSI [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) HelpTest.

         > Supports layout.gadget/window.class backfills.

     METHODS

        OM_NEW -- Create the list browser gadget.  Passed to superclass then
            calls OM_SET.

        OM_SET -- Set object attributes.  Passed to superclass first.

        OM_DISPOSE -- Frees up the list browser gadget.

        OM_UPDATE -- Set object notification attributes.  Passed to
            superclass first.

        GM_RENDER -- Renders the gadget imagery.  Overrides the superclass.

        GM_GOACTIVE -- Handles activation, and selection of the scrollbars
            and arrows.  Overrides the superclass.

        GM_HANDLEINPUT -- Handles input events once active.  Overrides the
            superclass.

        GM_GOINACTIVE -- Closes the chooser menu.  Overrides the superclass.

        [LBM_ADDNODE](../Includes_and_Autodocs_3._guide/node0441.html) -- Adds a node to the attached list.

        [LBM_EDITNODE](../Includes_and_Autodocs_3._guide/node0442.html) -- Edit an attached nodes attributes.

        [LBM_REMNODE](../Includes_and_Autodocs_3._guide/node0443.html) -- Removes a node from the attached list.

        LBM_SORT -- Sort attached list on specified column (V42)

        LBM_SHOWCHILDREN --  (V42)

        LBM_HIDECHILDREN --  (V42)

        All other methods are passed to the superclass.

     ATTRIBUTES
        GA_Disabled (BOOL)
            Set to TRUE to disable gadget, FALSE otherwise.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        GA_ReadOnly (BOOL)
            Specifies that the list browser be read-only.  This means that
            no nodes within the list can be selected, the user can just
            scroll through and view the list.  The frame of the list will be
            rendered as recessed as a visual cue that no nodes can be
            selected.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        GA_TextAttr (struct [TextAttr](../Includes_and_Autodocs_3._guide/node05EC.html#line64) *)
            Font to use for the contents of the list browser.

            Defaults to the screen's font.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_Top (LONG)
            Sets the node that is to appear at the top of list browser view.
            Must be positive.  If its beyond the maximum possible value,
            the last page in the list will be displayed.

            Defauts to 0.

            Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY)

        LISTBROWSER_MakeVisible (LONG)
            Ensures that the specified is within the view and will scroll
            only when necessary (unlike LISTBROWSER_Top which will always
            scrolls).

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET)

        LISTBROWSER_Labels (struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *)
            An Exec list.  Nodes in this list must be allocated with
            [AllocListBrowserNodeA()](../Includes_and_Autodocs_3._guide/node0444.html).

            A value of ~0 or NULL indicates that the list is "detached".
            This must be done before you can modify a list already attached
            to a list browser. After detaching, you should carry out your
            updates to the list as quickly as possibly and then re-attach.
            When a list browser is initially added to a window it MUST have
            a list attached to it, ~0 is not valid in this case.

            If you are using the LISTBROWSER_AutoFit attribute, the column
            sizes will NOT be re-calculated when you change lists, you must
            pass LISTBROWSER_AutoFit, TRUE again to adjust the column sizes
            to fit your new list.

            Note that when changing lists, you may want to reset certain
            other attributes, such as LISTBROWSER_Selected, as this value
            will be retained even when changing lists.

            NOTE: Lists can NOT be shared amongst other list browsers
            simultaneously.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_Spacing (WORD)
            If you would like additional spacing between nodes in your
            ListBrowser, use this tag to define how many extra pixels you
            want.

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_Selected (LONG)
            Sets the node in a single-select list that will be selected.
            Any previously selected node(s) will be deselected.  Note
            that a node can become selected without being visible.  A
            value of -1 ( (ULONG)~0 ) is used to say that no item is
            selected.  The results of this tag are undefined in a multi-
            select list browser.

            This value is returned in the IntuitMessage.Code field.

            Defaults to -1.

            Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY)
