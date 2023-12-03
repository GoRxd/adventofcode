#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int stringToInt(std::string& str)
{
	if (str.size() >= 2)
		return std::stoi(str);
	else 
		return str[0] - '0';
}

bool isAdjacent(std::vector<std::string>& schematic, int& startX, int& endX, int& y)
{
	for (int i = y - 1; i <= y + 1; i++)
	{
		if (i < 0 || i >= schematic.size()) continue;
		for (int x = startX; x <= endX; x++)
		{
			if (x < 0 || x >= schematic[0].size()) continue;
			if (!isdigit(schematic[i][x]) && schematic[i][x] != '.')
				return true;
		}
	}
	return false;
}

int part1(std::vector<std::string>& schematic)
{
	std::string number = "";
	int sum = 0;
	int startX = -1;
	int endX = -1;
	for (int y = 0; y < schematic.size(); y++)
	{
		for (int x = 0; x < schematic[0].size(); x++)
		{
			if (isdigit(schematic[y][x]))
			{
				number += schematic[y][x];
				startX = x - number.size();
			}
			else if (number != "")
			{
				endX = x;
				std::cout << number << " is adjactent: " << isAdjacent(schematic, startX, endX, y) << std::endl;
				if (isAdjacent(schematic, startX, endX, y))
					sum += stringToInt(number);
				number = "";
			}
		}
		if (number != "") {
			endX = schematic[0].size() - 1;
			std::cout << number << " is adjactent: " << isAdjacent(schematic, startX, endX, y) << std::endl;
			if (isAdjacent(schematic, startX, endX, y))
				sum += stringToInt(number);
			number = "";
		}
	}
	return sum;
}

int main()
{
	std::fstream file("data.txt");
	std::string line;
	std::vector<std::string> schematic;

	int sum = 0;

	while (std::getline(file, line))
	{
		schematic.push_back(line);
	}

	sum = part1(schematic);

	std::cout << sum << std::endl;
}