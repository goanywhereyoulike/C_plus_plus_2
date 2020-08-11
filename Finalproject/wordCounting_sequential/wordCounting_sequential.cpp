#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <regex>
#include <future>
#include <vector>
#include <mutex>
#include <thread>


using namespace std;
using WordCountMapType = unordered_map<string, size_t>;

WordCountMapType wordsInFile(const char*filename)
{
	regex re("[\\[\\] \\^ \\ - _ * ×――:·、。，；, .; \"-]");
	ifstream bookFile(filename);
	string word1;
	WordCountMapType wordCounts;
	if (bookFile.good())
	{
		for (string word; bookFile >> word;)
		{
			word1 = regex_replace(word, re, "");
			if(word1!="")
				++wordCounts[word1];
			
		}
	}
	else
	{
		cout << "Failed to open file " << filename << endl;
		
	}

	return wordCounts;
}

bool compare_map(const pair<string, size_t>&a, const pair<string, size_t>&b) {
	return a.second > b.second;
}
// This application reads a text file entered in command line and do word counting for the words in the
// file. Words are separated by space, tab, or next line characters. This project, as it is now, is the 
// bases of the final project. The description of what to do for final is outlined bellow at end of main 
// function. Steps there, do not have to be done in the order specified, as long as all steps are implemented.

vector<pair<string, size_t>> wordcounting(WordCountMapType mainWordMap)
{
	
	
	
	// write a function to find the  most commong word:
	string mostCommonWord{};
	size_t mostCommonWordCount{ 0 };
	for (auto const& wordInfo : mainWordMap)
	{
		if (wordInfo.second > mostCommonWordCount)
		{
			mostCommonWord = wordInfo.first;
			mostCommonWordCount = wordInfo.second;
		}
	}
	//words.push_back(mostCommonWord);
	//cout << "File name: " << filename << endl;
	cout << "Most common word is \"" << mostCommonWord << "\", count= " << mostCommonWordCount << endl;
	//totalamount += mostCommonWordCount;
	vector<pair<string, size_t>> a;
	for (auto &temp : mainWordMap)
	{
		a.push_back(temp);
	}
	sort(a.begin(), a.end(), compare_map);
	int number = 1;
	for (auto it = a.begin(); it < a.begin() + 20; ++it)
	{
		cout << "[" << number << "]word: " << it->first << ", count: " << it->second << endl;
		number++;
	}

	return a;


}




int main(int argc, const char*argv[])
{


	cout << "This application name is " << argv[0] << endl;
	if (argc < 2)
	{
		cout << "Provide a book name to process.";
		return 0;
	}
	else
	{
		int totalamount = 0;
		//vector<string> words;
		//WordCountMapType WordMap;
		vector<pair<string, size_t>> b;
		vector<future<vector<pair<string, size_t>>>> task;
		vector<future<WordCountMapType>> task2;
		vector<WordCountMapType> e;
		vector<WordCountMapType> f;


		cout << endl;




			auto startTime = chrono::system_clock::now();
			for (int i = 1; i < argc; i++)
			{
				WordCountMapType mainWordMap = wordsInFile(argv[i]);
				if (mainWordMap.empty())
				{
					return 0;
				}
				e.push_back(mainWordMap);

			}
			auto endTime = chrono::system_clock::now();
	


			auto startTime2 = chrono::system_clock::now();
			for (int i = 1; i < argc; i++)
			{
				task2.push_back(async(wordsInFile, argv[i]));
			
			}
			for (auto &th : task2)
				f.push_back(th.get());
			auto endTime2 = chrono::system_clock::now();
		

			cout << endl;
		for (int i = 1; i < argc; i++)
		{
			cout << "File name: " << argv[i] << endl;
			auto c = wordcounting(f[i - 1]);
			cout << endl;
			cout << "-------------------------------------------" << endl;



			cout << endl;


			if (i == 1)
			{
				for (auto it = c.begin(); it != c.end(); ++it)
				{
					b.push_back(*it);
				}
			}
			else
			{
				for (auto its = c.begin(); its != c.end(); ++its)
				{
					int number = 0;
					for (auto it = b.begin(); it !=b.end(); ++it)
					{
		

						if (its->first == it->first)
						{
							it->second += its->second;
							number++;
							break;
						}

					}
					if (number == 0)
					{
						b.push_back(*its);
					}
				}
			}

		}


		
		
		sort(b.begin(), b.end(), compare_map);
		int number2 = 1;
		cout << "The total word counting from all files" << endl;
		cout << endl;
		for (auto it = b.begin(); it < b.begin() + 20; ++it)
		{
			cout << "[" << number2 << "]word: " << it->first << ", count: " << it->second << endl;
			number2++;
		}
		//cout << "Most common word is \"" << words[0] << "\", total count= " << totalamount << endl;

		cout << endl;
		cout << "Calculate the loading time" << endl;
		cout << "The time for sequential processing is: " << chrono::duration<double>{endTime - startTime}.count() << "seconds" << endl;
		cout << "The time for multi-thread tasks is: " << chrono::duration<double>{endTime2 - startTime2}.count() << "seconds" << endl;

	}


	// steps to do for this project:
	/*
	0- Modify the above code, so that you "clean" the word before adding it to the map. This mean you should
	remove trailing comma, period, dash, semi-colon, and quaotation marks.
	1- Extend the above solution to process multiple files. This means we should be able to enter multiple
	books on command line. Combine the wordCount for all the files together.
	2- Sort the output using std::sort based on word counts, and save it in a vector.
	3- Print out the 20 most common words and their counts. You should print the most common 20 words for each
	  file and the filename first, following by the most common 20 words overall for all files.
	4- Add basic multi-threading as we did last week to this project. This means you should launch one thread
	per each book being processed. YOu can use either synchronous or async method for multi-threading.
	5- Add timing to this solution. The goal is to see what is the benefit in terms of time of execution we
	get by using multi-threading. So make sure you time the sequential processing separately and the parallel
	processing also separately, so the comparision is fair. Also only compare the loading and reading the words
	from the files, not the later processing and find the common words or such.
	6- I have provided 4 books for testing. You can look up other books in txt format and use as well. I may test
	your exe using any combination of books.

	As usual, hand in the clean porject, with exe in release mode. I will be running your exe from command line,
	so make sure it prints out the steps above clearly. I do mark the quality of your test output as well.
	YOu can finish the project next week in class. The deadline is the end of next week's class time.
	*/
	system("pause");
		return 0;
	
}