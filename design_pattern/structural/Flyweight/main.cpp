#include<iostream>
#include<string>
#include<unordered_map>

class Interface{
    public:
    virtual void draw() = 0;
};

class Circle : public Interface{
    public:
    Circle(std::string color):color(color){}
    void draw() override
    {
        std::cout << "Circle: Draw() [Color : " << color << "]" << std::endl;
    }
    private:
    std::string color;
};

class Rectangle : public Interface{
    public:
    Rectangle(std::string color):color(color){}
    void draw() override
    {
        std::cout << "Rectangle: Draw() [Color : " << color << "]" << std::endl;
    }
    private:
    std::string color;
};


class FlyweightFactory{

    public:
        Interface* getIcon(std::string s, std::string color)
        {
            if(m_cache.find(s) != m_cache.end())
            {
                std::cout<<"Skip create new obj"<<std::endl;
                return m_cache[s];
            }
            else{
                if(s == "Circle")
                {
                    m_cache[s] = new Circle(color);
                    return m_cache[s];
                }
                else if (s == "Rect")
                {
                    m_cache[s] = new Rectangle(color);
                    return m_cache[s];
                }
                else
                {
                    std::cout<<"Not valid key"<<std::endl;
                    return nullptr;
                }
            }
        }

    private:
        std::unordered_map<std::string, Interface*> m_cache;
};

int main()
{
    FlyweightFactory f;
    auto rect1 = f.getIcon("Rect", "Red");
    auto rect2 = f.getIcon("Rect", "Blue");
    auto circle1 = f.getIcon("Circle", "Green");
    rect1->draw();
    rect2->draw();
    circle1->draw();
}