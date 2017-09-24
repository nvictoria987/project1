#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

PriceList::PriceList() {
	PLI = new PriceListItem[1000000];
	size = 0;

}
// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid just checks if the barcode exsists, so it needs to check if its in the price list
bool PriceList::isValid(string code) const {
	for (size_t i = 0; i < code.size(); i++)
	{
		if (!isdigit(code[i]))
			return false;
	}
	if (code == "No_Code")
		return false;
	else
		return true;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	for (int i = 0; i <= size; i++)
	{
		if (PLI[i].getCode() == code)
			return PLI[i];
	}
	throw invalid_argument("\nNo Matching barcode found!\n");
}

// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	PLI[size].addAll(itemName, code, price, taxable);
	size++;
}
PriceList& PriceList::operator=(const PriceList& PL) {
	delete[] PLI;
	PLI = new PriceListItem[1000000];
	size = PL.size;
	for (int i = 0; 0 < size; i++) {
		PLI[i] = PL.PLI[i];
	}

	return  PL; // I havee no idea why this isnt working this is the only error i know about 
}
PriceList::~PriceList() {
	delete[] PLI;
	PLI = NULL;
}