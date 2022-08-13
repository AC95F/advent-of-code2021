#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "aoc4.h"

class Board {
public:
	int squares[5][5];
	bool marks[5][5] = { {false, false, false, false, false},
						{false, false, false, false, false},
						{false, false, false, false, false},
						{false, false, false, false, false},
						{false, false, false, false, false}
						};};

void day4Part1() {
	std::ifstream filein("aoc04.txt");
	std::string input;
	std::vector<int> draws;
	std::vector<Board> boards;
	int currentBoard = -1;
	int currentLine = 0;
	int currentColumn = 0;
	int winningBoard = 0;
	int winningDraw;

	if (filein.is_open()) {
		
		// Registers all the draws
		std::getline(filein, input);

		std::stringstream ss(input);
		std::string token;

		while (std::getline(ss, token, ',')) {
			draws.push_back(std::stoi(token));
		}

		// Fills all the boards
		while(std::getline(filein, input)) {
			if (input.empty()) {
				boards.push_back(Board());
				currentBoard++;
				currentLine = 0;
				currentColumn = 0;
			}
			else {
				ss.clear();
				ss.str(input);
			
				while (std::getline(ss, token, ' ')) {
					if (!token.empty()) {
						boards[currentBoard].squares[currentLine][currentColumn] = std::stoi(token);
						currentColumn++;
						if (currentColumn >= 5) {
							currentLine++;
							currentColumn = 0;
						}
					}
				}
			}
		}

		filein.close();
	}

	// Checks all the winning draws against each square of each board
	for (int draw : draws) {
		for (int m = 0; m < boards.size(); m++) {
			for (size_t i = 0; i < 5; i++) {
				for (size_t j = 0; j < 5; j++) {
					if (boards[m].squares[i][j] == draw) {
						boards[m].marks[i][j] = true;

						// Checks if this is a winning board
						for (int k = 0; k < 5; k++) {
							if (boards[m].marks[k][0] &&
								boards[m].marks[k][1] &&
								boards[m].marks[k][2] &&
								boards[m].marks[k][3] &&
								boards[m].marks[k][4]) {
							winningBoard = m;
							winningDraw = draw;
							goto endloop;
							}
						}

						for (int l = 0; l < 5; l++) {
							if (boards[m].marks[0][l] &&
								boards[m].marks[1][l] &&
								boards[m].marks[2][l] &&
								boards[m].marks[3][l] &&
								boards[m].marks[4][l]) {
							winningBoard = m;
							winningDraw = draw;
							goto endloop;
							}
						}
					}
				}
			}
		}
	}

	endloop:

	// Calculates the final result
	int unmarkedTotal = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!boards[winningBoard].marks[i][j]) {
				unmarkedTotal += boards[winningBoard].squares[i][j];
			}
		}
	}

	std::cout << "The score of the winning board is : " << unmarkedTotal * winningDraw << std::endl;
}

// void day4Part2() {
// 	std::ifstream filein("aoc04.txt");

// 	if (filein.is_open())
// 	{
// 		filein.close();
// 	}
// }