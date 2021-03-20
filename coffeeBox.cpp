#include <iostream>
#define EspressoCost 2
#define CapuccinoCost 3
#define LatteCost 3

using namespace std;

void showStartMenu();
void showSugarMenu();
void showBalanceMenu();
void showDiscrepancyWarning();
int getChosenCoffee();
int getSugar();
int inputValidation(int chosenCoffee, int enteredValue);
int giveCoffee();

int main(){
	int enteredValue, chosenCoffee, amountOfSugar;
	
	showStartMenu();
	chosenCoffee = getChosenCoffee();
	
	/*showSugarMenu();
	amountOfSugar = getSugar();
	
	showBalanceMenu();
	enteredValue = getMoney();
	
	if (inputValidation(chosenCoffee, enteredValue)){
		giveCoffee();
	} else {
		showDiscrepancyWarning();
	}
	
	*/
	
	return 0;
}

void showStartMenu(){
	cout << "***************************************************" << endl;
	cout << "Please, choose your coffee" << endl;
	cout << "1 - Espresso" << endl 
		 << "2 - Capuccino" << endl
		 << "3 - Latte" << endl;
	cout << "***************************************************" << endl << endl;
}

int getChosenCoffee(){
	int typeOfCoffee;
	
	cin >> typeOfCoffee;
	
	return typeOfCoffee;
}
