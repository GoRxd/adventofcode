#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string withoutSquareBrackets(std::string& line)
{
	std::string without = "";
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != '[' && line[i] != ']')
			without += line[i];
		else
			without += " ";
	}
	without.erase(without.begin());

	return without;
}

std::vector<std::string> splitToStacks(std::vector<std::string> crates)
{
	std::vector<std::string> stacks;
	for (int x = 0; x < crates[0].size(); x += 4)
	{
		std::string stack;
		for (int y = 0; y < crates.size(); y++) {
			if (crates[y][x] != ' ')
				stack += crates[y][x];
		}

		stacks.push_back(stack);
	}
	return stacks;
}

std::vector<int> returnDigitsFromString(std::string s)
{
	std::string number;
	std::vector<int> digits;
	for (auto& c : s)
	{
		if (isdigit(c)) {
			number += c;
		}
		else if (number.size() > 0) {
			digits.push_back(std::stoi(number));
			number = "";

		}
	}
	if (number.size() > 0) {
		digits.push_back(std::stoi(number));
	}
	return digits;
}

std::string returnPartOfString(std::string s, int start)
{
	std::string part;

	for (int i = start; i < s.size(); i++)
		part += s[i];

	return part;
}

void doCommands(std::vector<std::string>& stacks, std::vector<std::string> commands)
{
	for (auto& command : commands)
	{
		std::vector<int> parameters = returnDigitsFromString(command);

		int quantity = parameters[0];
		int out = parameters[1] - 1;
		int in = parameters[2] - 1;

		if (out >= stacks.size() || in >= stacks.size())
			continue;
		
		for (int i = 0; i < quantity; i++)
			stacks[in].insert(0, 1, stacks[out][i]);

		stacks[out] = returnPartOfString(stacks[out], quantity);
	}
}

bool hasNumberInside(std::string s)
{
	for (auto& c : s)
	{
		if (isdigit(c))
			return true;
	}
	return false;
}

bool hasOnlyNumbersInside(std::string s)
{
	for (auto& c : s)
	{
		if (isalpha(c))
			return false;
	}
	return true;
}

std::string combineTops(std::vector<std::string> stacks)
{
	std::string tops;

	for (int y = 0; y < stacks.size(); y++)
		tops += stacks[y][0];

	return tops;
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

	std::vector<std::string> crates;
	std::vector<std::string> commands;

	while (std::getline(file, line))
	{
		if (!hasOnlyNumbersInside(line) && !hasNumberInside(line))
			crates.push_back(withoutSquareBrackets(line));

		else if (!hasOnlyNumbersInside(line) && hasNumberInside(line))
			commands.push_back(line);
	}

	std::vector<std::string> stacks = splitToStacks(crates);

	doCommands(stacks, commands);

	std::cout << combineTops(stacks) << std::endl;
}