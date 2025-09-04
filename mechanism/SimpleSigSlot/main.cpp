#include<functional>
#include<iostream>
#include<vector>
#include<string>

template<typename T>
class Signal;
template<typename R, typename... Args>
class Signal<R(Args...)>{
    using Slot = std::function<R(Args...)>;
    public:
        void connect(Slot slot)
        {
            slots.push_back(slot);
        }
        void emit(Args... args)
        {
            for(auto slot : slots)
            {
                slot(args...);
            }
        }
    private:
        std::vector<Slot> slots;
};



void print(int a, std::string s)
{
    std::cout << a << " "<< s <<std::endl;
}
int main()
{
    Signal<void(int, std::string)> s;
    s.connect(print);
    s.emit(2, "hello");
}