#include "VectorLengthException.h"

const char* VectorLengthException::excep() const throw()
{
    return "ERROR! Attention, the length of the vector is zero!";
}