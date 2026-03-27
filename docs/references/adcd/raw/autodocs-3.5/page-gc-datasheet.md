# page_gc/--datasheet--



  NAME

      page.gadget -- a gadget for easy creation of GUI pages.
  SUPERCLASS

      gadgetclass
  DESCRIPTION

```c
      Page gadget takes a list of BOOPSI objects and treats each as a
      single page of a multi-page GUI group. Used together with
      tabs.gadget and layout.gadget, it allows complex GUI layouts with
      hidden objects with virtually no work for the developer.

      This gadget class is contained within the layout.gadget binary.
      Thus, you will need to [OpenLibrary](../Includes_and_Autodocs_3._guide/node0222.html) layout.gadget, but not
      page.gadget.
```
  METHODS

      GM_DOMAIN
      GM_RENDER
      GM_LAYOUT
      DTM_PROCLAYOUT
      OM_SET
      OM_UPDATE
      OM_NEW
      OM_DISPOSE

      All other methods are passed to the currently visible object.
  ATTRIBUTES

```c
      PAGE_Add (Object *)
          A BOOPSI gadget (probably a layout.gadget) to add to the end of
          the page list.

          Applicability is (OM_NET, OM_SET)

      PAGE_Remove (Object *)
          Pointer to a gadget to remove from the page list. page.gadget
          will automatically dispose all attached objects when disposed of.

          Applicability is (OM_SET)

      PAGE_Current (ULONG)
          Sets/gets the currently visible page. Note that OM_SET will NOT
          trigger a rerender, call [RethinkLayout()](../Includes_and_Autodocs_3._guide/node043D.html) afterwards. OM_UPDATE
          will rerender automatically.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)

      PAGE_FixedVert, PAGE_FixedHoriz (BOOL)
          Like the respective tags of layout.gadget, these will, if set
          to FALSE, force the group's dimensions to the smallest possible
          in the respective direction.

          Applicability is (OM_NEW, OM_SET, OM_UPDATE)
```
  SEE ALSO

            layout.gadget/--datasheet--
      ReAction example source for usage.
