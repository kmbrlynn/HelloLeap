#include "Leap.h"
#include "helloleap.hpp"
#include <string>

const std::string fingerNames[] = {"thumb", "pointer", "middle", "ring", "pinky"};

// A callback function, invoked when: 
// - Controller object is connected to Leap Motion software
//   and Leap device is plugged in, or 
// - its Listener object is added to a Controller 
//   that is already connected
void KimsListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
    controller.enableGesture(Gesture::TYPE_SWIPE);
}

void KimsListener::onFrame(const Controller& controller) {
    // std::cout << "Frame available" << std::endl;
    const Frame frame = controller.frame();
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Frame id: " << frame.id() << std::endl;
    std::cout << "Time: " << frame.timestamp() << std::endl;
 
    // list the hand
    HandList hands = frame.hands();
    HandList::const_iterator hlist;
    for (hlist = hands.begin(); hlist != hands.end(); ++hlist) {
        const Hand hand = *hlist;
        std::string handType = hand.isLeft() ? "Left hand: " : "Right hand: ";
        std::cout << std::endl << handType << hand.fingers().extended().count();
        std::cout << " fingers" << std::endl;

        // list all of its extended fingers
        FingerList fingers = hand.fingers();
        FingerList::const_iterator flist;
        for (flist = fingers.begin(); flist != fingers.end(); ++flist) {
            const Finger finger = *flist;
            if (finger.isExtended()){
                std::string fingerType = fingerNames[finger.type()];
                std::cout << "\t" << fingerType;
            }

            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}
