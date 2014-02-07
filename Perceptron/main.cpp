#include <iostream>
#include <fstream>
#include <string>
#include <Perceptron.h>

int main(int argc, char **argv)
{
	std::string path="";
	size_t input_size = 2;

	while(true) {
		std::cout << "Size of feature vector? (constant incl.) ";
		std::cin >> input_size;
		if( input_size == 0 ) break;

		Perceptron _p {input_size};

		std::ifstream traindata;


		std::cout << "Training set? ";
		std::cin >> path;

		traindata.open(path);

		_p.Train( traindata , true );

		traindata.close();
	}
	return 0;
}
