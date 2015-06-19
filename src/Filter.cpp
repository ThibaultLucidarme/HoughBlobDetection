#include "Filter.hpp"
#include <opencv2/highgui/highgui.hpp>//imshow

using namespace cv;
using namespace std;


	Filter::Filter(std::string s)
	{
		_name = s;
	}
	
	void Filter::Update(void)
	{
		if( _inputFilter )
		{
			if( !_inputFilter->HasBeenCalculated() )
			{
				_inputFilter->Update();
			}
			_input = _inputFilter->GetOutputMat();
		}
		
		cout<<"Executing :'"<< _name <<"'"<<endl;
		Execute();
		_isCalculated = true;

		if( _displayOutput )
		{
			imshow( _name, _output );
		}
		
	}
	
	void Filter::SetInput( Filter* f)
	{
		_inputFilter = f;
		_isCalculated = false;
	}
		
	void Filter::SetInput( Mat m)
	{
		_input = m;
		_isCalculated = false;
	}
	
	void Filter::SetCanvas( Mat c)
	{
		_canvas = c;
		_isCalculated = false;
	}
	
	Mat Filter::GetOutputMat(void)
	{
		return _output;		
	}
	
	Filter* Filter::GetOutput(void)
	{
		return this;
	}	
	
	void Filter::Display(bool d)
	{
		_displayOutput = d;
	}
	
	bool Filter::HasBeenCalculated(void)
	{
		return _isCalculated;
	}

