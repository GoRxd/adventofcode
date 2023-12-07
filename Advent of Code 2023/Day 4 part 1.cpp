#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string& str, char del)
{
	std::vector<std::string> splittedStr;
	std::string elem;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == del)
		{
			splittedStr.push_back(elem);
			elem = "";
		}
		else
			elem += str[i];
	}
	splittedStr.push_back(elem);
	return splittedStr;
}

int stringToInt(std::string& str)
{
	if (str.size() >= 2)
		return std::stoi(str);
	else
		return str[0] - '0';
}

std::vector<int> findWinningNumbers(std::vector<int>& firstPair, std::vector<int>& secPair)
{
	std::vector<int> winningNumbers;

	for (int i = 0; i < firstPair.size(); i++)
	{
		for (int k = 0; k < secPair.size(); k++)
		{
			if (firstPair[i] == secPair[k]) {
				winningNumbers.push_back(firstPair[i]);
				break;
			}
		}
	}
	return winningNumbers;
}

int valueOfCard(std::string& card)
{
	int points = 1;
	std::vector<int> firstPair;
	std::vector<int> secPair;
	std::vector<int> winningNumbers;
	std::string number = "";
	std::string numbers = card.substr(card.find(':') + 2, card.size());
	std::vector<std::string> pairs = split(numbers, '|');
	for (auto& p : pairs[0])
	{
		if (isdigit(p))
			number += p;
		else if (number != "")
		{
			firstPair.push_back(stringToInt(number));
			number = "";
		}
	}
	number = "";
	for (auto& p : pairs[1])
	{
		if (isdigit(p))
			number += p;
		else if (number != "")
		{
			secPair.push_back(stringToInt(number));
			number = "";
		}
	}
	secPair.push_back(stringToInt(number));
	winningNumbers = findWinningNumbers(firstPair, secPair);

	if (winningNumbers.size() == 0)
		return 0;

	for (int i = 1; i < winningNumbers.size(); i++)
		points *= 2;

	return points;
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

	int sum = 0;

	while (std::getline(file, line))
	{
		sum += valueOfCard(line);
	}
	std::cout << sum << std::endl;

}