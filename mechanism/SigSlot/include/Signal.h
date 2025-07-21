#ifndef Signal_H
#define Signal_H


#include <vector>
#include "Slot.h"
#include <mutex>
template <typename... Args>
class Signal {
public:
    void connect(const Slot<Args...>& slot, ConnectionType type = Auto) {
        std::unique_lock<std::mutex> lock(mutex_);
        Slot<Args...> tempSlot = slot;
        tempSlot.setConnectionType(type);
        slots_.emplace_back(tempSlot);
    }

    void emit(Args... args) {
        for (const auto& slot : slots_) {
            slot(args...);  // Pass arguments by value to each slot
        }
    }

    void disconnect()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        slots_.clear();
    }

    void disconnect(const Slot<Args...>& slot) {
        std::unique_lock<std::mutex> lock(mutex_);
        auto it = std::remove(slots_.begin(), slots_.end(), slot);
        slots_.erase(it, slots_.end());

    }
private:
    std::vector<Slot<Args...>> slots_;
    std::mutex mutex_;
};


#endif