#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "aoc4.h"

class Board {
public:
	int numbers[5][5];
	bool marks[5][5];
};

void day4Part1() {
	std::ifstream filein("aoc04.txt");
	std::string input;
	std::vector<int> draws;
	std::vector<Board> boards;

	if (filein.is_open()) {
		std::getline(filein, input);

		std::istringstream ss(input);
		std::string token;

		while (std::getline(ss, token, ',')) {
			draws.push_back(std::stoi(token));
		}

		while (std::getline(filein, input)) {
			ss.clear();
			ss.str(input);

			while (std::getline(ss, token, ' ')) {
				if (token == "\n")
					break;
			}
		}


		filein.close();
	}
}

void day4Part2() {
	std::ifstream filein("aoc04.txt");

	if (filein.is_open())
	{
		filein.close();
	}
}