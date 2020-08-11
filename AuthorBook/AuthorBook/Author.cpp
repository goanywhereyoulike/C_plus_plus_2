#include<iostream>
#include<string>
#include<memory>
#include "Author.h"
#include "Book.h"
using namespace std;

Author::Author(std::string const & authorname) :name(authorname)
{
}

Author::Author(Author&& author): name(std::move(author.name)),weakBookPtr(std::move(author.weakBookPtr))
{
	std::cout << "Move constructor called" << std::endl;

}

Author & Author::operator=(Author&& other)
{
	std::cout << "Move assignment called" << std::endl;
	if (this != &other)
	{
		name = std::move(other.name);
		weakBookPtr = std::move(other.weakBookPtr);

		return *this;
	}
}



Author::~Author()
{
	cout << "Destructor for Author: " << name << endl;
}

void Author::printBookTitle()
{
	int count = 0;
	cout << "Author " << name << " wrote the books: " << endl;
	for (int i = 0; i < weakBookPtr.size(); i++)
	{
		
		shared_ptr<Book>bookptr = weakBookPtr[i].lock();
		
		if (bookptr)
		{

			//cout << "printBookTitle Reference count for book " << bookptr->title << " is " << bookptr.use_count() << endl;
			//cout << "Author " << name << " wrote the above book" << endl;
			cout << "[" << i+1 << "]:" << bookptr->title << endl;
			count++;
		}


			//cout << "The Author has no book any more" << endl;
	}
	if (count == 0)
	{
		cout << "The Author has no book any more" << endl;
	}
	cout << endl;
}
