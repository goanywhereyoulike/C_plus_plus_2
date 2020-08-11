#pragma once
#include <string>
#include <memory>
#include <vector>


class Book;// forward declaration of class book
class Author
{
public:
	Author(std::string const & authorname);
	Author(Author&& author);
	Author& operator=(Author&& other);
	~Author();//destructor
	void printBookTitle();
	std::string name;
	//std::weak_ptr<Book> weakBookPtr;//Book the author wrote

	std::vector<std::weak_ptr<Book>> weakBookPtr;



};