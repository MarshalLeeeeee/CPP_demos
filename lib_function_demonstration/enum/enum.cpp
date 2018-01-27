
#include <iostream>
#include <cstring>
#define LEN 30

using namespace std;

enum spectrum {red,orange,yellow,green,blue,violet};
const char *colors[] = {"red","orange","yellow","green","blue","violet"};//connect the index of their name in string form

int main()
{
    char choice[LEN];
    enum spectrum c;
    int color;

    cout << "Enter a color (Empty line to quit): " << endl;
    cin.getline(choice,LEN);
    while(!cin.fail() || choice[0] == '\0')
    {
        int color_is_found = 0;
        for(color = red; color <= violet; color++)
        {
            if(strcmp(choice,colors[color]) == 0)
            {
                color_is_found = 1;
                break;
            }
        }
        if(color_is_found)
        {
            switch(color)
            {
                case red: cout << "Roses are red." << endl; break;
                case orange: cout << "Poppies are orange" << endl; break;
                case yellow: cout << "Sunflowes are yellow" << endl; break;
                case green: cout << "Grass is green" << endl; break;
                case blue: cout << "Bluebells are blue" << endl; break;
                case violet: cout << "Violets are violet" << endl; break;
            }
        }
        else
        {
            cout << "I have no ideas" << endl;
        }
        cout << "Enter a color (Empty line to quit): " << endl;
        cin.getline(choice,LEN);
    }
    cout << "Goodbye" << endl;

    return 0;
}
