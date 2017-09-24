#include "GroceryBill.h"
#include <iostream>
#include <fstream>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	PL = *priceList; //may need to make a copy constructor in the pricelist class if this doesnt impliment right
	tax_rate = taxRate;
	PLI = new PriceListItem[1000];
	PLI_quanity = new double[1000];
	size = 0;
}


void GroceryBill::scanItem(string scanCode, double quantity) {
	PriceListItem temp;
	temp = PL.getItem(scanCode);
	PLI[size] = temp; //will need copy constructor for PLI class
	PLI_quanity[size] = quantity;
	size;
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	ifstream fin(filename);

	if (fin.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string code;
		double quanity;
		while (fin >> code >> quanity) {
			scanItem(code, quanity);
		}
		fin.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	double total = 0;
	if (size == 0)
		return total;
	for (int i = 0; i < size; i++)
	{
		total += PLI_quanity[i] * PLI[i].getPrice();
		if (PLI[i].isTaxable()) {
			total += PLI_quanity[i] * PLI[i].getPrice() * tax_rate;
		}
	}
	return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() { //may consider setting precsion
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << PLI[i].getItemName() << "    "
			<< PLI[i].getPrice() * PLI_quanity[i]
			<< "  ";
		if (PLI[i].isTaxable())
			cout << 'T';
		cout << endl;
	}
	cout << "Total    " << getTotal() << endl << endl;
} 
GroceryBill::~GroceryBill() {
	delete[] PLI;
	delete[] PLI_quanity;
	PLI = NULL;
	PLI_quanity = NULL;
}