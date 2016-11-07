// Class definition.
#ifndef BOWLSTRING_H
#define BOWLSTRING_H

// Namespace.
namespace Bowles
{
	class String
	{
	// Member functions.
	public:
		String ();
		String (char *);
		~String ();
		void setSize (int);
		void setString (char *);
		void dispalyString () const;
		int getSize ();
	// Data members.
	private:
		char *ptr_;
		int size_;
	};
}
#endif