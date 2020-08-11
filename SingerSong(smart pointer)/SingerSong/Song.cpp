#include"Song.h"
#include <iostream>

Song::Song(const std::string& SongTitle)
{
	title = SongTitle;
}

void Song::printSingerName()
{
	std::cout << title << std::endl;
}