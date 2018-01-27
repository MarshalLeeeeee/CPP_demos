#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

void CharacterToMorse(const char, char *);
void StringToMorse(const char *, char *);
char MorseToCharacter(const char *);
int MorseToString(const char *, char *);

void CharacterToMorse(const char ch, char * code)
{
    switch(ch)
    {
        case 'A': strcpy(code, ".- ");break;
        case 'B': strcpy(code, "-... ");break;
        case 'C': strcpy(code, "-.-. ");break;
        case 'D': strcpy(code, "-.. ");break;
        case 'E': strcpy(code, ". ");break;
        case 'F': strcpy(code, "..-. ");break;
        case 'G': strcpy(code, "--. ");break;
        case 'H': strcpy(code, ".... ");break;
        case 'I': strcpy(code, ".. ");break;
        case 'J': strcpy(code, ".--- ");break;
        case 'K': strcpy(code, "-.- ");break;
        case 'L': strcpy(code, ".-.. ");break;
        case 'M': strcpy(code, "-- ");break;
        case 'N': strcpy(code, "-. ");break;
        case 'O': strcpy(code, "--- ");break;
        case 'P': strcpy(code, ".--. ");break;
        case 'Q': strcpy(code, "--.- ");break;
        case 'R': strcpy(code, ".-. ");break;
        case 'S': strcpy(code, "... ");break;
        case 'T': strcpy(code, "- ");break;
        case 'U': strcpy(code, "..- ");break;
        case 'V': strcpy(code, "...- ");break;
        case 'W': strcpy(code, ".-- ");break;
        case 'X': strcpy(code, "-..- ");break;
        case 'Y': strcpy(code, "-.-- ");break;
        case 'Z': strcpy(code, "--.. ");break;
        case '1': strcpy(code, ".---- ");break;
        case '2': strcpy(code, "..--- ");break;
        case '3': strcpy(code, "...-- ");break;
        case '4': strcpy(code, "....- ");break;
        case '5': strcpy(code, "..... ");break;
        case '6': strcpy(code, "-.... ");break;
        case '7': strcpy(code, "--... ");break;
        case '8': strcpy(code, "---.. ");break;
        case '9': strcpy(code, "----. ");break;
        case '0': strcpy(code, "----- ");break;
        case ' ': strcpy(code, "  ");break;
    }
}
void StringToMorse(const char *str, char *code)
{
    int index;
    char unit[7];//考虑到最后的'\0'
    for(index = 0; index < strlen(str); index++)
    {
        if(isalpha(str[index]))
        {
            CharacterToMorse(toupper(str[index]), unit);
            strcat(code, unit);
        }
        else if(isdigit(str[index]))
        {
            CharacterToMorse(str[index], unit);
            strcat(code, unit);
        }
        else if(isblank(str[index]))
        {
            CharacterToMorse(' ', unit);
            strcat(code, unit);
        }
        else
        {
            continue;
        }
    }
}
char MorseToCharacter(const char *unit)
{
    if(!strcmp(unit, ".- "))
    {
        return 'A';
    }
    else if(!strcmp(unit, "-... "))
    {
        return 'B';
    }
    else if(!strcmp(unit, "-.-. "))
    {
        return 'C';
    }
    else if(!strcmp(unit, "-.. "))
    {
        return 'D';
    }
    else if(!strcmp(unit, ". "))
    {
        return 'E';
    }
    else if(!strcmp(unit, "..-. "))
    {
        return 'F';
    }
    else if(!strcmp(unit, "--. "))
    {
        return 'G';
    }
    else if(!strcmp(unit, ".... "))
    {
        return 'H';
    }
    else if(!strcmp(unit, ".. "))
    {
        return 'I';
    }
    else if(!strcmp(unit, ".--- "))
    {
        return 'J';
    }
    else if(!strcmp(unit, "-.- "))
    {
        return 'K';
    }
    else if(!strcmp(unit, ".-.. "))
    {
        return 'L';
    }
    else if(!strcmp(unit, "-- "))
    {
        return 'M';
    }
    else if(!strcmp(unit, "-. "))
    {
        return 'N';
    }
    else if(!strcmp(unit, "--- "))
    {
        return 'O';
    }
    else if(!strcmp(unit, ".--. "))
    {
        return 'P';
    }
    else if(!strcmp(unit, "--.- "))
    {
        return 'Q';
    }
    else if(!strcmp(unit, ".-. "))
    {
        return 'R';
    }
    else if(!strcmp(unit, "... "))
    {
        return 'S';
    }
    else if(!strcmp(unit, "- "))
    {
        return 'T';
    }
    else if(!strcmp(unit, "..- "))
    {
        return 'U';
    }
    else if(!strcmp(unit, "...- "))
    {
        return 'V';
    }
    else if(!strcmp(unit, ".-- "))
    {
        return 'W';
    }
    else if(!strcmp(unit, "-..- "))
    {
        return 'X';
    }
    else if(!strcmp(unit, "-.-- "))
    {
        return 'Y';
    }
    else if(!strcmp(unit, "--.. "))
    {
        return 'Z';
    }
    else if(!strcmp(unit, ".---- "))
    {
        return '1';
    }
    else if(!strcmp(unit, "..--- "))
    {
        return '2';
    }
    else if(!strcmp(unit, "...-- "))
    {
        return '3';
    }
    else if(!strcmp(unit, "....- "))
    {
        return '4';
    }
    else if(!strcmp(unit, "..... "))
    {
        return '5';
    }
    else if(!strcmp(unit, "-.... "))
    {
        return '6';
    }
    else if(!strcmp(unit, "--... "))
    {
        return '7';
    }
    else if(!strcmp(unit, "---.. "))
    {
        return '8';
    }
    else if(!strcmp(unit, "----. "))
    {
        return '9';
    }
    else if(!strcmp(unit, "----- "))
    {
        return '0';
    }
    else if(!strcmp(unit, "  "))
    {
        return ' ';
    }
    else
    {
        return -1;
    }
}
int MorseToString(const char *code, char *str)
{
    int len = strlen(code);
    int code_index, str_index = 0, unit_index = 0;
    char unit[7];
    for(code_index = 0; code_index < len; code_index++)
    {
        unit[unit_index] = code[code_index];
        if((code[code_index] != ' ' || unit_index == 0) && (code_index != len - 1))
        {
            unit_index++;
        }
        else if(code_index == len - 1)
        {
            unit[unit_index + 1] = ' ';
            unit[unit_index + 2] = '\0';
            if(MorseToCharacter(unit) == -1)
            {
                cout << "Error in decoding the morse code" << endl;
                cout << unit << " is invalid..." << endl;
                return 0;
            }
            else
            {
                str[str_index++] = MorseToCharacter(unit);
            }
        }
        else
        {
            unit[unit_index + 1] = '\0';
            unit_index = 0;
            if(MorseToCharacter(unit) == -1)
            {
                cout << "Error in decoding the morse code" << endl;
                cout << unit << " is invalid..." << endl;
                return 0;
            }
            else
            {
                str[str_index++] = MorseToCharacter(unit);
            }
        }
    }
    str[str_index] = '\0';
    return 1;
}

