#ifndef HELLOLEAP_H
#define HELLOLEAP_H
#include "Leap.h"

using namespace Leap;

class KimsListener : public Listener {
    public:
        virtual void onConnect(const Controller&);
        virtual void onFrame(const Controller&);
};

#endif
