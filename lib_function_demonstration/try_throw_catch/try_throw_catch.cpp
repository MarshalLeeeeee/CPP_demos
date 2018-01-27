#include <iostream>
#include <fstream>

using namespace std;

class up
{
    public:up(void){cout << "up" << endl;}
};
class down
{
    public:down(void){cout << "down" << endl;}
};

int f(int)throw(up,down);//in the declaration, we should show the thrown class explicitily
int ff(int);
int fff(int);

int main()
{
    fstream file;
    file.open("a.txt", ios::in);

    try
    {
        if(!file)
            throw int(1);//throw an object
        int x;
        file >> x;
        cout << x << endl;
    }
    catch(double y){cout << "Invalid file name_double" << endl;cout << y << endl;}//if catch an object, than in the current scope
                                                                                  //this object is initialized with the value of what is thrown out
    catch(int){cout << "Invalid file name_int" << endl;}

    cout << endl;
    int index;
    for(index = 1; index < 4; index++)
    {
        try{cout << f(index) << endl;}
        catch(up){cout << "up caught" << endl;}
        catch(down){cout << "down caught" << endl;}
    }
    //try and catch forever stay together in the same scope!!

    int tmp;
    try
    {
        tmp = ff(0);
    }
    catch(up){cout << "main catch" << endl;}
    //catch is implemanted according the sequence rather than the optimized choice
    //the exception go through every possible catch, and is caught at the first corresponded location
    //if fail to be caught, the program is aborted and no order after that try block will be implemented

    f(1);
    cout << 1 << endl;
    cout << 2 << endl;

    return 0;
}
int f(int x)throw(up,down)
{
    switch(x)
    {
        case 1:throw up();break;
        case 2:throw down();break;
        default:return 1;
    }
}
int fff(int x)
{
    if(!x) throw up();
    return x;
}
int ff(int x)
{
    try
    {
        return fff(x);
    }
    catch(int){cout << "ff catch" << endl;}
}
