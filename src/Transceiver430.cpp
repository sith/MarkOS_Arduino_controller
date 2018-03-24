//
// Created by Oleksandra Baukh on 3/21/18.
//

#include <HardwareSerial.h>
#include <RH_ASK.h>
#include <SPI.h>
#include "Transceiver430.h"

#include <Arduino.h>

void Transceiver430::send(Message<mark_os::controller::ControllerState> &message) {
    driver.send((uint8_t *) &message, sizeof(message));
    driver.waitPacketSent();
}

Transceiver430::Transceiver430() {
    if (!driver.init()) {
        Serial.println("init failed");
    }
}
