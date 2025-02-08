#include <iostream>

// cpp 里面的多态说白了就是父类指针可以调用子类的方法
// 当父类指针指向子类对象，且子类重写了父类的某个方法的时候会产生以下两种可能
// 1. 该方法是虚函数，则调用子类成员方法(让一个函数成为虚函数，需要在父类和子类的对应函数前面都加上virtual, 子类不加也行，当函数名形参返回值完全一致的时候会自动加)
// 2. 该方法不是虚函数，则调用父类成员方法(因为实现的是静态绑定，在编译时就已经确定好调用的地址)

// 为了防止开发人员不小心写错，cpp11添加了override关键字
// 父类的析构函数必须是虚函数:这一点非常重要，因为当父类指针指向子类对象的时候，非虚的析构函数可能会导致子类的内存泄露问题
// 虚函数实现的是动态绑定，在运行期才会确定调用的是哪个方法:程序在编译时确定的是函数寻找虚函数地址的方法
// 每一个有虚函数的类都会有虚函数表，每一个类都有且仅有一个虚函数表，所有的对象共用，对象其实就是指向虚函数表的指针(意思就是对象在实现的存储结构中不止包含了成员熟悉还存了一份指向虚函数表的指针)

class Spear
{
public:
    virtual void openFire() const
    {
        std::cout << "Spear::openSpear" << std::endl;
    }
};

class FireSpear : public Spear
{
public:
    virtual void openFire() const
    {
        std::cout << "Spear::openFireSpear" << std::endl;
    }

private:
};

class IceSpear : public Spear
{
public:
    // override关键字表示该方法是在重写父类的方法
    void openFire() const override
    {
        std::cout << "Spear::openIceSpear" << std::endl;
    }
};

void openFire(const Spear *pspear)
{
    pspear->openFire();
    delete pspear;
}

int main()
{
    openFire(new Spear);
    openFire(new FireSpear);
    openFire(new IceSpear);
    return 0;
}
