#ifndef TYPECONVERTER_HPP
#define TYPECONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

namespace p
{
    void ConvertType(std::string& s, std::string& s2)
	{
		s2 = s;	
	}
	
    // STRING INT
    void ConvertType(std::string& s, int& i)
	{
		i = std::atoi( s.c_str() );		
	}

    void ConvertType(int& i, std::string& s)
    {
        std::stringstream ss;
        ss << i;
        ss >> s;
    }
    
    void ConvertType(std::string& s, unsigned int& i)
	{
		i = (unsigned int)std::atoi( s.c_str() );		
	}

    void ConvertType(unsigned int& i, std::string& s)
    {
        std::stringstream ss;
        ss << i;
        ss >> s;
    }

    // STRING FLOAT
	void ConvertType(std::string& s, float& f)
	{
		f = (float)std::atof( s.c_str() );
	}
    
    void ConvertType(float& f, std::string& s)
    {
        std::stringstream ss;
        ss << f;
        ss >> s;
    }

    // STRING DOUBLE
	void ConvertType(std::string& s, double& d)
	{
		d = std::atof( s.c_str() );
	}
    
    void ConvertType(double& d, std::string& s)
    {
        std::stringstream ss;
        ss << d;
        ss >> s;
    }
	
    // STRING CHAR*
	void ConvertType(std::string& s, char* c)
	{
        //c_str returns a const char*
		c = const_cast<char*>( s.c_str() );
	}
    
    void ConvertType(char* c, std::string& s)
    {
        std::stringstream ss;
        ss << c;
        ss >> s;
    }
    
}

#endif


