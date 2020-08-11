#pragma once
#include <string>

class Singer; // forward declaration

class Song
{
public:
	std::string title;
	std::shared_ptr<Singer> SingerPtr;
public:
	Song(const std::string& SongTitle);
	~Song() {}
	void printSingerName();



};
