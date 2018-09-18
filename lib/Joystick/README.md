# Joystick

A joystick library for HW-504.

![](data:image/jpeg;base64,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)

## Documents

Please refer to [Joystick.h](src/Joystick.h).

## Author

[Henry Li](https://github.com/MagicCube)