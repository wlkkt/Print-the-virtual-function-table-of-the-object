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
//�麯����ָ��->�麯����{�麯��1�ĵ�ַ���麯��2�ĵ�ַ...}

typedef void(*VFPTR)();//Ϊ����ָ������������ΪVFPTR


//void PrintVFT(VFPTR vft[])���·���Ч
void PrintVFT(VFPTR* vft)//���鲻�ܴ�����
{
    for (size_t i = 0; i < 4; i++)
    {
        printf("%p\n", vft[i]);//��ʮ�����Ƶ���ʽ��ӡ�麯���ĵ�ַ
    }
}

int main()
{
    Base b;
    Child c;

    //ֻ���й���������֮�����ֱ�ӷ���ǿ������ת��
    //�������Ϳ���ͨ�����캯��ת��Ϊ�Զ�������
    //int���ͺ�����ָ�����Ͷ����Է���ǿ��ת����char��float�Ȳ���
    //��ͬ���͵�ָ��֮����Է���ǿ������ת��������ת������ܻᵼ�º������ݵķ���


    //�Զ������͵Ķ�����ֱ��ǿתΪ�������ͣ�(int)c����
    //����ͨ�����ǿ������ת���õ����ĵ�ַ��

    //c���Զ������͵Ķ���&c���øö���ĵ�ַ������Child*����Child*ǿ������ת��Ϊint*
    //��Ϊ����������Ҫ�ľ���c�����ǰ�ĸ��ֽڵĵ�ַ������x86������һ��ָ��Ĵ�С�����ֽ�
    //Ȼ���int*���͵ĵ�ַ���н����û�ȡ���ĸ��ֽڵ�����ֵint
    //���intǿתVFPTR*

    VFPTR* ptr = (VFPTR*)(*((int*)&c));
    PrintVFT(ptr);
  

    ////���庯��ָ������ַ�ʽ
    //void (*p1)();

    //VFPTR p2;
    //
    ////���庯��ָ����������ַ�ʽ
    //void (*pa1[10])();

    //VFPTR pa2[10];
    return 0;
}
