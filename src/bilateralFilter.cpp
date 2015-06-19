#include "bilateralFilter.hpp"

#include <opencv2/imgproc/imgproc.hpp>//SimpleBlobDetector

using namespace cv;
using namespace std;

BilateralFilter::BilateralFilter(std::string s):Filter(s)
{}

void BilateralFilter::Execute(void)
{
	Size s= Size(_size,_size);
	Mat tmp;
	normalize(_input, tmp, 0.0, 255.0, cv::NORM_MINMAX, CV_8U);
	adaptiveBilateralFilter(tmp, _output,s, _size+2.0);
	
}

void BilateralFilter::SetSize(unsigned int s)
{
	_size = s;
	if(_size%2==0)
		_size = _size*2+1;
				
	_isCalculated = false;
}
