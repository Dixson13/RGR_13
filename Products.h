#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED

using namespace std;

#include<iostream>
#include"CounterParty.h"

class Products : public CounterParty
{
    private:                                                //модификатор доступа private: доступ открыт самому классу (т.е. функциям-членам данного класса) и друзьям (friend) данного класса - как функциям, так и классам.
        string Sale;
    public:
        Products() : CounterParty("","","","")
        {
            setSale("");
        }
        Products(string receipt_date, string product_received, string price_product, string company_name, string sale_of_goods) : CounterParty(receipt_date, product_received, price_product, company_name)
        {
            setSale(sale_of_goods);
        }
        void setSale(string sale_of_goods)
        {
            this->Sale = sale_of_goods;
        }
        string getSale() const
        {
            return Sale;
        }
        Products(const Products &pp)
        {
            this->Date = pp.Date;
            this->Product = pp.Product;
            this->Price = pp.Price;
            this->Firm = pp.Firm;
            this->Sale = pp.Sale;
        }
        ~Products()
		{

		}
};

#endif // PRODUCTS_H_INCLUDED
