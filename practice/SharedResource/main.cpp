#include<memory>
#include<iostream>
#include<vector>

class Add{
    public:
        Add(std::shared_ptr<std::vector<int>> vect)
            : _vect(vect)
        {
        }
        void add(int value)
        {
            _vect->push_back(value);
        }
    private:
        std::shared_ptr<std::vector<int>> _vect;
};
int main()
{
    auto vect = std::make_shared<std::vector<int>>();
    for(int i = 0;i<100;i++)
    {
        vect->push_back(i);
    }
    Add add(vect);
    for(int i = 0;i<100;i++)
    {
        add.add(i);
    }
    std::cout<<vect->size() << std::endl;
}