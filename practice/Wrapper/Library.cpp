#include"Libraby.h"
#include<chrono>

SimpleTimer::SimpleTimer() : m_running(false), 
    m_callback(nullptr), m_user_data(nullptr) {}

SimpleTimer::~SimpleTimer(){
    stop();
}

void SimpleTimer::start() {
    if(m_running) return;
    m_running = true;
    m_thread = std::thread(&SimpleTimer::timerLoop, this);
}

void SimpleTimer::registerCallback(Callback cb, void* user_data)
{
    m_callback = cb;
    m_user_data = user_data;
}

void SimpleTimer::stop()
{
    m_running = false;
    if(m_thread.joinable())
    {
        m_thread.join();
    }
}
void SimpleTimer::timerLoop()
{
    while (m_running) {
        if (m_callback) {
            m_callback(m_user_data);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}
