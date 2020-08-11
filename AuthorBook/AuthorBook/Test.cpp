#include<iostream>
#include<memory>
#include<array>
#include<string>
#include "Author.h"
#include "Book.h"

using namespace std;

int main()
{
	shared_ptr<Book> bookPtr11 = make_shared<Book>("Curtain");
	shared_ptr<Book> bookPtr12 = make_shared<Book>("Sleeping");
	shared_ptr<Book> bookPtr13 = make_shared<Book>("The Murder at the Vicarage");
	shared_ptr<Book> bookPtr21 = make_shared<Book>("The Comedy of Errors");
	shared_ptr<Book> bookPtr22 = make_shared<Book>("A midsummer Night's Dream");
	shared_ptr<Book> bookPtr23 = make_shared<Book>("Merchant of Venice");	
	shared_ptr<Book> bookPtr31 = make_shared<Book>("Harry Potter");
	shared_ptr<Book> bookPtr32 = make_shared<Book>("Fantastic Beasts and where to find them");
	shared_ptr<Book> bookPtr41 = make_shared<Book>("War and Peace");
	shared_ptr<Book> bookPtr42 = make_shared<Book>("Anna Karenina");
	shared_ptr<Book> bookPtr5 = make_shared<Book>("Tiny Pretty Things");
	shared_ptr<Book> bookPtr6 = make_shared<Book>("Zenith");
	shared_ptr<Book> bookPtr7 = make_shared<Book>("Tales from the Shadowhunter Academy");
	
	shared_ptr<Author> authorPtr1 = make_shared<Author>("Agatha Christie");
	shared_ptr<Author> authorPtr2 = make_shared<Author>("William Shakespeare");
	shared_ptr<Author> authorPtr3 = make_shared<Author>("J.K. Rowling");
	shared_ptr<Author> authorPtr4 = make_shared<Author>("Leo Tolstoy");

	shared_ptr<Author> authorPtr5 = make_shared<Author>("Sona Charaipotra");
	shared_ptr<Author> authorPtr6 = make_shared<Author>("Dhonielle Clayton");

	shared_ptr<Author> authorPtr7 = make_shared<Author>("Sasha Alsberg");
	shared_ptr<Author> authorPtr8 = make_shared<Author>("Lindsay Cummings");

	shared_ptr<Author> authorPtr9 = make_shared<Author>("Cassandra Clare");
	shared_ptr<Author> authorPtr10 = make_shared<Author>("Sarah Rees Brennan");
	shared_ptr<Author> authorPtr11 = make_shared<Author>("Maureen Johnson");
	shared_ptr<Author> authorPtr12 = make_shared<Author>("Robin Wasserman");

	array<shared_ptr<Author>, 12> authorPtr{ authorPtr1, authorPtr2, authorPtr3, authorPtr4,authorPtr5,authorPtr6,authorPtr7,authorPtr8,authorPtr9,authorPtr10,authorPtr11,authorPtr12 };
	array<shared_ptr<Author>, 2> authorPtra{ authorPtr5,authorPtr6 };
	array<shared_ptr<Author>, 2> authorPtrb{ authorPtr7,authorPtr8 };
	array<shared_ptr<Author>, 4> authorPtrc{ authorPtr9,authorPtr10, authorPtr11,authorPtr12 };

	vector<shared_ptr<Book>> bookPtr1{ bookPtr11,bookPtr12, bookPtr13 };
	vector<shared_ptr<Book>> bookPtr2{ bookPtr21,bookPtr22, bookPtr23 };
	vector<shared_ptr<Book>> bookPtr3{ bookPtr31,bookPtr32};
	vector<shared_ptr<Book>> bookPtr4{ bookPtr41,bookPtr42};


	array<shared_ptr<Book>, 3> CrimeBooks{ bookPtr11,bookPtr12,bookPtr13 };
	array<shared_ptr<Book>, 3> PlayBooks{ bookPtr21,bookPtr22, bookPtr23 };
	array<shared_ptr<Book>, 3> 	FantasyBooks{ bookPtr31,bookPtr32,bookPtr7 };
	array<shared_ptr<Book>, 3> NovelsBooks{ bookPtr41,bookPtr42,bookPtr5 };
	array<shared_ptr<Book>, 1> ScienceFictionBooks{ bookPtr6 };

	
	//{ CrimeBooks,PlayBooks,FantasyBooks,NovelsBooks,ScienceFictionBooks };
	for (int i = 0; i < 3; i++)
	{
		authorPtr1->weakBookPtr.push_back(bookPtr1[i]);
		//cout << "Ref count for book: " << bookPtr1[i].use_count() << endl;

		bookPtr1[i]->sharedAuthorPtr[i] = authorPtr1;
		//bookPtr1[i]->printAuthorName();
	}
	for (int i = 0; i < 3; i++)
	{
		authorPtr2->weakBookPtr.push_back(bookPtr2[i]);
		//cout << "Ref count for book: " << bookPtr1[i].use_count() << endl;

		bookPtr2[i]->sharedAuthorPtr[i] = authorPtr2;
		//bookPtr2[i]->printAuthorName();
	}
	for (int i = 0; i < 2; i++)
	{
		authorPtr3->weakBookPtr.push_back(bookPtr3[i]);
		//cout << "Ref count for book: " << bookPtr1[i].use_count() << endl;

		bookPtr3[i]->sharedAuthorPtr[i] = authorPtr3;
		//bookPtr3[i]->printAuthorName();
	}

	for (int i = 0; i < 2; i++)
	{
		authorPtr4->weakBookPtr.push_back(bookPtr4[i]);
		//cout << "Ref count for book: " << bookPtr1[i].use_count() << endl;

		bookPtr4[i]->sharedAuthorPtr[i] = authorPtr4;
		//bookPtr4[i]->printAuthorName();
	}
	//cout << "Ref count for author: " << authorPtr.use_count() << endl;


	for (int i = 0; i < 2; i++)
	{
		authorPtra[i]->weakBookPtr.push_back(bookPtr5);
		bookPtr5->sharedAuthorPtr[i] = authorPtra[i];
	}

	for (int i = 0; i < 2; i++)
	{
		authorPtrb[i]->weakBookPtr.push_back(bookPtr6);
		bookPtr6->sharedAuthorPtr[i] = authorPtrb[i];
	}

	for (int i = 0; i < 4; i++)
	{
		authorPtrc[i]->weakBookPtr.push_back(bookPtr7);
		bookPtr7->sharedAuthorPtr[i] = authorPtrc[i];
	}

	for (int i = 0; i < 12; i++)
	{
		authorPtr[i]->printBookTitle();
	}

	shared_ptr<Book> bookPtr10 = move(bookPtr7);
	//for (int i = 0; i < 2; i++)
	//{
	//	cout << "Ref count for book, after print: " << bookPtr[i].use_count() << endl;
	//}
	//cout << "Ref count for author, after print: " << authorPtr.use_count() << endl;
	//bookPtr4[0]->printAuthorName();
	//bookPtr5->printAuthorName();
	//bookPtr7->printAuthorName();

	array<array<shared_ptr<Book>, 3>, 5> BookGenre;
	for (int j = 0; j < 3; j++)
	{
		BookGenre[0][j] = CrimeBooks[j];
		BookGenre[1][j] = PlayBooks[j];
		BookGenre[2][j] = FantasyBooks[j];
		BookGenre[3][j] = NovelsBooks[j];
	}
	BookGenre[4][0] = ScienceFictionBooks[0];

	Book b1("What");
	Book b3("how");
	b1.sharedAuthorPtr[0] = authorPtr1;
	Book b2 = move(b1);
	b2 = move(b3);
	b2.printAuthorName();




	BookGenre[1][2]->printAuthorName();
	bookPtr10->printAuthorName();
	cout << "About to leave the scope" << endl;
	system("pause");
	return 0;

}