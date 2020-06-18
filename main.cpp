#include <iostream>		    // ������������ ���� ���������� ��� ������ � �������� �����-������ �������.
#include <locale>		    // ������������ ���� ����������� ���������� ����� ���������������� �, ������� ������������ ��� �����, ��������� � ������������.
#include <vector>		    // ������������ ���� ���������� ��� ������ � ���������: ����������� ������ ����������� ���������������� ����� C++ std::vector<T> � ���������� ������������� �������.
#include <fstream>		    // ������������ ���� ���������� ��� ������ � ��������� ��������.
#include <sstream>		    // ������������ ���� ���������� ��� ������ � ���������� ��������.
#include <windows.h>	    // ������������ ���� ���������� ��� ������ � WINAPI.

#define CIN_FLUSH if (cin.peek()) cin.ignore()  // ������ ������� ������ �����.

using namespace std;	                        //������������ ����������� ���.

#include"GoodsReceipt.h"                        //������ � �������� � �����������, ������� �� ������� ��� ������ � ����.
#include"SalesGoods.h"
#include"WareHouse.h"
#include"CounterParty.h"
#include"Products.h"

void menu() {                                   //���������� �������� ���� ���������.
	cout << "#########################################################################################" << endl;
	cout << "################################## ��������� ���������� #################################" << endl;
	cout << "#########################################################################################" << endl;
	cout << "##################################### ���� ��������� ####################################" << endl;
	cout << "#########################################################################################" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~ ����� ~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      |> 1.   ����������� ������                |" << endl;
	cout << "                      |> 2.   ���������� �����                  |" << endl;
	cout << "                      |> 3.   ��������� ������ �� ������        |" << endl;
	cout << "                      |> 4.   ������� ����������� �����        |" << endl;
	cout << "                      |> 5.   �������� �����                    |" << endl;
	cout << "                      |> 6.   ����� ������ �� ����              |" << endl;
	cout << "                      |> 7.   ����� ������ �� ��������          |" << endl;
	cout << "                      |> 8.   ����� ������ �� ����              |" << endl;
	cout << "                      |> 9.   ����� ������ �� ����������        |" << endl;
    cout << "                      |> 10.  ��������� ������ �� �����         |" << endl;
    cout << "                      |> 11.  ��������� ������ � ����           |" << endl;
    cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~ ������ ����� ������ ~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      |> 12.  ������� ������                    |" << endl;
	cout << "                      |> 13.  ������ ������                     |" << endl;
	cout << "                      |> 14.  ������������� ������ ������       |" << endl;
	cout << "                      |> 15.  ��������� ��������� �����         |" << endl;
	cout << "                      |> 16.  �������� ������ ������            |" << endl;
	cout << "                      |> 17.  ����� ������ ������ �� ����       |" << endl;
	cout << "                      |> 18.  ����� ������ ������ �� ��������   |" << endl;
	cout << "                      |> 19.  ����� ������ ������ �� ����       |" << endl;
    cout << "                      |> 20.  ����� ������ ������ �� �����      |" << endl;
	cout << "                      |> 21.  ����� ������ ������ �� ���������� |" << endl;
	cout << "                      |> 22.  ��������� ������ �� �����         |" << endl;
	cout << "                      |> 23.  ��������� ������ � ����           |" << endl;
    cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      |> 0.   ����� �� ���������                |" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "                                    ������� ����� ����  > ";
}

vector <WareHouse> Storage;	                    //�������� ������� ��� �������� ������� �� ������.
vector <Products> Sales;                        //�������� ������� ��� �������� ��������� �������.

void addProduct()                               //������� ��������� �� ����� ����� �����.
{
	system("cls");                              //������� �������.
	string x;                                //���������� ��� ��������� ������ � ������ �� �������.
	WareHouse c;	                            //������ ��� �������� ������ ������.
	CIN_FLUSH;                                  //������� ������ �����.
	cout << "����� ��������..." << endl << endl;
	cout << "����: "; getline(cin, x);
	c.setDate(x);
	cout << "�����: "; getline(cin, x);
	c.setProduct(x);
	cout << "����: "; getline(cin, x);
	c.setPrice(x);
	cout << "����������: "; getline(cin, x);
	c.setAmount(x);
	Storage.push_back(c);
	cout << endl << "�������� ��������� �������..." << endl << endl;
}

