# 14 / / Argument Passing In Workbench / Two Arguments


All project icons (data files) have a default tool field associated with
them that tells Workbench which application tool to run in order to
operate on the data that the icon represents.  When the user activates a
project icon, Workbench runs the application specified in the default tool
field passing it two arguments in the [WBStartup](../Libraries_Manual_guide/node023E.html) message: the name of the
tool and the project icon that the user activated.

