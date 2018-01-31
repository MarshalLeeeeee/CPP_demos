// matrix_regular.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(void)
{
	DWORD TimeStart = GetTickCount();
	//ifstream fin("read.txt");
	ifstream fin("read.txt");
	ofstream fout("out.txt");
	srand((unsigned int)time(NULL));
	int ax, ay, bx, by;
	fin >> ax >> ay >> bx >> by;
	int **matrixa, **matrixb, **matrixc;
	matrixa = new int *[ax];for (int index = 0; index < ax; index++) matrixa[index] = new int[ay];
	matrixb = new int *[bx];for (int index = 0; index < bx; index++) matrixb[index] = new int[by];
	matrixc = new int *[ax];for (int index = 0; index < ax; index++) matrixc[index] = new int[by];
	for (int index1 = 0; index1 < ax; index1++)
	{
		for (int index2 = 0; index2 < ay; index2++)
		{
			matrixa[index1][index2] = rand();
			//fin >> matrixa[index1][index2];
		}
	}
	for (int index1 = 0; index1 < bx; index1++)
	{
		for (int index2 = 0; index2 < by; index2++)
		{
			matrixb[index1][index2] = rand();
			//fin >> matrixb[index1][index2];
		}
	}
	for (int index1 = 0; index1 < ax; index1++)
	{
		for (int index2 = 0; index2 < by; index2++)
		{ 
			matrixc[index1][index2] = 0;
			for (int index3 = 0; index3 < ay; index3++)
			{
				matrixc[index1][index2] += matrixa[index1][index3] * matrixb[index3][index2];
			}
			//cout << index1 << ' ' << index2 << ' ' << matrixc[index1][index2];
		}
	}
	for (int index1 = 0; index1 < ax; index1++)
	{
		for (int index2 = 0; index2 < by; index2++)
		{
			fout << matrixc[index1][index2] << ' ';
		}
		fout << '\n';
	}
	DWORD TimeEnd = GetTickCount();
	cout << "run time: " << TimeEnd - TimeStart << "ns\n";
	system("pause");
	return 0;
}

