#include <iostream>
#include <fstream>
#include <Perceptron.h>

int main(int argc, char **argv)
{
	Perceptron _p {2};
	
	std::ifstream traindata;
	traindata.open(argv[1]);
	
	_p.Train( traindata , true );	
		
	return 0;
}
