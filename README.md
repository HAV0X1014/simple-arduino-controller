# simple-arduino-controller
Simple program to send defined keyboard keys when an input is received. Supports rebinding controls, and is user friendly.

I created this for use on an Arduino Micro. It should also work with other Arduino types with Keyboard support. (Tested to be working with Arduino Leonardo.)
## Usage
In the Arduino IDE, install the Keyboard library. As of Arduino IDE 2.3.4, click "Tools", "Manage Libraries...", "Filter your search...", and search for "Keyboard", and install it. I used version 1.0.6 of the Keyboard library for this project.

Under the line `struct pinMap pm[] = {`, add/edit/remove the pin bindings you want to send. For example, to make a button wired to pin 5 send the 'p' key, add `{5, 'p'},` to the pinMap struct. 

Note that the last entry in the struct cannot have a comma following the `}` but all other entries should be followed with a comma.

## Project tips!
If you are creating an arcade game input method, you can "daisy chain" the ground wires across multiple buttons to save on ground pin usage. The Arduino will still register all inputs, including simultaneous inputs!

To send "special" key inputs like arrow keys or backspace, use [this documentation created by Arduino](https://reference.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/).
