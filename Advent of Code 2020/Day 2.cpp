#include <iostream>
#include <fstream>
#include <string>

int stringToInt(std::string str)
{
	if (str.size() >= 2)
		return std::stoi(str);
	else
		return str[0] - '0';
}

bool isLetterWithinRange(int& min, int& max, char& letter, std::string& password)
{
	int occurences = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] == letter)
			occurences++;
	}
	if (occurences >= min && occurences <= max) return true;
	return false;
}

bool isValid(int& index, int& secIndex, char& letter, std::string& password)
{
	bool isOnIndex = false;
	bool isOnSecIndex = false;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] == letter && (i + 1) == index)
			isOnIndex = true;
		else if (password[i] == letter && (i + 1) == secIndex)
			isOnSecIndex = true;
	}
	if (isOnIndex && isOnSecIndex) return false;
	else if (isOnIndex || isOnSecIndex) return true;
	return false;
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

	int valid = 0;

	while (std::getline(file, line))
	{
		int min = stringToInt(line.substr(0, line.find('-'))); // in part 2 it would be index
		int max = stringToInt(line.substr(line.find('-') + 1, line.find(' '))); // in part 2 it would be secIndex
		char letter = line.substr(line.find(' ') + 1, 1)[0];
		std::string password = line.substr(line.find(':') + 2, line.size() - (line.find(':') + 2));
		std::cout << line << " " << isValid(min, max, letter, password) << std::endl;
		//part 1
		//if (isLetterWithinRange(min, max, letter, password))
		//	valid++;
		//part 2
		if (isValid(min, max, letter, password))
			valid++;
	}
	std::cout << valid << std::endl;
}