#ifndef __blob__
#define __blob__


#include "Filter.hpp"

class BlobFilter: public Filter 
{
	private:
	void Execute(void);
	unsigned int _minArea = 5;
	
	public:
	BlobFilter(std::string);
	void SetMinArea(unsigned int);
	
};

#endif
