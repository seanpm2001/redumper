module;

#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>

export module utils.strings;



namespace gpsxre
{

export void trim_left_inplace(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char c) { return !std::isspace(c); }));
}


export void trim_right_inplace(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](char c) { return !std::isspace(c); }).base(), s.end());
}


export void trim_inplace(std::string &s)
{
    trim_right_inplace(s);
    trim_left_inplace(s);
}


export std::string trim(std::string s)
{
    trim_inplace(s);
    return s;
}


export void erase_all_inplace(std::string &s, char c)
{
    s.erase(std::remove(s.begin(), s.end(), c), s.end());
}


export std::string erase_all(std::string s, char c)
{
    erase_all_inplace(s, c);
    return s;
}


export void extend_left_inplace(std::string &s, char c, size_t width)
{
    s = std::string(width - std::min(width, s.length()), c) + s;
}


export std::string extend_left(std::string s, char c, size_t width)
{
    extend_left_inplace(s, c, width);
    return s;
}


export void replace_all_inplace(std::string &s, std::string from, std::string to)
{
    for(size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.length())
        s.replace(pos, from.length(), to);
}


export std::string replace_all(std::string s, const std::string &from, const std::string &to)
{
    replace_all_inplace(s, from, to);
    return s;
}


export bool ends_with(const std::string &s, const std::string &suffix)
{
    if(suffix.size() > s.size())
        return false;

    return std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}


export std::string str_uppercase(const std::string &s)
{
    std::string str_uc;
    std::transform(s.begin(), s.end(), std::back_inserter(str_uc), [](unsigned char c)
    {
        return std::toupper(c);
    });

    return str_uc;
}

}
