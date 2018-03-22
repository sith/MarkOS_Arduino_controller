//
// Created by Oleksandra Baukh on 3/21/18.
//
#include <Arduino.h>
#include "ArduinoController.h"

ArduinoController *arduinoController;

mark_os::controller::ControllerState previousControllerState{};

void setup() {
    Serial.begin(9600);

    arduinoController = new ArduinoController();
    Serial.println("Ready");
}

void loop() {
    auto controllerState = arduinoController->readControllerState();

    if (controllerState != previousControllerState) {
        Serial.print("Left X: ");
        Serial.println(controllerState.leftX);
        Serial.print("Left Y: ");
        Serial.println(controllerState.leftY);
        Serial.println(controllerState.a);
        Serial.println(controllerState.b);
        Serial.println(controllerState.x);
        Serial.println(controllerState.y);
        Serial.println();
        previousControllerState = controllerState;
    }

    delay(1000);
}



