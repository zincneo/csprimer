#include <iostream>
// RTTI Run Time Type Identification
class Base
{
public:
    Base(int i) : i(i) {}
    virtual void test() const
    {
        std::cout << "Base" << std::endl;
    }

private:
    int i;
};

class FireBase : public Base
{
public:
    FireBase(int i, int j) : Base(i), j(j) {}
    void test() const override
    {
        std::cout << "FireBase" << std::endl;
    }

private:
    int j;
};
class IceBase : public Base
{
public:
    IceBase(int i, int j) : Base(i), j(j) {}
    void test() const override
    {
        std::cout << "IceBase" << std::endl;
    }

private:
    int j;
};

int main()
{
    // c++为了实现多态指针和指向的类型可能不同
    // 父类指针指向子类对象的时候，这时就可以使用RTTI来判断实际的类型，这是判断指针或引用实际类型的唯一方式
    Base *pa = new FireBase(3, 4);
    // 用处: 异常处理、IO操作
    // 使用方法: 注意要使用下面两个父类和子类必须要有虚函数，这样类型才会是多态类型，没有虚函数的继承也不会作为多态类型
    // typeid函数，返回一个叫做type_info的结构体，该结构体包含了所指向对象的实际信息，其中name函数包含了返回类型的真实名称
    std::cout << typeid(*pa).name() << std::endl;
    // dynamic_cast c++提供的将父类指针转换为子类指针的函数
    FireBase *pb = dynamic_cast<FireBase *>(pa);
    if (pb)
    {
        std::cout << "success" << std::endl;
    }
    // 实际的做法
    // 这里要转为std::string是因为两个const char*判等比较的是地址而不是内容
    if (std::string(typeid(*pa).name()) == "8FireBase")
    {
        FireBase *pb = dynamic_cast<FireBase *>(pa);
        if (pb)
        {
            std::cout << "cast FireBase success" << std::endl;
        }
    }
    delete pa;
    return 0;
}
