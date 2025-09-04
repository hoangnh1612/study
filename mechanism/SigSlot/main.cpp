#include "HandleMainLoop.h"
#include "Slot.h"
#include "Signal.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "DefinedMacro.h"

struct CustomData
{
    int id;
    std::string name;
};

void signal(Signal<CustomData> &s)
{
    std::cout << "Start function" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Signal 1 emitted" << std::endl;
    CustomData data1{1, "Data1"};
    s.emit(data1);
    std::this_thread::sleep_for(std::chrono::seconds(5));

}

void slotFunction(CustomData value) {
    std::cout << "Slot triggered with value: " << value.id<<" " <<value.name<< std::endl;
}

void anotherSlotFunction(CustomData value) {
    std::cout << "Another slot triggered with value: " << value.id << std::endl;
}



int main() {
    HandleMainLoop mainLoop;
    Signal<CustomData> signal1;

    std::vector<Slot<CustomData>> slotPool;
    Slot<CustomData> mySlot(slotFunction, &mainLoop, Auto);
    Slot<CustomData> anotherSlot(anotherSlotFunction, &mainLoop, Auto);
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