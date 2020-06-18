#ifndef GOODSRECEIPT_H_INCLUDED                             //��������� �������������: ������������ �������� ���������� ��� ��������������� ������������� ���������.
#define GOODSRECEIPT_H_INCLUDED                             //��������� �������������: ����� ���������������� (������) ��� ������������� ���������.

using namespace std;                                        //������������ ����������� ���.

#include<iostream>                                          //������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������ � ����� ���������������� C++.

class GoodsReceipt                                          //���������� ������ GoodsReceipt.
{
	protected:                                              //����������� ������� protected: ������ ������ �������, ����������� �� �������.
		string Date;                                        //���������� ���� ������.
	public:                                                 //����������� ������� public: ������ ������ ����, ��� ����� ����������� ������� ������.
		GoodsReceipt()                                      //����������� ��� ����������.
        {
		    setDate("");
		}
		GoodsReceipt(string receipt_date)                   //����������� � �����������.
        {
			setDate(receipt_date);
		}
		void setDate(string receipt_date)                   //����� setDate.
        {
            this->Date = receipt_date;
        }
        string getDate() const                              //����� getDate.
        {
            return Date;
        }
		GoodsReceipt(const GoodsReceipt &pp)                //����������� �����������.
        {
            this->Date = pp.Date;
        }
		~GoodsReceipt()                                     //���������� ��� ����������.
		{

		}
};

#endif // GOODSRECEIPT_H_INCLUDED                           //��������� �������������: ����� ����� �������� ����������.

//��������� ��� ������ �� �����, ������ ��� ��� ��������� ���� �����.
