#pragma once

#include <string>
#include <vector>

class Song;

class Singer
{
public:
	std::string name;
	std::vector<std::shared_ptr<Song>> songs;
public:
	Singer(const std::string& SingerName);

	~Singer() {}
	void printSongsTitles();

	

};
