/* Source: ADCD 2.1
 * Section: 3-bitplanes-and-color-selecting-the-number-of-bitplanes
 * Library: hardware
 * ADCD reference: hardware/3-bitplanes-and-color-selecting-the-number-of-bitplanes.md
 */

          Table 3-5: Setting the Number of Bitplanes


                    Number of     Name(s) of
          Value     Bitplanes     Bitplanes
          -----     ---------     ----------
           000       None *
           001         1           PLANE 1
           010         2           PLANES 1 and 2
           011         3           PLANES 1 - 3
           100         4           PLANES 1 - 4
           101         5           PLANES 1 - 5
           110         6           PLANES 1 - 6 **
           111                     Value not used.


     *  Shows only a background color; no playfield is visible.

     ** Sixth bitplane is used only in  [dual-playfield mode](../Hardware_Manual_guide/node0079.html)  and in
         [hold-and-modify mode](../Hardware_Manual_guide/node008F.html)  (described in the section called
        Advanced Topics.
