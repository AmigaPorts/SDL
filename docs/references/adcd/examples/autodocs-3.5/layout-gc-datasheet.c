/* Source: ADCD 2.1
 * Section: layout-gc-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/layout-gc-datasheet.md
 */

    METHODS
        GM_HANDLEINPUT -- Passed to the currently active child

        GM_DOMAIN -- Passed to all children

        GM_RENDER -- Passed to all children When invoked
            by input.device, the stack is first swapped to provide
            more workspace.

        GM_LAYOUT -- Passed to all children after first setting
            their size and position with SetAttrs. When invoked
            by input.device, the stack is first swapped to provide
            more workspace.

        GM_HITTEST -- Passed to the child in whose domain
            rectangle the pointer is

        GM_HELPTEST -- Passed to the child in whose domain
            rectangle the pointer is

        GM_GOACTIVE -- Passed to the currently "active" child (one
            that returned GM_HITTEST)

        GM_GOINACTIVE -- Passed to the currently active child

        OM_SET -- Passed to superclass after scanning the
            taglist for layout specific tags

        OM_UPDATE -- Passed to superclass after scanning the
            taglist for layout specific tags

        OM_GET -- Passed to superclass for non-layout tags

        OM_NEW -- Passed to superclass, then adding all the
            children on the taglist to the private list.

        OM_DISPOSE -- Passed to all children (thus disposing all
            of them), then to superclass.

        GM_CLIPRECT -- Passed to all children.

        DTM_PROCLAYOUT -- Like GM_LAYOUT, but passes DTM_PROCLAYOUT
            forward. Useful if the layout group contains only
            datatype objects.

        All other methods are passed to the superclass.
