/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_XML_XMLPUSHPARSER_HPP_
#define _ISHIKO_CPP_XML_XMLPUSHPARSER_HPP_

#include <boost/utility/string_view.hpp>
#include <string>
#include <vector>

namespace Ishiko
{

class XMLPushParser
{
public:
    class Callbacks
    {
    public:
        virtual ~Callbacks() = default;

        virtual void onXMLDeclaration();
        virtual void onStartTag();
        virtual void onEndTag();
    };

    XMLPushParser(Callbacks& callbacks);

    bool onData(boost::string_view data, bool eod);

private:
    enum class ParsingMode
    {
        document,
        prolog,
        xmlDeclaration,
        element,
        startTag,
        content,
        endTag,
        leftAngleBracket,
        name,
        forwardSlash,
        whitespace,
        end
    };

    std::vector<ParsingMode> m_parsingModeStack;
    std::string m_fragmentedData;
    Callbacks& m_callbacks;
};

}

#endif
