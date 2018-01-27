#include <iostream>

using namespace std;

//template <class T> class Tarray;
//template <class TT> ostream &operator<<(ostream &, const Tarray<TT> &);
//template <class TT> istream &operator<<(istream &, Tarray<TT> &);

template <class T>
class Tarray
{
    template <class TT> friend ostream &operator<<(ostream &, const Tarray<TT> &);
    template <class TT> friend istream &operator>>(istream &, Tarray<TT> &);

    private:
        T *ptr;
        int len;
        void order(void);
    public:
        Tarray(int = 100);
        ~Tarray(void);
        T operator[](int);

};

int main()
{
    Tarray<int> x(10);
    cin >> x;
    cout << x;
    return 0;
}
template <class T>
Tarray<T>::Tarray(int x)
{
    len  = x;
    ptr = new T[len];
}
template <class T>
Tarray<T>::~Taaray(void)
{
    delete []ptr;
}
template <class T>
T Tarray<T>::operator[](int index)
{
    return ptr[index];
}
template <class T>
void Tarray<T>::order(void)
{
    T tmp;
    int index1, index2;
    for(index1 = 0; index1 < len; index1++)
    {
        for(index2 = index1 + 1; index2 < len; index2++)
        {
            if(ptr[index2] < ptr[index1])
            {
                tmp = ptr[index2];
                ptr[index2] = ptr[index1];
                ptr[index1] = tmp;
            }
        }
    }
}
template <class T>
ostream &operator<<(ostream &os, const Tarray<T> &p)
{
    int index;
    for(index = 0; index < p.len; index++)
    {
        os << p.ptr[index] << '\t';
    }
    return os;
}
template <class T>
istream &operator>>(istream &is, Tarray<T> &p)
{
    int index;
    for(index = 0; index < p.len; index++)
    {
        is >> p.ptr[index];
    }
    p.order();
    return is;
}



