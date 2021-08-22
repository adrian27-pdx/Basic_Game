// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file will be used to hold all the functions that have to do with the data sturctures.

#include "nodes.h"

using namespace std;
 
// This is the constructor.
CLL_node::CLL_node()
{
	characters= new Player*[3]; // Allocate memory for three character pointers. 
	characters[0] = new Knight; // Allocate memory for a new Knight 
	characters[1] = new Mage; // Allocate memory for a new Mage
	characters[2] = new Orge; // Allocate memory for a new Orge
	next = NULL; // Set the next pointer to NULL.
}

// This is the destructor.
CLL_node::~CLL_node()
{
	delete characters[0]; // Deallocate the dynamic memory.
	delete characters[1]; // Deallocate the dynamic memory. 
	delete characters[2]; // Deallocate the dynamic memory. 
	delete [] characters; // Deallocate the dynamic memory.
}

// This function will traverse to the next node. 
CLL_node * & CLL_node::go_next()
{
	return this->next; // Return the next pointer by reference. 
}

// This function will display the data.
void CLL_node::display_characters()
{
	characters[0]->display(); // Display the characters data. 
	characters[1]->display(); // Display the characters data. 
	characters[2]->display(); // Display the characters data. 
}

// This is the constructor. 
CLL::CLL()
{
	rear = NULL; // Set rear to NULL
}

// This is the destructor. 
CLL::~CLL()
{
	delete rear; // Deallocate the memory for rear. 
	rear = NULL; // Set rear back to NULL.
}

// This function will display all the data. 
void CLL::display_all()
{
	rear->display_characters();// Call the function to display.
}

// This is a wrapper function.
void CLL::create()
{
	create(rear);
}

// This function will create the circular linked list.
void CLL::create(CLL_node * & rear)
{
	rear = new CLL_node; // Allocate memory for a CLL_node
}

// This is the constructor. 
Node::Node():next(NULL), name(NULL), wins(0), loses(0)
{}

// This is the destructor. 
Node::~Node()
{
	if(name)
	{
		delete [] name; // Deallocate the dynamic memory. 
		name = NULL; // Set the pointer to NULL. 
	}
	wins = 0; // Set wins to 0. 
	loses = 0; // Set loses to 0.
	next = NULL; // Set next to NULL.
}

// This function will creat a new node.
void Node::create(char * new_name)
{
	name = new char[strlen(new_name)+1]; // Allocate the memory for a new node. 
	strcpy(name,new_name); // Copy the name over.
}

// This function will traverse to the next node. 
Node * & Node::go_next(Node * & current)
{
	return current->next; // Return the next pointer by reference. 
}

// This will connect two nodes. 
void Node::connect(Node * & current)
{
	current->next = NULL; // Set the next pointer to NULL.
}

// This will update the win and loses. 
void Node::update(int result)
{
	// Check to see if the player won.
	if(result > 0) 
		wins++; // Add one win to the counter. 
	else
		loses++; // Add one lose to the counter. 
}

// This will display the wins and loses for the player. 
void Node::display()
{
	// Display the number of wins and loses the player has. 
	cout<< endl << name << " has: " << wins << " wins."
	    << endl << " and has: " << loses << " loses.";
}

// This function will deallocate all of the memory.
int Node::remove_all(Node * & head)
{
	if(!head)
		return 0; 
	Node * temp = head; // Set temp equal to NULL. 
	head = head->next; // Set head to the next node. 
	delete temp; // Deallocate the memory
	return remove_all(head); // Call the recursive function.
}

// This is the constructor. 
Hash_Table::Hash_Table()
{
	head = new Node*[2]; // Allocate memory for a new node.
	head[0] = NULL; // Set the first index to NULL. 
	head[1] = NULL; // Set the second index to NULL. 
}

// This is the destructor. 
Hash_Table::~Hash_Table()
{
	// Check to see if there is anything in the index
	if(head[0])
	{
		head[0]->remove_all(head[0]); // Calls the function to deallocate the memory. 
		head[0] = NULL; // Set the pointer to NULL.
	}
	// Check to see if there is anyting in the index
	if(head[1])
	{
		head[1]->remove_all(head[1]); // Call the function to deallocate all the memory.
		head[1] = NULL; // Set the pointer to NULL.
	}
	delete [] head; // Deallocate the array.
}

// This function will display all the data. 
int Hash_Table::display_all(int where)
{
	if(where == 2)
		return 0;
	else
	{
		head[where]->display(); // Call the function to display.
		return display_all(where+1); // Call the recursive function. 
	}
}

// This function will add a node. 
int Hash_Table::add(char * name)
{
	if(!head[0])
	{
		head[0] = new Node; // Allocate memory for a new node. 
		head[0]->create(name); // Call the function to store the neme. 
		return 1; // Return 1 to the client.
	}
	else if(!head[1])
	{
		head[1] = new Node; // Allocate memory for a new node. 
		head[1]->create(name); // Call the function to store the name.
		return 1; // Return 1 to the client.
	}
	else 
		return 0; // Return 0 to the client. 
}

// This function will update the wins and loses. 
void Hash_Table::update(int player, int result)
{
	head[player]->update(result); // Call the function to update the results. 
}

