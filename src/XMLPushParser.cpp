/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLPushParser.hpp"

using namespace Ishiko;

XMLPushParser::XMLPushParser(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
}

bool XMLPushParser::onData(boost::string_view data, bool eod)
{
    return false;
}
