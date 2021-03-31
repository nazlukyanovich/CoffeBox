#include <iostream>
#include <stdlib.h>
#define EspressoCost 1.5
#define CapuccinoCost 2.0
#define LatteCost 2.5
#define PIN 9932

using namespace std;

void showStartMenu(double &money, double &gBalance, int &cups);
void showSugarMenu();
void showBalanceMenu(double chosenCoffe, double &money, double &gBalance, int &cups);
void showDiscrepancyWarning();
void showUIStars();
void cupsWarning(double &money, double &gBalance, int &cups);
void showDeviceName();
void coincidenceCheck(double chosenCoffee, double &money, double &gBalance, int &cups);
void cleanConsole();

void enterServiceMenu(double &money, double &gBalance, int &cups);
void showServiceMenu(double &money, double &gBalance, int &cups);
void userChoiceServiceMenuNumber(int userChoice, double &money, double &gBalance, int &cups);
void showServiceBalance(double &money, double &gBalance, int &cups);
void showCupsBalance(double &money, double &gBalance, int &cups);
void showWithdrawMoney(double &money, double &gBalance, int &cups);
void cupsReplenishmentMenu(double &money, double &gBalance, int &cups);
void withdrawMoneyMenu(double &money, double &gBalance, int &cups);
	
int cupsMaxTest(int &cups);
int getChosenCoffee();
int getSugar();

double getBalance(double &money);
double coffeeValidation(double chosenCoffee, double &money, double &gBalance, int &cups);
double getMoney(double &money, double &gBalance, int &cups);
double getCoffeeCost(double chosenCoffee);
double inputValidation(double chosenCoffee, double &money, int &cups);
double giveCoffee(double chosenCoffee);

double gMoney = 0.0;
int attemptPin = 2;

int main(){
	int cups = 7;
	double money = 0.0, gBalance = 0.0;

	showStartMenu(money, gBalance, cups);
	
	return 0;
}

void showStartMenu(double &money, double &gBalance, int &cups){
	
	double chosenCoffee = 0;
	
	cin.clear();
	fflush(stdin);
	
	if (cups > 0){
	
		do {
			
			cleanConsole();
			
			cupsWarning(money, gBalance, cups);
			showDeviceName();
			
			cout << endl;
			showUIStars();
			cout << "Your balance: " << money << " BYN" << endl << endl;
			cout << "Please, choose your coffee" << endl << endl;
			cout << "1 - Espresso (" << EspressoCost << " BYN)"  << endl 
				 << "2 - Capuccino (" << CapuccinoCost << " BYN)"  << endl
				 << "3 - Latte (" << LatteCost << " BYN)" << endl
				 << "4 - Top up balance" << endl
				 << "0 - Enter the service menu" << endl;
			showUIStars();
			cout << endl;
			
			cin >> chosenCoffee;
			
		} while(coffeeValidation(chosenCoffee, money, gBalance, cups));
		
		coincidenceCheck(chosenCoffee, money, gBalance, cups);
		
	} else if (cups == 0) {
		cleanConsole();
		showUIStars();
		
		cout << "The cups are over! Please, try later." << endl;
		cout << "You will be redirected to the service menu" << endl;
		cout << "Please, call the serviceman to replenish cups: +375 29 1223344" << endl;
		showUIStars();
		
		system("pause");
		
		enterServiceMenu(money, gBalance, cups);
	}
}

void showBalanceMenu(double chosenCoffee, double &money, double &gBalance, int &cups){
	
	cin.clear();
	fflush(stdin);
	
	cleanConsole();
		
	showDeviceName();
		
	cout << endl;
	showUIStars();
	cout << "Attention! Coffee machine does not give out change" << endl << endl;
	cout << "Please, insert required amount of money" << endl << endl
		 << "The cost of your order: " << getCoffeeCost(chosenCoffee) << " BYN" << endl
		 << "Your balance: " << money << " BYN" << endl
		 << "1 - 0.50 BYN" << endl
		 << "2 - 1 BYN" << endl
		 << "3 - 2 BYN" << endl
		 << "4 - 5 BYN" << endl
		 << "5 - 10 BYN" << endl
		 << "0 - back to menu" << endl;
	showUIStars();
	cout << endl;
		
	money += getMoney(money, gBalance, cups);
	gMoney = money;
	
	coincidenceCheck(chosenCoffee, money, gBalance, cups);
}



