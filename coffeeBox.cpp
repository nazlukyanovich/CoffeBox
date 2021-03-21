#include <iostream>
#define EspressoCost 2
#define CapuccinoCost 3
#define LatteCost 4

using namespace std;

void showStartMenu();
void showSugarMenu();
void showBalanceMenu(double enteredValue, int chosenCoffe);
void showDiscrepancyWarning();
int getChosenCoffee();
int coffeeValidation(int chosenCoffee);
int getSugar();
double getMoney();
int getCoffeeCost(int chosenCoffee);
int inputValidation(int chosenCoffee, int enteredValue);
int giveCoffee(int chosenCoffee);

int main(){
	double enteredValue = 0.0;
	int chosenCoffee = 0, amountOfSugar = 0;
	
	do{
	
		do{
			showStartMenu();
			chosenCoffee = getChosenCoffee();
		} while (coffeeValidation(chosenCoffee));
		
		showSugarMenu();
		amountOfSugar = getSugar();
		
		do {
			showBalanceMenu(enteredValue, chosenCoffee);
			enteredValue += getMoney();
			
		} while(inputValidation(chosenCoffee, enteredValue) == false);
		
		if (inputValidation(chosenCoffee, enteredValue)){
			giveCoffee(chosenCoffee);
			enteredValue -= getCoffeeCost(chosenCoffee);
		} else {
			cout << "Error! Something went wrong";
			return 1;
		}
		
	} while (true); // здесь добавить Стаканчики, чтобы весь цикл выполнялся пока они есть
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

void showSugarMenu(){
	cout << "***************************************************" << endl;
	cout << "Please, choose your amount of sugar" << endl;
	cout << "1 - 1 Sugar cube" << endl
		 << "2 - 2 Sugar cubes" << endl
		 << "3 - 3 Sugar cubes" << endl;
	cout << "***************************************************" << endl << endl;
}

void showBalanceMenu(double enteredValue, int chosenCoffee){
	cout << "***************************************************" << endl;
	cout << "Please, insert required amount of money" << endl
		 << "The cost of your order: " << getCoffeeCost(chosenCoffee) << endl
		 << "Your balance: " << enteredValue << " rubles" << endl;
	cout << "***************************************************" << endl << endl;
}

//получаем цену кофе
int getCoffeeCost(int chosenCoffee){
	if (chosenCoffee == 1){
		return EspressoCost;
	} else if (chosenCoffee == 2){
		return CapuccinoCost;
	} else if (chosenCoffee == 3){
		return LatteCost;
	} else return false;
}

//получаем кофе
int getChosenCoffee(){
	int typeOfCoffee;
	
	cin >> typeOfCoffee;
	
	return typeOfCoffee;
}

//получаем сахар
int getSugar(){
	int amountOfSugar;
	
	cin >> amountOfSugar;
	
	return amountOfSugar;
}
 
//получаем деньги
double getMoney(){
	double money;
	
	cin >> money;
	
	return money;
}

//проверка номера кофе
int coffeeValidation(int chosenCoffee){
	if (chosenCoffee > 3 || chosenCoffee <= 0){
		cout << "Error! There is no such coffee. Try again" << endl;
		return true;
	} else return false;
}

//проверка совпадения цены выбранного кофе и введенных денег
int inputValidation(int chosenCoffee, int enteredValue){
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

//типа выдача кофе)
int giveCoffee(int chosenCoffee){
	if (chosenCoffee == 1){
		cout << "   ________" << endl
			 << "  /        \\" << endl
			 << " |\\________/|_" << endl
			 << " |          | \\" << endl
			 << " | Espresso |  |" << endl
			 << " |          |_/" << endl
			 << " \\          /" << endl
			 << "  \\________/" << endl << endl;
	} else if (chosenCoffee == 2){
		cout << "   _________" << endl
			 << "  /         \\" << endl
			 << " |\\_________/|_" << endl
			 << " |           | \\" << endl
			 << " | Capuccino |  |" << endl
			 << " |           |_/" << endl
			 << " \\           /" << endl
			 << "  \\_________/" << endl << endl;

	} else if (chosenCoffee == 3){
		cout << "   ________" << endl
			 << "  /        \\" << endl
			 << " |\\________/|_" << endl
			 << " |          | \\" << endl
			 << " |  Latte   |  |" << endl
			 << " |          |_/" << endl
			 << " \\          /" << endl
			 << "  \\________/" << endl << endl;
	} else return false;
}
