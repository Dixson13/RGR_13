#include <iostream>		    // заголовочный файл библиотеки для работы с потоками ввода-вывода консоли.
#include <locale>		    // заголовочный файл стандартной библиотеки языка программирования С, который используется для задач, связанных с локализацией.
#include <vector>		    // заголовочный файл библиотеки для работы с векторами: Стандартный шаблон обобщённого программирования языка C++ std::vector<T> — реализация динамического массива.
#include <fstream>		    // заголовочный файл библиотеки для работы с файловыми потоками.
#include <sstream>		    // заголовочный файл библиотеки для работы с текстовыми потоками.
#include <windows.h>	    // заголовочный файл библиотеки для работы с WINAPI.

#define CIN_FLUSH if (cin.peek()) cin.ignore()  // макрос очистки потока ввода.

using namespace std;	                        //пространство стандартных имён.

#include"GoodsReceipt.h"                        //классы с методами и переменными, которые мы создали для работы с ними.
#include"SalesGoods.h"
#include"WareHouse.h"
#include"CounterParty.h"
#include"Products.h"

void menu() {                                   //Реализация удобного меню программы.
	cout << "#########################################################################################" << endl;
	cout << "################################## СКЛАДСКОЕ ПРИЛОЖЕНИЕ #################################" << endl;
	cout << "#########################################################################################" << endl;
	cout << "##################################### МЕНЮ ПРОГРАММЫ ####################################" << endl;
	cout << "#########################################################################################" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~ Склад ~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      |> 1.   Поступление товара                |" << endl;
	cout << "                      |> 2.   Посмотреть склад                  |" << endl;
	cout << "                      |> 3.   Исправить ошибку на складе        |" << endl;
	cout << "                      |> 4.   Удалить Определённый товар        |" << endl;
	cout << "                      |> 5.   Очистить склад                    |" << endl;
	cout << "                      |> 6.   Поиск товара по дате              |" << endl;
	cout << "                      |> 7.   Поиск товара по названию          |" << endl;
	cout << "                      |> 8.   Поиск товара по цене              |" << endl;
	cout << "                      |> 9.   Поиск товара по количеству        |" << endl;
    cout << "                      |> 10.  Загрузить данные из файла         |" << endl;
    cout << "                      |> 11.  Сохранить данные в файл           |" << endl;
    cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~ Журнал учёта продаж ~~~~~~~~~~~" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      |> 12.  Продажа товара                    |" << endl;
	cout << "                      |> 13.  Список продаж                     |" << endl;
	cout << "                      |> 14.  Редактировать список продаж       |" << endl;
	cout << "                      |> 15.  Исключить проданный товар         |" << endl;
	cout << "                      |> 16.  Очистить список продаж            |" << endl;
	cout << "                      |> 17.  Поиск продаж товара по дате       |" << endl;
	cout << "                      |> 18.  Поиск продаж товара по названию   |" << endl;
	cout << "                      |> 19.  Поиск продаж товара по цене       |" << endl;
    cout << "                      |> 20.  Поиск продаж товара по фирме      |" << endl;
	cout << "                      |> 21.  Поиск продаж товара по количеству |" << endl;
	cout << "                      |> 22.  Загрузить данные из файла         |" << endl;
	cout << "                      |> 23.  Сохранить данные в файл           |" << endl;
    cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                      |> 0.   Выход из программы                |" << endl;
	cout << "                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "                                    Введите пукнт меню  > ";
}

vector <WareHouse> Storage;	                    //создание вектора для хранения товаров на складе.
vector <Products> Sales;                        //создание вектора для хранения проданных товаров.

void addProduct()                               //функция добавляет на склад новый товар.
{
	system("cls");                              //очистка консоли.
	string x;                                //переменная для получения данных о товаре из консоли.
	WareHouse c;	                            //объект для создания нового товара.
	CIN_FLUSH;                                  //очистка потока ввода.
	cout << "Новая поставка..." << endl << endl;
	cout << "Дата: "; getline(cin, x);
	c.setDate(x);
	cout << "товар: "; getline(cin, x);
	c.setProduct(x);
	cout << "Цена: "; getline(cin, x);
	c.setPrice(x);
	cout << "Количество: "; getline(cin, x);
	c.setAmount(x);
	Storage.push_back(c);
	cout << endl << "Поставка завершена успешно..." << endl << endl;
}

void printProduct()                             //функция вывода списка всех товаров на складе.
{
	system("cls");
	int num = 0;                             //переменная для нумерации контактов.
	if(Storage.size())                          //условие, показывающее, есть ли на складе товары.
    {
		cout << "=========================================================================================" << endl;
		cout << "= №\tДата\t\tПродукт\t\tЦена\t\tКоличество\t=================" << endl;
		cout << "=========================================================================================" << endl;
		for (WareHouse c : Storage)             //Благодаря циклу "для", проходим по все товарам на складе.
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
		cout << "На складе пусто..." << endl;
	}
	cout << endl;
}

