---
title: locale.library/--structures--
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-structures
functions: [FormatDate]
libraries: [locale.library]
---

# locale.library/--structures--

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

	The [Locale](autodocs-3.5/include-libraries-locale-h.md) structure is the main public structure provided by
	locale.library. The structure is defined in [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md)
	and consists of the following fields:

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_LocaleName
	    Locale's name.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_LanguageName
	    The language of the driver bound to this locale.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_PrefLanguages[10]
	    The ordered list of preferred languages for this locale.

	ULONG loc_Flags
	    [Locale](autodocs-3.5/include-libraries-locale-h.md) flags. Currently always 0.

	ULONG loc_CodeSet
	    Specifies the code set required by this locale. Currently, this
	    value is always 0.

	ULONG loc_CountryCode
	    The international country code.

	ULONG loc_TelephoneCode
	    The international telephone code for the country.

	[LONG](autodocs-3.5/include-exec-types-h.md) loc_GMTOffset
	    The offset in minutes of the current location from GMT.
	    Positive indicates a Westerly direction from GMT,
	    negative Easterly.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MeasuringSystem
	    The measuring system being used.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_DateTimeFormat
	    The date and time format string, ready to pass to [FormatDate()](autodocs-3.5/locale-library-formatdate.md)

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_DateFormat
	    The date format string.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_TimeFormat
	    The time format string.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_ShortDateTimeFormat
	    The short date and time format string, ready to pass to
	    [FormatDate()](autodocs-3.5/locale-library-formatdate.md)

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_ShortDateFormat
	    The short date format string.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_ShortTimeFormat
	    The short time format string.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_DecimalPoint
	    The decimal point character used to format non-monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_GroupSeparator
	    The characters used to separate groups of digits before the
	    decimal-point character in formatted non-monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_FracGroupSeparator
	    The characters used to separate groups of digits after the
	    decimal-point character in formatted non-monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_Grouping
	    A string whose elements indicate the size of each group of digits
	    before the decimal-point character in formatted non-monetary
	    quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_FracGrouping
	    A string whose elements indicate the size of each group of digits
	    after the decimal-point character in formatted non-monetary
	    quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonDecimalPoint
	    The decimal-point used to format monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonGroupSeparator
	    The separator for groups of digits before the decimal-point in
	    monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonFracGroupSeparator
	    The separator for groups of digits after the decimal-point in
	    monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonGrouping
	    A string whose elements indicate the size of each group of digits
	    before the decimal-point character in monetary quantities.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonFracGrouping
	    A string whose elements indicate the size of each group of digits
	    after the decimal-point character in monetary quantities.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonFracDigits
	    The number of fractional digits (those after the decimal-point)
	    to be displayed in a formatted monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonIntFracDigits
	    The number of fractional digits (those after the decimal-point)
	    to be displayed in an internationally formatted monetary quantity.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonCS
	    The local currency symbol applicable to the current locale.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonSmallCS
	    The currency symbol for small amounts.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonIntCS
	    The international currency symbol applicable to the current
	    locale. The first three characters contain the alphabetic
	    international currency symbol in accordance with those specified
	    in ISO 4217 Codes for the Representation of Currency and Funds.
	    The fourth character (immediately preceding the NULL) is the
	    character used to separate the international currency symbol from
	    the monetary quantity.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonPositiveSign
	    The string used to indicate a non-negative monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonPositiveSpaceSep
	    Specifies the number of spaces separating the currency symbol from
	    the non-negative monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonPositiveSignPos
	    Set to a value indicating the positioning of loc_MonPositiveSign
	    for a non-negative monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonPositiveCSPos
	    Set to 1 or 0 if loc_MonCS respectively precedes or succeeds
	    the value for a non-negative monetary quantity.

	[STRPTR](autodocs-3.5/include-exec-types-h.md) loc_MonNegativeSign
	    The string used to indicate a negative monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonNegativeSpaceSep
	    Specifies the number of spaces separating the currency symbol from
	    the negative monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonNegativeSignPos
	    Set to a value indicating the positioning of loc_MonNegativeSign
	    for a negative monetary quantity.

	[UBYTE](autodocs-3.5/include-exec-types-h.md) loc_MonNegativeCSPos
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

---

## See Also

- [FormatDate — locale.library](../autodocs/locale.library.md#formatdate)
