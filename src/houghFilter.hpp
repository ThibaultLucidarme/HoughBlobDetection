#ifndef __hough__
#define __hough__


#include "Filter.hpp"

class HoughFilter: public Filter 
{
	private:
	void Execute(void);
	unsigned int _minAcc = 150;
	unsigned int _size = 5;
	
	public:
	HoughFilter(std::string);
	void SetMinAccumulation(unsigned int);
	void SetSize(unsigned int );
	
};


#endif
