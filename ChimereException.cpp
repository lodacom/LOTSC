#include "stdafx.h"
#include "ChimereException.h"


ChimereException::ChimereException()
{
}

const char * ChimereException::what() const throw(){
	return "Erreur de malheur!!!";
}

ChimereException::~ChimereException()
{
}
