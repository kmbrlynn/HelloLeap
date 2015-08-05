#include "Leap.h"
#include "helloleap.hpp"

void KimsListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void KimsListener::onFrame(const Controller & controller) {
    std::cout << "Frame available" << std::endl;
}
