#ifndef SALESGOODS_H_INCLUDED
#define SALESGOODS_H_INCLUDED

using namespace std;

#include<iostream>
#include"GoodsReceipt.h"

class SalesGoods : public GoodsReceipt                      //объ€влени€ класса SalesGoods, наследуемый класс GoodsReceipt.
{
    protected:
        string Product;
        string Price;
    public:
        SalesGoods() : GoodsReceipt("")
        {
            setProduct("");
            setPrice("");
        }
        SalesGoods(string receipt_date, string product_received, string price_product) : GoodsReceipt(receipt_date)
        {
            setProduct(product_received);
            setPrice(price_product);
        }
        void setProduct(string product_received)
        {
            this->Product = product_received;
        }
        void setPrice(string price_product)
        {
            this->Price = price_product;
        }
        string getProduct() const
        {
            return Product;
        }
        string getPrice() const
        {
            return Price;
        }
        SalesGoods(const SalesGoods &pp)
        {
            this->Date = pp.Date;
            this->Product = pp.Product;
            this->Price = pp.Price;
        }
        ~SalesGoods()
		{

		}
};

#endif // SALESGOODS_H_INCLUDED
