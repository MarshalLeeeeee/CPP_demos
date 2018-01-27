#include <iostream>
#include <cstring>

using namespace std;

void dashbar(void);

int main()
{
    char s1[81] = "lsadkcfoiewpmcqwf";
    char s2[81] = "abcde";
    char s3[81];
    char s4[81];
    char s5[81] = "abcde";
    char s6[81] = "abcdefg";
    char s7[81] = "cde";
    char s8[81] = "This is a test#program.";
    char s9[81] = "abcdefghijklmn";
    char s10[81];
    char ch = 'c';

    //strlen
    cout << strlen(s1) << endl;//the length of s1
    dashbar();

    //strcpy
    cout << strcpy(s4, s2) << endl;//copy from s2 to the start of s4, print from the start of s4
    cout << strcpy(s4 + 1, s2) << endl;//copy from s2 to the second character of s4, print from the second character of s4
    cout << s4 << endl;//print full s4
    cout << strcpy(s9, "cd") << endl;//if the latter string is shorter thaan the former one, the rest characters are discarded by \0
    dashbar();

    //strncpy
    cout << strncpy(s3, s1, 10) << endl;//copy 10 characters from s1 to the start of s3, print from the start of s3
                                        //strncpy() will not add \0 automatically.
    cout << strncpy(s3+8, s1, 5) << endl;//copy from 5 characters of s1 to the nineth character of s3, print from the ninth character of s3
                                         //error! because if strlen(s3+8) < 5, \0 will not be added.
    s3[10] = 0;//eliminate the error
    cout << s3 << endl;
    dashbar();

    //strcat
    cout << strcat(s4, s3) << endl;//add s3 to the end of s4
    cout << strcat(s4+strlen(s4), s3) << endl;//the working principle of the function is to find the first \0
    cout << s4 << endl;
    cout << strcat(s10, s8) << endl;//maybe it is not safe, kuz strcat will find the nearest \0
    dashbar();

    //strncat
    cout << strncat(s4, s3, 3) << endl;//add 3 characters of s3 to the end of s4
    dashbar();

    //strcmp
    cout << strcmp(s2, s5) << endl;//compare s2 and s5, if totally same, return 0, or, return a positive or nagetive number
    cout << strcmp(s2+1, s5) << endl;//compare from the second character of s2 and s5, if totally same, return 0, or, return 1
    cout << strcmp(s2, strcat(s5, "a")) << endl;//compare s2 and s5, if totally same, return 0, or, return a positive or nagetive number
                                        //if the first str is smaller than the second one(in ASCII), return -1(in CodeBlocks10.05)
                                        //if the first str is bigger than the second one(in ASCII), return 1(in CodeBlocks10.05)
    dashbar();

    //strncmp
    cout << strncmp(s2, s5, 5) << endl;//compare the first 5 characters of s1 and s2
    dashbar();

    //strchr
    //it seems that it can only be used when str is const
    cout << strchr(s5, 'a') << endl;//return the position of the first 'a'
    cout << strchr(s5, 'b') << endl;//return the position of the first 'b'
    cout << strchr(s5, 'c') - s5 << endl;//return the index of the first 'c'
    cout << !strchr(s5, 'z') << endl;//if failing to find, return NULL
    dashbar();

    //strrchr
    cout << strrchr(s1, 'c') << endl;//return the last position of 'c' in s1
    cout << strrchr(s1, 'c') - s1 << endl;//return the index of the last 'c' in s1
    dashbar();

    //strcspn
    cout << strcspn(s1, s2) << endl;//return the length of the start string of s1 which dont have any character in s2, in this example is "ls", and return 2
    cout << strcspn(s2, s1) << endl;//if the first character of the first is in the latter one, return 0
    dashbar();

    //strspn
    cout << strspn(s1, s2) << endl;//if the first character of the first string is not in the latter one, return 0
    cout << strspn(s5, s2) << endl;//return the length of the start string of s5 which contains all characters in s2
    cout << strspn(s4, s3) << endl;//in this examaple, s4 is "aab...", and no b in s3, so return 2
    dashbar();

    //strpbrk
    cout << strpbrk(s5, s6) << endl;//return the position of the character whichever in s6 that first appears from the start of s5
    cout << strpbrk(s1, s5) - s1 << endl;//return the index of the character whichever in s5 that first appears from the start of s1
    cout << !strpbrk(s7, "ab") << endl;//if all characters in the latter string doesn't appear in the s7, return NULL
    dashbar();

    //strstr
    cout << strstr(s6, s7) << endl;//return the position of which first contain the entire s7 in s6
    cout << strstr(s5, s7) - s5 << endl;//return the index
    cout << !strstr(s5, s6) << endl;//if fail, return NULL
    dashbar();

    //strtok
    char *ptr;
    cout << s8 << endl;
    ptr = strtok(s8, " #");//seperate s8 into a turple by the character in the latter string
    while(ptr)
    {
        cout << ptr << endl;
        ptr = strtok(NULL, " #");//point to the next turple
                                 //if find it, return the address(not NULL), otherwise, return NULL
    }
    cout << "*****" << endl;
    cout << s8 << endl;//here, we can see how the function works
    cout << s8 + strlen(s8) + 1 << endl;//the function modify the string in the way that substitude \0 for the initial character
                                        //so, the string is not protected and if necessary, please make the copy
    dashbar();

    return 0;
}
void dashbar(void)
{
    cout << "________________________________________________" << endl;
}
