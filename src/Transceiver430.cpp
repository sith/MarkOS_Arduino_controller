//
// Created by Oleksandra Baukh on 3/21/18.
//

#include <HardwareSerial.h>
#include "Transceiver430.h"

void Transceiver430::send(uint8 channelId, mark_os::controller::ControllerState &message) {
    if (previousControllerState != message) {
        Serial.println(message.left);
        Serial.println(message.leftX);
        Serial.println(message.leftY);
        Serial.println(message.a);
        Serial.println(message.b);
        Serial.println(message.x);
        Serial.println(message.y);
        Serial.println("________");
        Serial.println();
        previousControllerState = message;
    }
}
