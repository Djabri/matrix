#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

#define FILE_PATH_1 "F:\\secondSem\\ÀßÏ\\labs\\matrix\\matrix\\A.txt"
#define FILE_PATH_2 "F:\\secondSem\\ÀßÏ\\labs\\matrix\\matrix\\B.txt"

class matrix_t {
private:
	int ** data_;
	unsigned int rows_;
	unsigned int collumns_;
public:
	matrix_t();
	matrix_t(std::string, std::string);
	matrix_t(const matrix_t&);

	matrix_t add(matrix_t & other) const;
	matrix_t sub(const matrix_t & other) const;
	matrix_t mul(const matrix_t & other) const;
	matrix_t T(const matrix_t & other) const;


	std::ifstream & read(std::ifstream &stream)
	{
		unsigned int rows;
		unsigned int collumns;
		char symbol;

		bool success = true;
		if (stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns) {
			int ** data = new int *[rows];
			for (std::size_t i = 0; success && i < rows; ++i) {
				data[i] = new int[collumns];
				for (std::size_t j = 0; j < collumns; ++j) {
					if (!(stream >> data[i][j])) {
						success = false;
						break;
					}
				}
			}

			if (success) {
				for (std::size_t i = 0; i < rows_; ++i) {
					delete[] data_[i];
				}
				delete[] data_;

				rows_ = rows;
				collumns_ = collumns;
				data_ = data;
			}
			else {
				for (std::size_t i = 0; i < rows; ++i) {
					delete[] data[i];
				}
				delete[] data;
			}
		}
		else {
			success = false;
		}

		if (!success) {
			stream.setstate(std::ios_base::failbit);
		}

		return stream;
	}

	std::ostream & write(std::ostream & stream) const
	{
		stream << rows_ << ", " << collumns_;
		for (std::size_t i = 0; i < rows_; ++i) {
			stream << '\n';
			for (std::size_t j = 0; j < collumns_; ++j) {
				stream << data_[i][j];
				if (j != rows_ - 1) {
					stream << ' ';
				}
			}
		}

		return stream;
	}
};

matrix_t::matrix_t() : rows(0), collumns(0), data(nullptr)
{
}

matrix_t::matrix_t(const matrix_t& other)
{
	rows_ = other.rows_;
	collumns_ = other.collumns_;

	data_ = new int *[rows_];
	for (unsigned int i = 0; i < other.rows_; i++)
	{
		data_[i] = new int[other.collumns_];
	}

	for (unsigned int i = 0; i < other.rows_; i++)
	{
		for (unsigned int j = 0; j < other.collumns_; j++)
		{
			data_[i][j] = other.data_[i][j];
		}
	}
}

//matrix_t::matrix_t(std::string stream, std::string stream_2)
//{	
//	char op;
//	matrix_t A, B;
//
//	std::ifstream fileOne(stream);
//	std::ifstream fileTwo(stream_2);
//
//	assert(fileOne.is_open() , fileTwo.is_open());
//	
//	if (fileOne >> A.rows && fileOne >> op && op == ',' && fileOne >> A.collumns)
//	{
//
//	}
//	else
//	{
//		fileOne.setstate(std::ios_base::failbit);
//	}
//
//	for (unsigned int i = 0; i < A.rows; i++)
//	{
//		//for (unsigned int j = 0; j < B.rows; j++)
//		//{
//		//	fileOne >> A.data[i][j];
//		//	fileTwo >> B.data[i][j];
//		//}
//		fileOne >> op;
//		std::cout << std::endl;
//	}
//
//
//}

matrix_t matrix_t::add(matrix_t &other)const {

	matrix_t re;

	for (unsigned int i = 0; i < rows_; i++)
	{
		for (unsigned int j = 0; j < collumns_; j++)
		{
			re.data_[i][j] = data_[i][j] + other.data_[i][j];
		}
	}

	return re;
}


int main()
{
	std::string fileOne = FILE_PATH_1;
	std::string fileTwo = FILE_PATH_2;

	matrix_t A(fileOne, fileTwo);
	std::cin.get();
	return 0;
}