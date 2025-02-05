#include <iostream>
#include <functional>

void test(int i)
{
    return;
}

using pf_type = void (*)(int);
using func_type = std::function<void(int)>;

void myFunc(pf_type pf, int i)
{
    pf(i);
}

class Test
{
public:
    void operator()(int i)
    {
        std::cout << i << std::endl;
    }

private:
};

int main()
{
    // 可调用对象
    // 如果一个对象可以使用调用运算符“()”，()里面可以放参数，这个对象就是可调用对象

    // 1. 函数
    myFunc(test, 100);
    // 2. 仿函数
    // 具有operator()函数的类对象
    Test t;
    t(20); // 本身是类对象但是可以使用小括号，因此称为仿函数

    // 3. lambda表达式 也可以说是匿名函数
    // lambda表达式很重要，现代C++程序中，lambda表达式是大量使用的
    // lambda表达式的格式：最少是“[] {}”，完整的格式为“[] () ->ret {}”
    []
    {
        std::cout << "lambda" << std::endl;
    }();
    // []表示不捕获任何变量
    // [=]表示按值捕获所有变量
    int i = 1;
    [=]
    {
        std::cout << i << std::endl;
    }();
    // [&]表示按照引用捕获所有变量
    // =，&也可以混合使用，比如
    // [=, &i] 表示变量i用引用传递，除i的所有变量用值传递
    // [&, i] 表示变量i用值传递，除i的所有变量用引用传递
    // [i] 表示以值传递的形式捕获i
    // [&i] 表示以引用传递的方式捕获i
    // ()代表lambda表达式的参数，函数有参数，lambda自然也有
    [i](int elem)
    {
        std::cout << i + elem << std::endl;
    }(10);
    // 返回值->ret表示指定lambda的返回值，如果不指定，lambda表达式也会推断出一个返回值的
    auto ret = []() -> int
    { return 0; };
    // lambada表达式最常见的用法还是给普通函数作为参数使用
    // 作为函数指针的时候，捕获列表必须为空
    // function模板和函数指针完全相同，唯一区别就是可以让lambada表达式捕获内容
    return 0;
}