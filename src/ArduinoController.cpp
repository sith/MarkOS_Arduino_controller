//
// Created by Oleksandra Baukh on 3/21/18.
//

#include "ArduinoController.h"
#include "Statistic.h"

ArduinoController::ArduinoController() {
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    pinMode(buttonApin, INPUT_PULLUP);
    pinMode(buttonBpin, INPUT_PULLUP);
    pinMode(buttonXpin, INPUT_PULLUP);
    pinMode(buttonYpin, INPUT_PULLUP);


    leftXZero = calibrateJoystick(left_X_pin);
    leftYZero = calibrateJoystick(left_Y_pin);
    Serial.println(leftXZero);
    Serial.println(leftYZero);
}

int16 ArduinoController::calibrateJoystick(uint8 pin) {
    Statistic statistic;
    for (int8 i = 0; i < 10; i++) {
        statistic.add(analogRead(pin));
        delay(10);
    }
    return (int16) (statistic.average());
}

mark_os::commons::Optional<mark_os::controller::ControllerState> ArduinoController::readControllerState() {
    mark_os::controller::ControllerState controllerState{};
    controllerState.left = digitalRead(SW_pin) == 0;
    controllerState.leftX = map(analogRead(left_X_pin), leftXZero - 512, leftXZero + 512, -512, 512);
    controllerState.leftY = map(analogRead(left_Y_pin), leftYZero + 512, leftYZero - 512, -512, 512);

    controllerState.a = digitalRead(buttonApin) == LOW;
    controllerState.b = digitalRead(buttonBpin) == LOW;
    controllerState.x = digitalRead(buttonXpin) == LOW;
    controllerState.y = digitalRead(buttonYpin) == LOW;

    return mark_os::commons::optional(controllerState);
}

