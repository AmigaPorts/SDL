/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-dospecial-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-dospecial-c.md
 */

        if (Param > 199) {
                outputBuffer[x++] = '2';
                Param -= 200;
        }
        else if (Param > 99) {
                outputBuffer[x++] = '1';
                Param -= 100;
        }
        else {
                outputBuffer[x++] = '0'; /* always return 3 digits */
        }

        if (Param > 9) {
                outputBuffer[x++] = Param / 10 + '0';
        }
        else {
                outputBuffer[x++] = '0';
        }

        outputBuffer[x++] = Param % 10 + '0';
