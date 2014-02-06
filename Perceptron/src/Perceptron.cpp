#include <Perceptron.h>
#include <iterator>
#include <iostream>

int Perceptron::Classify( const std::vector<double>& input ) {
	double product=0; // dot product of theta and input
	for( size_t i = 0; i < _insize; ++i ) {
		product += _theta[i]*input[i];
	}
	
	if( product > 0 ) return 1;
	return -1;
}

bool Perceptron::Train(const std::vector<double>& input, const int& output) { // return whether theta has been changed
	if( Classify(input) != output ){
		for( size_t i = 0; i < _insize; ++i ) {
			_theta[i] += input[i]*output;
		}		
		return true;
	}
	return false;
}

void Perceptron::Train( std::ifstream& data , bool verbose /* = false */ ) {
  size_t N;  // number of points in data set
  std::vector<double> x {0,_insize};
  int y;
  bool cont = false; // whether training should continue
  int count = 0;
  
  data >> N; // read number of points
  
  do{
	cont = false; // reset flag
    for( size_t i=0; i < N; ++i ) {
	    for( size_t j=0; j < _insize; ++j ) {
		    data >> x[j];
	    }
	    data >> y;
		if( Train(x,y) ) { // if a mistake has been encountered
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
  }while(cont && count < 10000);
   
}