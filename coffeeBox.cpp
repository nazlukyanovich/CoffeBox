#include <iostream>
#include <stdlib.h>
#define EspressoCost 2
#define CapuccinoCost 3
#define LatteCost 4

using namespace std;

void showStartMenu(double enteredValue);
void showSugarMenu();
void showBalanceMenu(double enteredValue, double chosenCoffe);
void showDiscrepancyWarning();
void showUIStars();
void showDeviceName();
void cleanConsole();

int getChosenCoffee();
double coffeeValidation(double chosenCoffee);
int getSugar();
double getMoney(double enteredValue, double chosenCoffee);
double getCoffeeCost(double chosenCoffee);
double inputValidation(double chosenCoffee, double enteredValue);
double giveCoffee(double chosenCoffee);

int main(){
	double enteredValue = 0.0, generalBalance = 0.0, chosenCoffee = 0, amountOfSugar = 0;
	
	//showDeviceName();
	
	while(true){ // Add coffee cups here so that the whole cycle runs while they are
	
		do{
			showStartMenu(enteredValue);
			chosenCoffee = getChosenCoffee();
		} while (coffeeValidation(chosenCoffee));
		
		if(chosenCoffee == 0){
			
			return 1; // request PIN and direct to service menu
			
		} else{
		
			//showSugarMenu();
			//amountOfSugar = getSugar();
			
			do {
				showBalanceMenu(enteredValue, chosenCoffee);
				enteredValue += getMoney(enteredValue, chosenCoffee);
				generalBalance += enteredValue;
				
			} while(inputValidation(chosenCoffee, enteredValue) == false);
			
			if (inputValidation(chosenCoffee, enteredValue)){
				giveCoffee(chosenCoffee);
				enteredValue -= getCoffeeCost(chosenCoffee);
			} else {
				cout << "Error! Something went wrong";
				return 1;
			}
			
			cout << generalBalance;
		}
	}
	return 0;
}

void showDeviceName(){
	cout << "EspressoBiancci. LEI700" << endl;
}

void showUIStars(){
	cout << "***************************************************" << endl;
}

void showStartMenu(double enteredValue){
	showDeviceName();
	cout << endl;
	showUIStars();
	cout << "Your balance: " << enteredValue << " rubles" << endl;
	cout << "Please, choose your coffee" << endl;
	cout << "1 - Espresso" << endl 
		 << "2 - Capuccino" << endl
		 << "3 - Latte" << endl
		 << "0 - Enter the service menu" << endl;
	showUIStars();
	cout << endl;
}

void showSugarMenu(){
	cout << endl;
	showUIStars();
	cout << "Please, choose your amount of sugar" << endl;
	cout << "1 - 1 Sugar cube" << endl
		 << "2 - 2 Sugar cubes" << endl
		 << "3 - 3 Sugar cubes" << endl;
	showUIStars();
	cout << endl;
}

void showBalanceMenu(double enteredValue, double chosenCoffee){
	cleanConsole();
	showDeviceName();
	cout << endl;
	showUIStars();
	cout << "Attention! Coffee machine does not give out change" << endl;
	cout << "Please, insert required amount of money" << endl
		 << "The cost of your order: " << getCoffeeCost(chosenCoffee) << endl
		 << "Your balance: " << enteredValue << " rubles" << endl
		 << "1 - 0.50 rubles" << endl
		 << "2 - 1 ruble" << endl
		 << "3 - 2 rubles" << endl
		 << "4 - 5 rubles" << endl
		 << "5 - 10 rubles" << endl;
	showUIStars();
	cout << endl;
}

//use to get ñost of coffee
double getCoffeeCost(double chosenCoffee){
	if (chosenCoffee == 1){
		return EspressoCost;
	} else if (chosenCoffee == 2){
		return CapuccinoCost;
	} else if (chosenCoffee == 3){
		return LatteCost;
	} else return false;
}

//use to get type of coffee
int getChosenCoffee(){
	int typeOfCoffee;
	
	cin >> typeOfCoffee;
	
	return typeOfCoffee;
}

//use to get amount of sugar
int getSugar(){
	int amountOfSugar;
	
	cin >> amountOfSugar;
	
	return amountOfSugar;
}
 
//use to get cash
double getMoney(double enteredValue, double chosenCoffee){
	double money;
	
	if (enteredValue >= getCoffeeCost(chosenCoffee)){
		return 0;
	} else{
	
		cin >> money;
		
		if (money == 1){
			return 0.50;
		} else if (money == 2){
			return 1;
		} else if (money == 3){
			return 2;
		} else if (money == 4){
			return 5;
		} else if (money == 5){
			return 10;
		} else return 0;
	
	}
}

//use to check entered number of coffee
double coffeeValidation(double chosenCoffee){
	if (chosenCoffee > 3 || chosenCoffee < 0){
		cleanConsole();
		cout << "Error! There is no such coffee. Try again" << endl;
		return true;
	} else return false;
}

//use to check the coincidence of the price of the selected coffee and the deposited money
double inputValidation(double chosenCoffee, double enteredValue){
	if (chosenCoffee == 1){
		if (enteredValue >= EspressoCost){
			return true;
		} else return false;
	} else if (chosenCoffee == 2){
		if (enteredValue >= CapuccinoCost){
			return true;
		} else return false;
	} else if (chosenCoffee == 3){
		if (enteredValue >= LatteCost){
			return true;
		} else return false;
	} else return false;
}

//it gives you coffee :)
double giveCoffee(double chosenCoffee){
	if (chosenCoffee == 1){
		cleanConsole();
		cout << endl;
		showUIStars();
		cout << "   ________" << endl
			 << "  /        \\" << endl
			 << " |\\________/|_" << endl
			 << " |          | \\" << endl
			 << " | Espresso |  |" << endl
			 << " |          |_/" << endl
			 << " \\          /" << endl
			 << "  \\________/" << endl << endl;
			 showUIStars();
			 cout << endl;
	} else if (chosenCoffee == 2){
		cleanConsole();
		cout << endl;
		showUIStars();
		cout << "   _________" << endl
			 << "  /         \\" << endl
			 << " |\\_________/|_" << endl
			 << " |           | \\" << endl
			 << " | Capuccino |  |" << endl
			 << " |           |_/" << endl
			 << " \\           /" << endl
			 << "  \\_________/" << endl << endl;
			 showUIStars();
			 cout << endl;

	} else if (chosenCoffee == 3){
		cleanConsole();
		cout << endl;
		showUIStars();
		cout << "   ________" << endl
			 << "  /        \\" << endl
			 << " |\\________/|_" << endl
			 << " |          | \\" << endl
			 << " |  Latte   |  |" << endl
			 << " |          |_/" << endl
			 << " \\          /" << endl
			 << "  \\________/" << endl << endl;
			 showUIStars();
			 cout << endl;
	} else return false;
}

void cleanConsole(){
	 system("cls");
}
