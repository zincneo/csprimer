#include <iostream>
#include <memory>

// 循环引用问题
struct B;
struct A {
    std::shared_ptr<B> sharedB;
};
struct B {
    std::shared_ptr<A> sharedA;
};

int main()
{
    // weak_ptr在c++11引入标准库，作用主要是解决shared_ptr循环引用的问题
    // weak_ptr必须绑定到shared_ptr上，区别只是不会增加引用计数
    // 用法一样，但需要使用shared_ptr复制构造
    std::shared_ptr<int> sharedI(new int(18));
    std::cout << sharedI.use_count() << std::endl;
    std::weak_ptr<int> weakI(sharedI);
    // 可以看到引用计数没有增加
    std::cout << sharedI.use_count() << std::endl;

    // 循环引用问题
    std::shared_ptr<A> sharedA = std::make_shared<A>();
    std::shared_ptr<B> sharedB = std::make_shared<B>();

    // 循环引用导致无法释放
    sharedA->sharedB = sharedB;
    sharedB->sharedA = sharedA;

    return 0;
}
