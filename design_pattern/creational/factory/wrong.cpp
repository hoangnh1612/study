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

// client

class Client{
    private:
        std::shared_ptr<Shape> pShape;
    public:
        Client(int type){
            if(type == 1)
                pShape = std::shared_ptr<Circle>();
            else if (type == 2)
                pShape = std::shared_ptr<Rectangle>();
            else
                pShape = nullptr;
        }

        ~Client(){
        }

        std::shared_ptr<Shape> getShape(){
            return pShape;
        }
};

int main()
{
    Client pClient = Client(1);
    std::shared_ptr<Shape> pShape = pClient.getShape();
    pShape->printShape();
    
}