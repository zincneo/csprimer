#include <iostream>

// 多继承
class Base1
{
public:
    Base1(int i) : Base1I(i)
    {
    }

protected:
    int Base1I;
};
class Base2
{
public:
    Base2(int i) : Base2I(i)
    {
    }

protected:
    int Base2I;
};

// c++允许继承多个类
// 因此可能会导致菱形继承的问题，即A作为基类有B, C两个子类，D继承了B和C
// 平时不推荐使用多继承
// 一般用到多继承的就是接口模式，其他的面向对象的语言比如java直接取消了多继承添加了接口的概念
class Derived : public Base1, Base2
{
public:
    Derived(int i, int j) : Base1(i), Base2(j) {}
};

int main()
{
    return 0;
}