#include<iostream>
#include<memory>
#include<string>
enum class CarType : int
{
    Sedan = 0,
    SUV = 1,
    Truck = 2,
    Coupe = 3,
    Hatchback = 4
};
class Car {
    public:
        Car(CarType type)
        {
            m_type = type;
        }
        virtual void print() = 0;
        virtual std::shared_ptr<Car> clone() = 0;
        CarType getType() const {
            return m_type;
        }
    private:
        CarType m_type;
};

class Sedan : public Car {
    public:
        Sedan() : Car(CarType::Sedan) {}
        void print() override {
            std::cout << "This is a " <<static_cast<int>(getType())<< std::endl;
        }

        std::shared_ptr<Car> clone ()
        {
            return std::make_shared<Sedan>();
        }

};

class SUV : public Car {
    public:
        SUV() : Car(CarType::SUV) {}
        void print() override {
            std::cout << "This is a " << static_cast<int>(getType()) << std::endl;
        }

        std::shared_ptr<Car> clone ()
        {
            return std::make_shared<SUV>();
        }
};

int main()
{

    std::shared_ptr<Car> car1 = std::make_shared<Sedan>();
    car1->print();

    std::shared_ptr<Car> car2 = car1->clone();
    car2->print();

    std::shared_ptr<Car> car3 = std::make_shared<SUV>();
    car3->print();

    std::shared_ptr<Car> car4 = car3->clone();
    car4->print();

    return 0;
}