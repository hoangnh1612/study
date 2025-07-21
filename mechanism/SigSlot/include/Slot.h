#ifndef Slot_H
#define Slot_H

#include "HandleMainLoop.h"
#include <functional>
#include <type_traits>
#include <iostream>
#include <functional>
#include <stdexcept>



enum ConnectionType {
    Direct,
    Queued,
    Auto
};

using SlotID = uint64_t;
static SlotID generateSlotID()
{
    static std::atomic<SlotID> slotID(0);
    return ++slotID;
};
template <typename... Args>
class Slot {
public:

    Slot() = default;

    template <typename Func>
    Slot(Func&& func, HandleMainLoop* loop, ConnectionType type = Auto)
        : callback_(std::forward<Func>(func)), loop_(loop), type_(type), slotID_(generateSlotID()) {}

    void setConnectionType(ConnectionType type) {
        type_ = type;
    }

    void operator()(Args... args) const {
        if (type_ == Direct || (type_ == Auto && std::this_thread::get_id() == loop_->getThreadId())) {
            if (callback_) {
                callback_(std::forward<Args>(args)...);
            } else {
                // Handle the absence of task
                std::cerr << "Task is not set" << std::endl;
            }
        } else if (type_ == Queued || (type_ == Auto && std::this_thread::get_id() != loop_->getThreadId())) {
            auto bound_args = std::make_tuple(std::forward<Args>(args)...);
            loop_->postSlot([callback = callback_, bound_args = std::move(bound_args)]() mutable {
                std::apply(callback, std::move(bound_args));
            });
        }
    }

    SlotID getID()
    {
        return slotID_;
    }
    bool operator==(const Slot& other) const
    {
        return slotID_ == other.slotID_;
    }
    // void setSlotFunction(std::function<void(Args...)> callback)
    // {
    //     callback_ = callback;
    // }

    // void setSlotFunction(void (*callback)(Args...))
    // {
    //     callback_ = callback;
    // }
private:
    std::function<void(Args...)> callback_;
    HandleMainLoop* loop_;
    ConnectionType type_;
    SlotID slotID_{0};
};


#endif