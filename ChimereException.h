#include "stdafx.h"

using namespace std;

class ChimereException : exception
{
public:
	ChimereException();
	const char * what() const throw();
	virtual ~ChimereException();
};

