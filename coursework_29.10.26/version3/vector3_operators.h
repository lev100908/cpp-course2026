#pragma once

#include "vector3.h"
#include <iostream>

template<typename T, typename A>
std::ostream& operator<<(std::ostream& stream, const VectorVer3<T, A>& rhs)
{
    for (std::size_t i = 0; i < rhs.size(); i++)
    {
        stream << rhs[i] << " ";
    }
    stream << std::endl;
    return stream;    
}