#ifndef _6036_PERCEPTRON_H
#define _6036_PERCEPTRON_H

#include <fstream>
#include <cstddef>
#include <vector>

class Perceptron
{
	size_t _insize;
	std::vector<double> _theta;
public:
	Perceptron( const size_t input_size ) : _insize { input_size }, _theta { } { for(size_t i=0; i<_insize; ++i) _theta.push_back(0); };
	Perceptron( const size_t input_size, const std::vector<double> theta0 ) : _insize { input_size }, _theta { theta0 } {};
	~Perceptron() {};
	inline std::vector<double> theta() const {
		return _theta;
	}
	int Classify( const std::vector<double>& input );
	bool Train( const std::vector<double>& input , const int& output ); // return whether theta has been changed
	void Train( std::ifstream& data , bool verbose = false );
};

#endif // _6036_PERCEPTRON_H
