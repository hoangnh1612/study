#ifndef HandleMainLoop_H
#define HandleMainLoop_H


#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>


class HandleMainLoop {
public:
    HandleMainLoop() : stopFlag_(false) {
        thread_ = std::thread([this]() { this->run(); });
        threadId_ = thread_.get_id();
    }

    ~HandleMainLoop() {
        stop();
    }

    void postSlot(std::function<void()> slot) {
        {
            std::lock_guard<std::mutex> lock(queueMutex_);
            slotQueue_.push(slot);
        }
        queueCondition_.notify_one();
    }

    void stop() {
        {
            std::lock_guard<std::mutex> lock(queueMutex_);
            stopFlag_ = true;
        }
        queueCondition_.notify_one();
        if (thread_.joinable()) {
            thread_.join();
        }
    }

    std::thread::id getThreadId() const {
        return threadId_;
    }

    int currentRemainSlot()
    {
        return slotQueue_.size();
    }

private:
    void run() {
        while (true) {
            std::function<void()> slot;
            {
                std::unique_lock<std::mutex> lock(queueMutex_);
                queueCondition_.wait(lock, [this]() { return !slotQueue_.empty() || stopFlag_; });
                if (stopFlag_ && slotQueue_.empty()) {
                    break;
                }
                slot = slotQueue_.front();
                slotQueue_.pop();
            }
            slot();
        }
    }

    std::thread thread_;
    std::thread::id threadId_;
    std::queue<std::function<void()>> slotQueue_;
    std::mutex queueMutex_;
    std::condition_variable queueCondition_;
    std::atomic<bool> stopFlag_;
};



#endif