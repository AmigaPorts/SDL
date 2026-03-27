/* Source: ADCD 2.1
 * Section: reaction-lib-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/reaction-lib-datasheet.md
 */

       The following program will print out the class base of
       layout.gadget and the base address of [gradientslider.gadget](../Includes_and_Autodocs_3._guide/node029A.html) (which
       doesn't have functions or a proto header) when compiled and linked
       with reaction.lib:

       #include <proto/layout.h>
       #include <proto/dos.h>

       extern void *GradientSliderBase;
       long __reactionversion = 37;

       main()
       {
           Printf( "layout.gadget minimum version %ld class base is %lxn",
                   __layoutversion, [LAYOUT_GetClass()](../Includes_and_Autodocs_3._guide/node043B.html) );
           Printf( "explicit reference to GradientSliderBase will force "
                   "initialization:n base address is %lxn",
                   GradientSliderBase );
       }
