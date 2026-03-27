# 4 Intuition Windows / Communicating with Intuition


Intuition can notify an application when the user moves the mouse, makes a
menu choice, selects an application gadget or changes the window's size.
To find out about user activity from Intuition, there are two methods:

  * Use the Intuition Direct Communications Message Port (IDCMP) system.

    Input events are received as standard Exec messages at a port
    Intuition creates for your window.
  * Use the console.device to receive all input events as character

    sequences.
 [The IDCMP](../Libraries_Manual_guide/node010D.html)             [The IDCMP And The Active Window](../Libraries_Manual_guide/node010F.html) 
 [The Console Device](../Libraries_Manual_guide/node010E.html)    [The IDCMP And Gadgets](../Libraries_Manual_guide/node0110.html) 

