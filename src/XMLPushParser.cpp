/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLPushParser.hpp"

using namespace Ishiko;

void XMLPushParser::Callbacks::onXMLDeclaration()
{
}

void XMLPushParser::Callbacks::onStartTagBegin()
{
}

void XMLPushParser::Callbacks::onStartTagEnd()
{
}

void XMLPushParser::Callbacks::onEndTag()
{
}

XMLPushParser::XMLPushParser(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
    m_parsingModeStack.push_back(ParsingMode::xmlDeclaration);
}

bool XMLPushParser::onData(boost::string_view data, bool eod)
{
    // TODO: cope with partial data

    const char* previous = data.data();
    const char* current = previous;
    const char* end = current + data.length();
    while (current < end)
    {
        switch (m_parsingModeStack.back())
        {
        case ParsingMode::xmlDeclaration:
            // TODO: cope with no XML decl
            while (current < end)
            {
                if (*current == '>')
                {
                    m_callbacks.onXMLDeclaration();
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmentedData.append(previous, (current - previous));
            }
            else
            {
                ++current;
                m_parsingModeStack.back() = ParsingMode::whitespace;
            }
            break;

        case ParsingMode::startTag:
            while (current < end)
            {
                if (*current == '>')
                {
                    // TODO
                    //m_callbacks.();
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmentedData.append(previous, (current - previous));
            }
            else
            {
                ++current;
                m_parsingModeStack.back() = ParsingMode::end;
            }
            break;

        case ParsingMode::whitespace:
            while (current < end)
            {
                if ((*current != '\t') && (*current != '\r') && (*current != '\n') && (*current != ' '))
                {
                    // TODO
                    if /* (m_fragmentedData1.empty()) */ ((current - previous) > 0)
                    {
                        //m_callbacks.onWhitespace(boost::string_view(previous, (current - previous)));
                    }
                    /*else
                    {
                        m_fragmentedData1.append(data.data(), current - data.data());
                        m_callbacks.onMethod(m_fragmentedData1);
                        m_fragmentedData1.clear();
                    }*/
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                // TODO
                //m_fragmentedData1.append(previous, (current - previous));
            }
            else
            {
                m_parsingModeStack.back() = ParsingMode::startTag;
            }
            break;

        case ParsingMode::end:
            // TODO: verify state, we should not have any more data
            return true;

        default:
            // TODO: error
            break;
        }
    }
    if ((current == end) && eod)
    {
        // TODO: check we are in correct state
        return true;
    }
    return false;
}
