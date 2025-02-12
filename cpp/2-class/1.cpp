#include <iostream>

// 面向对象和面向过程是一个相对的概念
// 面向过程是按照计算机的工作逻辑来编码的方式，最典型的面向过程的语言就是c语言了，c语言直接对应汇编，汇编又对应电路
// 面向对象则是按照人类的思维来编码的一种方式，C++就完全支持面向对象功能，可以按照人类的思维来处理问题
// 举个例子，要把大象装冰箱，按照人类的思路自然是分三步，打开冰箱，将大象装进去，关上冰箱
// 要实现这三步，我们就要首先有人，冰箱这两个对象。人有给冰箱发指令的能	力，冰箱有能够接受指令并打开或关闭门的能力
// 但是从计算机的角度讲，计算机只能定义一个叫做人和冰箱的结构体。人有手这个部位，冰箱有门这个部位。然后从天而降一个函数，是这个函数让手打开了冰箱，又是另一个函数让大象进去，再是另一个函数让冰箱门关上
// 从开发者的角度讲，面向对象显然更利于程序设计。用面色过程的开发方式，程序一旦大了，各种从天而降的函数会非常繁琐，一些用纯c写的大型程序，实际上也是模拟了面向对象的方式
// 那么，如何用面向过程的c语言模拟出面向对象的能力呢？类就诞生了，在类中可以定义专属于类的函数，让类有了自己的动作。回到那个例子，人的类有了让冰箱开门的能力，冰箱有了让人打开的能力，不再需要天降神秘力量了

// 面向对象不需要莫名其妙空降的函数了，利用封装的特性，将人可以做到的开冰箱(函数)和人这种自定义的数据结构(结构体)绑定在一起，对于程序员来说就可以说人这个类的实例可以做到开冰箱这件事

// 前向声明 IceChest
struct IceChest;

class Person
{
public:
    void openIceChest(const IceChest &iceChest) {}

private:
protected:
};

// cpp中struct关键字和class关键字唯一的区别是struct的属性和方法默认public，而class默认private
struct IceChest
{
    void openDoor()
    {
    }
    void closeDoor()
    {
    }
};

struct A
{
    int i, j;
    // 类再怎么吹，它也是通过面向过程的机器实现的，类相当于定义了一个新类型，该类型生成在堆或栈上的对象时内存排布和c语言相同。但是c++规定，C++有在类对象创建时就在对应内存将数据初始化的能力，这就是构造函数
    // 1. 默认构造函数,可以自己实现不写会有编译器自动实现的什么都不做的版本
    A() : i(1), j(1)
    {
    }
    // 2. 普通构造函数，传入自定义的参数
    A(int i, int j) : i(i), j(j) {}
    // 3. 复制构造函数，传入一个本类型的引用
    A(const A &a) : i(a.i), j(a.j) {}
    // 4. 移动构造 后面再看

    // 析构函数，当类对象被销毁时，就会调用析构函数。栈上对象的销毁时机就是函数栈销毁时，代码演示。堆上的对象销毁时机就是该堆内存被手动释放时，如果用new申请的这块堆内存，那调用delete销毁这块内存时就会调用析构函数。
    // 析构函数不能带参数，因此无法重载
    // 总结，当类对象销毁时有一些我们必须手动操作的步骤时，析构函数就派上了用场。所以，几乎所有的类我们都要写构造函数，析构函数却未必需要
    // 如果在类中需要手动使用new关键字申请内存就一定要在析构函数中按照正确的方式delete
    ~A() {
        std::cout << "A destructor" << std::endl;
    }
};

int main()
{
    A a; // 调用默认构造函数
    std::cout << a.i << std::endl;
    A a1 = A(3, 4); // 调用普通构造函数创建一个栈上的A实例
    A* a2 = new A(1, 2);
    delete a2;
}