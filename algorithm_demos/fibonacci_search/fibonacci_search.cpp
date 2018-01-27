#include <iostream>

using namespace std;

class matrix_2_2
{
    friend const matrix_2_2 operator*(const matrix_2_2 &, const matrix_2_2 &);
    private:
        int mat[2][2];
    public:
        matrix_2_2(void);
        matrix_2_2 &operator=(const matrix_2_2 &obj);
        void modify(int, int, int, int);
        int left_down(void);
};

matrix_2_2 matrix_2_2_pow(matrix_2_2, int);

int main()
{
    int n;
    cin >> n;
    matrix_2_2 mat, ans;
    mat.modify(1, 1, 1, 0);
    ans = matrix_2_2_pow(mat, n);
    cout << ans.left_down() << endl;
    return 0;
}
matrix_2_2::matrix_2_2(void)
{
    int i, j;
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            mat[i][j] = 0;
        }
    }
}
matrix_2_2 &matrix_2_2::operator=(const matrix_2_2 &obj)
{
    if(this == &obj) return *this;
    else
    {
        int i, j;
        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 2; j++)
            {
                mat[i][j] = obj.mat[i][j];
            }
        }
    }
    return *this;
}
const matrix_2_2 operator*(const matrix_2_2 &obj1, const matrix_2_2 &obj2)
{
    matrix_2_2 ans;
    ans.mat[0][0] = obj1.mat[0][0] * obj2.mat[0][0] + obj1.mat[0][1] * obj2.mat[1][0];
    ans.mat[0][1] = obj1.mat[0][0] * obj2.mat[0][1] + obj1.mat[0][1] * obj2.mat[1][1];
    ans.mat[1][0] = obj1.mat[1][0] * obj2.mat[0][0] + obj1.mat[1][1] * obj2.mat[1][0];
    ans.mat[1][1] = obj1.mat[1][0] * obj2.mat[0][1] + obj1.mat[1][1] * obj2.mat[1][1];
    return ans;
}
void matrix_2_2::modify(int v1, int v2, int v3, int v4)
{
    mat[0][0] = v1;
    mat[0][1] = v2;
    mat[1][0] = v3;
    mat[1][1] = v4;
}
matrix_2_2 matrix_2_2_pow(matrix_2_2 mat, int exp)
{
    matrix_2_2 ans;
    if(exp == 0)
    {
        ans.modify(1, 0, 0, 1);
        return ans;
    }
    else if(exp == 1)
    {
        ans.modify(1, 1, 1, 0);
        return ans;
    }
    else
    {
        return matrix_2_2_pow(mat, exp / 2) * matrix_2_2_pow(mat, exp - exp / 2);
    }
}
int matrix_2_2::left_down(void)
{
    return mat[1][0];
}
