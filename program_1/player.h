// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file will be used to hold the player class and derived classes declarations.

// This is the player class.
class Player 
{
	public:
		Player(); // This is the constructor.
		virtual ~Player(); // This is the destructor.
		virtual void display(); // This function will display the players name. 
		virtual int attack_player(); // This function will attack the other player. 
		virtual int take_damage(int damage_taken); // This function will calculate how mych dalmage the character takes. 
		virtual void level_up(); // This function will level up the character. 
		virtual void reset(); // This function will rest the characters stats. 
		void set_name(char * new_name); // This function will set the players name. 
	protected:
		char * name; // This pointer will store the players name. 
};

// This is the character class. 
class Character: public Player
{
	public:
		Character(); // This is the constructor.
		virtual ~Character(); // This is the destructor. 
		virtual void display(); // This function will display the data.
		int take_damage(int damage_taken); // This function will calculate how much damage the character takes.  
		virtual int attack_player(); // This function will attack the other player. 
		virtual void read_in(); // This function will read in the characters data. 
		virtual void level_up(); // This function will level up the character. 
		virtual void reset(); // This function will rest the characters stats. 
	protected:
		char * character_name; // This is characters name. 
		int health; // This is the characters health. 
		int defense; // This is the characters defense. 
		int attack; // This is the characters base attack. 
		int weapon; // This will be the characters weapon. 
}; 

// This is the Knight class. 
class Knight: public Character
{
	public:
		Knight(); // This is the constrctor.
		~Knight(); // This is the destructor. 
		void display(); // This will display the data. 
		int attack_player(); // This function will attack the other player.
		void read_in(); // This function will read in from the text file. 
		void reset(); // This function will reset the characters stats. 
};

// This is the Mage class. 
class Mage: public Character
{
	public:
		Mage(); // This is the consturctor.
		~Mage(); // This is the destructor.
		void display(); // This function will display the data. 
		int attack_player(); // This function will attack the other player.
		void read_in(); // This function will read in from the text file. 
		void reset(); // This function will reset the characters stats. 
};

// This is the Orge class.
class Orge: public Character
{
	public:
		Orge(); // This is the constructor.
		~Orge(); // This is the destructor. 
		void display(); // This function will display the data.
		int attack_player(); // This function will attack the other player.
		void read_in(); // This function will read in from the text file. 
		void reset(); // This function will reset the characters stats. 
};
