/*
* 程序执行后被称为一个进程，一个进程通常可以分为很多区域
* 代码区和常量区
* 栈区:栈内存通常很小，大小不会超过8M
* 堆区:更加灵活的需要程序员手动申请和释放的内存空间
* 静态变量区: 静态变量 全局变量
*/
#include <iostream>
#include <vector>

std::vector<int *> iVec;

int test() {
    // 这是一个服务端程序，用来接收用户发送的数据
    int *i = new int(rand()); // i变量是栈上的一个指针，指向堆上手动创建出来的内存
    iVec.push_back(i);
    static unsigned funcCallCount = 0; // 静态变量:常常需要一些局部作用范围，生命周期却很长的变量
    ++funcCallCount;
    return funcCallCount;
}

int main() {
    // 程序进入一个函数时，就会给该函数创建一个栈，并在栈中执行该函数的代码
    test();
    const char * str = "hello world"; // 字符串的字面量"hello world"被存储在常量区，const关键字只是告诉编译器将被修饰的变量str当作常量对待，并不是真的把变量str放在常量区
    test();
    test();
    unsigned testFuncCallCount = test();
    std::cout << testFuncCallCount << std::endl;
    return 0;
    // 函数执行完毕后，该函数的栈就会被销毁
}