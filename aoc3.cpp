#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "aoc3.h"

void day3Part1()
{
	std::ifstream filein("aoc03.txt");

	if (filein.is_open())
	{
		std::string input;
		std::vector<int> gammaRate;
		std::vector<int> epsilonRate;
		int gammaDec{ 0 };
		int epsilonDec{ 0 };
		std::vector<int> totals;
		int lineCount{ 0 };

		while (std::getline(filein, input))
		{
			for (size_t i{ 0 }; i < input.length(); i++)
			{
				if (totals.size() < input.length())
				{
					totals.push_back(input[i] - '0');
				}
				else
				{
					totals[i] += (input[i] - '0');
				}
			}
			lineCount++;
		}

		for (size_t i{ 0 }; i < totals.size(); i++)
		{
			if (totals[i] >= lineCount / 2)
			{
				gammaRate.push_back(1);
				epsilonRate.push_back(0);
			}
			else
			{
				gammaRate.push_back(0);
				epsilonRate.push_back(1);
			}
		}

		size_t g{0};
		for (size_t i{ gammaRate.size() }; i > 0; i--)
		{
			gammaDec += (int)(gammaRate[i - 1] * pow(2, g));
			g++;
		}

		size_t e = 0;
		for (size_t i{ epsilonRate.size() }; i > 0; i--)
		{
			epsilonDec += (int)(epsilonRate[i - 1] * pow(2, e));
			e++;
		}

		for (size_t g : gammaRate)
		{
			std::cout << g;
		}
		std::cout << '\n';

		std::cout << "Gamma and Epsilon rate multiplied together = " << gammaDec * epsilonDec << '\n';

		filein.close();
	}
}

void day3Part2()
{
	std::ifstream filein("aoc03.txt");

	if (filein.is_open())
	{
		std::string input;
		int mostCommon{ 0 };
		int leastCommon{ 0 };
		std::vector<std::string> numbers;
		std::vector<std::string> otherNumbers;
		std::string oxGenRat;
		std::string coScrubRat;

		while (std::getline(filein, input))
		{
			numbers.push_back(input);
			otherNumbers.push_back(input);
		}

		// Calculate the Oxygen Generator Rating
		for (size_t i{ 0 }; i < input.length(); i++)
		{
			for (std::string number : numbers)
			{
				if (number[i] == '1')
				{
					mostCommon++;
				}
			}

			mostCommon = mostCommon >= numbers.size() / 2.0 ? '1' : '0';

			for (size_t j{ 0 }; j < numbers.size(); j++)
			{
				if (numbers[j][i] != mostCommon)
				{
					auto itr = std::find(numbers.begin(), numbers.end(), numbers[j]);
					if (itr != numbers.end())
					{
						numbers.erase(itr);
						j--;
					}
				}
			}

			if (numbers.size() == 1)
			{
				oxGenRat = numbers[0];
				break;
			}

			mostCommon = 0;
		}

		// Calculate the CO2 scrubber rating
		for (size_t i{ 0 }; i < input.length(); i++)
		{
			for (std::string number : otherNumbers)
			{
				if (number[i] == '1')
				{
					leastCommon++;
				}
			}

			std::cout << leastCommon << " " << otherNumbers.size() / 2 << '\n';

			if (leastCommon >= otherNumbers.size() / 2.0)
			{
				leastCommon = '0';
			}
			else
			{
				leastCommon = '1';
			}


			for (size_t j{ 0 }; j < otherNumbers.size(); j++)
			{
				if (otherNumbers[j][i] != leastCommon)
				{
					auto itr = std::find(otherNumbers.begin(), otherNumbers.end(), otherNumbers[j]);
					if (itr != otherNumbers.end())
					{
						otherNumbers.erase(itr);
						j--;
					}
				}
			}

			if (otherNumbers.size() == 1)
			{
				coScrubRat = otherNumbers[0];
				std::cout << coScrubRat << '\n';
				break;
			}

			leastCommon = 0;
		}

		unsigned long long oxDec = std::stoull(oxGenRat, 0, 2);
		unsigned long long coDec = std::stoull(coScrubRat, 0, 2);

		std::cout << "Oxygen Generator Rating : " << oxGenRat << " CO2 Scrubber Rating : " << coScrubRat << '\n';
		std::cout << "Oxygen Generator Rating : " << oxDec << " CO2 Scrubber Rating : " << coDec << '\n';
		std::cout << oxDec * coDec;

		filein.close();
	}
}