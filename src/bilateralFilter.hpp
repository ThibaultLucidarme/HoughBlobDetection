#ifndef __smooth__
#define __smooth__


#include "Filter.hpp"

class BilateralFilter: public Filter 
{
	private:
	void Execute(void);
	unsigned int _size = 9;
	
	public:
	BilateralFilter(std::string);
	void SetSize(unsigned int);
	
};


#endif
