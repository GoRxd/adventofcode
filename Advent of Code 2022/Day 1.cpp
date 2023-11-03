#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int mostCalories(std::vector<int> totalCalories)
{
	int max = totalCalories[0];
	for (int i = 1; i < totalCalories.size(); i++)
	{
		if (max < totalCalories[i])
			max = totalCalories[i];
	}
	return max;
}

int caloriesOfTop3(std::vector<int> totalCalories)
{
	int calories = 0;
	for (int i = 0; i < 3; i++)
	{
		int max = mostCalories(totalCalories);
		calories += max;
		for (int i = 0; i < totalCalories.size(); i++)
		{
			if (max == totalCalories[i])
			{
				totalCalories.erase(totalCalories.begin() + i);
			}
		}
	}
	return calories;
}

void loadData(std::fstream& file, std::vector<int>& totalCalories)
{
	int numOfCalories = 0;

	std::string line;
	while (std::getline(file, line))
	{
		if (line == "")
		{
			totalCalories.push_back(numOfCalories);
			numOfCalories = 0;
		}
		else
		{
			numOfCalories += std::stoi(line);
		}
	}
	totalCalories.push_back(numOfCalories);
}

int main()
{
	std::fstream file("data.txt");
	std::string line;
	std::vector<int> totalCalories;
	
	loadData(file, totalCalories);

	std::cout << mostCalories(totalCalories) << std::endl;

	std::cout << caloriesOfTop3(totalCalories) << std::endl;

	file.close();
}