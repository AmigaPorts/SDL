---
title: listbrowser_gc/--datasheet--
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-datasheet
functions: [ActivateGadget, ScrollRaster, ScrollWindowRaster]
libraries: [graphics.library, intuition.library]
---

# listbrowser_gc/--datasheet--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
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

         > [Text](autodocs-3.5/graphics-library-text-2.md) items can be edited in place.

         > Hierarchical display of items supported.

         > Can displays column headers.

         > Allows allows horizontal scrolling of the list.

         > Supports window relativity.

         > Supports OS 3.0 BOOPSI [Gadget](autodocs-3.5/include-intuition-intuition-h.md) HelpTest.

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

        [LBM_ADDNODE](autodocs-3.5/listbrowser-gc-lbm-addnode.md) -- Adds a node to the attached list.

        [LBM_EDITNODE](autodocs-3.5/listbrowser-gc-lbm-editnode.md) -- Edit an attached nodes attributes.

        [LBM_REMNODE](autodocs-3.5/listbrowser-gc-lbm-remnode.md) -- Removes a node from the attached list.

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

        GA_TextAttr (struct [TextAttr](autodocs-3.5/include-graphics-text-h.md) *)
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

        LISTBROWSER_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *)
            An Exec list.  Nodes in this list must be allocated with
            [AllocListBrowserNodeA()](autodocs-3.5/listbrowser-gc-alloclistbrowsernodea.md).

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
```
		LISTBROWSER_SelectedNode (struct [Node](autodocs-3.5/include-exec-nodes-h.md) *)
		    This is the same as LISTBROWSER_Selected, except that you refer
		    to a node by its actual node structure.


```c
            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_MultiSelect (BOOL)
            Puts the list browser into multi-select mode.  In multi-select
            mode the user can select several items from the list by either
            dragging the mouse over items, or holding down the shift key and
            click items to add them to the ones selected.  Nodes can be
            deselected by holding down the shift key and clicking on selected
            node.

            Selected nodes will have the LBNA_Selected attribute set to
            TRUE (see GetListBrowserNodeAttrs()).

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_PersistSelect (BOOL)
            When the list browser is in multi-select mode, this flag changes
            the selection behaviour so that shift does NOT have to be held
            down to select multiple nodes

            Please be aware that this is distinctly NON-STANDARD behaviour
            and therefore should be used with extreme discretion.  About
            the only time this may be appropriate is when you are dealing
            with long lists where users are typically having to select a
            large number of nodes.  Because there is no simple way to clear
            all selections when in this, some method should exist in your
            user interface for clearing all selections.

            This has no meaning if the list browser is not in multi-select
            mode.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_ShowSelected (BOOL)
            Specifies that you want the selected item in a single-select
            list browser to be remain visible after it is selected, until
            another item is selected.  This tag has undefined results in
            a multi-select list browser.

            Defaults to TRUE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_NumSelected (LONG)
            The number of items selected in a multi-select list browser.
            This contains a meaningless value if your listbrowser is not
            multi-select.

            Applicability is (OM_GET)

        LISTBROWSER_RelEvent (ULONG)
            Describes the event that caused the gadget release of the list
            browser.  Currently defined events are:

                LBRE_NORMAL - Normal selection of an item.
                LBRE_HIDECHILDREN - The user tried to hide children in a
                    hierarchical listbrowser.
                LBRE_SHOWCHILDREN - The user tried to show children in a
                    hierarchical listbrowser.
                LBRE_EDIT - The contents of a node were edited.
                LBRE_DOUBLECLICK - The node was double-clicked on.
