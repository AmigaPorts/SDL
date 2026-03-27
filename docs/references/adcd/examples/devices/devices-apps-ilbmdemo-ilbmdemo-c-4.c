/* Source: ADCD 2.1
 * Section: devices-apps-ilbmdemo-ilbmdemo-c
 * Library: devices
 * ADCD reference: devices/devices-apps-ilbmdemo-ilbmdemo-c.md
 */

      	code  = msg->Code;
      	mousex = msg->MouseX;
      	mousey = msg->MouseY;

      	ReplyMsg(msg);
      	switch(class)
