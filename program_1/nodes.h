// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file wil be the .h for all the data structure classes. 

#include <iostream>
#include <cstring> 
#include <cctype> 
#include <fstream>
#include <cstdlib>
#include <sys/time.h>
#include "event.h"
#include "player.h"

// This is the node class for the CLL. 
class CLL_node
{
	public:
		CLL_node(); // This is the constructor.
		~CLL_node(); // This is the destructor.
		CLL_node * & go_next(); // This function will traverse to the next node. 
		void display_characters(); // This function will display the data. 
	private:
		Player ** characters; 
		CLL_node * next;
};

// This class will manage the circular linked list. 
class CLL
{
	public: 
		CLL(); // This is the constructor. 
		~CLL(); // This is the destructor. 
		void display_all(); // This function will display all the data. 
		void create(CLL_node * & rear); // This function will create the circular linked list.
		void create(); // This is a wrapper function.
	private:
		CLL_node * rear; 
};

// This is the node class for a LLL. 
class Node 
{
	public: 
		Node(); // This is the constructor. 
		~Node(); // This is the destructor. 
		void create(char * new_name); // This function will creat a new node.
		Node * & go_next(Node * & current); // This function will traverse to the next node. 
		void connect(Node * & current); // This will connect two nodes. 
		void update(int result); // This will update the win and loses. 
		void display(); // This will display the wins and loses for the player. 
		int remove_all(Node * & head); // This function will deallocate all of the memory.
	private: 
		Node * next; // This is a pointer to the next node. 
		char * name; // This will be the players name.
		int wins; // This will track the wins the player has. 
		int loses; // This will track the loses the player has.
};

// This class will manage the Hash Table. 
class Hash_Table
{
	public:
		Hash_Table(); // This is the constructor. 
		~Hash_Table(); // This is the destructor. 
		int display_all(int where); // This function will display all the data. 
		int add(char * name); // This function will add a node. 
		void update(int player, int result); // This function will update the wins and loses. 
	private: 
		Node ** head; // This will make the array of head pointers. 
};