```
				Additional return values added with V42;

```c
                LBRE_CHECKED - A checkbox node was checked.
                LBRE_UNCHECKED_ - A checkbox node was unchecked.
                LBRE_TITLECLICK - A column's title was clicked.
                LBRE_COLUMNADJUST - A column's separator was clicked/dragged.

            Applicability is (OM_GET)

        LISTBROWSER_VertSeparators (BOOL)
        LISTBROWSER_Separators (BOOL)
            Specifies that bevelled lines be drawn as separators between
            each column.  Has no effect if the list only has one column.

            Defaults to TRUE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_HorizSeparators	(BOOL) (V41)
            Renders horizontal lines below each node.  This is useful if your
            listbrowser is very wide, and you want to make it easier for
            users to follow the rows of data.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_Borderless (BOOL)
            Create a view without a border.  Useful if you wish the list
            browser to take up the entire window, and have an attached
            scroller in the window border.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_ColumnInfo (struct [ColumnInfo](autodocs-3.5/include-gadgets-listbrowser-h.md) *)
            Provides the column layout info for the list browser.  This is
            an array of struct [ColumnInfo](autodocs-3.5/include-gadgets-listbrowser-h.md).  The array must have one entry
            per column, plus one terminating entry where the ci_Width field
            is -1.  Each field in an array entry is filled in as follows:

                ci_Width (WORD)
                This specifies the percentage of the view width you want the
                column to be.  If a virtual width is given, this will be a
                percentage of that, otherwise it will be a percentage of the
                actual gadget width.  Since you are specifying a percentage,
                the actual size of the column will automatically adjust as the
                virtual or actual width of the gadget changes.

                ci_Title (STRPTR)
                If you have specified LISTBROWSER_ColumnTitles, TRUE then
                you MUST fill in the titles you wish to appear for each column
                here.

                ci_Flags (ULONG)
                Flags for the column, suported by V42 and later only.

                     CIF_WEIGHTED -- weighted width column (default)
                     CIF_FIXED -- fixed pixel width specided in ci_Width.
                     CIF_DRAGGABLE -- separator is user draggable.
                     CIF_NOSEPARATORS -- no separator on this column.
                     CIF_SORTABLE -- column is sortable.

            Passing NULL for the [ColumnInfo](autodocs-3.5/include-gadgets-listbrowser-h.md) means that you want a single
            column taking up the entire width of the gadget with no title.

            NOTES: [ColumnInfo](autodocs-3.5/include-gadgets-listbrowser-h.md) can NOT be shared amongst other list browsers
            simultaneously.  While the ColumInfo is in use by list browser,
            you may not modify it.  If you wish to make any modifications
            to it, then first detach the list, make your modifications then
            re-attach the list AND give use LISTBROWSER_ColumnInfo tag
            again.  [List](autodocs-3.5/include-exec-lists-h.md) browser may modify the contents of this structure.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_ColumnTitles (BOOL)
            Show titles above each column.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_AutoFit (BOOL)
            Informs the ListBrowser that you want your column widths
            calculated automatically for you to best fit the items in the
            list attached to it.  This will make your gadget a virtual
            width gadget, with the virtual width being the width needed to
            fit all columns.

            For this to work, you must still pass LISTBROWSER_ColumnInfo with
            a ColumInfo structure that has entries for each column, as normal.
            The only change being that the initial values of the ci_Width
            field will be ignored, and instead will be filled in by
            ListBrowser.

            If you are using the LISTBROWSER_AutoFit attribute, the column
            sizes will NOT be re-calculated when you change lists with
            LISTBROWSER_Label, you must pass LISTBROWSER_AutoFit, TRUE again
            to adjust the column sizes to fit your new list.

            Note for V42, with autofit enabled, wordwrap columns presently
