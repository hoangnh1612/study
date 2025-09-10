#include <iostream>
#include <memory>

enum class HandlerType
{
    TYPE1,
    TYPE2,
    TYPE3
};
class IHandler
{
public:
    virtual void setNext(std::shared_ptr<IHandler> handler) = 0;
    virtual void handle(HandlerType type) = 0;
};

class Handler1 : public IHandler
{
public:
    Handler1()
    {
        m_next = nullptr;
    }
    void setNext(std::shared_ptr<IHandler> handler) override
    {
        m_next = handler;
    }
    void handle(HandlerType type) override
    {
        if (type == HandlerType::TYPE1)
        {
            std::cout << "Handle by Handler1" << std::endl;
        }
        else if (m_next)
        {
            m_next->handle(type);
        }
        else
        {
            std::cout << "No one can handle" << std::endl;
        }
    }

private:
    std::shared_ptr<IHandler> m_next;
};


class Handler2 : public IHandler
{
public:
    Handler2()
    {
        m_next = nullptr;
    }
    void setNext(std::shared_ptr<IHandler> handler) override
    {
        m_next = handler;
    }
    void handle(HandlerType type) override
    {
        if (type == HandlerType::TYPE2)
        {
            std::cout << "Handle by Handler2" << std::endl;
        }
        else if (m_next)
        {
            m_next->handle(type);
        }
        else
        {
            std::cout << "No one can handle" << std::endl;
        }
    }

private:
    std::shared_ptr<IHandler> m_next;
};


class Handler3 : public IHandler
{
public:
    Handler3()
    {
        m_next = nullptr;
    }
    void setNext(std::shared_ptr<IHandler> handler) override
    {
        m_next = handler;
    }
    void handle(HandlerType type) override
    {
        if (type == HandlerType::TYPE3)
        {
            std::cout << "Handle by Handler3" << std::endl;
        }
        else if (m_next)
        {
            m_next->handle(type);
        }
        else
        {
            std::cout << "No one can handle" << std::endl;
        }
    }

private:
    std::shared_ptr<IHandler> m_next;
};

int main()
{
    std::shared_ptr<IHandler> h1 = std::make_shared<Handler1>();
    std::shared_ptr<IHandler> h2 = std::make_shared<Handler2>();
    std::shared_ptr<IHandler> h3 = std::make_shared<Handler3>();

    h1->setNext(h2);
    h2->setNext(h3);

    h1->handle(HandlerType::TYPE1);
    h1->handle(HandlerType::TYPE2);
    h1->handle(HandlerType::TYPE3);
    h2->handle(HandlerType::TYPE1);
    h1->handle(static_cast<HandlerType>(100));
}