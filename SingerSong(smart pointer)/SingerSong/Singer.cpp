#include"Song.h"
#include "Singer.h"
#include<iostream>

Singer::Singer(const std::string& SingerName)
{
	name = SingerName;
}
void Singer::printSongsTitles()
{
	for (int i = 0; i < 4; ++i)
	{
		std::cout <<"Song name: "<< songs[i]->title <<" ,Ref count: "<< songs[i].use_count() << std::endl;
	}
}