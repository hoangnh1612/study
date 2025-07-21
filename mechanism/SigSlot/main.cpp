#include "HandleMainLoop.h"
#include "Slot.h"
#include "Signal.h"
#include "SignalSlotBase.h" 
#include <iostream>
#include <thread>
#include <chrono>
#include <string>


void signal(Signal<double> &s)
{
    std::cout << "Start function" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Signal 1 emitted" << std::endl;
    s.emit(3.52);
    std::this_thread::sleep_for(std::chrono::seconds(5));

}

void slotFunction(double value) {
    std::cout << "Slot triggered with value: " << value << std::endl;
}

void anotherSlotFunction(double value) {
    std::cout << "Another slot triggered with value: " << value << std::endl;
}


int main() {
    HandleMainLoop mainLoop;
    Signal<double> signal1;

    std::vector<Slot<double>> slotPool;
    Slot<double> mySlot(slotFunction, &mainLoop, Auto);
    Slot<double> anotherSlot(anotherSlotFunction, &mainLoop, Auto);
    slotPool.push_back(mySlot);
    slotPool.push_back(anotherSlot);

    for (auto& slot : slotPool) {
        signal1.connect(slot);
    }

    std::cout << "Calling sig1 from main thread: " << std::this_thread::get_id() << std::endl;
    std::thread signalThread(signal, std::ref(signal1));
    signalThread.join();


    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    mainLoop.stop();

    return 0;

}