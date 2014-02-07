#include <Perceptron.h>
#include <iterator>
#include <iostream>

int Perceptron::Classify( const std::vector<double>& input )
{
	double product=0; // dot product of theta and input

	for( size_t i = 0; i < _insize; ++i ) {
		product += _theta[i]*input[i];
	}

	if( product > 0 ) return 1;
	if( product < 0 ) return -1;
	return 0;
}

bool Perceptron::Train(const std::vector<double>& input, const int& output)   // return whether theta has been changed
{
	//std::cout << Classify(input) << output << std::endl;
	if( Classify(input) != output ) {
		for( size_t i = 0; i < _insize; ++i ) {
			//std::cout << "theta " << i << " = " << _theta[i] << std::endl;
			//std::cout << "Delta theta " << i << " = " << input[i]*output << std::endl;
			_theta[i] += input[i]*output;
			//std::cout << "theta " << i << " = " << _theta[i] << std::endl;
		}
		return true;
	}
	return false;
}

void Perceptron::Train( std::ifstream& data , bool verbose /* = false */ )
{
	size_t N;  // number of points in data set
	std::vector<std::vector<double>> x;
	std::vector<int> y;
	bool cont = false; // whether training should continue
	int count = 0;

	data >> N; // read number of points
	for( size_t i=0; i < N; ++i ) {
		x.push_back(std::vector<double> (_insize, 0.0));
		for( size_t j=0; j < _insize; ++j ) {
			data >> x[i][j];
			if(verbose) std::cout << x[i][j] << " ";
		}
		y.push_back(0);
		data >> y[i];
		if(verbose) std::cout << y[i] << std::endl;
	}


	do {
		cont = false; // reset flag
		for( size_t i=0; i < N; ++i ) {
			if( Train(x[i],y[i]) ) { // if a mistake has been encountered
				cont = true;
				if( verbose ) { // print a message
					std::cout << "Mistake encountered at point " << i << std::endl;
					std::cout << "New thetas: ";
					for( double value : _theta ) {
						std::cout << value << " ";
					}
					std::cout << std::endl;
				}
			}
		}
		count++;
	} while(cont && count < 3);

}
