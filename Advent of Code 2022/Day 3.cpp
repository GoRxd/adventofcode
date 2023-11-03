#include <iostream>
#include <fstream>
#include <string>
#include <vector>

char commonItem(std::string firstCompartment, std::string secCompartment)
{
	char item = 'n';
	for (int i = 0; i < firstCompartment.size(); i++)
	{
		for (int k = 0; k < secCompartment.size(); k++)
		{
			if (firstCompartment[i] == secCompartment[k])
			{
				item = firstCompartment[i];
				break;
			}
		}
	}
	return item;
}

int sumPriorities(std::vector<char> items)
{
	int sum = 0;
	for (auto& item : items)
	{
		if (islower(item))
			sum += item - 96;
		else if (isupper(item))
			sum += item - 38;
	}
	return sum;
}

void part1()
{
	std::fstream file("data.txt");
	std::string line;

	std::vector<char> items;

	while (std::getline(file, line))
	{
		std::string firstCompartment = line.substr(0, line.size() / 2);
		std::string secCompartment = line.substr(line.size() / 2, line.size());

		items.push_back(commonItem(firstCompartment, secCompartment));
	}

	std::cout << sumPriorities(items) << std::endl;
}

char commonItemBetweenRucksacks(std::vector<std::string> rucksacks)
{
	char item = 'n';
	for (int i = 0; i < rucksacks[0].size(); i++)
	{
		int sameItems = 0;
		for(int j = 0; j < rucksacks[1].size(); j++)
		{
			if (rucksacks[0][i] == rucksacks[1][j]) {
				sameItems++;
				break;
			}
		}
		for (int k = 0; k < rucksacks[2].size(); k++)
		{
			if (rucksacks[0][i] == rucksacks[2][k]){
				sameItems++;
				break;
			}
		}
		if (sameItems == 2)
		{
			item = rucksacks[0][i];
		}
	}
	return item;
}

void part2()
{
	std::fstream file("data.txt");
	std::string line;

	std::vector<char> items;
	std::vector<std::string> rucksacks;

	int i = 1;

	while (std::getline(file, line))
	{
		rucksacks.push_back(line);

		if (i % 3 == 0)
		{
			items.push_back(commonItemBetweenRucksacks(rucksacks));
			rucksacks.clear();
		}
		i++;
	}
	std::cout << sumPriorities(items) << std::endl;
}

int main()
{
	part1();
	part2();
}