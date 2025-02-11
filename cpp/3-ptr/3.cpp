#include <iostream>
#include <memory>

int main()
{
    // unique_ptr 独占智能指针，禁止复制构造和赋值运算符，其他和shared_ptr一样，性能更好
    // 使用new关键字初始化
    std::unique_ptr<int> uniqueI(new int(1));
    // 或者使用make_unique函数进行初始化
    std::unique_ptr<int> uniqueJ = std::make_unique<int>(200);
    // 但是允许移动构造，移动赋值

    // 能使用智能指针就尽量使用智能指针
    // 不能使用的情况
    // 1. 网络传输函数，比如windows下的send,recv函数，只能使用c语言指针
    // 2. c语言的文件操作部分，c++自己的文件操作完全支持智能指针
    return 0;
}