void fixProduct()                               //функция редактирует информацию о товарах на складе.
{
	system("cls");
	int num;                                    //редактируемый товар со склада.
	WareHouse c;
	string x;
	if(Storage.size())
    {
		printProduct();
		cout << "Введите номер товара, который хотите отредактировать: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Storage.size())    //условие допустимого товара.
		{
			CIN_FLUSH;
			cout << "Дата: "; getline(cin, x);
			c.setDate(x);
			cout << "товар: "; getline(cin, x);
			c.setProduct(x);
			cout << "Цена: "; getline(cin, x);
			c.setPrice(x);
			cout << "Количество: "; getline(cin, x);
			c.setAmount(x);
			Storage[num - 1] = c;
			cout << endl << "Товар был изменен..." << endl << endl;
		}
        else
        {
			cout << "Введен некорректный номер товара..." << endl << endl;
		}
	}
	else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void deleteProduct()                            //функция удаляет избранный товар со склада.
{
	system("cls");
	int num;
	if(Storage.size())
    {
		printProduct();
		cout << "Введите номер товара, который хотите удалить: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Storage.size())
		{
            auto first = Storage.cbegin();      // указатель на первый контакт.
			Storage.erase(first + num - 1);     // удаляется товар с номером num со склада.
			cout << "Товар был удалён..." << endl << endl;
		}
        else
        {
			cout << "Введён некорректный номер товара..." << endl << endl;
		}
	}
	else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void deleteAllProduct()                         //функция полной очистки товаров со склада.
{
	system("cls");
	if(Storage.size())
    {
		Storage.clear();                        //проводим чистку вектора.
		cout << "Все товары были удалены со склада..." << endl << endl;
	}
	else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void searchProductDate()                        //функция поиска товара со склада по дате.
{
	system("cls");
	string date;                                //переменная для ввода даты.
	bool match = false;                         //переменная, показывающая нашлись ли нужные товары на складе.
	int num;	                                //переменная для нумерации найденных товаров на складе.
	if(Storage.size())
    {
		CIN_FLUSH;
		cout << "Введите дату товара для поиска: ";
		getline(cin, date);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
    else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void searchProducts()                           //функция поиска товара со склада по продукту.
{
	system("cls");
	string product;
	bool match = false;
	int num;
	if(Storage.size())
    {
		CIN_FLUSH;
		cout << "Введите название товара для поиска: ";
		getline(cin, product);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void searchProductPrice()                       //функция поиска товара со склада по цене.
{
	system("cls");
	string price;
	bool match = false;
	int number;
	if(Storage.size())
    {
		CIN_FLUSH; // очистка потока ввода
		cout << "Введите название товара для поиска: ";
		getline(cin, price);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void searchProductAmount()                      //функция поиска товара со склада по его количеству.
{
	system("cls");
	string amount;
	bool match = false;
	int number;
	if(Storage.size())
    {
		CIN_FLUSH;
		cout << "Введите название товара для поиска: ";
		getline(cin, amount);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "На складе нет ни одного товара..." << endl << endl;
	}
}

void getProductFromFile()                       //функция для записи данных из файла.
{
	system("cls");
	Storage.clear();
	ifstream fin("Storage.txt"); 	            //открываем файл списка товаров со склада для чтения.
	string line;					            //строка для считывания контактов из файла.
	WareHouse c; 				                //объект для записи в него товара со склада.
	string x;					                //переменная для получения данных товара из тектстового потока.
	if(!fin.is_open())
    {
		cerr << "ОШИБКА: не удалось открыть файл для получения информации о товарах..." << endl;
		exit(EXIT_FAILURE);                     //завершение программы с ошибкой.
	}
	else
    {
		while(getline(fin, line))               //читаем по одному товару.
		{
			stringstream ss(line);	            //делаем из строки строковый поток.
			ss >> x; c.setDate(x);              //переносим из строкового потока данные в объект.
			ss >> x; c.setProduct(x);
			ss >> x; c.setPrice(x);
			ss >> x; c.setAmount(x);
			Storage.push_back(c);               //записываем объект в складское приложение.
		}
		fin.close();                            //закрытие файла.
		cout << "Товары были загружены из файла..." << endl << endl;
	}
}

void writeProductInFile()                       //функция для записи данных в файл.
{
	system("cls");
	ofstream fout("Storage.txt");	            //открываем файл списка товаров со склада на запись.
	string product;	                            //переменная для записи товара со склада.
	if(!fout.is_open())
    {
		cerr << "ОШИБКА: не удалось открыть файл для сохранения информации о товарах..." << endl;
		exit(EXIT_FAILURE);                     //завершение программы с ошибкой.
	}
	else
    {
		for(WareHouse c : Storage)              //проходим по всем контактам из складского приложения.
		{
			product = c.getDate();              //формируем строку товара со склада.
			product += " ";
			product += c.getProduct();
			product += " ";
			product += c.getPrice();
            product += " ";
			product += c.getAmount();
			fout << product << endl;            //записываем строку в файл.
		}
		fout.close();                           //закрытие файла.
		cout << "Товары были сохранены в файл..." << endl << endl;
	}
}
                                                //Далее идёт аналогичное описание, которое можно опустить.
void addProductSale()
{
    system("cls");
	string x;
	Products c;
	CIN_FLUSH;
	cout << "Продаваемая продукция..." << endl << endl;
	cout << "Дата: "; getline(cin, x);
	c.setDate(x);
	cout << "товар: "; getline(cin, x);
	c.setProduct(x);
	cout << "Цена: "; getline(cin, x);
	c.setPrice(x);
	cout << "Фирма: "; getline(cin, x);
	c.setFirm(x);
	cout << "Количество: "; getline(cin, x);
	c.setSale(x);
	Sales.push_back(c);
	cout << endl << "Продукция успешно продана..." << endl << endl;
}

void printProductSale()
{
	system("cls");
	int num = 0;
	if(Sales.size())
        {
		cout << "=========================================================================================" << endl;
		cout << "= №\tДата\t\tПродукт\t\tЦена\t\tФирма\t\tКоличество\t=" << endl;
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
		cout << "Ничего не продано..." << endl;
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
		cout << "Введите номер проданного товара, который хотите отредактировать: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Sales.size())
		{
			CIN_FLUSH;
			cout << "Дата: "; getline(cin, attr);
			c.setDate(attr);
			cout << "товар: "; getline(cin, attr);
			c.setProduct(attr);
			cout << "Цена: "; getline(cin, attr);
			c.setPrice(attr);
			cout << "Фирма: "; getline(cin, attr);
			c.setFirm(attr);
			cout <<"Количество: "; getline(cin, attr);
            c.setSale(attr);
			Sales[num - 1] = c;
			cout << endl << "Проданный товар был изменен..." << endl << endl;
		}
        else
        {
			cout << "Введен некорректный номер проданного товара..." << endl << endl;
		}
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
	}
}

void deleteProductSale()
{
	system("cls");
	int num;
	if(Sales.size())
    {
		printProductSale();
		cout << "Введите номер проданного товара, который хотите удалить: ";
		cin >> num;
		cout << endl;
		if(num > 0 && num <= Sales.size())
		{
            auto first = Sales.cbegin();
			Sales.erase(first + num - 1);
			cout << "Проданный товар был удалён..." << endl << endl;
		}
        else
        {
			cout << "Введён некорректный номер проданного товара..." << endl << endl;
		}
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
	}
}

void deleteAllProductSale()
{
	system("cls");
	if(Sales.size())
    {
		Sales.clear();
		cout << "Все проданные товары были удалены из списка..." << endl << endl;
	} else
	{
		cout << "Ничего не продано..." << endl << endl;
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
		cout << "Введите дату проданного товара для поиска: ";
		getline(cin, date);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
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
		cout << "Введите дату проданного товара для поиска: ";
		getline(cin, product);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
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
		cout << "Введите дату проданного товара для поиска: ";
		getline(cin, price);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
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
		cout << "Введите дату проданного товара для поиска: ";
		getline(cin, firm);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
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
		cout << "Введите дату проданного товара для поиска: ";
		getline(cin, sale);
		cout << endl << "Совпадения:" << endl;
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
			cout << "не найдены..." << endl;
		}
		cout << endl;
	}
	else
    {
		cout << "Ничего не продано..." << endl << endl;
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
		cerr << "ОШИБКА: не удалось открыть файл для получения информации о товарах..." << endl;
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
		cout << "Проданные товары были загружены из файла..." << endl << endl;
	}
}

void writeProductSaleInFile()
{
	system("cls");
	ofstream fout("Sales.txt");
	string product;
	if(!fout.is_open())
    {
		cerr << "ОШИБКА: не удалось открыть файл для сохранения информации о товарах..." << endl;
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
		cout << "Проданные товары были сохранены в файл..." << endl << endl;
	}
}

int main ()
{
    system("mode con cols=89 lines=50");            //установка размера консоли.
    system("color 1F");                             //установка цвета консоли и шрифта.
	setlocale(LC_ALL,"rus");                        //функция для использования русских букв.
	SetConsoleCP(1251);                             //установка кодировок для ввода/вывода консоли.
    SetConsoleOutputCP(1251);
	int x;                                          //переменная для выбора пунктов меню.

	do {                                            //цикл с постусловием.
		menu();                                     //выводим меню.
		cin >> x;                                   //пользователь выбирает пункт меню.
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
				system("cls");                      //очистка консоли.
				cout << "Завершение работы программы..." << endl;
				cin.get();
				return EXIT_SUCCESS;                //успешное завершение главной функции.
			}
		}
	} while(true);
    return 0;
}
