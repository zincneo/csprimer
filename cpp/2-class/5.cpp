#include <iostream>
#include <vector>

// 很多时候我们想让类对象也能像基础类型的对象一样进行作基础操作，比如“+”，“-”，“*”，“\”，也可以使用某些运算符“=”，“()”，“[]”,“<<”，“>>”。但是一般的类即使编译器可以识别这些运算符，类对象也无法对这些运算符做出应对，我们必须对类对象定义处理这些运算符的方式
// C++提供了定义这些行为的方式，就是“operator 运算符”来定义运算符的行为，operator是一个关键字，告诉编译器我要重载运算符了
// 我们只能重载C++已有的运算符，所有无法将“**”这个运算符定义为指数的形式，因为C++根本没有“**”这个运算符
// C++重载运算符不能改变运算符的元数，“元数”这个概念就是指一个运算符对应的对象数量，比如“+”必须为“a + b”，也就是说“+”必须有两个对象，那么“+”就是二元运算符。比如“++”运算符，必须写为“a++”，也就是一元运算符

// 三元运算符?:不能重载
// “=”类会默认进行重载，如果不需要可以用“delete关键字进行修饰”

// 可以重载的运算符
// 一元运算符 -- ++ [] () << >>
// 二元运算符 - + * / = < > ==
// 类类型转换 operator 类型
// 特殊运算符 new delete new[] delete{}
struct Test
{
    // 输入输出运算符必须使用友元函数的方式重载
    friend std::ostream &operator<<(std::ostream &os, const Test &test);
    friend std::istream &operator>>(std::istream &is, Test &test);
    void operator++()
    {
        ++count;
    }
    void operator--()
    {
        --count;
    }
    int operator[](unsigned i)
    {
        // 非常糟糕的写法，完全没做越界判断和其他错误处理，这里只是作为演示
        return ivec[i];
    }
    // 仿函数
    void operator()()
    {
        std::cout << "mock function" << std::endl;
    }
    void operator()(const std::string &str)
    {
        std::cout << str << std::endl;
    }

    // +
    Test operator+(const Test &test)
    {
        count += test.count;
        return *this;
    }
    // 手动显示标明默认重载=运算符
    Test& operator=(const Test &test) = default;
    unsigned count = 0;
    std::vector<int> ivec{1, 2, 3, 4, 5, 6};
    std::string name;
};
std::ostream &operator<<(std::ostream &os, const Test &test)
{
    os << test.name << std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Test &test)
{
    is >> test.name;
    return is;
}
int main()
{
    Test test;
    ++test;
    std::cout << test.count << std::endl;
    --test;
    std::cout << test.count << std::endl;
    return 0;
}