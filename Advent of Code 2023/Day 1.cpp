#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int part1(std::string& line)
{
	std::string combined;
	char firstDigit;
	char lastDigit;
	for (int i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i]))
		{
			firstDigit = line[i];
			break;
		}
	}
	for (int i = line.size() - 1; i >= 0; i--)
	{
		if (isdigit(line[i]))
		{
			lastDigit = line[i];
			break;
		}
	}
	combined = firstDigit;
	combined += lastDigit;

	return std::stoi(combined);
	
}

char spelledDigit(std::string& line, int currIndex, std::map<std::string, char>& spelledDigits)
{
	for (auto& spell : spelledDigits)
	{
		int good = 0;
		for (int i = currIndex; i < currIndex + spell.first.size(); i++)
		{
			if (spell.first[i - currIndex] == line[i])
				good++;
			else break;
		}
		if (good == spell.first.size())
			return spell.second;
	}
	return ' ';
}

int part2(std::string& line, std::map<std::string, char>& spelledDigits)
{
	std::string combined;
	char firstDigit;
	char lastDigit;


	for (int i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i]))
		{
			firstDigit = line[i];
			break;
		}
		else
		{
			char potentialFirst = spelledDigit(line, i, spelledDigits);
			if (potentialFirst != ' ')
			{
				firstDigit = potentialFirst;
				break;
			}
		}
	}
	for (int i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i]))
		{
			lastDigit = line[i];
		}
		else
		{
			char potentialFirst = spelledDigit(line, i, spelledDigits);

			if (potentialFirst != ' ')
				lastDigit = potentialFirst;
		}
	}
	combined = firstDigit;
	combined += lastDigit;
	return std::stoi(combined);
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

	int sum = 0;

	std::map<std::string, char> spelledDigits = {
		{"one", '1'},
		{"two", '2'},
		{"three", '3'},
		{"four", '4'},
		{"five", '5'},
		{"six", '6'},
		{"seven", '7'},
		{"eight", '8'},
		{"nine", '9'},
	};

	while (getline(file, line))
	{
		//sum += part1(line);
		sum += part2(line, spelledDigits);
	}
	std::cout << sum << std::endl;
}