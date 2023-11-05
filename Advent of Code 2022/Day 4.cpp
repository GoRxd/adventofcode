#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

bool doesFullyContainOther(std::vector<short> firstRange, std::vector<short> secRange)
{
	short contained = 0;

	for (int i = 0; i < firstRange.size(); i++)
	{
		for (int k = 0; k < secRange.size(); k++)
		{
			if (firstRange[i] == secRange[k])
				contained++;
		}
	}

	int smallestSize = (firstRange.size() > secRange.size()) ? secRange.size() : firstRange.size();

	return contained == smallestSize;
}

bool doesOverlapAtAll(std::vector<short> firstRange, std::vector<short> secRange)
{
	for (int i = 0; i < firstRange.size(); i++)
	{
		for (int k = 0; k < secRange.size(); k++)
		{
			if (firstRange[i] == secRange[k])
				return true;
		}
	}
	return false;
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

	int overlappingPairs = 0;

	while (std::getline(file, line))
	{
		std::vector<short> firstRange;
		std::vector<short> secRange;

		std::string firstPath = line.substr(0, line.find(','));

		short start = std::stoi(firstPath.substr(0, firstPath.find('-')));
		short end = std::stoi(firstPath.substr(firstPath.find('-') + 1, firstPath.size() - 1));

		for (int i = start; i <= end; i++)
			firstRange.push_back(i);

		std::string secPath = line.substr(line.find(',') + 1, line.size() - 1);

		start = std::stoi(secPath.substr(0, secPath.find('-')));
		end = std::stoi(secPath.substr(secPath.find('-') + 1, secPath.size() - 1));

		for (int i = start; i <= end; i++)
			secRange.push_back(i);

		if (doesFullyContainOther(firstRange, secRange)) // doesFullyContainOther - part 1, doesOverlapAtAll - part 2.
			overlappingPairs++;
	}
	std::cout << overlappingPairs << std::endl;
}