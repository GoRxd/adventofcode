#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int MARKER_SIZE = 14;

bool charsDoesntRepeat(std::string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		for (int k = i + 1; k < s.size(); k++)
		{
			if (s[i] == s[k])
				return false;
		}
	}
	return true;
}

int processedCharacters(std::string buffer)
{
	for (int i = 0; i < buffer.size(); i++)
	{
		std::string possibleMarker;
		for (int k = i; k < i + MARKER_SIZE; k++)
		{
			possibleMarker += buffer[k];
		}
		if (charsDoesntRepeat(possibleMarker))
		{
			return i + MARKER_SIZE;
		}
	}
	return 0;
}

int main()
{
	std::fstream file("data.txt");
	std::string buffer;

	std::getline(file, buffer);
	
	std::cout << processedCharacters(buffer) << std::endl;

}