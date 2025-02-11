#include <iostream>

// c++三大模块: 面向过程，面向对象，模板和泛型
// 模板分为类模板和函数模板

// 类模板 关键字typename
template <typename T>
class MyArray
{
    using iterator = T *;
    using const_iterator = const T *;

public:
    MyArray(size_t count);
    // {
    //     if (count)
    //     {
    //         data = new T[count]();
    //     }
    //     else
    //     {
    //         data = nullptr;
    //     }
    // }

    ~MyArray();
    // {
    //     if (data)
    //     {
    //         delete[] data;
    //     }
    // }
    iterator begin() const;
    // {
    //     return data;
    // }
    const_iterator cbegin() const;
    // {
    //     return data;
    // }

private:
    // 这里使用普通指针是偷懒以及智能指针创建数组不方便
    T *data;
};

// 成员函数模板
template <typename T>
MyArray<T>::MyArray(size_t count)
{
    if (count)
    {
        data = new T[count]();
    }
    else
    {
        data = nullptr;
    }
}

template <typename T>
MyArray<T>::~MyArray()
{
    if (data)
    {
        delete[] data;
    }
}

template <typename T>
// 没办法直接使用MyArray<T>::iterator，必须要加上typename关键字让编译器知道这是一个类型
typename MyArray<T>::iterator MyArray<T>::begin() const
{
    return data;
}

template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const
{
    return data;
}

// 注意模板声明和实现的时候必须在同一个文件中，分文件编译器会报错，原因见编译原理
// 因此一般放在hpp文件中声明和实现

int main() {}