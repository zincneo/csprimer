#include <iostream>

// 编译器将this解释为指向函数所作用的对象的指针
class Test
{
public:
    Test(const std::string &name, unsigned age);
    ~Test() {}
    // 可以简单理解为成员函数有一个隐藏参数this，指向实例化的对象本身
    // 当然，这么说并非完全准确，this是一个关键字，只是我们将它当做指针理解罢了
    // this有很多功能是单纯的指针无法满足的。比如每个类函数的参数根本没有名	叫this的指针。这不过是编译器赋予的功能罢了
    void outPut()
    {
        // 这里变量name的全名是this->name, age的全名是this->age
        std::cout << "name = " << name << ", age = " << age << std::endl;
    }
    // 常成员函数和常对象很多人并不在意，确实，都写普通变量也可以。但是，我还是要提一点，在大型程序中，尽量加上const关键字可以减少很多不必要的错误。
    // const关键字含义：普通的const之前已经见过了
    // 常成员函数就是无法修改成员变量的函数。可以理解为将this指针指向对象用const修饰的函数
    // 且普通成员函数和常成员函数可以重载，普通对象优先调用普通成员函数，常对象优先调用常成员函数
    // 通常不会重载写两份，能写常成员函数就写常成员函数，可以尽量避免错误
    void outPut() const
    {
        // 这里的this就可以当中是被const修饰不可以被用来修改成员变量的值
        std::cout << "name = " << name << ", age = " << age << std::endl;
    }
    // 常对象就是用const修饰的对象，定义好之后就再也不需要更改成员变量的值了。常对象在大型程序中还是很有意义的

private:
    std::string name;
    unsigned age;
};

Test::Test(const std::string &name, unsigned age) : name(name), age(age) {}

// 从c的角度上来说outPut函数本质就是
// void outPut(Test *const myThis)
// {
//     std::cout << "name = " << myThis->name << ", age = " << myThis->age << std::endl;
// }

// 这个空形参列表的函数指针可以指向成员函数outPut，这就说明成员函数根本不存在this这个形参，this是编译器提供的关键字
void (Test::*pf)() = &Test::outPut;

int main()
{
    Test test(std::string("abc"), 22);
    test.outPut();
    (test.*pf)();
    // 常对象，禁止修改，也就不能调用非常成员函数(也就是普通函数)
    const Test test2(std::string("abc"), 23);
    test2.outPut(); 
    return 0;
}