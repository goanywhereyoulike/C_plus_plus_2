#pragma once
#include <string>
#include <memory>
#include <array>

class Author;// forward declaration of class book
class Book
{
public:
 Book(std::string const & bookname);
	Book(Book && other);
	Book& operator=(Book&& other);
	~Book();//destructor

	std::string title;
	//std::weak_ptr<Author> weakAuthorPtr;
	std::array<std::shared_ptr<Author>,10> sharedAuthorPtr;

	void printAuthorName();


};
