#ifndef WAREHOUSE_H_INCLUDED
#define WAREHOUSE_H_INCLUDED

using namespace std;

#include<iostream>
#include"SalesGoods.h"

class WareHouse : public SalesGoods
{
    protected:
        string Amount;
    public:
        WareHouse() : SalesGoods("","","")
        {
            setAmount("");
        }
        WareHouse(string receipt_date, string product_received, string price_product, string quantity_of_goods) : SalesGoods(receipt_date, product_received, price_product)
        {
            setAmount(quantity_of_goods);
        }
        void setAmount(string quantity_of_goods)
        {
            this->Amount = quantity_of_goods;
        }
        string getAmount() const
        {
            return Amount;
        }
        WareHouse(const WareHouse &pp)
        {
            this->Date = pp.Date;
            this->Product = pp.Product;
            this->Price = pp.Price;
            this->Amount = pp.Amount;
        }
        ~WareHouse()
		{

		}
};

#endif // WAREHOUSE_H_INCLUDED
