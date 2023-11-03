#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

char findWinningAction(char opponent)
{
	char action = 'X';
	for (int i = 0; i < 2; i++)
	{
		if ((action == 'X' && opponent == 'C') || (action == 'Y' && opponent == 'A') || (action == 'Z' && opponent == 'B'))
			break;
		action++;
	}
	return action;
}

char findDrawingAction(char opponent)
{
	char action = 'X';
	for (int i = 0; i < 2; i++)
	{
		if ((action == 'X' && opponent == 'A') || (action == 'Z' && opponent == 'C') || (action == 'Y' && opponent == 'B'))
			break;
		action++;
	}
	return action;
}

char findLosingAction(char opponent)
{
	char action = 'X';
	for (int i = 0; i < 2; i++)
	{
		if ((action == 'X' && opponent == 'B') || (action == 'Z' && opponent == 'A') || (action == 'Y' && opponent == 'C'))
			break;
		action++;
	}
	return action;
}

int part1(std::map<char, int> values)
{
	std::fstream file("data.txt");
	int totalScore = 0;
	std::string line;
	while (std::getline(file, line))
	{
		char opponent = line[0];
		char player = line[2];

		totalScore += values[player];

		if ((player == 'X' && opponent == 'A') || (player == 'Z' && opponent == 'C') || (player == 'Y' && opponent == 'B'))
			totalScore += 3;
		else if ((player == 'X' && opponent == 'C') || (player == 'Y' && opponent == 'A') || (player == 'Z' && opponent == 'B'))
			totalScore += 6;
	}
	file.close();
	return totalScore;
}

int part2(std::map<char, int> values)
{
	std::fstream file("data.txt");
	int totalScore = 0;
	std::string line;
	while (std::getline(file, line))
	{
		char opponent = line[0];
		char roundEnd = line[2];
		char player = 'X';

		if (roundEnd == 'X')
			player = findLosingAction(opponent);
		else if (roundEnd == 'Y') {
			player = findDrawingAction(opponent);
			totalScore += 3;
		}
		else if (roundEnd == 'Z') {
			player = findWinningAction(opponent);
			totalScore += 6;
		}

		totalScore += values[player];
	}
	file.close();
	return totalScore;
}

int main()
{
	std::map<char, int> values =
	{
		{'X', 1},
		{'Y', 2},
		{'Z', 3}
	};
	std::cout << part1(values) << std::endl;
	std::cout << part2(values) << std::endl;
}