#include <iostream>

// 静态成员变量与静态函数，static关键字其实作用和在类外一样
// 静态成员函数就是为了静态成员变量存在的，目的是为了维持封装性
class Test
{

public:
    static unsigned getI()
    {
        return i;
    }

private:
    // 必须在类外进行初始化，否则会报未定义的错误
    // 为了避免破坏封装性，一般还是写为private的，使用静态成员函数初始化和操作
    static unsigned i;
};

unsigned Test::i = 10;
// 存储区完全相同(存储在静态变量区)，作用逻辑也完全相同，只是属于类本身，可以直接使用类名调用，也可以使用实例化的对象调用
static unsigned i = 10;

int main()
{
    return 0;
}
