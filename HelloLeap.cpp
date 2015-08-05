#include <iostream>
#include <string>
#include "helloleap.hpp"
#include "Leap.h"

using namespace Leap;

int main(int argc, char* argv[]) {

    // Connects, asynchronously, to the Leap Motion service.
    // If there is a successful connection && Leap is plugged in, 
    // then controller.isConnected() = true;
    // This invokes the Listener.onConnect() callback function
    Controller controller;
    
    // The asynchronous Controller can be polled for frames (or other state data), 
    // or it can use a Listener. We will use a Listener for this program
    KimsListener listener;

    controller.addListener(listener);

    // Keep this process running until user hits Enter
    std::cout << "Hit Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the listener when you're done
    controller.removeListener(listener);

    return 0;
}
