#include <iostream>

// 虚继承就是为了避免多重继承产生二义性的问题
class Base1
{
public:
    Base1(int i) : i(i)
    {
    }
    int i;
};

class Base2
{
public:
    Base2(int i) : i(i)
    {
    }
    int i;
};

class Derived : public Base1, Base2
{
public:
    Derived(int i, int j, int k) : Base1(i), Base2(j), i(k) {}
    int i;
};

// 如果要产生菱形继承，要使用虚继承
// 这样最后只有有一个i
class A
{
public:
    std::string icon;
    int i = 100;
};

// 对于虚继承而言会有一个虚继承表,表中记载了成员属性相对于自身的偏移地址
class B : virtual public A
{
};
class C : virtual public A
{
};
// 这样D里面继承到i，查虚继承表，都相对于自身便宜了一个std::string的大小，就会认为这是同一个属性只继承这一个
class D : public B, C
{
};

int main()
{
    // 调用i的时候存在二义性，需要用类名指明
    Derived d(1, 2, 3);
    std::cout << d.Base1::i << " " << d.Derived::i << std::endl;
    // 但是真实场景不应该写出这种代码，而要用虚继承，而且一般只会在游戏开发领域经常见到，其他领域一般很少用
    return 0;
}
