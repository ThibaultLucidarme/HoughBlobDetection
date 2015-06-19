#include "houghFilter.hpp"

#include <opencv2/imgproc/imgproc.hpp>//SimpleBlobDetector
#include <opencv2/highgui/highgui.hpp>//imshow

using namespace cv;
using namespace std;

HoughFilter::HoughFilter(std::string s):Filter(s)
{}

void HoughFilter::Execute(void)
{

	//gradient
	Mat gradient;
    blur( _input, gradient, Size(_size,_size) );
    Canny(gradient, gradient, 0, 10, 3);
    
	// detect lines
    vector<Vec2f> lines;
    normalize(gradient, gradient, 0.0, 255.0, cv::NORM_MINMAX, CV_8U);
    HoughLines(gradient, lines, 1, CV_PI/180, _minAcc, 50, 0 );
    cout<< "\tnumber of scratched found: "<<lines.size()<<endl;

	// draw lines
	cvtColor(_input, _output, CV_GRAY2BGR);
    
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];

	    bool t0 = theta>CV_PI/180*170 || theta<CV_PI/180*10;
	    bool t90 = theta>CV_PI/180*80 || theta<CV_PI/180*100;

	    if(t0 || t90) {
            Point pt1, pt2;
		    double a = cos(theta), b = sin(theta);
		    double x0 = a*rho, y0 = b*rho;
		    pt1.x = cvRound(x0 + 1000*(-b));
		    pt1.y = cvRound(y0 + 1000*(a));
		    pt2.x = cvRound(x0 - 1000*(-b));
		    pt2.y = cvRound(y0 - 1000*(a));
		    line( _output, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
	    }
    }

}

void HoughFilter::SetMinAccumulation(unsigned int a)
{
	_minAcc = a;
	_isCalculated = false;
}

void HoughFilter::SetSize(unsigned int s)
{
	_size = s;
	if(_size%2==0)
		_size = _size*2+1;
		
	_isCalculated = false;
}
