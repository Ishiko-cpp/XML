/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_XML_XMLPUSHPARSER_HPP_
#define _ISHIKO_CPP_XML_XMLPUSHPARSER_HPP_

#include <boost/utility/string_view.hpp>

namespace Ishiko
{

class XMLPushParser
{
public:
    class Callbacks
    {
    public:
        virtual ~Callbacks() = default;
    };

    XMLPushParser(Callbacks& callbacks);

    bool onData(boost::string_view data, bool eod);

private:
    Callbacks& m_callbacks;
};

}

#endif
