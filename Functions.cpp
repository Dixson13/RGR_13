#include <iostream>		// ������������ ���� ���������� ��� ������ � �������� �����-������ �������
#include <locale>		// ������������ ���� ���������� ��� ������ � ��������
#include <vector>		// ������������ ���� ���������� ��� ������ � ���������
#include <fstream>		// ������������ ���� ���������� ��� ������ � ��������� ��������
#include <sstream>		// ������������ ���� ���������� ��� ������ � ���������� ��������
#include <windows.h>	// ������������ ���� ���������� ��� ������ � WINAPI

#define CIN_FLUSH if (cin.peek()) cin.ignore() // ������ ������� ������ �����

using namespace std;	// ����������� ������������ ���� std

#include"GoodsReceipt.h"
#include"SalesGoods.h"
#include"WareHouse.h"
#include"CounterParty.h"
#include"Products.h"

void menu() {
	cout << "#########################################################" << endl;
	cout << "################# ���������� ���������� #################" << endl;
	cout << "#########################################################" << endl;
	cout << "###################- ���� ��������� -####################" << endl;
	cout << "#########################################################" << endl;
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "          |> 1.   ��������� ������ �� �����   |" << endl;
	cout << "          |> 2.   ��������� ������ � ����     |" << endl;
	cout << "          |> 3.   ����������� ��������        |" << endl;
	cout << "          |> 4.   �������� �������            |" << endl;
	cout << "          |> 5.   �������� �������            |" << endl;
	cout << "          |> 6.   ������� �������             |" << endl;
	cout << "          |> 7.   ������� ���� ������!        |" << endl;
	cout << "          |> 8.   ����� �������� �� �������   |" << endl;
	cout << "          |> 9.   ����� �������� �� �����     |" << endl;
	cout << "          |> 10.  ����� �������� �� ������    |" << endl;
	cout << "          |> 0.   ����� �� ���������          |" << endl;
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "\t       ������� ����� ����  > ";
}

vector <WareHouse> Storage;	// ������ ��� �������� ��������� (���������� �����)

// ������� ���������� ������ ��������
void addProduct() {
	system("cls"); // ������� �������

	string attr; // ���������� ��� ��������� ������ �������� �� �������
	WareHouse c;	// ������ ��� �������� ��������

	CIN_FLUSH; // ������� ������ �����

	cout << "����� ��������..." << endl << endl;
	cout << "����: "; getline(cin, attr);
	c.setDate(attr);
	cout << "�������: "; getline(cin, attr);
	c.setProduct(attr);
	cout << "����: "; getline(cin, attr);
	c.setPrice(attr);
	cout << "����������: "; getline(cin, attr);
	c.setAmount(attr);

	Storage.push_back(c);

	cout << endl << "�������� ��������� �������..." << endl << endl;
}

// ������� ������ ������ ��������� � �������
void printProduct() {
	system("cls"); // ������� �������

	int number = 0; // ���������� ��� ��������� ���������

	if(Storage.size()) { // ���� � ���. ����������� ���� ��������
		cout << "=========================================================" << endl;
		cout << "= �\t����\t\t�������\t\t����\t\t����������\t\t=" << endl;
		cout << "=========================================================" << endl;
		// ��������� �� ���� ��������� �� ����������� �����������
		for (WareHouse c : Storage) {
			cout << "= " << (++number) << ".\t";
			cout << c.getDate() << "\t";
			if(c.getDate().length() < 8) cout << "\t";
			cout << c.getProduct() << "\t";
			if(c.getProduct().length() < 8) cout << "\t";
			cout << c.getPrice() << "\t";
			if(c.getPrice().length() < 8) cout << "\t";
			cout << c.getAmount() << "\t";
			if(c.getAmount().length() < 8) cout << "\t";
			cout << "=" << endl;
		}

		cout << "=========================================================" << endl << endl;
	} else {
		cout << "�� ������ �����..." << endl;
	}
	cout << endl;
}
