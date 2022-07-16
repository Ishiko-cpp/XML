/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLPushParserTestCallbacks.hpp"
#include "Ishiko/XML/XMLEscapedString.hpp"
#include "Ishiko/XML/XMLWriter.hpp"
#include <Ishiko/Errors.hpp>

using namespace Ishiko;

void XMLPushParserTestCallbacks::onXMLDeclaration()
{
    m_events.emplace_back("onXMLDeclaration", "");
}

void XMLPushParserTestCallbacks::onStartTag(boost::string_view name)
{
    m_events.emplace_back("onStartTag", name);
}

void XMLPushParserTestCallbacks::onEndTag()
{
    m_events.emplace_back("onEndTag", "");
}

void XMLPushParserTestCallbacks::onCharacterData(boost::string_view data)
{
    m_events.emplace_back("onCharacterData", data);
}

void XMLPushParserTestCallbacks::exportToXML(const boost::filesystem::path& path) const
{
    XMLWriter xmlWriter;
    // TODO: handle errors
    Error error;
    xmlWriter.create(path, error);
    xmlWriter.writeXMLDeclaration();
    xmlWriter.writeElementStart("events");
    xmlWriter.increaseIndentation();
    for (const std::pair<std::string, std::string>& e : m_events)
    {
        xmlWriter.writeNewlineAndIndentation();

        xmlWriter.writeElementStart("callback");
        xmlWriter.increaseIndentation();
        xmlWriter.writeNewlineAndIndentation();

        xmlWriter.writeElementStart("name");
        xmlWriter.writeText(e.first);
        xmlWriter.writeElementEnd();
        if (!e.second.empty())
        {
            xmlWriter.writeNewlineAndIndentation();
            xmlWriter.writeElementStart("argument");
            // Escape a few extra characters that are annoying to show in the logs
            XMLEscapedString escapedArgument = XMLEscapedString::FromUnescapedString(e.second.c_str(), "\r\n");
            xmlWriter.writeText(escapedArgument);
            xmlWriter.writeElementEnd();
        }

        xmlWriter.decreaseIndentation();
        xmlWriter.writeNewlineAndIndentation();
        xmlWriter.writeElementEnd();
    }
    xmlWriter.decreaseIndentation();
    xmlWriter.writeNewlineAndIndentation();
    xmlWriter.writeElementEnd();
}
