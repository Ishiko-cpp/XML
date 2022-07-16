/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLWriter.hpp"

using namespace Ishiko;

XMLWriter::XMLWriter()
    : m_mode(Mode::initial)
{
}

void XMLWriter::create(const boost::filesystem::path& path, Error& error)
{
    m_file.create(path.string(), error);
}

void XMLWriter::close()
{
    m_file.close();
}

void XMLWriter::writeXMLDeclaration()
{
    m_file.writeLine("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
}

void XMLWriter::writeElementStart(const std::string& name)
{
    // TODO: handle errors
    switch (m_mode)
    {
    case Mode::elementStartTagOpen:
        // We have an unclosed start tag
        m_file.write(">");
        m_mode = Mode::elementStartTagClosed;
        break;

    default:
        // TODO
        break;
    }

    m_file.write("<");
    m_file.write(name);
    m_openElements.push_back(name);
    m_mode = Mode::elementStartTagOpen;
}

void XMLWriter::writeElementEnd()
{
    // TODO: handle errors
    switch (m_mode)
    {
    case Mode::elementStartTagOpen:
        // We have an empty element
        m_file.write(" />");
        break;

    case Mode::elementStartTagClosed:
        // We have an element with some content and now we are closing it
        m_file.write("</");
        m_file.write(m_openElements.back());
        m_file.write(">");
        break;

    default:
        // TODO: error
        break;
    }

    m_openElements.pop_back();
    if (m_openElements.empty())
    {
        m_mode = Mode::rootClosed;
        m_file.write("\n");
    }
    else
    {
        m_mode = Mode::elementStartTagClosed;
    }
}

void XMLWriter::writeAttribute(const std::string& name, const std::string& unescapedValue)
{
    XMLEscapedString escapedValue = XMLEscapedString::FromUnescapedString(unescapedValue);
    writeAttribute(name, escapedValue);
}

void XMLWriter::writeAttribute(const std::string& name, const XMLEscapedString& value)
{
    // TODO: handle errors
    switch (m_mode)
    {
    default:
        // TODO
        break;
    }

    m_file.write(" ");
    m_file.write(name);
    m_file.write("=\"");
    m_file.write(value.asEscapedString());
    m_file.write("\"");
}

void XMLWriter::writeText(const std::string& unescapedText)
{
    XMLEscapedString escapedText = XMLEscapedString::FromUnescapedString(unescapedText);
    writeText(escapedText);
}

void XMLWriter::writeText(const XMLEscapedString& text)
{
    // TODO: handle errors
    switch (m_mode)
    {
    case Mode::elementStartTagOpen:
        // We have an unclosed start tag
        m_file.write(">");
        m_mode = Mode::elementStartTagClosed;
        break;

    default:
        // TODO
        break;
    }

    m_file.write(text.asEscapedString());
}

void XMLWriter::writeNewlineAndIndentation()
{
    // TODO: handle errors
    switch (m_mode)
    {
    case Mode::elementStartTagOpen:
        // We have an unclosed start tag
        m_file.write(">");
        m_mode = Mode::elementStartTagClosed;
        break;

    default:
        // TODO
        break;
    }

    m_file.write("\n");
    m_file.write(m_indentation);
}

void XMLWriter::increaseIndentation()
{
    m_indentation.append("    ");
}

void XMLWriter::decreaseIndentation()
{
    // TODO: error or exception if empty
    m_indentation.erase(m_indentation.end() - 4, m_indentation.end());
}
