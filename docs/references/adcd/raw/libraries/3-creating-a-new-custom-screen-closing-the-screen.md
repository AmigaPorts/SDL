# 3 / / Creating A New Custom Screen / Closing the Screen


When an application has finished using a screen, the memory that the
screen occupied should be returned to the system by calling [CloseScreen()](../Includes_and_Autodocs_2._guide/node0207.html).
Normally, an application should close only those screens that it created.
Under V34 and earlier versions of the OS, CloseScreen() returns no values.
Under Release 2, CloseScreen() returns a boolean value, TRUE for success
and FALSE for failure.  CloseScreen() can fail if the screen is [public](../Libraries_Manual_guide/node00E6.html) and
another task is still using the screen.

