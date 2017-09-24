#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName = "No_Name", const string &code = "No_Code", double price = 0.00, bool taxable = false) {
	name = itemName;
	barcode = code;
	tax = taxable;
	item_price = price;
	tax = taxable;
}

PriceListItem::PriceListItem() {
	name = "No_Name";
	barcode = "No_Barcode";
	tax = false;
	item_price = 0.00;
}

string PriceListItem::getItemName() {
	return name;
}

string PriceListItem::getCode() {
	return barcode;
}

double PriceListItem::getPrice() {
	return item_price;
}

bool PriceListItem::isTaxable() {
	return tax;
}
void PriceListItem::addAll(const string &itemName, const string &code, double price, bool taxable) {
	name = itemName;
	barcode = code;
	item_price = price;
	tax = taxable;
}
PriceListItem PriceListItem::operator=(PriceListItem& PL) {
	name = PL.name;
	barcode = PL.barcode;
	tax = PL.tax;
	item_price = PL.item_price;
	return 0;
}