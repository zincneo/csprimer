#include <iostream>

class Test {
    public:
    // 在函数声明或定义中函数返回类型前加上关键字inline就可以把函数指定为内联函数。关键字inline必须与函数定义放在一起才能使函数成为内联，仅仅将inline放在函数声明前不起任何作用。
    // 内联函数的作用，普通函数在调用时需要给函数分配栈空间以供函数执行，压栈等操作会影响成员运行效率，于是C++提供了内联函数将函数体放到需要调用函数的地方，用空间换效率
    // inline关键字的注意事项：inline关键字只是一个建议，开发者建议编译器将成员函数当做内联函数，一般适合搞内联的情况编译器都会采纳建议
    void outPut();
    // Mutable意为可变的，与const相对，被mutable修饰的成员变量，永远处于可变的状态，即便处于一个常函数中，该变量也可以被更改
    // 这个关键字在现代C++中使用情况并不多，一般来说只有在统计函数调用次数时才会用到
    void outPut() const;
    // mutable是一种万不得已的写法，一个程序不得不使用mutable关键字时，可以认为这部分程序是一个糟糕的设计
    // mutable不能修饰静态成员变量和常成员变量
    // mutable关键字是一种没有办法的办法，设计时应该尽量避免，只有在统计函数调用次数这类情况下才推荐使用。这个关键字也称不上是重点
    mutable unsigned outPutCount = 0;

    // default关键字的作用
    // 在编译时不会生成默认构造函数时便于书写
    // 也可以对默认复制构造函数，默认的赋值运算符和默认的析构函数使用，表示使用的是系统默认提供的函数，这样可以使代码更加明显
    // 现代C++中，哪怕没有构造函数，也推荐将构造函数用default关键字标记，可以让代码看起来更加直观，方便
    
    // 一旦自己实现了普通构造函数，编译器就不会生成默认构造函数
    Test(unsigned _null) {}
    // 如果这时候需要编译器生成的默认构造函数就可以使用default关键字
    Test() = default;
    // 对默认复制构造函数使用
    // Test(const Test& test) = default;
    // 对析构函数使用
    ~Test() = default;
    // 默认赋值运算符
    Test& operator=(const Test&) = default;

    // Delete关键字的作用：C++会为程序生成默认构造函数，默认复制构造函数，默认重载赋值运算符（重载部分会详细讲解）
    // 在很多情况下，我们并不希望这些默认的函数被生成，在C++11以前，只能有将此	函数声明为私有函数或是将函数只声明不定义两种方式
    // C++11于是提供了delete关键字，只要在函数最后加上“=delete”就可以明确告诉	编译期不要默认生成该函数
    // 该功能在一些模式中，比如单例模式中很有用
    Test(const Test& test) = delete;
    private:

};

// 必须在定义的地方加inline关键字，声明的地方加不加都可以
inline void Test::outPut() {}

void Test::outPut() const {
    // mutable关键字使得成员变量在常成员函数中也可以被修改
    ++outPutCount;
}

int main() {
    const Test test;
    test.outPut();
    test.outPut();
    test.outPut();
    test.outPut();
    test.outPut();
    test.outPut();
    test.outPut();
    test.outPut();
    test.outPut();
    std::cout << test.outPutCount << std::endl;
    return 0;
}