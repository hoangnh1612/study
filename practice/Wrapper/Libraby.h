#include <functional>
#include <thread>
#include <atomic>
// ref: functional
using Callback = void (*)(void*); 
class SimpleTimer {
public:

    SimpleTimer();
    ~SimpleTimer();

    void registerCallback(Callback callback, void* user_data);
    void start();
    void stop();


private:
    void timerLoop();
    Callback m_callback;        
    void* m_user_data;     
    std::atomic<bool> m_running;
    std::thread m_thread;  
};
