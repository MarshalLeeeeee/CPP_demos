#include <iostream>
#include <cstring>
#include <fstream>
#define MAX 256

using namespace std;

int main()
{
    cout << "This program counts the words in a passage" << endl;

    int choice;
    char passage[MAX];
    char line[MAX];
    char *ptr;
    int count;

    cout << "1.from keyboard" << endl;
    cout << "2.from files" << endl;
    cout << "0.quit" << endl;
    cin >> choice;
    cin.sync();

    while(choice)
    {
        count = 0;
        passage[0] = 0;
        if(choice == 1)
        {
            cout << "PLease input the passage" << endl;
            cout << "Empty line to quit" << endl;
            cin.getline(line, MAX);
            while(line[0])
            {
                //cout << line << endl;
                strcat(passage, " ");
                strcat(passage, line);
                cin.getline(line, MAX);
            }
            cout << passage << endl;
            {
                ptr = strtok(passage, " \n\t");
                while(ptr)
                {
                    count++;
                    cout << ptr << endl;
                    ptr = strtok(NULL, " \n\t");
                }
                cout << "The number of words in passage is: " << count << endl;
            }
        }
        else
        {
            char file[MAX];
            cout << "Input the infile name" << endl;
            cin.getline(file, MAX);
            ifstream fin(file);
            int index;
            for(index = 0; index < MAX && fin.get(passage[index]); index++)
            {
                ;
            }
            ptr = strtok(passage, " \n\t");
            while(ptr)
            {
                count++;
                ptr = strtok(NULL, " \n\t");
            }
            cout << "The number of words in passage is: " << count << endl;
        }

        cout << "________________" << endl;
        cout << "1.from keyboard" << endl;
        cout << "2.from files" << endl;
        cout << "0.quit" << endl;
        cin >> choice;
        cin.sync();
    }

    cout << "Over" << endl;
    return 0;
}
