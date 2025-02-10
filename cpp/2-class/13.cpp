#include <iostream>
#include <string.h>

// 移动构造和移动赋值运算符
// copy开销大，对于临时对象要赋值的时候选择直接move(rust直接使用所有权概念了)
class Test
{
public:
    Test() = default;
    // 左值使用copy
    Test(const Test &test)
    {
        if (test.str)
        {
            str = new char[strlen(test.str) + 1]();
            strcpy_s(str, strlen(test.str) + 1, test.str);
        }
        else
        {
            str = nullptr;
        }
    }
    // 右值直接move
    Test(Test &&test)
    {
        if (test.str)
        {
            str = test.str;
            test.str = nullptr;
        }
        else
        {
            str = nullptr;
            test.str = nullptr;
        }
    }
    Test &operator=(const Test &test)
    {
        if (this == &test)
        {
            return *this;
        }
        if (str)
        {
            delete[] str;
            str = nullptr;
        }
        if (test.str)
        {
            str = new char[strlen(test.str) + 1]();
            strcpy_s(str, strlen(test.str) + 1, test.str);
        }
        else
        {
            str = nullptr;
        }
        return *this;
    }
    Test &operator=(Test &&test)
    {
        if (this == &test)
        {
            return *this;
        }
        if (str)
        {
            delete[] str;
            str = nullptr;
        }
        if (test.str)
        {
            str = test.str;
            test.str = nullptr;
        }
        else
        {
            str = nullptr;
            test.str = nullptr;
        }
        return *this;
    }

private:
    char *str = nullptr;
};

Test makeTest()
{
    Test t;
    return t;
}

int main(){
    // 代码演示
    Test t = makeTest();
    return 0;
}