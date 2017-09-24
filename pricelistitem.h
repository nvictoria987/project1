#pragma once
#include <string>

using namespace std;

class PriceListItem {
public:
	PriceListItem();
	PriceListItem(const string &itemName, const string &code, double price, bool taxable);
	string getItemName();
	string getCode();
	double getPrice();
	bool isTaxable();
	void addAll(const string &itemName, const string &code, double price, bool taxable);
	PriceListItem operator=(PriceListItem& PL);
private:
	string name;
	string barcode;
	double item_price;
	bool tax;
};