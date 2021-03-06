#pragma once

#include <Arduino.h>

#include <Encoder.h>
#include <Joystick.h>

#include "settings.h"

enum class FusionNavState { INACTIVE, PANNING, ORBITING };

class FusionNavigator {
public:
  FusionNavigator(Joystick *joystick, Encoder *encoder, uint8_t shiftPin, uint8_t button1Pin);

  FusionNavState state();
  bool isZooming();

  void begin();
  void update();

private:
  int _updateEncoder();
  void _updateButtons();

  void _releaseAll();

  uint8_t _shiftButtonPin = 0;
  uint8_t _button1Pin = 0;

  FusionNavState _state = FusionNavState::INACTIVE;
  bool _zooming = false;
  int32_t _encoderValue = 0;
  bool _button1Pressed = false;

  Joystick *_joystick = NULL;
  Encoder *_encoder = NULL;

  unsigned long _lastUpdateTime = 0;
  uint8_t _updateInterval = UPDATE_INTERVAL;
};
