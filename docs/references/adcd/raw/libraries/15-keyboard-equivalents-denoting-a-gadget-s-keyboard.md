# 15 / / Keyboard Equivalents / Denoting a Gadget's Keyboard Equivalent


In order to denote the key equivalent, the application may add a
marker-symbol to the gadget label.  This is done by placing the
marker-symbol immediately before the character to be underscored.  This
symbol can be any character that is not used in the label.  The underscore
character, `_' is the recommended marker-symbol.  So, for example, to mark
the letter "F" as the keyboard equivalent for a button labelled "Select
Font...", create the gadget text:


```c
    ng.ng_GadgetText = "Select _Font...";
```
To inform GadTools of the underscore in the label, pass the GA_Underscore
tag to [CreateGadget()](../Libraries_Manual_guide/node025A.html) or [CreateGadgetA()](../Libraries_Manual_guide/node025A.html).  The data-value associated with
this tag is a character, not a string, which is the marker-symbol used in
the gadget label:


    GA_Underscore, '_',/* Note '_', not "_" !!! */
GadTools will create a gadget label which consists of the text supplied
with the marker-symbol removed and the character following the
marker-symbol underscored.

The gadget's label would look something like:


    Select Font...
           -
