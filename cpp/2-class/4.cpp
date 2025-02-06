#include <iostream>

class A
{
    // 友元的介绍：友元就是可以让另一个类或函数访问私有成员的简单写法
    friend class B;
    friend void output(const A &a);
    // 友元会破坏封装性，一般不推荐使用，所带来的方便写几个接口函数就解决了
    // 某些运算符的重载必须用到友元的功能，这才是友元的真正用途
public:
    // 一般封装接口函数就好了
    std::string getName() const
    {
        return name;
    }
    unsigned getOld() const
    {
        return old;
    }

private:
    std::string name;
    unsigned old;
};

class B
{
public:
    void output(const A &a)
    {
        std::cout << a.name << std::endl;
    }
};
void output(const A &a)

{
    std::cout << a.name << std::endl;
}

int main()
{
    return 0;
}