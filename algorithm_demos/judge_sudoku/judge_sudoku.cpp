#include <iostream>
#include <fstream>
using namespace std;
int gameMap[9][9];
int counttt = 0;
bool check_vaild_3x3(int x,int y, int v)
{
    for(int i = 0 ; i < 9; ++ i)
    if(gameMap[x][i] == v || gameMap[i][y] == v) return false;
    int row = x/3*3, col = y/3*3;
    for(int i = 0; i < 3; ++ i)
    {
        for(int j = 0 ; j < 3; ++ j)
        {
            if(gameMap[row+i][col+j] == v) return false;
        }
    }
    return true;
}
bool exam_sudoku(int (*arr)[9])
{
    int i, j;
    int tmp;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(arr[i][j])
            {
                tmp = arr[i][j];
                arr[i][j] = 0;
                if(!check_vaild_3x3(i, j, tmp))
                {
                    return 0;
                }
                arr[i][j] = tmp;
            }
        }
    }
    return 1;
}
void print_game()
{
    for(int i = 0; i < 9; ++ i)
    {
        for(int  j = 0; j < 9 ; ++j)
        {
            cout<<gameMap[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void fill_0(int (*arr)[9])
{
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            arr[i][j] = 0;
        }
    }
}
void dfs(int x,int y)
{
    if(counttt == 2) return ;
    if(x == 9 && y == 0)
    {
        counttt++;
        //print_game();
        return;
    }
    if(y == 9) dfs(x+1,0);
    if(gameMap[x][y])
    {
        if(0 < gameMap[x][y] && gameMap[x][y] < 10) dfs(x,y+1);
        else counttt = 2;
    }
    else
    {
        for(int i = 1; i <= 9; ++i)
        {
            if(check_vaild_3x3(x,y,i))
            {
                gameMap[x][y] = i;
                dfs(x,y+1);
                gameMap[x][y] = 0;
            }
        }
    }
}
int main()
{
    ifstream in("read.txt");
    int n;
    in >> n;
    while(n--)
    {
        fill_0(gameMap);
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                in >> gameMap[i][j];
            }
        }
        if(exam_sudoku(gameMap))
        {
            dfs(0,0);
            if(n >= 1)
            {
                if(counttt == 1) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
            else
            {
                if(counttt == 1) cout << "Yes";
                else cout << "No";
            }
            counttt = 0;
        }
        else cout << "No" << endl;

    }
    return 0;
}
