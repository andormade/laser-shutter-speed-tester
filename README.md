# laser-shutter-speed-tester

Laser shutter speed tester

To compile the project, you can use the `arduino-cli ` command. (Replace the --fqbn argument with the FBQN of your own board.)

    arduino-cli compile --fqbn arduino:megaavr:nona4809

To upload it to your Arduino board: (You're going to have to provide your own port address for this command as well, `/dev/cu.usbmodem1101` is just an example.)

    arduino-cli upload -p /dev/cu.usbmodem1101 --fqbn arduino:megaavr:nona4809

On linux or macOs systems you can use the screen command to read the shutter speed readings on the serial port:

    screen /dev/cu.usbmodem1101 9600

Or you can build your own web-based UI to display the readings, thanks to the [Web Serial API](Web Serial API).
