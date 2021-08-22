// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file will be used to store the players and derived class functions. 

#include "nodes.h"

using namespace std; 

ifstream file_in;
ofstream file_out;

// This is the constructor.
Player::Player()
{
	name = NULL; // Set name to NULL.
}

// This is the destructor. 
Player::~Player()
{
	delete [] name; // Deallocate the memory.
}

// This function will display the players name. 
void Player::display()
{
	cout<< endl << name << endl; // Display the name to the user.
}
// This function will set the players name. 
void Player::set_name(char * new_name)
{
	name = new char [strlen(new_name)+1]; // Allocate the memory to store the playrs name 
	strcpy(name,new_name); // Copy the name into the array.
}

// This fucntion will attack the other player. 
int Player::attack_player(){}

// This function will calculate how mych dalmage the character takes. 
int Player::take_damage(int damage_taken){}

// This function will level up the character. 
void Player::level_up(){}

// This function will rest the characters stats. 
void Player::reset(){}

// This is the constructor.
Character::Character(): Player()
{
	character_name = NULL;
	health = 0;
	defense = 0; 
	attack = 0; 
	weapon = 0;
}

// This is the destructor. 
Character::~Character()
{
	delete [] character_name; // Deallocate the memory for characters_name. 
	character_name = NULL; // Set character_name back to NULL.
	health = 0; // Set health back to 0. 
	defense = 0; // Set defense to 0. 
	attack = 0; // Set attack to 0. 
}

// This function will display the data. 
void Character::display()
{
	cout<< endl << "The " << character_name << "'s health is: " << health << "." << endl; // Display to the user
	cout<< endl << "The " << character_name << "'s defense is: " << defense << "." << endl; // Display to the user
	cout<< endl << "The " << character_name << "'s attack is: " << attack << "." << endl; // Display to the user
	cout<< endl << "The " << character_name << "'s weapon multiplies the damage by: " << weapon << "." << endl; // Display to the user
}

// This function will calculate how mych damage the character takes. 
int Character::take_damage(int damage_taken)
{
	damage_taken = damage_taken / defense; // Calculate the damage the character will take.
	health = health - damage_taken; // Subtract the damage form the health.
	
	// Check to see if the character still has health.
	if(health <= 0) 
	{
		cout<< endl << name << "'s " << character_name << " has died."; // Display to the user.
		return 0; // Return 0 to the client. 
	}
	else
	{
		// Display what happened to the user.
		cout<< endl << "The remaining damage on " << name << "'s " << character_name << " is: " << health << " health points left." << endl;
		return 1; // Return 1 to the client.
	}
}

// This function will attack the other player. 
int Character::attack_player()
{
	int damage = attack * weapon; // This will be the damage the character does. 
	cout<< endl << name << " dealt " << damage << " points of damage."; // Display to user
	return damage; // Return the amount of damage the player does. 
}

// This function will read in the characters data. 
void Character::read_in(){}

// This function will level up the character. 
void Character::level_up()
{
	read_in(); // Call the function to reset the values.
	health = health + (health * .1); // Increase health by 10%. 
	attack = attack + (health * .1); // Increase attack by 10%. 
	defense = defense + (defense* .1); // Increase deffense by 10%. 
}

// This function will reset the characters stats. 
void Character::reset()
{}

// This is the constrctor.
Knight::Knight(): Character()
{
	read_in(); // Read in the Knights data.
}

// This is the destructor. 
Knight::~Knight(){}

// This will display the data. 
void Knight::display()
{
	Player::display(); // Call the players display function. 
	Character::display(); // Call the characters display function.
}

// This function will attack the other player.
int Knight::attack_player()
{
	return Character::attack_player(); // Return the amount of damage the character does. 
}

// This function will read in from the text file. 
void Knight::read_in()
{
	char temp[500]; // This is a temp array of characters.

	file_in.open("knight.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("knight.txt");
	}
	file_in.get(temp,500,':'); // Read in the characters name.
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof()) // This function reads in data from the text file. 
	{
		if(!character_name) // Check to see if there is already a character name.
		{	
			character_name = new char [strlen(temp)+1]; // Allocate the memory for a new array. 
			strcpy(character_name,temp); // Copy the characters name. 
		}
	
		file_in>> health; // Store the amount of health the knight will have.
		file_in.ignore(); // Clear on item in the input stream.

		file_in>> defense; // Read in the amount of defense the knight will have. 
		file_in.ignore(); // Clear on item from the input stream. 

		file_in>> attack; // Read in the amount of attack the character will have.
		file_in.ignore(); // Clear one item from the input stream. 

		file_in>> weapon; // Read in the weapon value for the character. 
		file_in.ignore(); // Clear one item from the input stream. 

	}
	file_in.close(); // Close the connecton to the text file. 
}

