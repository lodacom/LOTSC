#include "stdafx.h"
#include "ChimereException.h"


ChimereException::ChimereException()
{
}

const char * ChimereException::what() const throw(){
	return "Attention vous essayer de construire une chimere!!!";
}

ChimereException::~ChimereException()
{
}
