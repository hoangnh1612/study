#include <functional>
#include <iostream>
int add(int a, int b)
{
    return a + b;
}

int sub (int a, int b)
{
    return a -b;
}
int mul (int a, int b)
{
    return a*b;
}
int divv (int a, int b)
{
    return a/b;
}

void func(int a, int b, std::function<int(int, int)> calc)
{
    std::cout<<calc(a,b)<<std::endl;
}

using Callback = void (*)(void*);
void print(void* data)
{
    std::string* strPtr = static_cast<std::string*>(data);
    if(strPtr == nullptr)
    {
        std::cout<<"Cannot cast from type to string"<<std::endl;
        return;
    }
    std::cout<<*strPtr<<std::endl;

}
int main()
{
    // int var =3;
    // func(2,3,add);
    // auto aadd = [var](int x, int y){return x + y + var;};
    // func(2,3,aadd);


    // void (*fprt)(const std::string&);
    // fprt = &print;
    // fprt("aaa");
    Callback cb = print;
    int a = 1;
    std::string s = "aaa";
    print(&a);
    print(&s);


}