// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file will be used to hold the main of the program. 

#include "nodes.h" 

using namespace std;

// Funtion Prototypes:
int game_round(); // This function will cause one game round to pass.

int main()
{	
	char temp[500]; // This is temp array. 
	int selection = 0; // This variable will be what the user decides to do.
	int life_1 = 1, life_2 = 1; // Will track both players health.
	int damage = 0; // This will the damage each player does. 
	int event = 0; // This will determine if an event will be trigered. 
	int pick = 0; // This will pick which player get hit by the event.
	int end = 1; // This will be used to end loops.
	Hash_Table history; // This will be the match history for the game.
	
	Player * player_1 = NULL; // Pointer of Player class.
	Player * player_2 = NULL; // Pointer of Player class. 

	Event * tornado = new Tornado; // A Event pointer to a Tornado class.
	Event * lion = new Lion; // A Event pointer to a Lion class.

	// Display to the user.
	cout<< endl << "Hello welcome to 'Battle Ultimate!!' the game where you battle your friends." << endl << endl;

	cout<< endl << "Player 1 enter your name: " << endl; // Display to user. 
	cin.get(temp,500,'\n'); // Read in the name. 
	cin.ignore(100,'\n'); // Clear the input buffer. 
	
	history.add(temp); // Add the node into the Hash table.
	
	//This loop is to allow the player to pick a character.
	while(!player_1)
	{
		// Display to the user. 
		cout<< endl << temp << " pick which player you would like to choice." << endl
		    << "1: Knight" << endl
		    << "2: Mage" << endl
		    << "3: Orge" << endl;
		cin>> selection; // Read in the selection. 
		cin.ignore(100,'\n'); // Clear the input buffer.
	
		switch(selection)
		{
			case 1: player_1 = new Knight; // Allocate memory for a new Knight. 
				break;
			
			case 2: player_1 = new Mage; // Allocate memory for a new Mage. 
				break;
				
			case 3: player_1 = new Orge; // Allocate memory for a new Orge.
				break;

			default: cout<< endl << temp << " you entered a invaild number. Try again." << endl; // Display to the user
				break; 
		}
	}

	player_1->set_name(temp); // Call the function to save the players name. 
	
	cout<< endl << "Player 2 enter your name: " << endl; // Display to the user. 
	cin.get(temp,500,'\n'); // Read in the name. 
	cin.ignore(100,'\n'); // Clear the input buffer. 

	history.add(temp); // Allocate the node into the hash table.

	// This loop is to allow the player to pick a character.
	while(!player_2)
	{
		// Display to the user. 
		cout<< endl << temp << " pick which player you would like to choice." << endl
		    << "1: Knight" << endl
		    << "2: Mage" << endl
		    << "3: Orge" << endl;
		cin>> selection; // Read in the selection. 
		cin.ignore(100,'\n'); // Clear the input buffer.
	
		switch(selection)
		{
			case 1: player_2 = new Knight; // Allocate memory for a new Knight. 
				break;
			
			case 2: player_2 = new Mage; // Allocate memory for a new Mage. 
				break;
				
			case 3: player_2 = new Orge; // Allocate memory for a new Orge.
				break;

			default: cout<< endl << temp << "You entered a invaild number. Try again." << endl; // Display to the user
				break; 
		}
	}

	player_2->set_name(temp); // Call the function to save the pointer. 

	while(end)
	{
		// Display to the user.
		cout<< endl << "What would you like to do next?" 
		    << endl << "1: To see the battle history." 
		    << endl << "2: To start the next battle." 
		    << endl << "3: To end the game.";

		cin>> selection; // Read in the input. 
		cin.ignore(100,'\n'); // Clear the input buffer.

		switch(selection)
		{
			case 1: history.display_all(0);
				break;
			case 2:	cout<< endl << "The battle will start now! Good luck!" << endl; // Display to the user.

				// This loop will run the game.
				do
				{
					// Make sure player 2 isnt dead already.
					if(life_2 >= 1)
					{ 
						// Call the function that does damage to the player.	
						damage = player_1->attack_player();
						life_2 = player_2->take_damage(damage); // Deal the damage to the character. 
					}
			
					// Make sure player 1 isnt dead already.	
					if(life_1 >= 1)
					{
						// Call the function that does damage to the player.	
						damage = player_2->attack_player();
						life_1 = player_1->take_damage(damage); // Deal the damage to the character. 
					}

					event = rand() % 8; // Randomly pick a number. 

					// Make sure player 1 and 2 are both still alive.
					if(life_1 >= 1 && life_2 >= 1)
					{
						// Check to see if the tornado event will be triggered. 
						if(event == 1) 
						{
							// Find the damage done by the tornado.
							damage = tornado->damage_player();
							pick = rand() % 2; // Pick which player will be hit by the event. 
							// Check if player 1 was picked. 
							if(!pick == 0) 
								life_1 = player_1->take_damage(damage); // Damage player 1
							else 
								life_2 = player_2->take_damage(damage); // Damage player 2
						}	
						// Check to see if the lion event will be triggered. 
						else if(event == 2)
						{
							damage = lion->damage_player(); // Find the damage done by the lion.
							pick = rand() % 2; // Randomly pick a player.
							// Check to see if player 2 was picked. 
							if(!pick)
								life_2 = player_2->take_damage(damage); // Damage player 2.
							else
								life_1 = player_1->take_damage(damage); // Damage player 1. 
						} 
						else 
						cout<< endl << "No event happened this turn."; // Display this to the user.
					}
			
				}while(life_1 >= 1 && life_2 >= 1);

				history.update(0,life_1); // Update player ones record.
				history.update(1,life_2); // Update player twos record.
				
				// Check to see who won.	
				if(life_1 > life_2) 
				{
					player_1->level_up(); // Level up player 1 
					player_2->reset(); // Retore player 2 
				}
				else
				{
					player_1->reset(); // Restore player 1
					player_2->level_up(); // Restore player 2
				}
			
				life_1 = 1; // Reset life_1
				life_2 = 1; // Reset life_2

				break;

			case 3: cout<< endl << "Thank you for playing." << endl; // Display to the user.
				end = 0; // End the loop.
				break; 

			default: cout<< endl << temp << "You entered a invaild number. Try again." << endl; // Display to the user
				break; 
		}
	}	
	
	delete player_1; // Deallocate the dynamic memory 
	delete player_2; // Deallocate the dynamic memory
	delete tornado; // Deallocate the dynamic memory 
	delete lion; // Deallocate the dynamic memory
}
