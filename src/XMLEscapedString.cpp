/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLEscapedString.hpp"
#include <algorithm>

using namespace Ishiko;

XMLEscapedString XMLEscapedString::FromUnescapedString(const char* str)
{
    XMLEscapedString result;
    const char* ptr = str;
    while (*ptr != '\0')
    {
        switch (*ptr)
        {
        case '&':
            result.m_escapedString.append("&amp;");
            break;

        case '<':
            result.m_escapedString.append("&lt;");
            break;

        case '>':
            result.m_escapedString.append("&gt;");
            break;

        default:
            // TODO: would it be faster to append a chunk?
            result.m_escapedString.push_back(*ptr);
            break;
        }
        ++ptr;
    }
    return result;
}

XMLEscapedString XMLEscapedString::FromUnescapedString(const std::string& str)
{
    return FromUnescapedString(str.c_str());
}

const size_t XMLEscapedString::size() const noexcept
{
    return m_escapedString.size();
}

const std::string& XMLEscapedString::asEscapedString() const
{
    return m_escapedString;
}

std::string XMLEscapedString::toUnescapedString() const
{
    std::string result;
    std::string::const_iterator it = m_escapedString.begin();
    while (it != m_escapedString.end())
    {
        if (*it != '&')
        {
            // TODO: would it be faster to append a chunk?
            result.push_back(*it);
        }
        else
        {
            std::string::const_iterator it2 = std::find((it + 1), m_escapedString.end(), ';');
            if (it2 != m_escapedString.end())
            {
                // TODO: is this safe this comparison with a literal? I guess so since the null char won't match
                if (std::equal((it + 1), it2, "amp"))
                {
                    result.push_back('&');
                }
                else if (std::equal((it + 1), it2, "lt"))
                {
                    result.push_back('<');
                }
                else if (std::equal((it + 1), it2, "gt"))
                {
                    result.push_back('>');
                }
            }
            else
            {
                // TODO: should be impossible if string was build properly, assert?
            }
            it = it2;
        }
        ++it;
    }
    return result;
}
