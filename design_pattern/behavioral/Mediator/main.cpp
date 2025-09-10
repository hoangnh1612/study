#include<iostream>
#include<memory>

// Mediator
// Concrete Mediator
// Colleague
// Concrete Colleague

// each colleague contain mediator for request
enum class Taskey
{
    TakeOff,
    Landing
};
class IColleague;
class IMediator{
    public: 
        virtual void fixedRequest(IColleague* col, Taskey t) = 0;
        virtual void customRequest(IColleague* col, std::string s) = 0;
        virtual ~IMediator() = default;
};

class IColleague{
    public:
        IColleague(IMediator* m) : med(m) {}
        virtual ~IColleague() = default;

        virtual void reqTakeoff() = 0;
        virtual void reqLanding() = 0;
        virtual void notify(const std::string& s) = 0;
        void takeOff()
        {
            std::cout <<"Take off"<<std::endl;
        }
        void landing()
        {
            std::cout<<"Landing"<<std::endl;
        }
        void custom(std::string s)
        {
            std::cout<<s<<std::endl;
        }
    protected:
        IMediator* med;
};

class Colleague1 : public IColleague {
    public:
        Colleague1(IMediator* m) : IColleague(m) {}
    
        void reqTakeoff() override { med->fixedRequest(this, Taskey::TakeOff); }
        void reqLanding() override { med->fixedRequest(this, Taskey::Landing); }
        void notify(const std::string& s) override { med->customRequest(this, s); }
    };

    class Colleague2 : public IColleague {
        public:
            Colleague2(IMediator* m) : IColleague(m) {}
        
            void reqTakeoff() override { med->fixedRequest(this, Taskey::TakeOff); }
            void reqLanding() override { med->fixedRequest(this, Taskey::Landing); }
            void notify(const std::string& s) override { med->customRequest(this, s); }
        };

class Mediator : public IMediator{
    public:
        void fixedRequest(IColleague* col, Taskey t) override
        {
            if(t == Taskey::TakeOff)
                col->takeOff();
            if(t == Taskey::Landing)
                col->landing();
        }

        void customRequest(IColleague* col, std::string s) override
        {
            col->custom(s);
        }
};

int main()
{
    Colleague1 col1(new Mediator());
    col1.reqTakeoff();
    col1.reqLanding();
}

