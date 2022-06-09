/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#include "XMLWriter.hpp"

namespace Ishiko
{

XMLWriter::XMLWriter()
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

}
