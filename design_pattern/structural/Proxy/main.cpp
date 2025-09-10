#include <iostream>

class Interface
{
public:
    virtual void display() = 0;
};

class Object : Interface
{
public:
    Object(std::string s)
    {
        name = s;
    }
    void display() override
    {
        std::cout << name << std::endl;
    }

private:
    std::string name;
};

class Proxy : Interface
{
public:
    Proxy(std::string s)
    {
        name = s;
    }
    void display() override{
        if(!m_obj)
        {
            m_obj = new Object(name);
        }
        m_obj->display();
    }

private:
    Object* m_obj;
    std::string name;
};

int main()
{
    Proxy p("hoangnh3");
    p.display();
}