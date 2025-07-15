#include<iostream>
#include <memory>
class Shape {
    public:
        virtual void printShape() = 0; 
};

class Circle : public Shape {
    public:
        void printShape() override {
            std::cout << "This is a Circle." << std::endl;
        }
};

class Rectangle : public Shape {
    public:
        void printShape() override {
            std::cout << "This is a Rec." << std::endl;
        }
};

enum class Type{
    circle,
    rec,
    unknown
};

class ShapeFactory {
    public:
        static inline std::shared_ptr<Shape> create(Type type){
            switch (type)
            {
            case Type::circle:
                return std::make_shared<Circle>();
            case Type::rec:
                return std::make_shared<Rectangle>();

            default:
                return nullptr;
            }
        }
};

class Client{
    private:
        std::shared_ptr<Shape> pShape;
    public:
        Client(Type type){
            pShape = ShapeFactory::create(type);
        }

        ~Client(){
        }

        std::shared_ptr<Shape> getShape(){
            return pShape;
        }
};

int main()
{
    Client pClient = Client(Type::circle);
    std::shared_ptr<Shape> pShape = pClient.getShape();
    pShape->printShape();
    
}