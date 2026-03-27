# 3 / Monitoring Clipboard Changes / Caveats For CBD_CHANGEHOOK


   *  [CBD_CHANGEHOOK](../Includes_and_Autodocs_2._guide/node04D9.html) should only be used by a special application, such as

      a clipboard viewing program.  Most applications can check the
      contents of the clipboard when, and if, the user requests a paste.
   *  Do not add system overhead by blindly reading and parsing the

      clipboard everytime a user copies data to it.  If all applications
      did this, the system could become intolerably slow whenever an
      application wrote to the clipboard.  Only read and parse when it is
      necessary.