void printProduct()                             //������� ������ ������ ���� ������� �� ������.
{
	system("cls");
	int num = 0;                             //���������� ��� ��������� ���������.
	if(Storage.size())                          //�������, ������������, ���� �� �� ������ ������.
    {
		cout << "=========================================================================================" << endl;
		cout << "= �\t����\t\t�������\t\t����\t\t����������\t=================" << endl;
		cout << "=========================================================================================" << endl;
		for (WareHouse c : Storage)             //��������� ����� "���", �������� �� ��� ������� �� ������.
        {
			cout << "= " << (++num) << ".\t";
			cout << c.getDate() << "\t";
			if(c.getDate().length() < 8) cout << "\t";
			cout << c.getProduct() << "\t";
			if(c.getProduct().length() < 8) cout << "\t";
			cout << c.getPrice() << "\t";
			if(c.getPrice().length() < 8) cout << "\t";
			cout << c.getAmount() << "\t";
			if(c.getAmount().length() < 8) cout << "\t";
			cout << "=================" << endl;
		}
		cout << "=========================================================================================" << endl << endl;
	}
	else
	{
		cout << "�� ������ �����..." << endl;
	}
	cout << endl;
}

void fixProduct()                               //������� ����������� ���������� � ������� �� ������.
{
	system("cls");
	int num;                                    //������������� ����� �� ������.
	WareHouse c;
	string x;
	if(Storage.size())
    {
		printProduct();
		cout << "������� ����� ������, ������� ������ ���������������: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Storage.size())    //������� ����������� ������.
		{
			CIN_FLUSH;
			cout << "����: "; getline(cin, x);
			c.setDate(x);
			cout << "�����: "; getline(cin, x);
			c.setProduct(x);
			cout << "����: "; getline(cin, x);
			c.setPrice(x);
			cout << "����������: "; getline(cin, x);
			c.setAmount(x);
			Storage[num - 1] = c;
			cout << endl << "����� ��� �������..." << endl << endl;
		}
        else
        {
			cout << "������ ������������ ����� ������..." << endl << endl;
		}
	}
	else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void deleteProduct()                            //������� ������� ��������� ����� �� ������.
{
	system("cls");
	int num;
	if(Storage.size())
    {
		printProduct();
		cout << "������� ����� ������, ������� ������ �������: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Storage.size())
		{
            auto first = Storage.cbegin();      // ��������� �� ������ �������.
			Storage.erase(first + num - 1);     // ��������� ����� � ������� num �� ������.
			cout << "����� ��� �����..." << endl << endl;
		}
        else
        {
			cout << "����� ������������ ����� ������..." << endl << endl;
		}
	}
	else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void deleteAllProduct()                         //������� ������ ������� ������� �� ������.
{
	system("cls");
	if(Storage.size())
    {
		Storage.clear();                        //�������� ������ �������.
		cout << "��� ������ ���� ������� �� ������..." << endl << endl;
	}
	else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void searchProductDate()                        //������� ������ ������ �� ������ �� ����.
{
	system("cls");
	string date;                                //���������� ��� ����� ����.
	bool match = false;                         //����������, ������������ ������� �� ������ ������ �� ������.
	int num;	                                //���������� ��� ��������� ��������� ������� �� ������.
	if(Storage.size())
    {
		CIN_FLUSH;
		cout << "������� ���� ������ ��� ������: ";
		getline(cin, date);
		cout << endl << "����������:" << endl;
		for (WareHouse c : Storage)
		{
			if (c.getDate().find(date) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getAmount() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
    else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void searchProducts()                           //������� ������ ������ �� ������ �� ��������.
{
	system("cls");
	string product;
	bool match = false;
	int num;
	if(Storage.size())
    {
		CIN_FLUSH;
		cout << "������� �������� ������ ��� ������: ";
		getline(cin, product);
		cout << endl << "����������:" << endl;
		for (WareHouse c : Storage)
		{
			if (c.getProduct().find(product) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getAmount() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void searchProductPrice()                       //������� ������ ������ �� ������ �� ����.
{
	system("cls");
	string price;
	bool match = false;
	int number;
	if(Storage.size())
    {
		CIN_FLUSH; // ������� ������ �����
		cout << "������� �������� ������ ��� ������: ";
		getline(cin, price);
		cout << endl << "����������:" << endl;
		for (WareHouse c : Storage)
		{
			if (c.getPrice().find(price) != string::npos)
			{
				match = true;
				cout << (++number) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getAmount() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void searchProductAmount()                      //������� ������ ������ �� ������ �� ��� ����������.
{
	system("cls");
	string amount;
	bool match = false;
	int number;
	if(Storage.size())
    {
		CIN_FLUSH;
		cout << "������� �������� ������ ��� ������: ";
		getline(cin, amount);
		cout << endl << "����������:" << endl;
		for (WareHouse c : Storage)
		{
			if (c.getAmount().find(amount) != string::npos)
			{
				match = true;
				cout << (++number) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getAmount() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "�� ������ ��� �� ������ ������..." << endl << endl;
	}
}

void getProductFromFile()                       //������� ��� ������ ������ �� �����.
{
	system("cls");
	Storage.clear();
	ifstream fin("Storage.txt"); 	            //��������� ���� ������ ������� �� ������ ��� ������.
	string line;					            //������ ��� ���������� ��������� �� �����.
	WareHouse c; 				                //������ ��� ������ � ���� ������ �� ������.
	string x;					                //���������� ��� ��������� ������ ������ �� ����������� ������.
	if(!fin.is_open())
    {
		cerr << "������: �� ������� ������� ���� ��� ��������� ���������� � �������..." << endl;
		exit(EXIT_FAILURE);                     //���������� ��������� � �������.
	}
	else
    {
		while(getline(fin, line))               //������ �� ������ ������.
		{
			stringstream ss(line);	            //������ �� ������ ��������� �����.
			ss >> x; c.setDate(x);              //��������� �� ���������� ������ ������ � ������.
			ss >> x; c.setProduct(x);
			ss >> x; c.setPrice(x);
			ss >> x; c.setAmount(x);
			Storage.push_back(c);               //���������� ������ � ��������� ����������.
		}
		fin.close();                            //�������� �����.
		cout << "������ ���� ��������� �� �����..." << endl << endl;
	}
}

void writeProductInFile()                       //������� ��� ������ ������ � ����.
{
	system("cls");
	ofstream fout("Storage.txt");	            //��������� ���� ������ ������� �� ������ �� ������.
	string product;	                            //���������� ��� ������ ������ �� ������.
	if(!fout.is_open())
    {
		cerr << "������: �� ������� ������� ���� ��� ���������� ���������� � �������..." << endl;
		exit(EXIT_FAILURE);                     //���������� ��������� � �������.
	}
	else
    {
		for(WareHouse c : Storage)              //�������� �� ���� ��������� �� ���������� ����������.
		{
			product = c.getDate();              //��������� ������ ������ �� ������.
			product += " ";
			product += c.getProduct();
			product += " ";
			product += c.getPrice();
            product += " ";
			product += c.getAmount();
			fout << product << endl;            //���������� ������ � ����.
		}
		fout.close();                           //�������� �����.
		cout << "������ ���� ��������� � ����..." << endl << endl;
	}
}
                                                //����� ��� ����������� ��������, ������� ����� ��������.
void addProductSale()
{
    system("cls");
	string x;
	Products c;
	CIN_FLUSH;
	cout << "����������� ���������..." << endl << endl;
	cout << "����: "; getline(cin, x);
	c.setDate(x);
	cout << "�����: "; getline(cin, x);
	c.setProduct(x);
	cout << "����: "; getline(cin, x);
	c.setPrice(x);
	cout << "�����: "; getline(cin, x);
	c.setFirm(x);
	cout << "����������: "; getline(cin, x);
	c.setSale(x);
	Sales.push_back(c);
	cout << endl << "��������� ������� �������..." << endl << endl;
}

void printProductSale()
{
	system("cls");
	int num = 0;
	if(Sales.size())
        {
		cout << "=========================================================================================" << endl;
		cout << "= �\t����\t\t�������\t\t����\t\t�����\t\t����������\t=" << endl;
		cout << "=========================================================================================" << endl;
		for (Products c : Sales)
		{
			cout << "= " << (++num) << ".\t";
			cout << c.getDate() << "\t";
			if(c.getDate().length() < 8) cout << "\t";
			cout << c.getProduct() << "\t";
			if(c.getProduct().length() < 8) cout << "\t";
			cout << c.getPrice() << "\t";
			if(c.getPrice().length() < 8) cout << "\t";
			cout << c.getFirm() << "\t";
			if(c.getFirm().length() < 8) cout << "\t";
			cout << c.getSale() << "\t";
			if(c.getSale().length() < 8) cout << "\t";
			cout << "=" << endl;
		}
		cout << "=========================================================================================" << endl << endl;
	}
	else
    {
		cout << "������ �� �������..." << endl;
	}
	cout << endl;
}

void fixProductSale()
{
	system("cls");
	int num;
	Products c;
	string attr;
	if(Sales.size())
        {
		printProductSale();
		cout << "������� ����� ���������� ������, ������� ������ ���������������: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Sales.size())
		{
			CIN_FLUSH;
			cout << "����: "; getline(cin, attr);
			c.setDate(attr);
			cout << "�����: "; getline(cin, attr);
			c.setProduct(attr);
			cout << "����: "; getline(cin, attr);
			c.setPrice(attr);
			cout << "�����: "; getline(cin, attr);
			c.setFirm(attr);
			cout <<"����������: "; getline(cin, attr);
            c.setSale(attr);
			Sales[num - 1] = c;
			cout << endl << "��������� ����� ��� �������..." << endl << endl;
		}
        else
        {
			cout << "������ ������������ ����� ���������� ������..." << endl << endl;
		}
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void deleteProductSale()
{
	system("cls");
	int num;
	if(Sales.size())
    {
		printProductSale();
		cout << "������� ����� ���������� ������, ������� ������ �������: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Sales.size())
		{
            auto first = Sales.cbegin();
			Sales.erase(first + num - 1);
			cout << "��������� ����� ��� �����..." << endl << endl;
		}
        else
        {
			cout << "����� ������������ ����� ���������� ������..." << endl << endl;
		}
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void deleteAllProductSale()
{
	system("cls");
	if(Sales.size())
    {
		Sales.clear();
		cout << "��� ��������� ������ ���� ������� �� ������..." << endl << endl;
	} else
	{
		cout << "������ �� �������..." << endl << endl;
	}
}

void searchProductSaleDate()
{
	system("cls");
	string date;
	bool match = false;
	int num;
	if(Sales.size())
    {
		CIN_FLUSH;
		cout << "������� ���� ���������� ������ ��� ������: ";
		getline(cin, date);
		cout << endl << "����������:" << endl;
		for (Products c : Sales)
		{
			if (c.getDate().find(date) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getFirm() << " ";
				cout << c.getSale() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void searchProductsSale()
{
	system("cls");
	string product;
	bool match = false;
	int num;
	if(Sales.size())
    {
		CIN_FLUSH;
		cout << "������� ���� ���������� ������ ��� ������: ";
		getline(cin, product);
		cout << endl << "����������:" << endl;
		for (Products c : Sales)
		{
			if (c.getProduct().find(product) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getFirm() << " ";
				cout << c.getSale() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void searchProductSalePrice()
{
	system("cls");
	string price;
	bool match = false;
	int num;
	if(Sales.size())
    {
		CIN_FLUSH;
		cout << "������� ���� ���������� ������ ��� ������: ";
		getline(cin, price);
		cout << endl << "����������:" << endl;
		for (Products c : Sales)
		{
			if (c.getPrice().find(price) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getFirm() << " ";
				cout << c.getSale() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void searchProductSaleFirm()
{
	system("cls");
	string firm;
	bool match = false;
	int num;
	if(Sales.size())
    {
		CIN_FLUSH;
		cout << "������� ���� ���������� ������ ��� ������: ";
		getline(cin, firm);
		cout << endl << "����������:" << endl;
		for (Products c : Sales)
		{
			if (c.getFirm().find(firm) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getFirm() << " ";
				cout << c.getSale() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void searchProductSales()
{
	system("cls");
	string sale;
	bool match = false;
	int num;
	if(Sales.size())
    {
		CIN_FLUSH;
		cout << "������� ���� ���������� ������ ��� ������: ";
		getline(cin, sale);
		cout << endl << "����������:" << endl;
		for (Products c : Sales)
		{
			if (c.getSale().find(sale) != string::npos)
			{
				match = true;
				cout << (++num) << ". ";
				cout << c.getDate() << " ";
				cout << c.getProduct() << " ";
				cout << c.getPrice() << " ";
				cout << c.getFirm() << " ";
				cout << c.getSale() << endl;
			}
		}
		if(!match)
		{
			cout << "�� �������..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "������ �� �������..." << endl << endl;
	}
}

void getProductSaleFromFile()
{
	system("cls");
	Sales.clear();
	ifstream fin("Sales.txt");
	string line;
	Products c;
	string attr;
	if(!fin.is_open())
    {
		cerr << "������: �� ������� ������� ���� ��� ��������� ���������� � �������..." << endl;
		exit(EXIT_FAILURE);
	} else
	{
		while(getline(fin, line))
		{
			stringstream ss(line);
			ss >> attr; c.setDate(attr);
			ss >> attr; c.setProduct(attr);
			ss >> attr; c.setPrice(attr);
			ss >> attr; c.setFirm(attr);
			ss >> attr; c.setSale(attr);
			Sales.push_back(c);
		}
		fin.close();
		cout << "��������� ������ ���� ��������� �� �����..." << endl << endl;
	}
}

void writeProductSaleInFile()
{
	system("cls");
	ofstream fout("Sales.txt");
	string product;
	if(!fout.is_open())
    {
		cerr << "������: �� ������� ������� ���� ��� ���������� ���������� � �������..." << endl;
		exit(EXIT_FAILURE);
	}
	else
    {
		for(Products c : Sales)
		{
			product = c.getDate();
			product += " ";
			product += c.getProduct();
			product += " ";
			product += c.getPrice();
            product += " ";
			product += c.getFirm();
			product += " ";
			product += c.getSale();
			fout << product << endl;
		}
		fout.close();
		cout << "��������� ������ ���� ��������� � ����..." << endl << endl;
	}
}

int main ()
{
    system("mode con cols=89 lines=50");            //��������� ������� �������.
    system("color 1F");                             //��������� ����� ������� � ������.
	setlocale(LC_ALL,"rus");                        //������� ��� ������������� ������� ����.
	SetConsoleCP(1251);                             //��������� ��������� ��� �����/������ �������.
    SetConsoleOutputCP(1251);
	int x;                                          //���������� ��� ������ ������� ����.

	do {                                            //���� � ������������.
		menu();                                     //������� ����.
		cin >> x;                                   //������������ �������� ����� ����.
		switch(x)
		{
			case 1:
                addProduct();
				break;
			case 2:
                printProduct();
				break;
			case 3:
                fixProduct();
				break;
			case 4:
                deleteProduct();
				break;
			case 5:
                deleteAllProduct();
				break;
			case 6:
                searchProductDate();
				break;
			case 7:
                searchProducts();
				break;
			case 8:
                searchProductPrice();
				break;
			case 9:
                searchProductAmount();
				break;
			case 10:
                getProductFromFile();
				break;
			case 11:
                writeProductInFile();
				break;
			case 12:
                addProductSale();
				break;
			case 13:
                printProductSale();
				break;
			case 14:
                fixProductSale();
				break;
			case 15:
                deleteProductSale();
				break;
			case 16:
                deleteAllProductSale();
				break;
			case 17:
                searchProductSaleDate();
				break;
			case 18:
                searchProductsSale();
				break;
			case 19:
                searchProductSalePrice();
				break;
			case 20:
                searchProductSaleFirm();
				break;
			case 21:
                searchProductSales();
                break;
			case 22:
                getProductSaleFromFile();
				break;
            case 23:
                writeProductSaleInFile();
                break;
			case 0:
            {
				system("cls");                      //������� �������.
				cout << "���������� ������ ���������..." << endl;
				cin.get();
				return EXIT_SUCCESS;                //�������� ���������� ������� �������.
			}
		}
	} while(true);
    return 0;
}
