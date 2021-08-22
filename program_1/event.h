// Adrian Perez Gonzalez 10/23/19
// Computer Science 202 Fall 2019
// Program #1
// This file will hold all the declarations for the event class and derived classes. 

// This is the event class.
class Event
{
	public: 
		Event(); // This is the constructor.
		virtual ~Event(); // This is the destructor. 
		void display(); // This function will display the base damage of any event.
		virtual int damage_player(); // This fucntion will damage the other player. 
	protected:
		char * event_type; // This will be what the event is. 
		int damage; // This is the base damage for all events. 
		int multiplier; // This will multiply the base damage to get the overall damage.
};

// This class is the Lion class. 
class Lion: public Event 
{
	public:
		Lion(); // This is the constructor.
		~Lion(); // This is the destructor.
		void display(); // This function will display the data. 
		int damage_player(); // This function will calculate the damage a player takes. 
		void read_in(); // This function will read in from the text file. 
};

// This class is the Tornado class. 
class Tornado: public Event
{
	public:
		Tornado(); // This is the constructor. 
		~Tornado(); // This is the destructor. 
		void display(); // This function will display the data. 
		int damage_player(); // This function will calculate the damage a player takes. 
		void read_in(); // This function will read in from the text file. 
};
