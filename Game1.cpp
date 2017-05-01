/*
 * A simple mediocre game.
 * Dont claim it as yours.
 * Version: 0.0.1
 * Powercreed
 */


#include <iostream>
#include <string> // For the choice
#include <cstdlib>
#include <ctime>
int workers=1,floors=1,janitors=1,money=2000;
bool endgame=false;
std::string choice;
unsigned short int workersforhire()
{
srand(time(NULL));
unsigned short int random=rand() % 10 + 1;
return random;
}
void purchasemenu()
{
	unsigned short int forhire=workersforhire();
	unsigned short int choice2=0; // This is a very, very small number.
	std::cout << "Enter a number to buy something or to exit." << std::endl;
	std::cout << "[1] Worker" << std::endl; //TODO: Make buying in bulk possible
	std::cout << "[2] Janitor" << std::endl;
	std::cout << "[3] Floor" << std::endl;
	std::cout << "[4] Exit" << std::endl;
	std::cout << "Today you can hire " << forhire << " " << "people. You can hire these people to be either workers or janitors."
	while(true)
	{
	std::cin >> choice2;
	if(choice2==1)
	{
		if(floors*4>workers) // && money>=100, but we have lose conditions, so we allow the player to go into negative numbers
		{
			workers++;
			std::cout << "Worker bought for 100$" << std::endl;
		}
		else
		{
			std::cout << "Not enough space, buy more floors" << std::endl;
		}
	}
	if(choice2==2)
	{
		if(floors>janitors)
		{
			std::cout << "Janitor bought for 50$" << std::endl;
			janitors++;
		}
		else
		{
			std::cout << "You dont need more janitors" << std::endl;
		}
	}
	if(choice2==3)
	{
		// This is just a floor, so there is no need for any restrictions on these
		std::cout << "Floor bought for 200$" << std::endl;
		floors++;
	}
	if(choice2==4)
	{
		std::cout << "Buying menu exited." << std::endl;
		break;
	}
	if(choice2!=1 && choice2!=2 && choice2!=3 && choice2!=4)
	{
		std::cout << "Unknown command try again." << std::endl;
	}
	}
}
void printout()
{
	int profit=0;
	int wages=workers*50+janitors*25;
	if(janitors<floors)
	{
		profit=workers*100-(wages+workers*25);
	}
	else
	{
		profit=workers*100-wages;
	}
	money=money+profit;
	std::cout << "For wages you payed: " << wages << std::endl;
	std::cout << "You earned: " << profit << std::endl;
	std::cout << "Your balance is: " << money << std::endl;
	if(money>=15000)
	{
		std::cout << "You win! Congratulations." << std::endl;
		endgame=true;
		return;
	}
	if(money<=-10000)
	{
		std::cout << "You lose. Try again." << std::endl;
		endgame=true;
		return;
	}
	std::cout << "You have: " << workers << " " << "workers." << std::endl;
	std::cout << "You have: " << janitors << " " << "janitors." << std::endl;
	std::cout << "You have: " << floors << " " << "floors." << std::endl;
	return;
}
int main()
{
	
	// Firstly a quick tutorial
	std::cout << "Workers: They work. They produce 100$ per day each. They cost 50$ for wages. You start with one. They cost 100$ to hire." << std::endl;
	std::cout << "Janitors: They clean. If there are no janitors, or less janitors then floors, worker earnings drop by 25$. They cost 50$ to hire. They  cost 25$ for wages. You start with one." << std::endl;
	std::cout << "Floors: They hold 4 workers and one janitor. They cost 200$ when purchased. You start with one." << std::endl;
	std::cout << "Type 'buy' to access the buy menu." << std::endl;
	std::cout << "Type 'end' to end the current day." << std::endl;
	std::cout << "Type 'exit' to exit the game. All progress will be lost." << std::endl;
	std::cout << "Starting money: 2000$. To win, get more than 15,000 dollars. To lose, get under -10000." << std::endl;
	while(true) // The game goes on indefinetly, or until the player exits
	{
		std::cin >> choice; // The player is asked what to do and a function is called depending on what they typed
		if(choice=="buy" || choice=="Buy") // Incase of a typo
		{
			purchasemenu();
			
	    } 
	    if(choice=="end" || choice=="End")
	    {
			printout();
		}
		if(choice=="exit" || choice=="Exit")
		{
			return 0;
		}
		if(choice!="buy" && choice!="Buy" && choice!="end" && choice!="End" && choice!="Exit" && choice!="exit")
		{
			std::cout << "Unknown command. Try again." << std::endl;
		}
		if(endgame==true)
		{
			return 0;
		}
	}
}

