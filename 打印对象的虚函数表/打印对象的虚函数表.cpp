#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Func1()
    {
        cout << "Func1()" << endl;
    }

    virtual void Func2()
    {
        cout << "Func1()" << endl;
    }

    virtual void Func3()
    {
        cout << "Func1()" << endl;
    }

private:
    int _b = 1;
};

class Child : public Base
{
public:
    virtual void Func1()
    {
        cout << "Func1()" << endl;
    }

    void Func3()
    {
        cout << "Func1()" << endl;
    }
private:
    int _c = 1;
};

//打印对象的虚函数表
//虚函数表的地址就是一个对象所在空间的首地址的前四个字节
//虚函数表指针->虚函数表{虚函数1的地址、虚函数2的地址...}

typedef void(*VFPTR)();//为函数指针的类型起别名为VFPTR


//void PrintVFT(VFPTR vft[])与下方等效
void PrintVFT(VFPTR* vft)//数组不能传引用
{
    for (size_t i = 0; i < 4; i++)
    {
        printf("%p\n", vft[i]);//以十六进制的形式打印虚函数的地址
    }
}

int main()
{
    Base b;
    Child c;

    //只有有关联的类型之间才能直接发生强制类型转换
    //内置类型可以通过构造函数转换为自定义类型
    //int类型和任意指针类型都可以发生强制转换，char，float等不行
    //不同类型的指针之间可以发生强制类型转换，但是转换后可能会导致忽略内容的风险


    //自定义类型的对象不能直接强转为内置类型：(int)c错误
    //可以通过间接强制类型转换得到它的地址：

    //c是自定义类型的对象，&c后获得该对象的地址类型是Child*，将Child*强制类型转换为int*
    //因为我们现在想要的就是c对象的前四个字节的地址，而在x86环境下一个指针的大小是四字节
    //然后对int*类型的地址进行解引用获取这四个字节的整型值int
    //最后将int强转VFPTR*

    VFPTR* ptr = (VFPTR*)(*((int*)&c));
    PrintVFT(ptr);
  

    ////定义函数指针的两种方式
    //void (*p1)();

    //VFPTR p2;
    //
    ////定义函数指针数组的两种方式
    //void (*pa1[10])();

    //VFPTR pa2[10];
    return 0;
}
