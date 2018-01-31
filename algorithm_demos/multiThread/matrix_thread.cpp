// matrix_thread3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int ** matrixa, **matrixb, **matrixc;
int ax, ay, bx, by;
HANDLE *calc_thread;
int *xx;

DWORD WINAPI calc(LPVOID Param)
{
	int x = *(int *)Param;
	for (int i = 0; i < by; i++)
	{
		matrixc[x][i] = 0;
		for (int index = 0; index < ay; index++)
		{
			matrixc[x][i] += matrixa[x][index] * matrixb[index][i];
		}
	}
	return 0;
}

int main(void)
{
	DWORD TimeStart = GetTickCount();
	ifstream fin("read.txt");
	ofstream fout("out.txt");
	srand((unsigned int)time(NULL));
	fin >> ax >> ay >> bx >> by;
	matrixa = new int *[ax]; for (int index = 0; index < ax; index++) matrixa[index] = new int[ay];
	matrixb = new int *[bx]; for (int index = 0; index < bx; index++) matrixb[index] = new int[by];
	matrixc = new int *[ax]; for (int index = 0; index < ax; index++) matrixc[index] = new int[by];
	calc_thread = new HANDLE[ax]; int thread_cnt = 0;
	xx = new int[ax]; for (int index = 0; index < ax; index++) xx[index] = index;
	for (int index1 = 0; index1 < ax; index1++)// initialize matrixa
	{
		for (int index2 = 0; index2 < ay; index2++)
		{
			matrixa[index1][index2] = rand();
			//fin >> matrixa[index1][index2];
		}
	}
	for (int index1 = 0; index1 < bx; index1++)// initialize matrixb
	{
		for (int index2 = 0; index2 < by; index2++)
		{
			matrixb[index1][index2] = rand();
			//fin >> matrixb[index1][index2];
		}
	}
	for (int index = 0; index < ax; index++)
	{
		calc_thread[thread_cnt++] = CreateThread(NULL, 0, calc, xx+index, 0, NULL);
	}
	WaitForMultipleObjects(ax, calc_thread, TRUE, INFINITE);
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

