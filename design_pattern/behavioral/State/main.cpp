#include<iostream>
#include<vector>
#include<memory>

// allow object to change it behavior when its internal state changes

// Context: Maintain a ref to the current state
//State Interface: virtual, context will work with it
// Concrete States: Implement IState, encap behavior for specific state and
// defining context action in those states

class IState
{
    public:
        virtual void handle() = 0;
};

class Stop : public IState
{
    void handle() override
    {
        std::cout<<"In stop state"<<std::endl;
    }
};

class Start : public IState
{
    void handle() override
    {
        std::cout<<"In start state"<<std::endl;
    }
};

class Init : public IState
{
    void handle() override
    {
        std::cout<<"In init state"<<std::endl;
    }
};

enum class State : int {
    init = 1,
    start = 2,
    stop = 3,

};
class StateHandler
{
    private:
        std::vector<std::shared_ptr<IState>> m_listState;
    public:
        StateHandler()
        {
            m_listState.resize(4);
            m_listState[static_cast<int>(State::init)] = std::make_shared<Init>();
            m_listState[static_cast<int>(State::start)] = std::make_shared<Start>();
            m_listState[static_cast<int>(State::stop)] = std::make_shared<Stop>();
        }
        std::shared_ptr<IState> changeState(State s)
        {
            return m_listState[static_cast<int>(s)];
        }
};
class Context
{
    public:
        Context()
        {
            m_stateHandler = std::make_shared<StateHandler>();
        }
        void request()
        {
            if(m_state)
                m_state->handle();
        }
        void changeState(State s)
        {
            m_state = m_stateHandler->changeState(s);
            request();
        }
    private:
        std::shared_ptr<StateHandler> m_stateHandler;
        std::shared_ptr<IState> m_state;
};

int main()
{
    Context s;
    s.changeState(State::init);
    s.changeState(State::start);
    s.changeState(State::stop);
}



