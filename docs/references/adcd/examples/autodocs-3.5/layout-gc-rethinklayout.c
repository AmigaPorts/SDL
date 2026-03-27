/* Source: ADCD 2.1
 * Section: layout-gc-rethinklayout
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/layout-gc-rethinklayout.md
 */

      Relayout and refresh the layout page. Call this function after
      a call SetGadgetAttrs() returns 1 to display the changes in the
      layout.  According to BOOPSI rules, a gadget will return a value
      of 1 from OM_SET to tell the application to refresh. This is what
      this function is for. Basically, it will call the GM_LAYOUT and
      GM_RENDER methods of the layout.
