#include <iostream>
#include <memory>
#include <vector>
class Observer
{
public:
    virtual void update(std::string s) = 0;
    ~Observer() = default;

protected:
    std::string state;
    void display()
    {
        std::cout << "New state: " << state << std::endl;
    }
};

class Subject
{
public:
    void addObserver(std::shared_ptr<Observer> s)
    {
        m_list.push_back(s);
    }
    void removeObserver(int id)
    {
        if (id < m_list.size())
            m_list.erase(m_list.begin() + id + 1);
    }
    void notify()
    {
        for (auto obs : m_list)
        {
            obs->update("AAAAAA");
        }
    }

private:
    std::vector<std::shared_ptr<Observer>> m_list;
};

class Observer1 : public Observer
{
public:
    void update(std::string s) override
    {
        state = s;
        display();
    }
};

int main()
{
    Subject sbj;
    std::shared_ptr<Observer1> obs1 = std::make_shared<Observer1>();
    sbj.addObserver(obs1);
    sbj.notify();

    std::shared_ptr<Observer1> obs2 = std::make_shared<Observer1>();
    std::shared_ptr<Observer1> obs3 = std::make_shared<Observer1>();

    std::shared_ptr<Observer1> obs4 = std::make_shared<Observer1>();

    std::shared_ptr<Observer1> obs5 = std::make_shared<Observer1>();

    sbj.addObserver(obs2);
    sbj.addObserver(obs3);
    sbj.addObserver(obs4);
    sbj.addObserver(obs5);
    sbj.notify();
}