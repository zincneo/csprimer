#include <iostream>
#include <memory>

void func(std::shared_ptr<int> i)
{

    std::cout << i.use_count() << std::endl;
    return;
}

int main()
{
    // 堆上内存必须通过栈上内存寻址
    // 因此可以给堆上内存加上一个引用计数，记录有几个指针指向它，引用计数就是几，当引用计数为0时，系统自动释放该块堆内存

    // 使用new关键字初始化
    std::shared_ptr<int> sharedI(new int(100));
    // 使用make_shared函数进行初始化
    std::shared_ptr<int> sharedJ = std::make_shared<int>(100);

    // 不要使用裸指针初始化shared_ptr 会导致内存泄漏的问题
    // int *pi = new int(10);
    // std::shared_ptr<int> shared_i(pi);

    // 使用复制构造函数初始化是可以的，不然叫共享智能指针干嘛
    std::shared_ptr<int> sharedK(sharedI);
    // 打印现在有多少引用计数的函数
    std::cout << sharedI.use_count() << std::endl;
    // 释放一个指针指针对堆内存控制权的函数
    sharedK.reset();
    std::cout << sharedI.use_count() << std::endl;
    // 智能指针可以像普通指针一样使用，shared_ptr这个类对操作符进行了重载

    // 常用函数
    // unique 判断该智能指针是否独占堆内存，返回布尔值
    // reset 有参数时，改变智能指针的指向，没有参数时将对象置空，也就是置为nullptr
    // get 强烈不推荐使用，会返回内存地址，如果一定要使用不要使用delete删除该内存
    // swap 交换两个智能指针指向的内存

    // 智能指针创建数组
    std::shared_ptr<int> sharedArray(new int[100]());
    std::cout << sharedArray.get()[10] << std::endl;

    // 作为函数参数使用的时候直接作为值传递就可以了
    func(sharedI);
    return 0;
}

