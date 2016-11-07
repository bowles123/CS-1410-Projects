// Class definition for the ListException and List, Brian Bowles, 04/15/14.
#ifndef BOWLLIST_H
#define BOWLLIST_H

#include <exception>
using namespace std;

namespace Bowles
{
	// ListException class.
	class ListException: public exception
	{
	// Member function (constructor).
	public:
		ListException (char *list): exception (list)
		{}
	};

	// List class template.
	template <typename T>
	class List
	{
	// Member functions.
	public:
		List ()
		{ head_ = 0; }
		void append (T newItem);
		void display () const;
		void remove (T item);
		~List ();
	// Data members.
	private:
		// New datatype for the linked list.
		struct Node
		{
			T item;
			Node *next;
		};
		Node *head_;
	};

	// This function adds an item to the end of the list.
	template <typename T>
	void List<T>:: append (T newItem)
	{
		// Variables.
		Node *newPtr = 0, *current = head_;
		
		// Traverse to the end of the linked list.
		if (head_ == 0)
		{
			head_ = new Node;
			head_ -> item = newItem;
			head_ -> next = 0;
			delete newPtr;
			delete current;
		}
		else
		{
			newPtr = new Node;
			newPtr -> item = newItem;
			newPtr -> next = 0;

			while (current -> next != 0)
				current = current -> next;
			current -> next = newPtr;
		}
	}

	// This function displays the contents of the list.
	template <typename T>
	void List<T>:: display () const
	{
		// Variable.
		Node * current = head_;

		// Traverse through the list and display the contents of the list.
		while (current != 0)
		{
			if (current -> next == 0)
				cout << current -> item << ".";
			else
				cout << current -> item << ", ";
			current = current -> next;
		}
		cout << endl;
	}

	// This function removes a specified item from the linked list.
	template <typename T>
	void List<T>:: remove (T item)
	{
		// Variables.
		Node *current = head_, *prev = 0;

		// Throw an exception if the list is empty.
		if (current == 0)
			throw ListException ("Empty list.");

		// Find the item to remove.
		while (current != 0 && current -> item != item)
		{
			prev = current;
			current = current -> next;
			if (current == 0)
				throw ListException ("Item not there.");
		}

		// Remove the node with the specified item in it.
		if (current == head_)
			head_ = head_ -> next;
		else
			prev -> next = current -> next;
		delete current;
	}

	// Destructor.
	template <typename T>
	List<T>:: ~List ()
	{
		// Variable.
		Node *ptr;

		// Delete the Nodes one at a time.
		while (head_ != 0)
		{
			ptr = head_;
			head_ = head_ -> next;
			delete ptr;
		}
	}
}
#endif