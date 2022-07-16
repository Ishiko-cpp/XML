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

void XMLPushParser::Callbacks::onStartTag(boost::string_view name)
{
}

void XMLPushParser::Callbacks::onEndTag()
{
}

void XMLPushParser::Callbacks::onCharacterData(boost::string_view data)
{
}

XMLPushParser::XMLPushParser(Callbacks& callbacks)
    : m_callbacks(callbacks)
{
    m_parsingModeStack.push_back(ParsingMode::document);
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
        case ParsingMode::document:
            m_parsingModeStack.push_back(ParsingMode::prolog);
            break;

        case ParsingMode::prolog:
            m_parsingModeStack.push_back(ParsingMode::xmlDeclaration);
            break;

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

        case ParsingMode::element:
            m_parsingModeStack.push_back(ParsingMode::startTag);
            break;

        case ParsingMode::startTag:
            previous = current;
            m_parsingModeStack.push_back(ParsingMode::name);
            break;

        case ParsingMode::endTag:
            // TODO: validate we have '>'
            m_callbacks.onEndTag();
            ++current;
            m_parsingModeStack.pop_back();
            m_parsingModeStack.pop_back();
            if (m_parsingModeStack.back() == ParsingMode::document)
            {
                // TODO: incorrect there could be Misc and PIs after root element
                m_parsingModeStack.back() = ParsingMode::end;
            }
            else if (m_parsingModeStack.back() == ParsingMode::content)
            {
                // Nothing to do, just proceed
            }
            else
            {
                // TODO
            }
            break;

        case ParsingMode::content:
            if (*current == '<')
            {
                m_parsingModeStack.push_back(ParsingMode::leftAngleBracket);
                ++current;
            }
            else
            {
                // TODO: validate that the char is actually a valid char to start charData
                m_parsingModeStack.push_back(ParsingMode::characterData);
                previous = current;
            }
            break;

        case ParsingMode::characterData:
            while (current < end)
            {
                if (*current == '<')
                {
                    if (m_fragmentedData.empty() && ((current - previous) > 0))
                    {
                        m_callbacks.onCharacterData(boost::string_view(previous, (current - previous)));
                    }
                    else
                    {
                        // TODO
                    }
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
                m_parsingModeStack.pop_back();
            }
            break;

        case ParsingMode::leftAngleBracket:
            m_parsingModeStack.pop_back();
            // TODO: handle other stuff that starts with '<'
            if (m_parsingModeStack.back() == ParsingMode::document)
            {
                m_parsingModeStack.push_back(ParsingMode::element);
            }
            else if (m_parsingModeStack.back() == ParsingMode::content)
            {
                if (*current == '/')
                {
                    // TODO: validate state
                    m_parsingModeStack.back() = ParsingMode::endTag;
                    ++current;
                }
                else
                {
                    m_parsingModeStack.push_back(ParsingMode::element);
                }
            }
            else
            {
                // TODO
            }
            break;

        case ParsingMode::name:
            while (current < end)
            {
                // TODO: fix isNameChar
                bool isNameChar = (((*current >= 'a') && (*current <= 'z'))
                    || ((*current >= '0') && (*current <= '9')));
                if (!isNameChar)
                {
                    if (m_fragmentedData.empty() && ((current - previous) > 0))
                    {
                        // TODO: we could be in something else than a start tag!
                        m_callbacks.onStartTag(boost::string_view(previous, (current - previous)));
                    }
                    else
                    {
                        // TODO
                    }
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
                m_parsingModeStack.back() = ParsingMode::whitespace;
            }
            break;

        case ParsingMode::forwardSlash:
            // TODO: cope with something else than "/>"
            ++current;
            // TODO: check current state and don't assume this is a closing "/>"
            m_parsingModeStack.pop_back();
            m_parsingModeStack.back() = ParsingMode::endTag;
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
                m_parsingModeStack.pop_back();
                // TODO: assert there is an element at back
                if (m_parsingModeStack.back() == ParsingMode::prolog)
                {
                    // TODO : verify state, cope with additional stuff in the prolog
                    // TODO: this is a hack as it could be any character, need a specific "unknown stuff" state
                    m_parsingModeStack.back() = ParsingMode::leftAngleBracket;
                    ++current;
                }
                else if (m_parsingModeStack.back() == ParsingMode::startTag)
                {
                    // TODO: we need to cope with attributes
                    if (*current == '>')
                    {
                        m_parsingModeStack.back() = ParsingMode::content;
                        ++current;
                    }
                    else if (*current == '/')
                    {
                        m_parsingModeStack.push_back(ParsingMode::forwardSlash);
                        ++current;
                    }
                    else
                    {
                        // TODO: error
                    }
                }
                else
                {
                    // TODO
                }
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
