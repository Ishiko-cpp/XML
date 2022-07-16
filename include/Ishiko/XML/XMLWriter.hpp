/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_XML_XMLWRITER_HPP_
#define _ISHIKO_CPP_XML_XMLWRITER_HPP_

#include "XMLEscapedString.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>
#include <string>
#include <vector>

namespace Ishiko
{

class XMLWriter
{
public:
    XMLWriter();
    void create(const boost::filesystem::path& path, Error& error);
    void close();

    void writeXMLDeclaration();
    void writeElementStart(const std::string& name);
    void writeElementEnd();
    void writeAttribute(const std::string& name, const std::string& unescapedValue);
    void writeAttribute(const std::string& name, const XMLEscapedString& value);
    void writeText(const std::string& unescapedText);
    void writeText(const XMLEscapedString& text);

    void writeNewlineAndIndentation();
    void increaseIndentation();
    void decreaseIndentation();

private:
    enum class Mode
    {
        initial,
        elementStartTagOpen,
        elementStartTagClosed,
        rootClosed
    };

    TextFile m_file;
    Mode m_mode;
    std::string m_indentation;
    std::vector<std::string> m_openElements;
};

}

#endif
