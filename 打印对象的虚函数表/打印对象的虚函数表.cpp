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

//��ӡ������麯����
//�麯����ĵ�ַ����һ���������ڿռ���׵�ַ��ǰ�ĸ��ֽ�


typedef void(*VFPTR)();//Ϊ����ָ������������ΪVFPTR

//void PrintVFT(VFPTR vft[])���·���Ч
void PrintVFT(VFPTR* vft)//���鲻�ܴ�����
{

}

int main()
{
    Base b;
    Child c;

    //ֻ���й���������֮����ܷ���ת��
    //�������Ϳ���ͨ�����캯��ת��Ϊ�Զ�������
    //int���ͺ�����ָ�����Ͷ����Է���ǿ��ת����char��float�Ȳ���
    //��ͬ���͵�ָ��֮����Է���ǿ������ת��������ת������ܻᵼ�º������ݵķ���


    //c���Զ������͵Ķ���&c���õ���������ĵ�ַ������Child*����Child*ǿ������ת��Ϊint*
    //��Ϊ����������Ҫ�ľ���c�����ǰ�ĸ��ֽڵĵ�ַ������x86������һ��int*ָ��Ĵ�С�����ֽ�
    //Ȼ���int*�����û�ȡ���ĸ��ֽڵ�����
    VFPTR* ptr = (VFPTR*)(*((int*)&c));

  



    ////���庯��ָ������ַ�ʽ
    //void (*p1)();

    //VFPTR p2;
    //
    ////���庯��ָ����������ַ�ʽ
    //void (*pa1[10])();

    //VFPTR pa2[10];
    return 0;
}
