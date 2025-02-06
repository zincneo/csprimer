#include <iostream>

// cpp面向对象三大特性:封装 继承 多态
// 封装就是权限管理 public private protected
// C++继承介绍：C++非继承的类相互是没有关联性的，假设现在需要设计医生，教师，公务员三个类，需要定义很多重复的内容而且相互没有关联，调用也没有规律。如果这还算好，那一个游戏有几千件物品，调用时也要写几千个函数。这太要命了。于是继承能力就应运而生了
// class FireSpear
// {
// private:
//     std::string name;
//     std::string icon;
// };

// class IceSpear
// {
// private:
//     std::string name;
//     std::string icon;
// };

class Spear
{
public:
    Spear(const std::string &name, const std::string &icon) : name(name), icon(icon)
    {
        std::cout << "Spear constructor" << std::endl;
    }
    ~Spear()
    {
        std::cout << "Spear destructor" << std::endl;
    }

protected:
    std::string name;
    std::string icon;
};

// cpp继承还分三种权限，但是就public最常用，其他两种根本没有任何用处
// cpp继承的原理可以理解为创建出子类的成员之前先创建出父类的成员，实际上c就是这么模拟出继承的
class FireSpear : public Spear
{
public:
    // 这里可以看出初始化列表是早于函数体执行的
    FireSpear(const std::string &name, const std::string &icon, int i) : Spear(name, icon), i(i)
    {
        std::cout << "FireSpear constructor" << std::endl;
    }
    ~FireSpear()
    {
        std::cout << "FireSpear destructor" << std::endl;
    }

private:
    int i;
};

class IceSpear : public Spear
{
};

int main()
{
    // 父类对象指针指向子类，类型检查的时候父类检查name，icon对应的成员都存在，至于剩下有什么可以理解为类型检查就不管了
    // C++子类对象的构造过程。先调用父类的构造函数，再调用子类的构造函数，也就是说先初始化父类的成员，再初始化子类的成员。
    // 若父类没有默认的构造函数，子类的构造函数又未调用父类的构造函数，则无法编译
    // C++子类对象的析构过程。先调用子类的析构函数，再调用父类的析构函数

    // Spear *pspear = new FireSpear("test", "test", 10);
    FireSpear *pspear = new FireSpear("test", "test", 10);
    delete pspear;
    return 0;
}