void coincidenceCheck(double chosenCoffee, double &money, double &gBalance, int &cups){
	
	
	if (inputValidation(chosenCoffee, money, cups)){
		giveCoffee(chosenCoffee);
		cups--;	
		//gMoney = money;
		//gBalance += gMoney;
		money -= getCoffeeCost(chosenCoffee);
		showStartMenu(money, gBalance, cups);
	} else {
		showBalanceMenu(chosenCoffee, money, gBalance, cups);
	}
}

void cupsWarning(double &money, double &gBalance, int &cups){
	if (cups <= 5){
		cout << "Warning! " << cups << " cups left!" << endl
			 << "Call the serviceman to replenish number of cups: +375 29 1223344" << endl;
	} else;
}

//use to get nost of coffee
double getCoffeeCost(double chosenCoffee){
	if (chosenCoffee == 1){
		return EspressoCost;
	} else if (chosenCoffee == 2){
		return CapuccinoCost;
	} else if (chosenCoffee == 3){
		return LatteCost;
	} else return false;
}
 
//use to get cash
double getMoney(double &money, double &gBalance, int &cups){
	
	int enteredValue = 0 ;
	
	cin >> enteredValue;
		
	if(enteredValue == 0){
		showStartMenu(money, gBalance, cups);
	} else if (enteredValue == 1){
		return 0.50;
	} else if (enteredValue == 2){
		return 1;
	} else if (enteredValue == 3){
		return 2;
	} else if (enteredValue == 4){
		return 5;
	} else if (enteredValue == 5){
		return 10;
	} else return 0;
	
}

//use to check entered number of coffee
double coffeeValidation(double chosenCoffee, double &money, double &gBalance, int &cups){
	if (chosenCoffee > 4 || chosenCoffee < 0){
		cleanConsole();
		
		cout << "Error! There is no such coffee. Try again" << endl;
		
		system("pause");
		
		return true;
	} else if (chosenCoffee == 0){
		enterServiceMenu(money, gBalance, cups);
	} else if (chosenCoffee == 4){
		showBalanceMenu(chosenCoffee, money, gBalance, cups);
	} else return false;
}

