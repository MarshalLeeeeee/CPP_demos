#include <iostream>
#include <cstring>
#include <ctype.h>
#define NONSENSE_LEN 30
#define PUNC_LEN 30
#define SENTENCE_LEN 2000
#define KEYWORD_LEN 80

using namespace std;
void input_nonsense(char *, int);
void input_punc(char *, int);
int input_keyword(char (*)[KEYWORD_LEN]);
int input_sentence(char *, char *, int *, const char *, int);
void tolower_str(char *);
int modify_corresponding(int *, int, int, int);
int str_str(char *, char *);
void dashbar(void);

int main()
{
    char nonsense[NONSENSE_LEN];//save nonsense
    char punc[PUNC_LEN];//save punctuation
    char sentence[SENTENCE_LEN];//save the origin sentence
    char sentence_backup[SENTENCE_LEN];//save the modified sentence
    char tmp[SENTENCE_LEN];//work as the temptation char
    int corresponding[SENTENCE_LEN];//record the origin index of the characters in sentence_backup
    char (*keyword)[KEYWORD_LEN];//save keywords
    int pos;
    input_nonsense(nonsense, NONSENSE_LEN);
    input_punc(punc, PUNC_LEN);
    while(strcspn(punc, nonsense) != strlen(punc))
    {
        cout << "there should be no intersection between the above 2 sets" << endl;
        dashbar();
        input_nonsense(nonsense, NONSENSE_LEN);
        input_punc(punc, PUNC_LEN);
    }

    int keyword_number;
    int index;
    cout << "Input the number of the keywords: ";
    cin >> keyword_number;
    keyword = new char [keyword_number][KEYWORD_LEN];
    cin.sync();
    cout << "Input the keywords and one word one line: " << endl;
    for(index = 0; index < keyword_number; index++)
    {
        cin.getline(keyword[index], KEYWORD_LEN);
        tolower_str(keyword[index]);
    }

    int sentence_backup_len;
    sentence_backup_len = input_sentence(sentence, sentence_backup, corresponding, nonsense, SENTENCE_LEN);
    for(index = 0; index < keyword_number; index++)
    {
        while((pos = str_str(sentence_backup, keyword[index])) >= 0)
        {
            strcpy(tmp, sentence_backup + pos + strlen(keyword[index]));
            strcpy(sentence_backup + pos, tmp);
            strcpy(tmp, sentence + corresponding[pos + strlen(keyword[index]) - 1] + 1);
            strcpy(sentence + corresponding[pos], tmp);
            sentence_backup_len = modify_corresponding(corresponding, pos, strlen(keyword[index]), sentence_backup_len);
            cout << sentence << endl;
            cout << sentence_backup << endl;
        }
    }
    cout << sentence << endl;
    return 0;
}
void input_nonsense(char *nonsense, int n)
{
    char tmp;
    int index;
    cout << "please input the nonsense character: ";
    for(index = 0; index < n; )
    {
        nonsense[index] = 0;//ensure the char array is a string at any time
        cin.get(tmp);
        if(tmp == '\n')
        {
            cin.sync();
            break;
        }
        else if(!ispunct(tmp))
        {
            continue;
        }
        else
        {
            if(!strchr(nonsense, tmp))
                nonsense[index++] = tmp;
        }
    }
    nonsense[index] = 0;
}
void input_punc(char *punc, int n)
{
    char tmp;
    int index;
    cout << "please input the punctuation character: ";
    for(index = 0; index < n; )
    {
        punc[index] = 0;//ensure the char array is a string at any time
        cin.get(tmp);
        if(tmp == '\n')
        {
            cin.sync();
            break;
        }
        else if(!ispunct(tmp))
        {
            continue;
        }
        else
        {
            if(!strchr(punc, tmp))
                punc[index++] = tmp;
        }
    }
    punc[index] = 0;
}
int input_keyword(char (*keyword)[KEYWORD_LEN])
{
    int num;
    int index;
    cout << "Input the number of the keywords: ";
    cin >> num;
    keyword = new char [num][KEYWORD_LEN];
    cin.sync();
    cout << "Input the keywords and one word one line: " << endl;
    for(index = 0; index < num; index++)
    {
        cin.getline(keyword[index], KEYWORD_LEN);
        tolower_str(keyword[index]);
        cout << keyword[index] << endl;
    }
    return num;
}
int input_sentence(char *sentence, char *sentence_backup, int *corresponding, const char *nonsense, int n)
{
    char tmp;
    int index_sentence = 0, index_sentence_backup = 0, index_corresponding = 0;
    cout << "Input the sentence:" << endl;
    while(index_sentence < SENTENCE_LEN && index_sentence_backup < SENTENCE_LEN && (tmp = cin.get()) != '\n')
    {
        sentence[index_sentence++] = tmp;
        if(strchr(nonsense, tmp))
            continue;
        else
        {
            sentence_backup[index_sentence_backup++] = tmp;
            corresponding[index_corresponding++] = index_sentence - 1;
        }
    }
    sentence_backup[index_sentence_backup] = 0;
    sentence[index_sentence] = 0;
    tolower_str(sentence_backup);
    tolower_str(sentence);
    return index_sentence_backup;
}
void tolower_str(char *str)
{
    int index;
    for(index = 0; index < strlen(str) - 1; index++)
    {
        if(isalpha(str[index]))
        {
            str[index] = tolower(str[index]);
        }
    }
}
int modify_corresponding(int *corresponding, int pos, int len, int n)
{
    int index;
    int step = corresponding[pos + len - 1] - corresponding[pos] + 1;
    for(index = 0; index < n - len; index++)
    {
        if(index >= pos)
        {
            corresponding[index] = corresponding[index + len] - step;
        }
        cout << corresponding[index] << " ";
    }
    cout << endl;
    return n - len;
}
int str_str(char *str1, char str2[KEYWORD_LEN])
{
    int i, j;
    int flag;
    if(strlen(str1) < strlen(str2))
    {
        return -1;
    }
    for(i = 0; i < strlen(str1) - strlen(str2) + 1; i++)
    {
        for(j = 0, flag = 1; j < strlen(str2); j++)
        {
            if(str1[i+j] != str2[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            return i;
        }
    }
    return -1;
}
void dashbar(void)
{
    cout << "____________________________" << endl;
}
