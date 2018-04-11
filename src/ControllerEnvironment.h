//
// Created by Oleksandra Baukh on 3/21/18.
//

#ifndef MARKOS_ARDUINO_CONTROLLER_CONTROLLERENVIRONMENT_H
#define MARKOS_ARDUINO_CONTROLLER_CONTROLLERENVIRONMENT_H


#include <Environment.h>
#include <TransceiverWithRetries.h>
#include <TransceiverWithRetries.cpp>
#include <JoystickToleranceAwareController.h>
#include "ArduinoController.h"
#include "TR433.h"

class ControllerEnvironment : public mark_os::controller::Environment {
    mark_os::cycle::Cycle cycle;
    ArduinoController arduinoController;
    mark_os::controller::JoystickToleranceAwareController controller{arduinoController};
    TR433<mark_os::controller::ControllerState> tr433;
    mark_os::communication::TransceiverWithRetries<mark_os::controller::ControllerState> transceiverWithRetries{tr433,
                                                                                                                2};
    mark_os::controller::ControllerStateTransceiver controllerStateTransceiver{controller, transceiverWithRetries};
public:

    mark_os::controller::Controller &getController()

    override;

    mark_os::cycle::Cycle &getCycle()

    override;

    mark_os::controller::ControllerStateTransceiver &getControllerStateTransceiver()

    override;
};


#endif //MARKOS_ARDUINO_CONTROLLER_CONTROLLERENVIRONMENT_H
