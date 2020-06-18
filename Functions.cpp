#include <iostream>		// заголовочный файл библиотеки для работы с потоками ввода-вывода консоли
#include <locale>		// заголовочный файл библиотеки для работы с локалями
#include <vector>		// заголовочный файл библиотеки для работы с векторами
#include <fstream>		// заголовочный файл библиотеки для работы с файловыми потоками
#include <sstream>		// заголовочный файл библиотеки для работы с текстовыми потоками
#include <windows.h>	// заголовочный файл библиотеки для работы с WINAPI

#define CIN_FLUSH if (cin.peek()) cin.ignore() // макрос очистки потока ввода

using namespace std;	// подключение пространства имен std

#include"GoodsReceipt.h"
#include"SalesGoods.h"
#include"WareHouse.h"
#include"CounterParty.h"
#include"Products.h"

void menu() {
	cout << "#########################################################" << endl;
	cout << "################# ТЕЛЕФОННЫЙ СПРАВОЧНИК #################" << endl;
	cout << "#########################################################" << endl;
	cout << "###################- МЕНЮ ПРОГРАММЫ -####################" << endl;
	cout << "#########################################################" << endl;
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "          |> 1.   Загрузить данные из файла   |" << endl;
	cout << "          |> 2.   Сохранить данные в файл     |" << endl;
	cout << "          |> 3.   Просмотреть контакты        |" << endl;
	cout << "          |> 4.   Добавить контакт            |" << endl;
	cout << "          |> 5.   Изменить контакт            |" << endl;
	cout << "          |> 6.   Удалить контакт             |" << endl;
	cout << "          |> 7.   Удалить весь список!        |" << endl;
	cout << "          |> 8.   Поиск контакта по фамилии   |" << endl;
	cout << "          |> 9.   Поиск контакта по имени     |" << endl;
	cout << "          |> 10.  Поиск контакта по номеру    |" << endl;
	cout << "          |> 0.   Выход из программы          |" << endl;
	cout << "          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "\t       Введите пукнт меню  > ";
}

vector <WareHouse> Storage;	// вектор для хранения контактов (телефонная книга)

// функция добавления нового контакта
void addProduct() {
	system("cls"); // очистка консоли

	string attr; // переменная для получения данных контакта из консоли
	WareHouse c;	// объект для создания контакта

	CIN_FLUSH; // очистка потока ввода

	cout << "Новая поставка..." << endl << endl;
	cout << "Дата: "; getline(cin, attr);
	c.setDate(attr);
	cout << "Продукт: "; getline(cin, attr);
	c.setProduct(attr);
	cout << "Цена: "; getline(cin, attr);
	c.setPrice(attr);
	cout << "Количество: "; getline(cin, attr);
	c.setAmount(attr);

	Storage.push_back(c);

	cout << endl << "Поставка завершена успешно..." << endl << endl;
}

// функция вывода списка контактов в консоль
void printProduct() {
	system("cls"); // очистка консоли

	int number = 0; // переменная для нумерации контактов

	if(Storage.size()) { // если в тел. справочнике есть контакты
		cout << "=========================================================" << endl;
		cout << "= №\tДата\t\tПродукт\t\tЦена\t\tКоличество\t\t=" << endl;
		cout << "=========================================================" << endl;
		// пробегаем по всем контактам из телефонного справочника
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
		cout << "На складе пусто..." << endl;
	}
	cout << endl;
}
