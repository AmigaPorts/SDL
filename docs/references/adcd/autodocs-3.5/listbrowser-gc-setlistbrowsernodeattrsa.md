---
title: listbrowser_gc/SetListBrowserNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-setlistbrowsernodeattrsa
functions: []
libraries: []
---

# listbrowser_gc/SetListBrowserNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        SetListBrowserNodeAttrsA -- Set attributes of a ListBrowser node.

    SYNOPSIS
        VOID SetListBrowserNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        SetListBrowserNodeAttrs(node, firsttag, ...)

        VOID SetListBrowserNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        SetListBrowserNodeAttrsA(node, taglist)

    FUNCTION
        Changes attributes for a ListBrowser node.  Since the ListBrowser
        class uses a private node structure, this is the only way to change
        node attributes.

        You may NOT change node attributes when the node is in a list
        attached to a ListBrowser gadget.  You must first detach the list
        with LISTBROWSER_Labels, ~0 before you can change attributes, and
        then re-attach the list.

    TAGS
        LBNA_Selected (BOOL)

        If this node is currently selected or not in a multi-select
        list browser.  This field is not meaningful in a single-
        select list browser.

        LBNA_Flags (ULONG)

        Flags for this node.  See ListBrowser.h for available flags.

        LBNA_Generation (WORD)

        Sets which "generation" this node belongs to, if the ListBrowser
        is to be in hierarchical mode.  If you were to draw the nodes out
        in a sort of family tree, the generation would refer to the level
        in the tree.

        Generations start at 1.  A generation 1 node's children will be
        generation 2, you cannot skip generations.  Nodes need not have
        children and generations can go as deep as you like, limited by
        the available stack of input.device.

        LBNA_UserData (APTR)

        Abritrary user data for this node.

        LBNA_Column (WORD)

        A column (from 0 to number_of_columns-1) that the column
        attribute tags below (LBNA_Text, LBNA_Integer, LBNA_FGPen,
        LBNA_BGPen, LBNA_Image, LBNA_SelImage, LBNA_Justification)
        affect.  You typically specify the column to work on, and
        then the column attributes for that column, then the next
        column followed by its attributes, etc.

        LBNCA_Text (STRPTR)

        [Text](autodocs-3.5/graphics-library-text-2.md) that is to appear in the corresponding column for
        this node.  Only one of LBNA_Text, LBNA_Integer and
        LBNCA_Image may be non-NULL, specifying the type of contents
        for this column.  Each column of a node need not have the
        same type of contents.  Similarly, the same column in
        different nodes also need not have the same type of contents.

        LBNCA_CopyText (BOOL)

        Specifies that you want the LBNCA_Text copied to an internal
        buffer by ListBrowser.

        LBNCA_Editable (BOOL)

        Specifies that this item can be edited.  If the user clicks
        twice on this entry, the text will become a string gadget
        where the user can edit the contents.  This will only work
        if the contents are text (given with LBNCA_Text) AND if
        LBNCA_CopyText was used.  You MUST also specify LBNCA_MaxChars
        to specify how long the edited text can be.

        LBNCA_MaxChars(WORD)

        Maximum number of characters an editable text entry can be.

        LBNCA_Integer (LONG *)

        A pointer to an integer to display in this column, or NULL.

        LBNCA_FGPen, LBNA_BGPen (WORD)

        The pens to be used for rendering the text or integer in
        this column.  Requires that the LBFLG_CUSTOMPENS flag be
        specified, otherwise the default system pens will be used.

        LBNCA_Image, LBNA_SelImage (struct [Image](autodocs-3.5/include-intuition-intuition-h.md) *)

        Specifies that the column should contain an image.  The
        selected image is optional, if not provided, LBNA_Image will
        be rendered in the IDS_SELECTED state when then node is
        selected.

        LBNCA_Justification (WORD)

        Specifies a justification for the column, either LCJ_LEFT,
        LCJ_CENTRE or LCJ_RIGHT.

        LBNA_CheckBox (BOOL) (V41)

        Means that this node will be a checkbox node, that can be toggled
        on or off.

        Defaults to FALSE.

        LBNA_Checked (BOOL) (V41)

        Indicates whether a checkbox node is in the checked or unchecked
        state.

        Defaults to FALSE.

        LBNCA_EditTags (struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *) (V41)

        Tags that you want to be passed to the string gadget used when
        editing gadget text.  Though you could theoretically pass any
        tags to the gadget, you should generally not pass tags that
        affect the position of the gadget.

        Defaults to NULL.

        LBNCA_RenderHook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) (V41)

        A custom render hook for this node column.  You hook will
        receive a pointer to struct [Node](autodocs-3.5/include-exec-nodes-h.md) of the node in question as its
        object, and the following structure in the message pointer:

          struct [LBDrawMsg](autodocs-3.5/include-gadgets-listbrowser-h.md)
          {
              ULONG lbdm_MethodID;            /* LV_DRAW */
              struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *lbdm_RastPort; /* Where to render to */
              struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) *lbdm_DrawInfo; /* Useful to have around */
              struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) lbdm_Bounds;   /* Limits of where to render */
              ULONG lbdm_State;               /* How to render */
          };

        LBDrawMsg.lbdm_State will be either LBR_SELECTED or LBR_NORMAL.  The
        hook should return LBCB_OK if rendering was successful, or
        LBCB_UNKNOWN if lbdm_Method doesn't equal LV_DRAW.  No rendering
        should be performed in this case.

        Note that this is HIGHLY compatible with a GadTools listhook.

        Defaults to NULL.

        LBNCA_HookHeight (WORD) (V41)

        The height of this column, when using LBNCA_RenderHook.

        LBNA_MemPool (APTR) (V42)

        Specifies a custom memory pool to allocate listbrowser nodes from.

        Defaults to NULL (internal pool).

        LBNCA_WordWrap (BOOL) (V42)

        Specifies this column's text can be word wrapped. Useful in
        weighted column displays or fixed pixels columns. Primarily
        this feature exists at the request of IRC client authors.

        Initial implementation in V42.630 is slow. Improvement to be made.

        Defaults to FALSE.

    INPUTS
        node - [Node](autodocs-3.5/include-exec-nodes-h.md) whose attributes you are changing.
        taglist - [Tag](autodocs-3.5/include-utility-tagitem-h.md) list of attributes to change.

    SEE ALSO
        [GetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-getlistbrowsernodeattrsa.md)
```
