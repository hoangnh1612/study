#include<iostream>

class Printer{
    public:
    virtual void print() = 0;
};

class Adaptee{
    public:
        void legacyPrint() {
            std::cout << "Printing from legacy system." << std::endl;
        }
};

class Adapter : public Printer {
    private:
        Adaptee* adaptee;
    public:
        Adapter(Adaptee* a) : adaptee(a) {}
        void print() override {
            adaptee->legacyPrint();
        }
};

int main()
{
    Adaptee* oldPinrter = new Adaptee();
    Printer* printer = new Adapter(oldPinrter);
    printer->print();
    delete printer;
    delete oldPinrter;
    return 0;
}
