// Class template defintion for the Array class.
#ifndef BOWLARRAY_H
#define BOWLARRAY_H

// Namespace.
namespace Bowles
{
	// Template class definition.
	template <typename T>
	class Array
	{
	// Member functions of the class template.
	public:
		Array ()
		{ ptr_ = new T [size]; size_ = 0;}
		Array (int size)
		{ size_ = size ;  ptr_ = new T [size]; }
		~Array ()
		{ delete [] ptr_; }
		void addElement (T element);
		void removeElement ();
		int getSize ();
		T& operator[] (const int index);
	// Data members of the class template.
	private:
		T *ptr_;
		int size_;
	};

	// This function adds an element to the back of the array.
	template <typename T>
	void Array<T>:: addElement (T element)
	{
		// Temporary pointer to store data in.
		T *tempPtr;

		// Copy data from ptr_ into tempPtr.
		tempPtr = new T [size_ += 1];
		for (int i = 0; i < size_; i++)
			tempPtr [i] = ptr_[i];

		// Assign element to the new element of the array and delete the array ptr_ points to.
		tempPtr [size_ - 1] = element;
		delete [] ptr_;

		// Copy the data from tempPtr to ptr_ and delete the array tempPtr points to.
		ptr_ = new T [size_];
		for (int i = 0; i < size_; i++)
			ptr_ [i] = tempPtr [i];
		delete [] tempPtr;
	}

	// This function deletes an element from the end of the array.
	template <typename T>
	void Array<T>:: removeElement ()
	{
		// Temporary pointer to store data in.
		T *tempPtr;

		// Copy data from ptr_ into tempPtr and delete the array ptr_ points to.
		tempPtr = new T [size_ -= 1];
		for (int i = 0; i < size_; i++)
			tempPtr [i] = ptr_[i];
		delete [] ptr_;

		// Copy the data from tempPtr to ptr_ and delete the array tempPtr points to.
		ptr_ = new T [size_];
		for (int i = 0; i < size_; i++)
			ptr_ [i] = tempPtr [i];
		delete [] tempPtr;
	}

	// Overloaded subscript operator for the Array class template.
	template <typename T>
	T& Array<T>:: operator[] (const int index)
	{
		return ptr_ [index];
	}

	// This function reports the current size of the array.
	template <typename T>
	int Array<T>:: getSize () 
	{
		return size_;
	}
}
#endif