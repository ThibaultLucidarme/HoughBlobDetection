#include <iostream>
#include <stdlib.h>

#include <opencv/cv.hpp>//namespace
#include <opencv2/highgui/highgui.hpp>//imread

#include "blobFilter.hpp"
#include "bilateralFilter.hpp"
#include "houghFilter.hpp"
#include "CommandLineParser.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv)
{
	p::CommandLineParser parser(argc, argv);
	string inputFile = parser.addOption<string>("-i", "../data/img5.png", "Input PNG file");
	string outputFolder = parser.addOption<string>("-f", "../bin/output/", "Output PNG file folder");
	unsigned int minAccumulation = parser.addOption<unsigned int>("-m", 150, "Minimum Hough accumulation");
	unsigned int minArea  = parser.addOption<unsigned int>("-a", 6, "Minimum Blob area");
		
	Mat input = imread(inputFile, CV_LOAD_IMAGE_GRAYSCALE);
	
	
	HoughFilter houghFilter("lines");
	houghFilter.SetMinAccumulation(minAccumulation);
	houghFilter.Display();
	
	BlobFilter blobFilter("blobs");
	blobFilter.SetMinArea(minArea);
	blobFilter.Display();
	
	houghFilter.SetInput(input);	
	blobFilter.SetInput(input);
	
	blobFilter.Update();
	houghFilter.Update();

    waitKey();
   
    try {
		size_t start = inputFile.find("img");
		size_t end = inputFile.find(".png");
		string fileName = inputFile.substr(start,end);
		cout<< outputFolder+fileName+"_blobs.png"<<endl;
		imwrite(outputFolder+fileName+"_blobs.png", blobFilter.GetOutputMat());
		imwrite(outputFolder+fileName+"_scratches.png", houghFilter.GetOutputMat());
    }
    catch (runtime_error& ex) {
        fprintf(stderr, "Exception writing PNG: %s\n", ex.what());
        return 1;
    }
    
    return EXIT_SUCCESS;
}

