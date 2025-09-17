#include<iostream>
#include<memory>
#include<vector>
class IProcess
{
    public:
    IProcess(){}
    ~IProcess(){}
    void exec()
    {
        step1();
        step2();
        step3();
        step4();
    }
    void step1()
    {
        std::cout<<"Execute step 1"<<std::endl;
    }
    void step2()
    {
        std::cout<<"Execute step 2"<<std::endl;
    }
    virtual void step3() = 0;
    virtual void step4() = 0;
};

class Proc1 : public IProcess
{
    void step3() override
    {
        std::cout<<"Step 3 in Proc1"<<std::endl;
    }
    void step4() override
    {
        std::cout<<"Step 4 in Proc1"<<std::endl;
    }
};

class Proc2 : public IProcess
{
    void step3() override
    {
        std::cout<<"Step 3 in Proc2"<<std::endl;
    }
    void step4() override
    {
        std::cout<<"Step 4 in Proc2"<<std::endl;
    }
};

enum class Process : int{
    proc1 = 1,
    proc2 = 2
};

class ProcHandler
{
    public:
        ProcHandler()
        {
            m_list.resize(3);
            m_list[static_cast<int>(Process::proc1)] = std::make_shared<Proc1>();
            m_list[static_cast<int>(Process::proc2)] = std::make_shared<Proc2>();

        }
        void execProc(Process p)
        {
            m_list[static_cast<int>(p)]->exec();
        }
    private:
        std::vector<std::shared_ptr<IProcess>> m_list;
};

int main()
{
    ProcHandler p;
    p.execProc(Process::proc1);
    p.execProc(Process::proc2);
}