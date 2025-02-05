#include <iostream>

class Test
{
public:
    Test(): i(0) {}
    Test(int _i) : i(_i) {}
private:
    int i;
};

// 解决同名类的方法，命名空间
// c++特有的库，特指c没有的库，都使用了命名空间std
namespace A {
    class Test {};
}

namespace B {
    class Test {};
    int a;
}

// using关键字用来简化命名空间的使用
// 因此在头文件当中一定不要使用using关键字，否则会导致命名空间的污染
using B::a;

int main()
{
    // new关键字可以给普通对象分配内存
    // 对于普通对象，可以使用()将所有值初始化为0，没有加小括号则分配的值对于c++来说是未定义的值
    int *pi = new int(100);
    std::cout << pi << std::endl;
    std::cout << *pi << std::endl;
    int *pa = new int[100]();
    // 当构造类对象的时候会调用构造函数，如果不存在构造函数，则会报错
    // 对于类对象加不加小括号都调用默认构造函数
    std::string *pString = new std::string("hello world");
    std::cout << pString << std::endl;
    std::cout << *pString << std::endl;
    
    Test *test = new Test[100]();

    // new创建的对象必须释放，否则就会导致内存泄漏
    delete pi;
    // 动态申请数组必须使用delete[]，否则就会导致内存泄漏
    delete[] pa;
    delete pString;
    delete[] test;
    // 不delete会导致内存泄漏，这是最严重的错误之一，解决方法:智能指针 异常处理

    return 0;
}
