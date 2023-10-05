#include <iostream>
#include <fstream>

void	replace(std::string infile, std::string str1, std::string str2)
{
	// OPEN INFILE
	std::ifstream	ifs;
	ifs.open(infile.c_str(), std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Failed to open infile." << std::endl;
		return ;
	}

	// OPEN OUTFILE
	std::ofstream	ofs;
	ofs.open((infile + ".replace").c_str(), std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Failed to open outfile." << std::endl;
		ifs.close();
		return ;
	}

	// READ + FIND + WRITE
	std::string	line;
	size_t		pos_str1;
	size_t		start;

	while (getline(ifs, line))
	{
		pos_str1 = 0;
		start = 0;
		while (pos_str1 != std::string::npos)
		{
			pos_str1 = line.find(str1, start);
			if (pos_str1 != std::string::npos)
			{
				ofs << line.substr(start, pos_str1 - start);
				ofs << str2;
				start += pos_str1 - start + str1.size();
			}
		}
		ofs << line.substr(start, line.size() - start);
		if (!ifs.eof())
			ofs << "\n";
	}

	// CLOSE
	ifs.close();
	ofs.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong arg format." << std::endl;
		return 1;
	}

	replace(av[1], av[2], av[3]);

	return 0;
}
