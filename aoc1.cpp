#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "aoc1.h"

void day1Part1()
{
	std::ifstream filein("aoc01.txt");

	if (filein.is_open())
	{
		std::string input;
		std::getline(filein, input);
		int previousDepth{ std::stoi(input) };
		int depthIncrCount{ 0 };

		while (std::getline(filein, input))
		{
			if (std::stoi(input) > previousDepth)
			{
				depthIncrCount++;
			}

			previousDepth = std::stoi(input);
		}

		std::cout << "The depth increased " << depthIncrCount << " times" << '\n';

		filein.close();
	}
}

void day1Part2()
{
	std::ifstream filein("aoc01.txt");

	if (filein.is_open())
	{
		std::string input;
		int depthIncrCount{ 0 };
		std::vector<int> windows;
		int measureCount{ 0 };

		while (std::getline(filein, input))
		{
			windows.push_back(std::stoi(input));
			if (measureCount >= 1)
			{
				windows[static_cast<std::vector<int, std::allocator<int>>::size_type>(measureCount) - 1] += std::stoi(input);
			}
			if (measureCount >= 2)
			{
				windows[static_cast<std::vector<int, std::allocator<int>>::size_type>(measureCount) - 2] += std::stoi(input);
			}
			if (measureCount >= 3)
			{
				if (windows[static_cast<std::vector<int, std::allocator<int>>::size_type>(measureCount) - 2] > windows[static_cast<std::vector<int, std::allocator<int>>::size_type>(measureCount) - 3])
				{
					depthIncrCount++;
				}
			}

			measureCount++;
		}

		std::cout << "The depth increased " << depthIncrCount << " times" << '\n';

		filein.close();
	}
}