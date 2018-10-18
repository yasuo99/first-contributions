// Chương trình nhập và in kết quả học tập của nhiều sinh viên.
// 1. Luyện Ngọc Thanh MSSV : 17110221.
// 2. Nguyễn Thành Như MSSV : 17110202
// 3. Lê Minh Tiến MSSV : 17110235
// 4. Mai Kim Huy MSSV : 17110148
// 5. Ôn Đức Khang MSSV : 17110310
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define max 50
typedef struct monhoc
{
	char mamh[10];
	char tenmh[50];
	int sotc;
	float diem;
};
struct sinhvien
{
	char hoten[50];
	char mssv[10];
	int somon;
	int tongtc;
	int tongtctl;
	float dtbc;
	float dtbtl;
	float tongdiem;
	monhoc kq[max];
};
void nhapmh(monhoc &m);
void nhap(sinhvien sv[] , int n );
void xuat(sinhvien sv[], int n);

int main()
{
	sinhvien sv[10];
	int n;
	cout << "Nhap vao so luong sinh vien : ";
	cin >> n;
	nhap(sv, n);
	xuat(sv, n);
}
void xuat(sinhvien sv[], int n)
{
	int kt;
	int k;
	for (int i = 1; i<=n; i++)
	{
		cout << "Thong tin sinh vien thu " << i << " : " << endl;
		cout << "=======================================================" << endl;
		cout << "MSSV : " << sv[i].mssv << endl;
		cout << "Ho va ten : " << sv[i].hoten << endl;
		cout << "So mon hoc : " << sv[i].somon << endl;
		cout << "Tong TC : " << sv[i].tongtc << endl;
		cout << "Tong TCTL : " << sv[i].tongtctl << endl;
		cout << "Diem TBC : " << sv[i].dtbc << endl;
		cout << "Diem TBTL : " << sv[i].dtbtl << endl;
		cout << "=======================================================" << endl;
		cout << "======================================================" << endl;
		printf("%-10s %-20s %-10s %-10s\n", "Ma MH", "Ten MH", "So TC", "Diem");
		for (int j = 1; j < sv[i].somon + 1; j++)
			printf("%-10s %-20s %-10d %-10.2lf\n", sv[i].kq[j].mamh, sv[i].kq[j].tenmh, sv[i].kq[j].sotc, sv[i].kq[j].diem);
	}
	cout << "Ds sinh vien theo chieu giam dan cua diem tbc la : " << endl;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (sv[i].dtbc < sv[j].dtbc)
			{
				sinhvien s = sv[i];
				sv[i] = sv[j];
				sv[j] = s;
			}
		}
	for (int i = 1; i <= n; i++)
		cout << sv[i].hoten << endl;
	cout << "Ds sinh vien duoc hoc bong la : " << endl;
	for (int i = 1; i < n; i++)
	{
		kt = 1;
		if (sv[i].dtbc >= 7)
		{
			for (int j = 1; j <= sv[i].somon; j++)
			{
				if (sv[i].kq[j].diem < 5)
					kt = 0;
			}
		}
		if (kt == 1)
			cout << sv[i].hoten << endl;
	}
	cout << "Bang diem cua sinh vien co DTBC cao nhat lop la : ";
	cout << "======================================================" << endl;
	printf("%-10s %-20s %-10s %-10s\n", "Ma MH", "Ten MH", "So TC", "Diem");
	for (int j = 1; j < sv[1].somon + 1; j++)
		printf("%-10s %-20s %-10d %-10.2lf\n", sv[1].kq[j].mamh, sv[1].kq[j].tenmh, sv[1].kq[j].sotc, sv[1].kq[j].diem);
}
void nhap(sinhvien sv[], int n)
{
	for (int i = 1; i<=n; i++)
	{
		int tongtc = 0;
		int tongtctl = 0;
		int dem = 0;
		float diemtl = 0;
		float dtbc = 0;
		cout << "Nhap vao thong tin sinh vien thu " << i << endl;
		cin.ignore();
		cout << "Nhap vao ho ten sinh vien : ";
		cin.getline(sv[i].hoten, 50);
		fflush(stdin);
		cout << "Nhap vao MSSV : ";
		cin.getline(sv[i].mssv, 10);
		fflush(stdin);
		cout << "Nhap so mon cho sinh vien : ";
		cin >> sv[i].somon;
		for (int j = 1; j <= sv[i].somon; j++)
		{
			nhapmh(sv[i].kq[j]);
			tongtc += sv[i].kq[j].sotc;
			dem += 1;
			dtbc += sv[i].kq[j].diem;
			if (sv[i].kq[j].diem >= 5)
			{
				tongtctl += sv[i].kq[j].sotc;
				diemtl += sv[i].kq[j].sotc * sv[i].kq[j].diem;
			}
			sv[i].tongtc = tongtc;
			sv[i].tongtctl = tongtctl;
		}
		sv[i].dtbc = (float)dtbc / sv[i].somon;
		sv[i].dtbtl = (float)diemtl /sv[i].tongtctl;
	}
}
void nhapmh(monhoc &m)
{
	cin.ignore();
	cout << "Nhap ma mon hoc : ";
	cin.getline(m.mamh, 10);
	cout << "Nhap ten mon hoc : ";
	cin.getline(m.tenmh, 50);
	cout << "Nhap so tin chi mon hoc : ";
	cin >> m.sotc;
	cout << "Nhap diem mon hoc : ";
	cin >> (float)m.diem;
}