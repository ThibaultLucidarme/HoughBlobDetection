/*
 * minimal code
 *
 *#include "CommandLineParser.hpp"
    p::CommandLineParser parser(argc, argv);

    int input = parser.addOption<int>("-i",-17,"test int");
    std::string allo = parser.addOption<std::string>("-s","coucou","test string");
    std::string peep = parser.addOption<std::string>("-p","salut");


 */
#include <iostream>
#include <sstream>
#include <string>
#include <cstdarg>
#include <vector>
#include <map>
#include "convertType.hpp"

namespace p
{
class CommandLineParser
{
private:
int								   _numArg;
std::vector<std::string>		   _argList;
std::map<std::string, std::string> _argmap;


public:
CommandLineParser(int argc, char** argv)
{
	_numArg = argc;

	// convert char** to vector<string>

	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss;
		std::string		  s;
		ss << argv[i];
		ss >> s;
		_argList.push_back(s);
	}

	// map <option , Argument>

	for (unsigned int i = 0; i < _argList.size(); i++)
	{
		if (_argList[i][0] == '-')
		{
			if (_argList[i + 1][0] != '-')
				_argmap.insert(std::pair<std::string, std::string>(_argList[i], _argList[i + 1]) );
			else
				_argmap.insert(std::pair<std::string, std::string>(_argList[i],  "") );
		}
	}
}

template<typename Type>
Type addOption(std::string optName, Type defaultValue, std::string description = "default description")
{
	Type result;

	//if option is found

	if (_argmap.find(optName) != _argmap.end() )
		p::ConvertType(_argmap.find(optName)->second, result);

	//if option not found, assign default value

	else
		result = defaultValue;

	return result;
}
};


/*
 *
 * CommandLineParser parser(argc, argv);
 * parser.addOption<int>( "-i", &input);
 * parser.addOption<std::string>( "-s", &allo, &quiEst, &la );
 *
 *
 *** overload
 *
 *
 * int i = parser.addOption<int>("-i", defaultValue);
 * std::string s[] = parser.addOption<std::string>( "-s", "defaultValue" );
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
}