// This function will reset the characters stats. 
void Knight::reset()
{
	read_in(); // Read in the orignial values.
}
// This is the consturctor.
Mage::Mage(): Character()
{
	read_in(); // Read in the mage's data
}

// This is the destructor.
Mage::~Mage(){}

// This function will display the data. 
void Mage::display()
{
	Player::display(); // Call the players display function. 
	Character::display(); // Call the characters display function. 
}

// This function will attack the other player.
int Mage::attack_player()
{
	return Character::attack_player(); // Return the amount of damage the player does. 
}

// This function will read in from the text file. 
void Mage::read_in()
{
	char temp[500]; // This is a temp array of characters.

	file_in.open("mage.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("mage.txt");
	}
	file_in.get(temp,500,':'); // Read in the characters name.
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof()) // This function reads in data from the text file. 
	{
		if(!character_name) // Check to see if there is already a character name.
		{	
			character_name = new char [strlen(temp)+1]; // Allocate the memory for a new array. 
			strcpy(character_name,temp); // Copy the characters name. 
		}
		file_in>> health; // Store the amount of health the knight will have.
		file_in.ignore(); // Clear on item in the input stream.

		file_in>> defense; // Read in the amount of defense the knight will have. 
		file_in.ignore(); // Clear on item from the input stream. 

		file_in>> attack; // Read in the amount of attack the character will have.
		file_in.ignore(); // Clear one item from the input stream. 

		file_in>> weapon; // Read in the weapon value for the character. 
		file_in.ignore(); // Clear one item from the input stream. 

	}
	file_in.close(); // Close the connecton to the text file. 
}

// This function will reset the characters stats. 
void Mage::reset()
{
	read_in(); // This function will reset the characters stats.
}

// This is the constructor.
Orge::Orge()
{
	read_in(); // Read in the Orge's data
}

// This is the destructor. 
Orge::~Orge(){}

// This function will display the data.
void Orge::display()
{
	Player::display(); // Call players display function. 
	Character::display(); // Call characters display function 
}

// This function will attack the other player.
int Orge::attack_player()
{
	return Character::attack_player(); // Return the amount of damage the player does. 
}

// This function will read in from the text file. 
void Orge::read_in()
{
	char temp[500]; // This is a temp array of characters.

	file_in.open("orge.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("orge.txt");
	}
	file_in.get(temp,500,':'); // Read in the characters name.
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof()) // This function reads in data from the text file. 
	{
		if(!character_name) // Check to see if there is already a character name.
		{	
			character_name = new char [strlen(temp)+1]; // Allocate the memory for a new array. 
			strcpy(character_name,temp); // Copy the characters name. 
		}
	
		file_in>> health; // Store the amount of health the knight will have.
		file_in.ignore(); // Clear on item in the input stream.

		file_in>> defense; // Read in the amount of defense the knight will have. 
		file_in.ignore(); // Clear on item from the input stream. 

		file_in>> attack; // Read in the amount of attack the character will have.
		file_in.ignore(); // Clear one item from the input stream. 

		file_in>> weapon; // Read in the weapon value for the character. 
		file_in.ignore(); // Clear one item from the input stream. 

	}
	file_in.close(); // Close the connecton to the text file. 
}

// This function will reset the characters stats. 
void Orge::reset()
{
	read_in(); // This function will reset the characters stats.
}

// This function will read in from the text file. 
void Tornado::read_in()
{
	char temp[500]; // This is a temp array of characters.

	file_in.open("tornado.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("tornado.txt");
	}
	file_in.get(temp,500,':'); // Read in the characters name.
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof())
	{
		if(!event_type) // Check to see if there is already a event type
		{
			event_type = new char [strlen(temp)+1]; // Allocate the memory for a new array. 
			strcpy(event_type,temp); // Copy the events name. 
		}
	
		file_in>> damage; // Store the ammount of base damage the tornado does. 
		file_in.ignore(); // Clear on item in the input stream.

		file_in>> multiplier; // Read in the multiplier that the tornado will have.
		file_in.ignore(); // Clear on item from the input stream. 
	
	}
	file_in.close(); // Close the connecton to the text file. 
}

// This function will read in from the text file. 
void Lion::read_in()
{
	char temp[500]; // This is a temp array of characters.

	file_in.open("lion.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("lion.txt");
	}
	file_in.get(temp,500,':'); // Read in the characters name.
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof())
	{
	
		if(!event_type) // Check to see if there is already a event type
		{
			event_type = new char [strlen(temp)+1]; // Allocate the memory for a new array. 
			strcpy(event_type,temp); // Copy the events name. 
		}
	
		file_in>> damage; // Store the amount of damage the event will do.
		file_in.ignore(); // Clear on item in the input stream.

		file_in>> multiplier; // Read in the multiplier that the event will have. 
		file_in.ignore(); // Clear on item from the input stream. 

	}
	file_in.close(); // Close the connecton to the text file. 
}