//use to check the coincidence of the price of the selected coffee and the deposited money
double inputValidation(double chosenCoffee, double &money, int &cups){
	if (chosenCoffee == 1 && cups > 0){
		
		if (money >= EspressoCost){
			return true;
		} else return false;
		
	} else if (chosenCoffee == 2 && cups > 0){
		
		if (money >= CapuccinoCost){
			return true;
		} else return false;
		
	} else if (chosenCoffee == 3 && cups > 0){
		
		if (money >= LatteCost){
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
		cout << "Please, take your coffee" << endl;
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
			 
		system("pause");
		
	} else if (chosenCoffee == 2){
		
		cleanConsole();
		
		cout << endl;
		showUIStars();
		cout << "Please, take your coffee" << endl;
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
			 
		system("pause");

	} else if (chosenCoffee == 3){
		
		cleanConsole();
		
		cout << endl;
		showUIStars();
		cout << "Please, take your coffee" << endl;
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
			 
		system("pause");
	} else return false;
}

void cleanConsole(){
	 system("cls");
}

void showDeviceName(){
	cout << "EspressoBiancci. LEI700" << endl;
}

void showUIStars(){
	cout << "***************************************************" << endl;
}

void enterServiceMenu(double &money, double &gBalance, int &cups){
	 
	int enteredPin = 0;
	
	gBalance += gMoney;
	
	while (attemptPin >= 0){
		cleanConsole();
		
		showUIStars();
		cout << "Enter the PIN code to enter the service menu: " << endl << endl
			 << "Press 0 to back to main menu" << endl;
		showUIStars();
		cout << endl;
		
		cin >> enteredPin;
		cout << endl;
		
		cleanConsole();
		
		if (enteredPin == PIN){
			money = 0;
			showServiceMenu(money, gBalance, cups);			
		} else if (enteredPin == 0){
			showStartMenu(money, gBalance, cups);
		} else if (enteredPin != PIN and attemptPin > 0){
			cout << "Error. Wrong PIN, try again." << endl;
			system("pause");
		} else if (attemptPin == 0){
			cout << "Wrong PIN. The system blocked" << endl;
			system("pause");
			exit(1);
		} else;
		
		attemptPin--;
	}
}

void showServiceMenu(double &money, double &gBalance, int &cups)
{
	int userChoice = 0;
	
	cleanConsole();
	showUIStars();
	cout << "Service menu" << endl;
	cout << "1. Actual balance" << endl;
	cout << "2. Cups balance" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "0. Return to the main menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	userChoiceServiceMenuNumber(userChoice, money, gBalance, cups);
}

void userChoiceServiceMenuNumber(int userChoice, double &money, double &gBalance, int &cups)
{
	if (userChoice == 1) {
		cleanConsole();
		showServiceBalance(money, gBalance, cups);
	}
	else if (userChoice == 2){
		cleanConsole();	
		showCupsBalance(money, gBalance, cups);
	}
	else if (userChoice == 3){
		cleanConsole();	
		showWithdrawMoney(money, gBalance, cups);
	}
	else if (userChoice == 0){
		cleanConsole();	
		showStartMenu(money, gBalance, cups);
	}
	else {
		cleanConsole();
		cout << "Wrong input. Choose correct option" << endl;
		userChoiceServiceMenuNumber(userChoice, money, gBalance, cups);
	}	
}

void showServiceBalance(double &money, double &gBalance, int &cups)
{	
	int userChoice = 0;
	
	showUIStars();
	cout << "The current cash balance is " << gBalance << endl;
	cout << "Press 1 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	cleanConsole();
	
	if (userChoice == 1){
		showServiceMenu(money, gBalance, cups);
		cout << "Wrong input!" << endl;
		showServiceBalance(money, gBalance, cups);
	}
}			

void showCupsBalance(double &money, double &gBalance, int &cups)
{
	int userChoice = 0, addNumCups = 0;
	
	showUIStars();
	cout << "The current cups balance is " << cups << endl << endl;
	cout << "Press 1 to replenish the cups" << endl;
	cout << "Press 2 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	cleanConsole();
	
	if (userChoice == 1){
		showUIStars();
		cout << "Enter the number of added cups" << endl;
		cin >> addNumCups;
		
		cups = cups + addNumCups;
		cupsMaxTest(cups);
		
		cupsReplenishmentMenu(money, gBalance, cups);
	}
	else if (userChoice == 2)
		showServiceMenu(money, gBalance, cups);
	else {
		cout << "Wrong input!" << endl;
		
		showCupsBalance(money, gBalance, cups);
	}
}				

int cupsMaxTest(int &cups)
{
	if (cups > 700){ 
		cout << "Error. Too many cups added. Maximum number of cups is 700" << endl;
		cout << "Current number of cups is 700" << endl << endl;               
		cups = 700;
	}
	
	return cups;
}

void cupsReplenishmentMenu(double &money, double &gBalance, int &cups)
{
	int userChoice = 0;
	
	cout << endl << "Press 2 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	cleanConsole();
	
	while (userChoice != 2){
		cout << "Wrong input. Press 2 to return to the service menu" << endl;
		cin >> userChoice;
	} 
	if (userChoice == 2)
		showServiceMenu(money, gBalance, cups);
}

void showWithdrawMoney(double &money, double &gBalance, int &cups) 
{
	int userChoice = 0;
	
	showUIStars();
	cout << "Press 1 to withdraw money" << endl;
	cout << "Press 2 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	cleanConsole();
	
	if (userChoice == 1){
		cout << "You withdrew " << gBalance << " BYN" << endl << endl;
		gBalance = 0;
		withdrawMoneyMenu(money, gBalance, cups);
	}
	else if (userChoice == 2)
		showServiceMenu(money, gBalance, cups);
	else {
		cout << "Wrong input!" << endl;
		showWithdrawMoney(money, gBalance, cups);
	}
}	

void withdrawMoneyMenu(double &money, double &gBalance, int &cups)
{
	int userChoice = 0;
	
	showUIStars();
	cout << "Press 2 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	if (userChoice == 2)
		showServiceMenu(money, gBalance, cups);
	else {
		cout << "Wrong input!" << endl;
		showWithdrawMoney(money, gBalance, cups);
	}	
}
