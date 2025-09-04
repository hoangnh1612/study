#include"Libraby.h"
#include<iostream>


// void periodicTask(void* s)
// {
//     std::string* str = static_cast<std::string*>(s);
//     std::cout<<*str<<std::endl;
// }
// int main()
// {
//     Callback cb;
//     cb = &periodicTask;
//     SimpleTimer t;
//     std::string s = "aaa";
//     t.registerCallback(cb, &s);
//     t.start();
//     std::this_thread::sleep_for(std::chrono::seconds(10));
// }

class CounterClass{
    public:
        CounterClass(int start) : m_count(start) {}
        void execCounting(){
            m_count ++;
            std::cout<<"Count increment "<<m_count<<std::endl;
        }

        static void wrapperCallback(void * user_data)
        {
            auto entity = static_cast<CounterClass*>(user_data);
            entity->execCounting();
        }
    private:
        int m_count;
};

int main()
{
    SimpleTimer timer;
    CounterClass execClass(0);
    timer.registerCallback(CounterClass::wrapperCallback, &execClass);
    timer.start();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    timer.stop();
}