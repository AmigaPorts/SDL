/* Source: ADCD 2.1
 * Section: include-libraries-locale-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-libraries-locale-h.md
 */

    STRPTR  loc_LocaleName;	      /* locale's name		     */
    STRPTR  loc_LanguageName;	      /* language of this locale     */
    STRPTR  loc_PrefLanguages[10];    /* preferred languages	     */
    ULONG   loc_Flags;		      /* always 0 for now	     */

    ULONG   loc_CodeSet;	      /* always 0 for now	     */
    ULONG   loc_CountryCode;	      /* user's country code	     */
    ULONG   loc_TelephoneCode;	      /* country's telephone code    */
    LONG    loc_GMTOffset;	      /* minutes from GMT	     */
    UBYTE   loc_MeasuringSystem;      /* what measuring system?      */
    UBYTE   loc_CalendarType;	      /* what calendar type?	     */
    UBYTE   loc_Reserved0[2];

    STRPTR  loc_DateTimeFormat;       /* regular date & time format  */
    STRPTR  loc_DateFormat;	      /* date format by itself	     */
    STRPTR  loc_TimeFormat;	      /* time format by itself	     */

    STRPTR  loc_ShortDateTimeFormat;  /* short date & time format    */
    STRPTR  loc_ShortDateFormat;      /* short date format by itself */
    STRPTR  loc_ShortTimeFormat;      /* short time format by itself */

    /* for numeric values */
    STRPTR  loc_DecimalPoint;	      /* character before the decimals */
    STRPTR  loc_GroupSeparator;       /* separates groups of digits    */
    STRPTR  loc_FracGroupSeparator;   /* separates groups of digits    */
    UBYTE  *loc_Grouping;	      /* size of each group	       */
    UBYTE  *loc_FracGrouping;	      /* size of each group	       */

    /* for monetary values */
    STRPTR  loc_MonDecimalPoint;
    STRPTR  loc_MonGroupSeparator;
    STRPTR  loc_MonFracGroupSeparator;
    UBYTE  *loc_MonGrouping;
    UBYTE  *loc_MonFracGrouping;
    UBYTE   loc_MonFracDigits;	      /* digits after the decimal point   */
    UBYTE   loc_MonIntFracDigits;     /* for international representation */
    UBYTE   loc_Reserved1[2];

    /* for currency symbols */
    STRPTR  loc_MonCS;		      /* currency symbol	      */
    STRPTR  loc_MonSmallCS;	      /* symbol for small amounts     */
    STRPTR  loc_MonIntCS;	      /* internationl (ISO 4217) code */

    /* for positive monetary values */
    STRPTR  loc_MonPositiveSign;      /* indicate positive money value	 */
    UBYTE   loc_MonPositiveSpaceSep;  /* determine if separated by space */
    UBYTE   loc_MonPositiveSignPos;   /* position of positive sign	 */
    UBYTE   loc_MonPositiveCSPos;     /* position of currency symbol	 */
    UBYTE   loc_Reserved2;

    /* for negative monetary values */
    STRPTR  loc_MonNegativeSign;      /* indicate negative money value	 */
    UBYTE   loc_MonNegativeSpaceSep;  /* determine if separated by space */
    UBYTE   loc_MonNegativeSignPos;   /* position of negative sign	 */
    UBYTE   loc_MonNegativeCSPos;     /* position of currency symbol	 */
    UBYTE   loc_Reserved3;
