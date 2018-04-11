//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_ARDUINO_CONTROLLER_ARDUINOCONTROLLER_H
#define MARKOS_ARDUINO_CONTROLLER_ARDUINOCONTROLLER_H

#include <Arduino.h>
#include <Controller.h>
#include <TR433.h>
#include <TR433.cpp>

class ArduinoController : public mark_os::controller::Controller {

    const uint8 SW_pin = 2;
    const uint8 left_X_pin = 0;
    const uint8 left_Y_pin = 1;

    const uint8 buttonApin = 3;
    const uint8 buttonBpin = 4;
    const uint8 buttonXpin = 5;
    const uint8 buttonYpin = 6;

    int16 leftXZero = 0;
    int16 leftYZero = 0;

    int16 calibrateJoystick(uint8 pin);

public:

    ArduinoController();

    mark_os::commons::Optional<mark_os::controller::ControllerState> readControllerState() override;
};


#endif //MARKOS_ARDUINO_CONTROLLER_ARDUINOCONTROLLER_H
