//
// Created by Oleksandra Baukh on 3/21/18.
//
#include <Arduino.h>
#include <ControllerStateTransceiver.h>
#include "ArduinoController.h"
#include "ControllerEnvironment.h"
ControllerEnvironment *controllerEnvironment;

void setup() {
    Serial.begin(9600);

    controllerEnvironment = new ControllerEnvironment;
    controllerEnvironment->init();
    Serial.println("Ready");
}

void loop() {
    controllerEnvironment->getCycle().next();
}
