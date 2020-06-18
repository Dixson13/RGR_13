#ifndef COUNTERPARTY_H_INCLUDED
#define COUNTERPARTY_H_INCLUDED

using namespace std;

#include<iostream>
#include"SalesGoods.h"

class CounterParty : public SalesGoods
{
    protected:
        string Firm;
    public:
        CounterParty() : SalesGoods("","","")
        {
            setFirm("");
        }
        CounterParty(string receipt_date, string product_received, string price_product, string company_name) : SalesGoods(receipt_date, product_received, price_product)
        {
            setFirm(company_name);
        }
        void setFirm(string company_name)
        {
            this->Firm = company_name;
        }
        string getFirm() const
        {
            return Firm;
        }
        CounterParty(const CounterParty &pp)
        {
            this->Date = pp.Date;
            this->Product = pp.Product;
            this->Price = pp.Price;
            this->Firm = pp.Firm;
        }
        ~CounterParty()
		{

		}
};

#endif // COUNTERPARTY_H_INCLUDED
