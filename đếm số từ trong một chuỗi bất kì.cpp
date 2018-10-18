// ConsoleApplication24.cpp : Defines the entry point for the console application.
// Luyện Ngọc Thanh
// MSSV : 17110221
// Chương trình đếm số từ trong một chuỗi bất kì 

#include "stdafx.h"
#include <string.h>			
#include <ctype.h>			
#include <stdio.h>
#include <iostream>
#include <conio.h> 

using namespace std;
int main()
{
	char a[50];
	char t[50];
	int len;
	int i, j, dem;
	cout << "Nhap vao 1 chuoi ky tu :";
	cin.getline(a, 50);
	int kiemtra = 1;
	len = strlen(a);
	if (len > 0)
	{
		while (a[0] == ' ')
		{
			strcpy(&a[0], &a[1]);
		}
		while (a[len - 1] == ' ')
			strcpy(&a[len - 1], &a[len]);

		for (i = 0; i < len; i++)
			if ((a[i] == ' ') && (a[i + 1] == ' '))
			{
				strcpy(&a[i], &a[i + 1]);
				i--;
			}
		dem = 1;
		for (i = 0; i < len; i++)
			if (a[i] == ' ')
				dem++;
		cout << "So tu trong chuoi la : " << dem << endl;
	}
	else
		cout << "Chuoi khong ton tai ! " << endl;
	return 0;
}
