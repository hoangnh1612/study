#include<iostream>
#include<memory>

class Visitor;
class Shape
{
    public:
    virtual void accept(Visitor* v)  = 0;
};
class Dot;
class Tri;
class Visitor
{
    public:
        virtual void visitDot(Dot* d) = 0;
        virtual void visitTri(Tri* t) = 0;
};
class Dot : public Shape {
    public:
    void accept(Visitor* v) override
    {
        v->visitDot(this);
    }
    void printD()
    {
        std::cout<<"From D"<<std::endl;
    }
};
class Tri : public Shape {
    public:
    void accept(Visitor* v) override
    {
        v->visitTri(this);
    }
    void printT()
    {
        std::cout<<"From T"<<std::endl;
    }
};
class VisitorA : public Visitor {
    public:
    void visitDot(Dot* d) override
    {
        d->printD();
    }
    void visitTri(Tri* t) override
    {
        t->printT();
    }
};

int main()
{
    Dot* d = new Dot();
    Tri* t = new Tri();
    VisitorA *v = new VisitorA();
    d->accept(v);
}


