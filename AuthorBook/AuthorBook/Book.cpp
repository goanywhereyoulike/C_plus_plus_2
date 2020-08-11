#include<iostream>
#include<string>
#include<memory>
#include "Author.h"
#include "Book.h"
using namespace std;

Book::Book(std::string const & bookname) :title(bookname)
{
}

Book::Book(Book&& other):title(std::move(other.title)),sharedAuthorPtr(std::move(other.sharedAuthorPtr))
{
	std::cout << "Move constructor called" << std::endl;

}

Book & Book::operator=(Book&& other)
{
	std::cout << "Move assignment called" << std::endl;
	if (this != &other)
	{
		title = std::move(other.title);
		sharedAuthorPtr = std::move(other.sharedAuthorPtr);
		return *this;
	}
}

Book::~Book()
{
	cout << "Destroying book: " << title << endl;
}

void Book::printAuthorName()
{
	//shared_ptr<Author> authorptr = weakAuthorPtr.lock();
	int count = 0;
	cout << "The authors of the book " << title << " is:" << endl;
	for (int i = 0; i < sharedAuthorPtr.size(); i++)
	{
		shared_ptr<Author> Authorptr = sharedAuthorPtr[i];
		if (Authorptr)
		{
			cout << "[" << i + 1 << "]:" << Authorptr->name << endl;
			//cout << "printAuthorName Reference count for Author " << Authorptr->name << " is " << Authorptr.use_count() << endl;
			count++;
		}
	
	}
	if (count == 0)
	{
		cout << "This book has no Author" << endl;
	}
	cout << endl;
}
