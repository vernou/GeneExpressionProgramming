#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

#include <sstream>

template<typename T>
inline bool from_string( const std::string & Str, T & Dest )
{
    std::istringstream iss( Str );
    return iss >> Dest != 0;
}

inline std::string FloatToString(float v)
{
    //Pour eviter que les grandes valeurs rendent illisible le graphe
    //Surtout lors des premieres iteration
    if(v>1000.f)
        return std::string("1000");
    std::ostringstream os;
    os<<v;
    return os.str();
}

inline std::string IntToString(int v)
{
    std::ostringstream os;
    os<<v;
    return os.str();
}

#endif // CONVERT_H_INCLUDED