```
			will NOT rewrap. This is an internal chicken and the egg issue.

```c
            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_VirtualWidth (WORD)
            Allows rendering beyond the right edge of the view area in the
            gadget.

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_Left (WORD)
            The left offset of the view.  This is only useful in combination
            with either LISTBROWER_VirtualWidth or LISTBROWSER_AutoFit to
            reveal horizontal parts of the view that might be hidden.  The
            offset is specified in terms of pixels.

            Defaults to 0.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_VerticalProp (BOOL)
            Creates a vertical scrollbar with arrows for scrolling up and
            down through the list.

            Defaults to TRUE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_HorizontalProp (BOOL)
            Creates a horizontal scrollbar with arrows for scrolling
            sideways across the view.  Not useful unless you've used
            LISTBROWSER_VirtualWidth or LISTBROWSER_AutoFit since there
            would be nothing horizontally hidden.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_SET, OM_GET)

        LISTBROWSER_VPropTotal
        LISTBROWSER_VPropTop
        LISTBROWSER_VPropVisible
        LISTBROWSER_HPropTotal
        LISTBROWSER_HPropTop
        LISTBROWSER_HPropVisible
            These tags are for getting the status of the two prop gadgets
            for the listbrowser.  These are read-only and are intended for
            linking external prop gadgets to a listbrowser.

            Applicability is:
            LISTBROWSER_VPropTotal, LISTBROWSER_VPropVisible,
            LISTBROWSER_HPropTotal, LISTBROWSER_HPropVisible:
                (OM_GET, OM_NOTIFY)
            LISTBROWSER_VPropTop, LISTBROWSER_HPropTop:
                (OM_SET, OM_GET, OM_NOTIFY)

        LISTBROWSER_Position (ULONG)
            Alters the view position within the listbrowser gadget.  See
            the include file for possible positions.  This tag exists mainly
            to make complex keyboard controls simple.

            Applicability is (OM_SET)

        LISTBROWSER_MouseX (WORD)
        LISTBROWSER_MouseY (WORD)
            Returns the co-ordinates of the mouse within the gadgets box
            when the mouse button was last released in the gadget.

            Applicability is (OM_GET)

        LISTBROWSER_ScrollRaster (BOOL)
            When this option is set, ListBrowser will use [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) for
            extra fast scrolling.  This option is safe to use if the gadget
            will be in a Smart Refresh or Super Bitmap window.

            If the gadget will be in a Simple Refresh window, you should be
            aware of an Intuition bug that will cause layer damage to not
            be updated properly.  This problem only exists under V37 of
            Intuition, as ListBrowser sets the GMORE_SCROLLRASTER flag which
            causes proper updates in V39 and above.  HOWEVER, if you are
            using [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) in a window that contains a ListBrowser,
            you MUST check the version of Intuition and use
            [ScrollWindowRaster()](autodocs-3.5/intuition-library-scrollwindowraster.md) instead if the version is 39 or higher!

            Defaults to TRUE.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_Hierarchical (BOOL)
            Puts the ListBrowser into hierarchical mode, where nodes can be
            browsed in a hierarchically by "generation", and generations can
            be hidden.

            See the LBNA_Generation node tag.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_ShowImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
        LISTBROWSER_HideImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
        LISTBROWSER_LeafImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)
            You can replace the images for showing a generation, hiding a
            generation and the leaf (no children) image with your own.  If
            you do not provide any of them, default images will be rendered
            for you.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_Editable (BOOL)
            If you want to enable in place editing of selected node columns,
            you must set this flag to TRUE.  Note that
            LISTBROWSER_ShowSelected must also be TRUE for node editing to
            work properly.

            Defaults to FALSE.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_EditNode (LONG)
            The number of a node that you want to start editing.  You must
            also specify the column you want to edit with
            LISTBROWSER_EditColumn, and then activate the gadget using
            [ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md) (or [ActivateLayoutGadget()](autodocs-3.5/layout-gc-activatelayoutgadget.md) if the listbrowser
            is being used with layout.gadget).

            This tag will also make the given node the selected node.

            Defaults to -1.

            Applicability is (OM_NEW, OM_SET)

        LISTBROWSER_EditColumn (WORD)
            The number of a column that you want to start editing.  You must
            also specify the node number you want to edit with
            LISTBROWSER_EditNode, and then activate the gadget using
            [ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md) (or [ActivateLayoutGadget()](autodocs-3.5/layout-gc-activatelayoutgadget.md) if the listbrowser
            is being used with layout.gadget).

            Defaults to -1.

            Applicability is (OM_NEW, OM_SET)

        LISTBROWSER_EditTags (struct TagList *)
            Tags that you want to be passed to the string gadget used when
            editing gadget text.  Though you could theoretically pass any
            tags to the gadget, you should generally not pass tags that
            affect the position of the gadget.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_RelColumn (WORD)
            The column the mouse was over when the button is released.  This
            is most useful in a listbrowser with editable nodes in different
            columns.  By checking both this and LISTBROWSER_RelEvent on
            gadget release, you can tell if a node was edited and what column
            of that node was edited.

            This  will not contain valid data if the mouse button was
            released over a read-only node or if your listbrowser is in read-
            only mode.

            Applicability is (OM_GET)

        LISTBROWSER_CheckImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)  (V41)
            Provide a custom image for a checkbox node while that node is
            in the checked state.  A NULL image means that listbrowser
            render some default imagery.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_UncheckedImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)  (V41)
            Provide a custom image for a checkbox node while that node is
            in the unchecked state.  A NULL image means that listbrowser
            render some default imagery.

            Defaults to NULL.

            Applicability is (OM_NEW, OM_GET, OM_SET)

        LISTBROWSER_TotalNodes (LONG)  (V41)
            Return the total number of nodes currently attached to the
            listbrowser.

            Applicability is (OM_GET)

        LISTBROWSER_MinNodeSize (LONG)  (V42)
            Minimum [Node](autodocs-3.5/include-exec-nodes-h.md) size for MemPool optimization, useful when
            coupled with LBNA_NodeSize and using the internal pool.

            Applicability is (OM_NEW,OM_SET)

        LISTBROWSER_TitleClickable (BOOL)  (V42)
            Enables column-title bar clicking when TRUE.

            Defaults to FALSE.

            Applicability is (OM_NEW,OM_SET)

        LISTBROWSER_MinVisible (LONG)  (V42)
            Minimum visible node count. This is a causes the
            minimum domain to be large enough to hold the specified number
            of nodes using the the estimated average node height.
            Note *ESTIMATED* this is not garanteed results. The result may
            be slightly less or greater than specified, and potentially
            alot greater if other objects within the layout group cause the
            listbrowser to layout larger than its minimum domain.

            Applicability is (OM_NEW,OM_SET)

        LISTBROWSER_PersistSelect (BOOL)  (V42)
            When set TRUE, SHIFT key is NOT required for multi-select.

            Defaults to FALSE.

            Applicability is (OM_NEW,OM_SET)

        LISTBROWSER_CursorSelect (LOng)  (V42)
            Keyboard cursor selected node number.

            Defaults to 0.

            Applicability is (OM_SET, OM_GET)

        LISTBROWSER_CursorNode (struct [Node](autodocs-3.5/include-exec-nodes-h.md) *)  (V42)
            Keyboard cursor selected node pointer.

            Defaults to NULL.

            Applicability is (OM_GET)

        LISTBROWSER_FastRender (BOOL)  (V42)
            Enables use of mask planes on non-CyberGraphx screens.
            Also turns off custom pen support.

            The potential performance improvement with deep ECS or
            AGA displays can be *HUGE* for complex multi-column lists.

            Defaults to FALSE.

            Applicability is (OM_NET, OM_SET)

        LISTBROWSER_TotalVisibleNodes (LONG)  (V42)
            Total visible node count (estimated).

            Defaults to 0.

            Applicability is (OM_GET)

        LISTBROWSER_WrapText (BOOL)  (V42)
            Enables word-wrapping of column nodes flagged for word wrap.
```
			Wrapping is delimited by a space, 'n' newline, or 't' tab.


```c
            Defaults to 0.

            Applicability is (OM_NEW, OM_SET)

    BUGS
        Versions 41.250 and below do not support LISTBROWSER_PersistSelect.
        Versions 41.631 and below do not support LISTBROWSER_FastRender correctly.

    SEE ALSO
        [graphics.library/ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md), [intuition.library/ActivateGadget()](autodocs-3.5/intuition-library-activategadget-2.md),
        [intuition.library/ScrollWindowRaster()](autodocs-3.5/intuition-library-scrollwindowraster.md), layers.library,
        [layout.gadget/ActivateLayoutGadget()](autodocs-3.5/layout-gc-activatelayoutgadget.md)
```

---

## See Also

- [ActivateGadget — intuition.library](../autodocs/intuition.library.md#activategadget)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
- [ScrollWindowRaster — intuition.library](../autodocs/intuition.library.md#scrollwindowraster)
