#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

#include <sstream>

template<typename T>
inline bool from_string( const std::string & Str, T & Dest )
{
    std::istringstream iss( Str );
    return iss >> Dest != 0;
}

template<typename T>
inline std::string to_string(T & src)
{
    std::ostringstream os;
    os<<src;
    return os.str();
}

#endif // CONVERT_H_INCLUDED
