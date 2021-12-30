#pragma once

#include <stdexcept>

class CanNotOpenFile : public std::exception
{
public:
	// Ekvivalentno sa:   const char* what() const noexcept {...
	const char* what() const throw () {  
		return "ERROR! Could not open all files! \n";
	}

};