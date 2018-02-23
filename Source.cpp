#include <iostream>
#include <fstream>

#define FILE_ONE "F:\\secondSem\\ÀßÏ\\labs\\matrix\\matrix\\A.txt"
#define FILE_TWO "F:\\secondSem\\ÀßÏ\\labs\\matrix\\matrix\\B.txt"

class matrix_t {
	int ** data;
	unsigned int rows;
	unsigned int collumns;

	matrix_t();

	matrix_t add(matrix_t & other);
	matrix_t sub(matrix_t & other);
	matrix_t mul(matrix_t & other);
	matrix_t trans(matrix_t & other);

	std::ifstream & read(std::ifstream &stream)
	{
		matrix_t other;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < collumns; j++)
			{
				read >> other.data[i][j];
			}
		}

		return stream;
	}
	std::ofstream & write(std::ofstream & stream) const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < collumns; j++)
			{
				write << other.data[i][j];
			}
		}

		return stream;
	}
};

matrix_t::matrix_t() : rows(0), collumns(0), data(nullptr)
{

}


matrix_t matrix_t::add(matrix_t & other)
{

}

matrix_t matrix_t::sub(matrix_t & other)
{

}

matrix_t matrix_t::mul(matrix_t & other)
{

}

matrix_t matrix_t::trans(matrix_t & other)
{

}

std::ifstream & read(std::ifstream & stream)
{

}
std::ofstream & write(std::ofstream & stream)
{

}

int main()
{
	std::ifstream fileOne(FILE_ONE);
	std::ifstream fileTwo(FILE_TWO);




	return 0;
}