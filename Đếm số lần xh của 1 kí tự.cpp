// ConsoleApplication23.cpp : Defines the entry point for the console application.
// Luyện Ngọc Thanh
// MSSV : 17110221
// Chương trình đếm số lần xuất hiện của kí tự ch

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
	int len;
	int i, j, dem;
	cout << "Nhap vao 1 chuoi ky tu :";
	cin.getline(a, 50);
	int kiemtra = 1;
	len = strlen(a);
	if (len > 0)
	{
		dem = 0;
		for (i = 0; i < len; i++)
			if (a[i] == 'c' && a[i + 1] == 'h')
				dem++;
		cout << "So lan xuat hien cua ki tu ch la : " << dem << endl;
	}
	else
		cout << "Chuoi khong ton tai ! " << endl;
	return 0;
}

