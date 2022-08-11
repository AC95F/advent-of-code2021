#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "aoc2.h"

void day2Part1()
{
	std::ifstream filein("aoc02.txt");

	if (filein.is_open())
	{
		std::string input;
		int horPos{ 0 };
		int depth{ 0 };

		while (std::getline(filein, input))
		{
			size_t n = input.find(" ");

			std::string direction = input.substr(0, n);
			int move = std::stoi(input.substr(n + 1));

			if (direction.compare("forward") == 0)
			{
				horPos += move;
			}
			else if (direction.compare("down") == 0)
			{
				depth += move;
			}
			else if (direction.compare("up") == 0)
			{
				depth -= move;
			}
		}

		std::cout << "Your final position is : " << horPos * depth << '\n';

		filein.close();
	}
}

void day2Part2()
{
	std::ifstream filein("aoc02.txt");

	if (filein.is_open())
	{
		std::string input;
		int horPos{ 0 };
		int depth{ 0 };
		int aim{ 0 };

		while (std::getline(filein, input))
		{
			size_t n = input.find(" ");

			std::string direction = input.substr(0, n);
			int move = std::stoi(input.substr(n + 1));

			if (direction.compare("forward") == 0)
			{
				horPos += move;
				depth += (aim * move);
			}
			else if (direction.compare("down") == 0)
			{
				aim += move;
			}
			else if (direction.compare("up") == 0)
			{
				aim -= move;
			}
		}

		std::cout << "Your final position is : " << horPos * depth << '\n';

		filein.close();
	}
}