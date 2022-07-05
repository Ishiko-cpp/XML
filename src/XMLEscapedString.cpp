/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#include "XMLEscapedString.hpp"

using namespace Ishiko;

XMLEscapedString XMLEscapedString::FromUnescapedString(const char* str)
{
    XMLEscapedString result;
    return result;
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
    return m_escapedString;
}
