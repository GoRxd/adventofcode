#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int findSet(std::string& line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ';')
            return i;
    }
    return -1;
}

void removeSeparators(std::string& line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ';' || line[i] == ',')
        {
            line.erase(line.begin() + i);
            i--;
        }
    }
}

int stringToInt(std::string& str)
{
    if (str.size() >= 2)
        return std::stoi(str);
    else
        return str[0] - '0';
}

bool isTooHigh(std::string& color, int& quantity)
{
    if (color == "red" && quantity > 12) return true;
    else if (color == "green" && quantity > 13) return true;
    else if (color == "blue" && quantity > 14) return true;

    return false;
}

int power(std::string& line)
{
    std::string game = line.substr(line.find(':') + 2, line.size());
    std::map<std::string, int> cubes =
    {
        {"red", 0},
        {"green", 0},
        {"blue", 0},
    };
    removeSeparators(game);
    int quantity;
    std::string number;
    std::string cube = "";
    for (int i = 0; i < game.size(); i++)
    {
        if (isdigit(game[i]))
        {
            if (cube != "") {
                quantity = stringToInt(number);
                if (cubes[cube] < quantity)
                    cubes[cube] = quantity;
                number = "";
                cube = "";
            }
            number += game[i];
        }
        else if (game[i] != ' ')
            cube += game[i];
    }
    quantity = stringToInt(number);
    if (cubes[cube] < quantity)
        cubes[cube] = quantity;

    return cubes["red"] * cubes["green"] * cubes["blue"];
}
bool isPossible(std::string& line)
{
    std::string game = line.substr(line.find(':') + 2, line.size());
    std::map<std::string, int> cubes =
    {
        {"red", 0},
        {"green", 0},
        {"blue", 0},
    };
    removeSeparators(game);
    int quantity;
    std::string number;
    std::string cube = "";
    for (int i = 0; i < game.size(); i++)
    {
        if (isdigit(game[i]))
        {
            if (cube != "") {
                quantity = stringToInt(number);
                cubes[cube] += quantity;

                if (isTooHigh(cube, quantity)) return false;
                number = "";
                cube = "";
            }
            number += game[i];
        }
        else if (game[i] != ' ')
            cube += game[i];
    }
    quantity = stringToInt(number);
    cubes[cube] += quantity;

    if (isTooHigh(cube, quantity)) return false;

    return true;
}

int main()
{
	std::fstream file("data.txt");
	std::string line;

    int sum = 0;
    int i = 1;
	while (std::getline(file, line))
	{
        //part 1
        /*if (isPossible(line))
            sum += i;
        i++;*/
        //part 2
        sum += power(line);
	}
    std::cout << sum << std::endl;
}