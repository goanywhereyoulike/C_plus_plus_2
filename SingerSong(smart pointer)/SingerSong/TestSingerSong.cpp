
/*
This project is a practice in using shared pointers. 2 classes, Singer and Song, header files is included
in this project. A Singer has a vector of song pointers which represent the songs he/she has sung.
A Song has a pointer to its singer.
We want to turn all raw pointers into shared pointers. You can use either RefCounterSharedPtr we
developed in class, or better use std::shared<T> from std, which is included in memory.h.
Create a Singer, give it the name of your favorite singer, and create a vector of 3 or 4 songs of this singer.
Once this is done, print out the Ref count for each shared object. The start deleting the songs one by one
and at the end delete the singer object.
*/
#include <iostream>
#include <memory>
#include <string>
#include "Singer.h"
#include "Song.h"
using namespace std;



int main()
{
	shared_ptr<Singer> p1 = make_shared<Singer>("Adam");

	shared_ptr<Song> s11 = make_shared<Song>("Hello");
	shared_ptr<Song> s12 = make_shared<Song>("World");
	shared_ptr<Song> s13 = make_shared<Song>("Love");
	shared_ptr<Song> s14 = make_shared<Song>("Happy end");
	cout << "The singer " << p1->name << "'s songs are: " << endl;
	vector<shared_ptr<Song>> s1{ s11, s12, s13, s14 };
	p1->songs = s1;
	//p1->songs.push_back(s11);
	//p1->songs.push_back(s12);
	//p1->songs.push_back(s13);
	//p1->songs.push_back(s14);
	cout << s11.use_count() << endl;
	p1->printSongsTitles();
	s11.reset();
	s12.reset();
	s13.reset();
	s14.reset();
	p1.reset();

	cout <<"Singer Adam's Ref count:"<< p1.use_count() << endl;

	system("pause");
}