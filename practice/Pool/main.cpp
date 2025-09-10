#include <iostream>
#include <memory>
#include <vector>

class Object
{
public:
    Object() { std::cout << "Object created" << std::endl; }
    ~Object() { std::cout << "Object destroyed" << std::endl; }
    void doSomething() { std::cout << "Doing something with the object" << std::endl; }
};
class ObjectPool
{
private:
    std::vector<std::shared_ptr<Object>> pool_;
    int max_size;

public:
    ObjectPool(int size)
    {
        max_size = size;
        for (int i = 0; i < max_size; i++)
            pool_.push_back(std::make_shared<Object>());
    }

    void release(std::shared_ptr<Object> obj)
    {
        if (pool_.size() < max_size)
            pool_.push_back(obj);
        else
            std::cout << "Pool is full" << std::endl;
    }

    std::shared_ptr<Object> acquire()
    {
        if (pool_.empty())
        {
            std::cout << "Pool is empty, create new object" << std::endl;
            return std::make_shared<Object>();
        }
        else
        {
            auto obj = pool_.back();
            pool_.pop_back();
            return obj;
        }
    }
};

int main()
{
    ObjectPool pool(3);
    for(int i = 0;i<4;i++)
    {
        auto work = pool.acquire();
        work->doSomething();
    }
}