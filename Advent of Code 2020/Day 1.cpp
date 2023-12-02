#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int multiplyTwoCorrectEntries(std::vector<int>& entries)
{
	for (int i = 0; i < entries.size(); i++)
	{
		for (int k = i + 1; k < entries.size(); k++)
		{
			if (entries[i] + entries[k] == 2020)
				return entries[i] * entries[k];
		}
	}
}

int multiplyThreeCorrectEntries(std::vector<int>& entries)
{
	for (int i = 0; i < entries.size(); i++)
	{
		for (int k = i + 1; k < entries.size(); k++)
		{
			for (int j = k + 1; j < entries.size(); j++)
			{
				if (entries[i] + entries[k] + entries[j] == 2020)
					return entries[i] * entries[k] * entries[j];
			}
		}
	}
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

	std::vector<int> entries;

	while (std::getline(file, line))
	{
		entries.push_back(std::stoi(line));
	}
	std::cout << multiplyTwoCorrectEntries(entries) << std::endl;
	std::cout << multiplyThreeCorrectEntries(entries) << std::endl;
}