//
// Created by Oleksandra Baukh on 3/21/18.
//

#include "ControllerEnvironment.h"

mark_os::controller::Controller &ControllerEnvironment::getController() {
    return controller;
}

mark_os::cycle::Cycle &ControllerEnvironment::getCycle() {
    return cycle;
}

mark_os::controller::ControllerStateTransceiver &ControllerEnvironment::getControllerStateTransceiver() {
    return controllerStateTransceiver;
}
