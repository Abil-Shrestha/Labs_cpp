//Abil Shrestha
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class GChar
{

public:
	static const int DEFAULT_CAPACITY = 5;

	//constructor
	GChar(string name = "john", int capacity = DEFAULT_CAPACITY);

	//copy constructor
	GChar(const GChar& source);

	//Overload Assignment
	GChar& operator=(const GChar& source);

	//Destructor
	~GChar();

	//Insert a New Tool
	void insert(const std::string& toolName);

private:

	//data members
	string name;
	int capacity;
	int used;
	string* toolHolder;

};
//constructor
GChar::GChar(string n, int cap)
{
	name = n;
	capacity = cap;
	used = 0;
	toolHolder = new string[cap];
}
//copy constructor
GChar::GChar(const GChar& source)
{
	cout << "Copy Constructor Called." << endl;
	name = source.name;
	capacity = source.capacity;
	used = source.used;
	toolHolder = new string[source.capacity];
	copy(source.toolHolder, source.toolHolder + used, toolHolder);
}
//Overload Assignment
GChar& GChar::operator=(const GChar& source)
{
	cout << "Overload Assignment Called." << endl;
	//Check for self assignment
	//c1=c1
	if (this == &source)
	{
		return *this;
	}
	this->name = source.name;
	this->capacity = source.capacity;
	used = source.used;

	copy(source.toolHolder, source.toolHolder + used, this->toolHolder);
}
//Destructor
GChar::~GChar()
{
	cout << "Destructor called for " << this->name << " @ this memory location " << this << endl;
	delete[] toolHolder;
}

void GChar::insert(const string& toolName)
{
  char choice;
	if (used == capacity)
	{
		cout << " The tool holder is full, Cannot add any additional tools" << endl;
    cout << "Do you want to expand the toolbox? (y/n):";
  cin >> choice; //asking for input
  choice = tolower(choice); // converting the choice to lowercase
  while(choice!='n' && choice!='y') //if the choice entered is neither y or n loop until y or n is entered
  {
      cout << "Enter your choice (y/n): ";
  }
  if(choice == 'y') //if choice entered is y then expand the capacity by 1
  {
    cout << "Currently Expanding Toolbox" << endl;
    string *tempTools = new string[used];
    copy(toolHolder, toolHolder + used, tempTools);
    delete[] toolHolder;
    capacity = used + 1;
    toolHolder = new string[capacity];
    copy(tempTools, tempTools + used, toolHolder);
    delete[] tempTools;
    cout << "Toolbox Expanded Successfully" << endl;
    cout << "Updated Capacity is now " << capacity << endl;
    cout << name<< "'s Toolbox has been updated, here is the contents of our toolHolder" << endl;
    toolHolder[used] = toolName;
    used++;
    for (int i = 0; i < used; i++)
    {
      cout << toolHolder[i] << " | ";
    }
    cout << endl;
  }
  else // else not expanding the toolbox
  {
      cout << "Not explanding the tool box!!" << endl;
  }
	}
	else
	{
		toolHolder[used] = toolName;
		used++;
	}
}

int main()
{
	GChar gc1;
	gc1.insert("potion");
	gc1.insert("crossbow");
	gc1.insert("candle");
	gc1.insert("cloak");
	gc1.insert("sword");
	gc1.insert("book of spells");

	GChar gc2("Bob", 5);

	GChar gc3 = gc2;

	return 0;
}
