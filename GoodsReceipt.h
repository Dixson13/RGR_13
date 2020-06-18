#ifndef GOODSRECEIPT_H_INCLUDED                             //директива препроцессора: осуществл€ет условную компил€цию при неопределЄнности символической константы.
#define GOODSRECEIPT_H_INCLUDED                             //директива препроцессора: задаЄт макроопределение (макрос) или символическую константу.

using namespace std;                                        //пространство стандартных имЄн.

#include<iostream>                                          //заголовочный файл с классами, функци€ми и переменными дл€ организации ввода-вывода в €зыке программировани€ C++.

class GoodsReceipt                                          //объ€влени€ класса GoodsReceipt.
{
	protected:                                              //модификатор доступа protected: доступ открыт классам, производным от данного.
		string Date;                                        //объ€вление пол€ класса.
	public:                                                 //модификатор доступа public: доступ открыт всем, кто видит определение данного класса.
		GoodsReceipt()                                      //конструктор без параметров.
        {
		    setDate("");
		}
		GoodsReceipt(string receipt_date)                   //конструктор с параметрами.
        {
			setDate(receipt_date);
		}
		void setDate(string receipt_date)                   //метод setDate.
        {
            this->Date = receipt_date;
        }
        string getDate() const                              //метод getDate.
        {
            return Date;
        }
		GoodsReceipt(const GoodsReceipt &pp)                //конструктор копировани€.
        {
            this->Date = pp.Date;
        }
		~GoodsReceipt()                                     //деструктор без реализации.
		{

		}
};

#endif // GOODSRECEIPT_H_INCLUDED                           //директива препроцессора: конец ветки условной компил€ции.

//ќписывать все классы не будем, потому что они однотипны друг другу.
