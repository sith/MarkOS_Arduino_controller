//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_ARDUINO_CONTROLLER_TRANSCEIVER430_H
#define MARKOS_ARDUINO_CONTROLLER_TRANSCEIVER430_H


#include <Transceiver.h>
#include <ControllerState.h>

class Transceiver430 : public mark_os::communication::Transceiver<mark_os::controller::ControllerState> {

    mark_os::controller::ControllerState previousControllerState;

public:
    void send(uint8 channelId, mark_os::controller::ControllerState &message) override;
};


#endif //MARKOS_ARDUINO_CONTROLLER_TRANSCEIVER430_H
