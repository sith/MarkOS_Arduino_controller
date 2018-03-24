//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_ARDUINO_CONTROLLER_TRANSCEIVER430_H
#define MARKOS_ARDUINO_CONTROLLER_TRANSCEIVER430_H


#include <Transceiver.h>
#include <ControllerState.h>

#include <RH_ASK.h>


struct Test{
    int a = 10;
};

class Transceiver430 : public mark_os::communication::Transceiver<mark_os::controller::ControllerState> {
    RH_ASK driver;
public:

    Transceiver430();

    void send(Message<mark_os::controller::ControllerState> &message) override;
};


#endif //MARKOS_ARDUINO_CONTROLLER_TRANSCEIVER430_H
