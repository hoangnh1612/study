#include<iostream>
#include<memory>

// abstract product
class Food {
    public:
        virtual void print() = 0;
};

class Spec {
    public:
        virtual void display() = 0;
};
// abstract factory
// concrete products
class VietFood : public Food {
    public:
        void print() override {
            std::cout << "Vietnamese Food" << std::endl;
        }
};
 class ThaiFood : public Food {
    public: 
        void print() override {
            std::cout << "Thai Food" << std::endl;
        } 
};
class VietSpec : public Spec {
    public:
        void display() override {
            std::cout << "Vietnamese Specification" << std::endl;
        }
};
class ThaiSpec : public Spec {
    public:
        void display() override {
            std::cout << "Thai Specification" << std::endl;
        }
};
class FoodFactory {
    public: 
        virtual std::shared_ptr<Food> createFood() = 0;
        virtual std::shared_ptr<Spec> Specification() = 0;
};
 // concrete factory
class VNFoodFactory : public FoodFactory {
    public:
    std::shared_ptr<Food> createFood() override {
            return std::make_shared<VietFood>();
        }
        
        std::shared_ptr<Spec> Specification() override {
            return std::make_shared<VietSpec>();
        }
};

class THFoodFactory : public FoodFactory {
    public:
    std::shared_ptr<Food> createFood() override {
        return std::make_shared<ThaiFood>();
    }
    
    std::shared_ptr<Spec> Specification() override {
        return std::make_shared<ThaiSpec>();
    }
};


// client
class Client {
    public:
        FoodFactory* m_factory;
        Client(FoodFactory* factory) : m_factory(factory) {}
        void run() {
            std::shared_ptr<Food> food = m_factory->createFood();
            food->print();
            std::shared_ptr<Spec> spec = m_factory->Specification();
            spec->display();
            delete m_factory;
        }
};

int main()
{
    VNFoodFactory* vnFactory = new VNFoodFactory();
    THFoodFactory* thFactory = new THFoodFactory();

    Client vnClient(vnFactory);
    vnClient.run();

    Client thClient(thFactory);
    thClient.run();


    return 0;
}

