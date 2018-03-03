#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

#define FILE_PATH_1 "A.txt"
#define FILE_PATH_2 "B.txt"
#define INPUT_FILE "R.txt"


class matrix_t
{
private:
	int **elements;
	unsigned int rows;
	unsigned int columns;
public:
	matrix_t();
	matrix_t(const matrix_t&);
	~matrix_t();
	
	int get_rows() const;
	int get_columns() const;


	matrix_t add(matrix_t & other) const;
	matrix_t sub(matrix_t & other) const;
	matrix_t mul(matrix_t & other) const;
	matrix_t trans(matrix_t & other) const;

	std::ifstream& read(std::ifstream & stream)
	{
		char op;
		int **elements_;
		unsigned int rows_;
		unsigned int columns_;

		assert(stream.is_open());

		if (stream >> rows_ && stream >> op && op == ',' && stream >> columns_)
		{
			elements_ = new int *[rows_];
			for (unsigned int i = 0; i < rows_; i++)
			{
				elements_[i] = new int[rows_];
			}		

			for (unsigned int i = 0; i < rows_; i++)
			{
				for (unsigned int j = 0; j < columns_; j++)
				{
					stream >> elements_[i][j];
				}
				std::cout << "\n";
			}

			rows = rows_;
			columns = columns_;

			elements = new int * [rows_];
			for (unsigned int i = 0; i < rows; i++)
			{
				elements[i] = new int[columns_];
			}

			for (unsigned int i = 0; i < rows_; i++)
			{
				for (unsigned int j = 0; j < columns_; j++)
				{
					elements[i][j] = elements_[i][j];
				}
				std::cout << "\n";
			}

			for (unsigned int i = 0; i < rows_; i++)
			{
				delete[]elements_[i];
			}

			delete[]elements_;
		}
		else
		{
			stream.setstate(std::ios_base::failbit);
		}

		stream.close();
		return stream;
	}
	std::ostream& write(std::ofstream & stream) const
	{
		for (unsigned int i = 0; i < rows; i++)
		{
			for (unsigned int j = 0; j < columns; j++)
			{
				stream << elements[i][j] << "  ";
			}
			stream << "\n";
		}
		stream.close();
		return stream;
	}
};

int matrix_t::get_rows() const 
{
	return rows;
}

int matrix_t::get_columns() const 
{
	return columns;
}

matrix_t::matrix_t() : elements(nullptr), rows(0), columns(0)
{

}

matrix_t::matrix_t(const matrix_t& other)
{
	rows = other.rows;
	columns = other.columns;

	elements = new int *[rows];
	for (unsigned int i = 0; i < rows; i++)
	{
		elements[i] = new int[columns];
		for (unsigned int j = 0; j < columns; j++)
		{
			elements[i][j] = other.elements[i][j];
		}
	} 
}

matrix_t matrix_t::add(matrix_t & other) const
{
	matrix_t result;
	
	result.elements = new int *[rows];

	for (unsigned int i = 0; i < rows; i++)
	{
		result.elements[i] = new int[columns];
	}

	if (other.rows == rows && other.columns == columns)
	{
		for (unsigned int i = 0; i < rows; i++) {
			for (unsigned int j = 0; j < columns; j++) {
				result.elements[i][j] = other.elements[i][j] + elements[i][j];
			}
		}

		result.rows = other.rows;
		result.columns = other.columns;
	}
	else
	{

	}

	return result;
}

matrix_t matrix_t::sub(matrix_t & other) const
{

}

matrix_t matrix_t::mul(matrix_t & other) const
{


}

matrix_t matrix_t::trans(matrix_t & other) const
{

}

matrix_t::~matrix_t()
{
	for (unsigned int i = 0; i < rows; i++)
	{
		delete[]elements[i];
	}

	delete[]elements;
}

int main()
{
	std::ifstream fileOne(FILE_PATH_1);
	std::ifstream fileTwo(FILE_PATH_2);
	std::ofstream input_file(INPUT_FILE);


	matrix_t A;
	matrix_t B;

	A.read(fileOne);
	B.read(fileTwo);

	char check;

	std::cout << "Select an arithmetic operation '+', '-', '*', 'T' \n";

	if (A.read(fileOne) && B.read(fileTwo))
	{
		switch (check)
		{
		case '+':
		{
			A.add(B).write(input_file);
			break;
		}
		case '-':
		{
			A.sub(B).write(input_file);
			break;
		}

		case '*':
		{
			A.mul(B).write(input_file);
			break;
		}

		case 'T':
		{
			A.trans.write(input_file);
			break;
		}

		default:
			std::cout << "An error has occured while reading input data\n";
			break;
		}
	}
	else
	{
		std::cout << "Select an arithmetic operation '+', '-', '*', '/'";
	}

	std::cin.get();
	return 0;
}

