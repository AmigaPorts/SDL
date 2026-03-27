# locale.library/--structures--



	The [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) structure is the main public structure provided by
	locale.library. The structure is defined in [<libraries/locale.h>](../Includes_and_Autodocs_3._guide/node05E3.html)
	and consists of the following fields:

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_LocaleName
	    Locale's name.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_LanguageName
	    The language of the driver bound to this locale.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_PrefLanguages[10]
	    The ordered list of preferred languages for this locale.

	ULONG loc_Flags
	    [Locale](../Includes_and_Autodocs_3._guide/node05E3.html#line117) flags. Currently always 0.

	ULONG loc_CodeSet
	    Specifies the code set required by this locale. Currently, this
	    value is always 0.

	ULONG loc_CountryCode
	    The international country code.

	ULONG loc_TelephoneCode
	    The international telephone code for the country.

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) loc_GMTOffset
	    The offset in minutes of the current location from GMT.
	    Positive indicates a Westerly direction from GMT,
	    negative Easterly.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MeasuringSystem
	    The measuring system being used.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_DateTimeFormat
	    The date and time format string, ready to pass to [FormatDate()](../Includes_and_Autodocs_3._guide/node0456.html)

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_DateFormat
	    The date format string.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_TimeFormat
	    The time format string.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_ShortDateTimeFormat
	    The short date and time format string, ready to pass to
	    [FormatDate()](../Includes_and_Autodocs_3._guide/node0456.html)

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_ShortDateFormat
	    The short date format string.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_ShortTimeFormat
	    The short time format string.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_DecimalPoint
	    The decimal point character used to format non-monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_GroupSeparator
	    The characters used to separate groups of digits before the
	    decimal-point character in formatted non-monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_FracGroupSeparator
	    The characters used to separate groups of digits after the
	    decimal-point character in formatted non-monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_Grouping
	    A string whose elements indicate the size of each group of digits
	    before the decimal-point character in formatted non-monetary
	    quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_FracGrouping
	    A string whose elements indicate the size of each group of digits
	    after the decimal-point character in formatted non-monetary
	    quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonDecimalPoint
	    The decimal-point used to format monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonGroupSeparator
	    The separator for groups of digits before the decimal-point in
	    monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonFracGroupSeparator
	    The separator for groups of digits after the decimal-point in
	    monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonGrouping
	    A string whose elements indicate the size of each group of digits
	    before the decimal-point character in monetary quantities.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonFracGrouping
	    A string whose elements indicate the size of each group of digits
	    after the decimal-point character in monetary quantities.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonFracDigits
	    The number of fractional digits (those after the decimal-point)
	    to be displayed in a formatted monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonIntFracDigits
	    The number of fractional digits (those after the decimal-point)
	    to be displayed in an internationally formatted monetary quantity.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonCS
	    The local currency symbol applicable to the current locale.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonSmallCS
	    The currency symbol for small amounts.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonIntCS
	    The international currency symbol applicable to the current
	    locale. The first three characters contain the alphabetic
	    international currency symbol in accordance with those specified
	    in ISO 4217 Codes for the Representation of Currency and Funds.
	    The fourth character (immediately preceding the NULL) is the
	    character used to separate the international currency symbol from
	    the monetary quantity.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonPositiveSign
	    The string used to indicate a non-negative monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonPositiveSpaceSep
	    Specifies the number of spaces separating the currency symbol from
	    the non-negative monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonPositiveSignPos
	    Set to a value indicating the positioning of loc_MonPositiveSign
	    for a non-negative monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonPositiveCSPos
	    Set to 1 or 0 if loc_MonCS respectively precedes or succeeds
	    the value for a non-negative monetary quantity.

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) loc_MonNegativeSign
	    The string used to indicate a negative monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonNegativeSpaceSep
	    Specifies the number of spaces separating the currency symbol from
	    the negative monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonNegativeSignPos
	    Set to a value indicating the positioning of loc_MonNegativeSign
	    for a negative monetary quantity.

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) loc_MonNegativeCSPos
	    Set to 1 or 0 if loc_MonCS respectively precedes or succeeds
	    the value for a negative monetary quantity.


	The grouping tables pointed to by loc_Grouping, loc_FracGrounping,
	loc_MonGrouping, and loc_MonFracGrouping contain a stream of bytes
	with the following values:

	    255		No further grouping is to be performed.

	    0		The previous element is to be repeatedly used for the
			remainder of the digits.

	    1..254	The integer value is the number of digits that comprise
			the current group. The next element is examined to
			determine the size of the next group of digits before
			the current group.

	The values of loc_MonPositiveSignPos and loc_MonNegativeSignPos are
	interpreted according to the following:

	    0		Parentheses surround the quantity and currency symbol

	    1		The sign string precedes the quantity and
			currency symbol

	    2		The sign string succeeds the quantity and
			currency symbol

	    3		The sign string immediately precedes the
			currency symbol

	    4		The sign string immediately succeeds the
			currency symbol.

