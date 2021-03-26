#include <iostream>
#include <stdlib.h>
#define EspressoCost 2
#define CapuccinoCost 2.50
#define LatteCost 3
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
			cout << "Your balance: " << money << " rubles" << endl;
			cout << "Please, choose your coffee" << endl;
			cout << "1 - Espresso (" << EspressoCost << " rubles)"  << endl 
				 << "2 - Capuccino (" << CapuccinoCost << " rubles)"  << endl
				 << "3 - Latte (" << LatteCost << " rubles)" << endl
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
		cout << "Please, call the serviceman to replenish cups" << endl;
		showUIStars();
		
		system("pause");
		enterServiceMenu(money, gBalance, cups);
	}
}

void showBalanceMenu(double chosenCoffee, double &money, double &gBalance, int &cups){
	
	cin.clear();
	fflush(stdin);
	
	//do{
		cleanConsole();
		
		showDeviceName();
		
		cout << endl;
		showUIStars();
		cout << "Attention! Coffee machine does not give out change" << endl << endl;
		cout << "Please, insert required amount of money" << endl
			 << "The cost of your order: " << getCoffeeCost(chosenCoffee) << " rubles" << endl
			 << "Your balance: " << money << " rubles" << endl
			 << "1 - 0.50 rubles" << endl
			 << "2 - 1 ruble" << endl
			 << "3 - 2 rubles" << endl
			 << "4 - 5 rubles" << endl
			 << "5 - 10 rubles" << endl
			 << "0 - back to menu" << endl;
		showUIStars();
		cout << endl;
		
		money += getMoney(money, gBalance, cups);
		
	//} while(inputValidation(chosenCoffee, money, cups) == false);
	
	gBalance += money;	
	
	coincidenceCheck(chosenCoffee, money, gBalance, cups);
}

void coincidenceCheck(double chosenCoffee, double &money, double &gBalance, int &cups){
	if (inputValidation(chosenCoffee, money, cups)){
		giveCoffee(chosenCoffee);
		cups--;
		money -= getCoffeeCost(chosenCoffee);
		showStartMenu(money, gBalance, cups);
	} else {
		showBalanceMenu(chosenCoffee, money, gBalance, cups);
	}
}

void cupsWarning(double &money, double &gBalance, int &cups){
	if (cups <= 5){
		cout << "Warning! " << cups << " cups left!" << endl
			 << "Call the serviceman to replenish number of cups" << endl;
	} else;
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

/*void cupsWarning(double money, double gBalance, int cups){
	if (cups <= 5){
		cout << "Warning! " << cups << " cups left!" << endl
			 << "Call the serviceman to replenish number of cups" << endl;
	} else if (cups == 0){
		cout << "The cups are over! Please, try later." << endl;
		showStartMenu(money, gBalance, cups);
	} else;
}*/

void enterServiceMenu(double &money, double &gBalance, int &cups)  
{
	int attemptPin = 2, enteredPin = 0;
	
	while (attemptPin >= 0){
		system("CLS");
		
		showUIStars();
		cout << "Enter the PIN code to enter the service menu: " << endl;
		showUIStars();
		cout << endl;
		
		cin >> enteredPin;
		cout << endl;
		
		system("CLS");
		if (enteredPin == PIN){
			showServiceMenu(money, gBalance, cups);			
		}
		else if (enteredPin != PIN and attemptPin > 0){
			cout << "Error. Wrong PIN, try again. You have " << attemptPin << " attempts" << endl;
			system("pause");
		}
		else if (attemptPin == 0){
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
	
	system("CLS");
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
		system("CLS");
		showServiceBalance(money, gBalance, cups);
	}
	else if (userChoice == 2){
		system("CLS");	
		showCupsBalance(money, gBalance, cups);
	}
	else if (userChoice == 3){
		system("CLS");	
		showWithdrawMoney(money, gBalance, cups);
	}
	else if (userChoice == 0){
		system("CLS");	
		showStartMenu(money, gBalance, cups);
	}
	else {
		system("CLS");
		cout << "Wrong input. Choose correct option" << endl;
		userChoiceServiceMenuNumber(userChoice, money, gBalance, cups);
	}	
}

void showServiceBalance(double &money, double &gBalance, int &cups)	//get function number of money from main menu
{	
	int userChoice = 0;
	
	showUIStars();
	cout << "The current cash balance is " << gBalance << endl;//get function number of money from main menu
	cout << "Press 1 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	system("CLS");
	if (userChoice == 1){
		showServiceMenu(money, gBalance, cups);
		cout << "Wrong input!" << endl;
		showServiceBalance(money, gBalance, cups);
	}
}			

void showCupsBalance(double &money, double &gBalance, int &cups)	//get function number of cups from main menu
{
	int userChoice = 0;   //get function number of cups from main menu
	
	showUIStars();
	cout << "The current cups balance is " << cups << endl << endl; //get function number of cups from main menu
	cout << "Press 1 to add 100 cups" << endl;
	cout << "Press 2 to add 200 cups" << endl;
	cout << "Press 3 to add 500 cups" << endl;
	cout << "Press 4 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	system("CLS");
	if (userChoice == 1){
		showUIStars();
		cout << "100 cups were added" << endl;
		cups = cups + 100;  //get function number of cups from main menu
		cupsMaxTest(cups);  //get function number of cups from main menu
		cupsReplenishmentMenu(money, gBalance, cups);
	}
	else if (userChoice == 2){
		showUIStars();
		cout << "200 cups were added" << endl;
		cups = cups + 200;  //get function number of cups from main menu
		cupsMaxTest(cups);
		cupsReplenishmentMenu(money, gBalance, cups);
	}
	else if (userChoice == 3){
		showUIStars();
		cout << "500 cups were added" << endl;
		cups = cups + 500;  //get function number of cups from main menu
		cupsMaxTest(cups);  
		cupsReplenishmentMenu(money, gBalance, cups);
	}
	else if (userChoice == 4)
		showServiceMenu(money, gBalance, cups);
	else {
		cout << "Wrong input!" << endl;
		showCupsBalance(money, gBalance, cups);
	}
}				

int cupsMaxTest(int &cups) // Add correct cups variable and in prototype
{
	if (cups > 700){   // Add correct cups variable
		cout << "Error. Too many cups added. Maximum number of cups is 700" << endl;
		cout << "Current number of cups is 700" << endl << endl;   // Add correct cups variable                  
		cups = 700; // Add correct cups variable
	}	return cups; // Add correct cups variable
}

void cupsReplenishmentMenu(double &money, double &gBalance, int &cups)
{
	int userChoice = 0;
	
	cout << endl << "Press 2 to return to the service menu" << endl;
	showUIStars();
	cout << endl;
	
	cin >> userChoice;
	
	system("CLS");
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
	
	system("CLS");
	if (userChoice == 1){
		cout << "You withdrew " << gBalance << " BYN" << endl << endl;
		//amount of money = 0; get function money from main menu
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
