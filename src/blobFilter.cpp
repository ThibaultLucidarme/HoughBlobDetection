#include "blobFilter.hpp"

#include <opencv2/features2d/features2d.hpp>//SimpleBlobDetector

using namespace cv;
using namespace std;

BlobFilter::BlobFilter(std::string s):Filter(s)
{}

void BlobFilter::Execute(void)
{
    vector<KeyPoint> keypoints;
    
    SimpleBlobDetector::Params params;
    params.minThreshold = 0;
    params.maxThreshold = 200;
    params.filterByArea = true;
    params.minArea = _minArea;
     
     #if CV_MAJOR_VERSION < 3 
      SimpleBlobDetector detector(params);
      detector.detect( _input, keypoints);
    #else
      Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
      detector->detect( _input, keypoints);
    #endif

    cout<< "\tnumber of blobs found: "<<keypoints.size()<<endl;
     
    drawKeypoints( _input, keypoints, _output, CV_RGB(0,255,0), DrawMatchesFlags::DEFAULT);
   
}

void BlobFilter::SetMinArea(unsigned int a)
{
	_minArea = a;
	_isCalculated = false;
}
