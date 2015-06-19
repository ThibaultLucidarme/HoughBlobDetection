#ifndef __filter__
#define __filter__

#include <opencv/cv.hpp>//namespace

class Filter 
{
	
	protected:

	Filter* _inputFilter = nullptr;
	cv::Mat _input;
	cv::Mat _output;
	cv::Mat _canvas;
	std::string _name = "";
	bool _displayOutput = false;
	bool _isCalculated = false;
	
	virtual void Execute(void) = 0;
	
	public:
	
	Filter(std::string);
	void Update(void);
	void SetInput(Filter*);
	void SetInput(cv::Mat);
	void SetCanvas(cv::Mat);
	cv::Mat GetOutputMat(void);
	Filter* GetOutput(void);
	void Display(bool d=true);
	bool HasBeenCalculated(void);
	
	
};

#endif
