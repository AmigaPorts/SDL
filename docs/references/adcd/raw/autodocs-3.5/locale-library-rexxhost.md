# locale.library/--rexxhost--



   HOST INTERFACE
	locale.library provides an ARexx function host interface that enables
	ARexx programs to take advantage of system localization. The
	functions provided by the interface are directly related to the
	functions described herein, with the differences mostly being
	in the way they are called.

	The function host library vector is located at offset -30 from the
	library. This is the value you provide to ARexx in the AddLib()
	function call.

   FUNCTIONS
	[CloseCatalog](../Includes_and_Autodocs_3._guide/node0452.html) (CATALOG/N/A)
	[ConvToLower](../Includes_and_Autodocs_3._guide/node0454.html) (CHARACTER/A)
	[ConvToUpper](../Includes_and_Autodocs_3._guide/node0455.html) (CHARACTER/A)
	[GetCatalogStr](../Includes_and_Autodocs_3._guide/node0458.html) (CATALOG/A,STRING/N/A,DEFAULT/A)
	IsAlNum (CHARACTER/A)
	IsAlpha (CHARACTER/A)
	IsCntrl (CHARACTER/A)
	IsDigit (CHARACTER/A)
	IsGraph (CHARACTER/A)
	IsLower (CHARACTER/A)
	IsPrint (CHARACTER/A)
	IsPunct (CHARACTER/A)
	IsSpace (CHARACTER/A)
	IsUpper (CHARACTER/A)
	IsXDigit (CHARACTER/A)
	[OpenCatalog](../Includes_and_Autodocs_3._guide/node045B.html) (NAME/A,BUILTINLANGUAGE/A,VERSION/N/A)
	Strncmp (STRING1/A,STRING2/A,TYPE/N/A)

   EXAMPLE
	/* localetest.rexx */

	/* Make sure locale is loaded as a function host */
	IF ~SHOW(L,'locale.library') THEN DO
	  CALL ADDLIB('locale.library',0,-30)
	END;

	say ConvToLower("A");
	say ConvToUpper("b");
	say IsAlpha("1");

	catalog = OpenCatalog("sys/workbench.catalog","english",0);
	say GetCatalogStr(catalog,34,"default");
	say CloseCatalog(catalog);
	say StrnCmp("test","test",2);

