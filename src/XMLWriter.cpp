/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#include "XMLWriter.hpp"

namespace Ishiko
{

XMLWriter::XMLWriter()
    : m_mode(Mode::initial)
{
}

void XMLWriter::create(const boost::filesystem::path& path, Error& error)
{
    m_file.create(path.string(), error);
}

void XMLWriter::writeXMLDeclaration()
{
    m_file.writeLine("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
}

void XMLWriter::writeElementStart(const std::string& name)
{
    m_file.write("<");
    m_file.write(name);
    m_openElements.push_back(name);
    m_mode = Mode::elementStart;
}

void XMLWriter::writeElementEnd()
{
    // TODO: handle errors
    switch (m_mode)
    {
    case Mode::elementStart:
        // We have an empty element
        m_file.write(" />");
        break;

    default:
        // TODO: error
        break;
    }

    m_openElements.pop_back();
}

}
