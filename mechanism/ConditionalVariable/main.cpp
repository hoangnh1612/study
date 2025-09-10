#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>
std::mutex mt;
bool ready = false;
std::condition_variable cv;
std::condition_variable cv1;
int data;
void producer()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::unique_lock<std::mutex> lock(mt);
    ready = true;
    data = 42;
    cv.notify_one();
    // cv1.wait(lock, [] {return data > 40;});
    // std::cout<<"cv1 is unblocked"<<std::endl;

}
void consumer()
{
    std::unique_lock<std::mutex> lock(mt);
    cv.wait(lock, [] {return ready;});
    std::cout<<data<<std::endl;
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}