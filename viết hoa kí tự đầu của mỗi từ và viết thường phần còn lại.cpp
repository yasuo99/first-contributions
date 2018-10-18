// ConsoleApplication25.cpp : Defines the entry point for the console application.
// Luyện Ngọc Thanh
// MSSV : 17110221
// Chương trình viết hoa ký tự đầu mỗi từ, viết thường các ký tự còn lại

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
	int i, j, vt;
	cout << "Nhap vao 1 chuoi ky tu :";
	cin.getline(a, 50);
	int kiemtra = 1;
	len = strlen(a);
	if (len > 0)
	{
		a[0] = toupper(a[0]);
		for (i = 0; i < len; i++)
			if (a[i] == ' ' && a[i + 1] != ' ')
				a[i + 1] = toupper(a[i + 1]);
		cout << a << endl;
	}
	else
		cout << "Chuoi khong ton tai ! " << endl;
    return 0;
}

