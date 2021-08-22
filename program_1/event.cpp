// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file will be used to store the events and derived classes data. 

#include "nodes.h"

using namespace std;

// This is the constructor.
Event::Event()
{
	event_type = NULL; // Set the pointer to NULL. 
	damage = 0; // Set the damage to 0.
	multiplier = 0; // Set the multiplier to 0. 
}

// This is the destructor. 
Event::~Event()
{
	delete [] event_type; // Deallocate the array of characters.
	event_type = NULL; // Set the pointer to NULL. 
	damage = 0; // Set the damage to 0. 
	multiplier = 0; // Set the multiplier to 0.
}

// This function will display the base damage of any event.
void Event::display()
{
	cout<< endl << "The base damage for all events is: " << damage << "." << endl; // Display to the user.  
}

// This fucntion will damage the other player. 
int Event::damage_player()
{
	int total_damage;
	
	total_damage = damage * multiplier; // This is the total ammout of damage this class does. 

	cout<< endl << "The " << event_type << " did: " << total_damage << " points of damage." << endl; 	
	return total_damage; // This will return the total damage 
}

// This is the constructor.
Lion::Lion(): Event()
{
	read_in(); // Call the function to read in the data.
}

// This is the destructor.
Lion::~Lion(){}

// This function will display the data. 
void Lion::display()
{
	cout<< endl << "The multiplier of the Lion class is: " << multiplier << "." << endl; 
}

// This function will calculate the damage a player takes. 
int Lion::damage_player()
{
	return Event::damage_player();
}

// This is the constructor. 
Tornado::Tornado(): Event()
{
	read_in(); // Call the function that reads in the data.
}

// This is the destructor. 
Tornado::~Tornado(){}

// This function will display the data. 
void Tornado::display()
{
	cout<< endl << "The multiplier of the Tornado class is: " << multiplier << "." << endl; 
}

// This function will calculate the damage a player takes. 
int Tornado::damage_player()
{
	return Event::damage_player();
}
