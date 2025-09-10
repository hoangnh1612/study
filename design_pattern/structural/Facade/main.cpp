#include<iostream>
#include <memory>
#include <vector>
class Entity{
    public:
        Entity(){}
        ~Entity(){}
        virtual void show() = 0;
};

class Triangle : public Entity{
    public:
        Triangle() {}
        ~Triangle() {}
        void show() override {
            std::cout<<"This is Triangle"<<std::endl;
        }


};

class Square : public Entity{
    public:
        Square() {}
        ~Square() {}
        void show() override {
            std::cout<<"This is Square"<<std::endl;
        }
};

class Rectangle : public Entity{
    public:
        Rectangle() {}
        ~Rectangle() {}
        void show() override {
            std::cout<<"This is Rectangle"<<std::endl;
        }
};

class Facade{
    public:
        Facade() {}
        ~Facade() {}
        void addEntity(const std::string& type) {
            if(type == "Triangle") {
                entities.push_back(std::make_unique<Triangle>());
            } else if(type == "Square") {
                entities.push_back(std::make_unique<Square>());
            } else if(type == "Rectangle") {
                entities.push_back(std::make_unique<Rectangle>());
            } else {
                std::cout<<"Unknown type"<<std::endl;
            }
        }
        void showEntities() {
            for(const auto& entity : entities) {
                entity->show();
            }
        }
    private:
        std::vector<std::unique_ptr<Entity>> entities;
};

class Client{
    public:
        Client() {}
        ~Client() {}
        void run() {
            Facade facade;
            facade.addEntity("Triangle");
            facade.addEntity("Square");
            facade.addEntity("Rectangle");
            facade.showEntities();
        }
};

int main()
{
    Client client;
    client.run();
}