#include <iostream>

using namespace std;

class A
{
    private:
        int aa;
    public:
        A(void){aa = 1;}
        virtual void f1(void){cout << "f1 in A" << endl;}
        void f2(void){cout << "f2 in A" << endl;}
        void f3(void){cout << "f3 in A" << endl;}
        static int aaa;
};
int A::aaa = 1;
class B:public A
{
    private:
        int bb;
    public:
        B(void){bb = 1;}
        void f1(void){cout << "f1 in B" << endl;}
        virtual void f2(void){cout << "f2 in B" << endl;}
        void f3(void){cout << "f3 in B" << endl;}
        static int bbb;
};
int B::bbb = 2;
class C:public B
{
    private:
        int cc;
    public:
        C(void){cc = 1;}
        virtual void f1(void){cout << "f1 in C" << endl;}
        virtual void f2(void){cout << "f2 in C" << endl;}
        virtual void f3(void){cout << "f3 in C" << endl;}
        static int ccc;
};
int C::ccc = 3;

void fff(const int *);

int main(void)
{
    A a;
    B b;
    C c;
    A *obja0 = &a;//a point to itself
    A *obja = &b;//a point to its son
    A *obja2 = &c;//a point to its grandson
    B *objb = &c;//b point to its son
    C *objc = &c;//c point to itself
    obja->f1();
    obja->f2();
    obja->f3();
    cout << endl;
    obja2->f1();
    obja2->f2();
    obja2->f3();
    cout << endl;
    objb->f1();
    objb->f2();
    objb->f3();
    cout << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << endl;
    return 0;
}
