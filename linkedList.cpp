/*
Nathaniel Kowalke
CSCI 301 Comp Sci 2

This program displays a menu to the user with multiple options. Whatever the option the user picks
it will either affect the linked list, or search the linked list for something.

The options in this program are as such. To be able to empty the list, it insert a value
into the list, to remove a value from the list, to check to see if the list is empty, to
show the length of the list, to see if a certain value is in the list, to show the value
at a certain position, to print the list, show the menu, and finally to exit the program.
*/
#include <iostream>
#include <fstream>  
#include <cstring>  
#include <string>  
#include <iomanip> 
using namespace std;


void
showmenu ()
{
  cout << "Please type in  one of the following options: \n";
  cout << "'e' to empty the list \n";
  cout << "'i v' to insert value v into the list \n";
  cout << "'r v' to remove value v from the list \n";
  cout << "'c' to check to see if list is empty \n";
  cout << "'l' to show length of the list \n";
  cout << "'s v' Is value v in the list?  \n";
  cout << "'k v' to show the vth value in list \n";
  cout << "'p' to print the list \n";
  cout << "'m' to show menu \n";
  cout << "'q' to quit program \n";
}

class Node
{
public:
  int data;
  Node *next;
    Node ()			//starts the list
  {
    data = 0;
    next = NULL;
  }
  Node (int data)		//adds to the list
  {
    this->data = data;
    this->next = NULL;
  }
};

//*********************************************
class linkedList
{
  Node *head;
public:
  // The constructor
    linkedList ()
  {
    head = NULL;
  }

  //Inserts value into list
  //Precondition: user inputs integer value
  //Postcondition: integer is added to list
  void insertNode (int);

  //Prints the list
  //Postcondition: List is printed
  void printList ();

  //Checks if list is empty or not
  //Postcondition: Says wheither or not the list is empty
  void listCheck ();

  //Deletes the value at given position
  //Postcondition: value is removed from list
  void deleteNode (int);

  //Clears the list
  //Postcondition: list is empty
  void deleteList ();

  //Gets length of list
  //Postcondition: prints length of list
  void listLength ();

  //Prints value at given position
  //Postcondition: prints an integer
  void posValue (int);

  //Searches for given value
  //Postcondition: confirms if number is found
  bool valueSearch (int);
};

//***********************************************************
void linkedList::deleteNode (int n)
{
  Node *temp1 = head, *temp2 = NULL;
//Special case to delete head
  if (temp1->data == n)
    {
      head = head->next;
      delete temp1;
      return;
    }

  while (temp1 != NULL)
    {
      if (temp1->data == n)
	{			//if value is found, delete it
	  temp2->next = temp1->next;
	  delete temp1;
	  return;
	}
      temp2 = temp1;		//Updates temp 2 and 1 if not equal
      temp1 = temp1->next;
    }
  return;
}

//***********************************************************
bool linkedList::valueSearch (int n)
{
  Node *temp1 = head, *temp2 = NULL;
  while (temp1 != NULL)
    {
      if (temp1->data == n)	//loops to see if any value is equal to desired value
	return true;		//returns true if value is found
      temp1 = temp1->next;	//moves temp1
    }
  return false;
}

//************************************************************
void linkedList::posValue (int nodeOffset)
{
  int position = nodeOffset;
  Node *temp1 = head, *temp2 = NULL;
  int length = 0;
  while (temp1 != NULL)
    {
      temp1 = temp1->next;	//finds lengh of list
      length++;
    }
  if (length < nodeOffset)
    {
      cout << "Index out of range" << endl;	//Checks to make sure that desired position
      return;			//is in the range of the list
    }
  temp1 = head;
  while (nodeOffset-- > 1)
    {				//counts down to desired position
      temp2 = temp1;		// Update temp2
      temp1 = temp1->next;	// Updates temp1
    }
  cout << "The value in position " << position << " is " << temp1->
    data << endl;
}

//***********************************************************
void linkedList::listLength ()
{
  Node *temp = head;
  int length = 0;
  while (temp != NULL)
    {
      temp = temp->next;	//counter goes up every time
      length++;			//temp can move a value
    }
  cout << "The length of the list is " << length << endl;
}

//***********************************************************
void linkedList::deleteList ()
{
  Node *temp1 = head, *temp2 = NULL;

  while (temp1 != NULL)
    {
      temp2 = temp1->next;	//Update temp2    
      delete temp1;		//deletes temp1
      temp1 = temp2;		//redefines temp1

    }
  head = NULL;			//resets list
}

//***********************************************************
void linkedList::insertNode (int data)
{
  Node *newNode = new Node (data);
  // Assign to head
  if (head == NULL)
    {
      head = newNode;
      return;
    }
  Node *temp = head;		//move to end of list
  while (temp->next != NULL)
    {
      temp = temp->next;	//move temp
    }
  temp->next = newNode;		//insert value
}

//***********************************************************
void linkedList::listCheck ()
{
  Node *temp = head;
  // Check for empty list.
  if (head == NULL)
    {
      cout << "List empty" << endl;
      return;
    }
  else
    cout << "List is not empty" << endl;
  return;
}

//*********************************************************
void linkedList::printList ()
{
  Node *temp = head;

  if (head == NULL)
    {
      cout << "List empty" << endl;	//Check for empty list
      return;
    }

  cout << "List values: < ";
  while (temp != NULL)
    {
      cout << temp->data << " ";	//prints value then ,
      temp = temp->next;	//moves to next node
    }
  cout << ">\n";
}

//***********************************************************
//***********************************************************
int
main ()
{
  bool search = false;
  int n;
  linkedList list;
  char choice;

  showmenu ();
  cout << "Please indicate your choice of operation (m for menu): ";
  cin >> choice;

  while ((choice != 'q') && (choice != 'Q'))
    {
      switch (choice)		//allows to select menu options using letter
    {				//both Upper and lower case
	case 'e':
	case 'E':
	  list.deleteList ();
	  cout << "List cleared" << endl;
	  break;
	case 'i':
	case 'I':
	  cin >> n;
	  list.insertNode (n);
	  break;
	case 'r':
	case 'R':
	  cin >> n;
	  list.deleteNode (n);
	  break;
	case 'c':
	case 'C':
	  list.listCheck ();
	  break;
	case 'l':
	case 'L':
	  list.listLength ();
	  break;
	case 's':
	case 'S':
	  cin >> n;
	  search = list.valueSearch (n);
	  if (search == true)
	    cout << "The value " << n << " is in the list" << endl;
	  else
	    cout << "The value " << n << " is not in the list" << endl;
	  break;
	case 'k':
	case 'K':
	  cin >> n;
	  list.posValue (n);
	  break;
	case 'p':
	case 'P':
	  list.printList ();
	  break;
	case 'm':
	case 'M':
	  showmenu ();
	  break;
	default:
	  cout << "Not a valid choice" << endl;
	}
      cin.ignore (200, '\n');
      cin.clear ();		//clear out all input  
      cout << "Please indicate your choice of operation (m for menu): ";
      cin >> choice;
    }

  cout << "Thank you, good-bye! \n";
return 0;
}

