/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_XML_XMLESCAPEDSTRING_HPP_
#define _ISHIKO_CPP_XML_XMLESCAPEDSTRING_HPP_

#include <string>

namespace Ishiko
{

class XMLEscapedString
{
public:
    XMLEscapedString() = default;
    static XMLEscapedString FromUnescapedString(const char* str);
    static XMLEscapedString FromUnescapedString(const std::string& str);

    const size_t size() const noexcept;

    const std::string& asEscapedString() const;
    std::string toUnescapedString() const;

private:
    std::string m_escapedString;
};

}

#endif
