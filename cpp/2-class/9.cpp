#include <iostream>

// 纯虚函数
// 目的是希望基类对象不能实例化，任何一个虚函数加上=0就变成了纯虚函数，让一个成员函数为纯虚函数则该类无法实例化，注意构造函数和析构函数不可以是纯虚函数
class Base
{
public:
    virtual void func() const = 0;
};

int main()
{
    // Base b; // 不可以实例化，因为该类存在纯虚函数
    return 0;
}