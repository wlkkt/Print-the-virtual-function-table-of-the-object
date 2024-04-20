#include <iostream>
using namespace std;

class Base {
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }
private:
    int a = 1;
};

class Child :public Base {
public:
    virtual void func1() { cout << "Derive::func1" << endl; }
    virtual void func3() { cout << "Derive::func3" << endl; }
    virtual void func4() { cout << "Derive::func4" << endl; }
private:
    int b = 2;
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
        printf("%p->", vft[i]);//��ʮ�����Ƶ���ʽ��ӡ�麯���ĵ�ַ

        VFPTR pf = vft[i];
        (*pf)();//���ú���ָ��
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
