#ifndef SignalSlotBase_H
#define SignalSlotBase_H


#include "HandleMainLoop.h"

class SignalSlotBase
{
public:
    SignalSlotBase(HandleMainLoop* handleMainLoop) : handleMainLoop_(handleMainLoop) {}
protected:
    HandleMainLoop* handleMainLoop_ = nullptr;
};


#endif