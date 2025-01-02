#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	file(filename.c_str());
	std::ofstream	replace(filename.append(".replace").c_str());
	std::string		line;
	int pos;

	while (getline(file, line))
	{
		while ((pos = line.find(s1)) != -1)
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length(), line.length());
		replace << line << std::endl;
	}
	file.close();
	replace.close();
	return 0;
}