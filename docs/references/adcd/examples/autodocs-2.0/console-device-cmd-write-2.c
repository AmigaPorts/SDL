/* Source: ADCD 2.1
 * Section: console-device-cmd-write
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/console-device-cmd-write.md
 */

    The console.device recognizes these SGR sequences.
    Note that some of these are new to V36.

    SGR (SELECT GRAPHICS RENDITION)
            Selects colors, and other display characteristics
            for text.

    Syntax:
            <ESC>[graphic-rendition...m

    Example:
            <ESC>[1;7m   (sets bold, and reversed text)

    Parameters:

            0       - Normal colors, and attributes
            1       - Set bold
            2       - Set faint (secondary color)
            3       - Set italic
            4       - Set underscore
            7       - Set reversed character/cell colors
            8       - Set concealed mode.
            22      - Set normal color, not bold    (V36)
            23      - Italic off                    (V36)
            24      - Underscore off                (V36)
            27      - Reversed off                  (V36)
            28      - Concealed off                 (V36)

            30-37   - Set character color
            39      - Reset to default character color

            40-47   - Set character cell color
            49      - Reset to default character cell color

            >0-7    - Set background color          (V36)
                      Used to set the background color before
                      any text is written.  The numeric parameter
                      is prefixed by ">".  This also means that if
                      you issue an SGR command with more than one
                      parameter, you must issue the digit only
                      parameters first, followed by any prefixed
                      parameters.
