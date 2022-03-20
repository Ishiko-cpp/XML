/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#include "XMLWriter.hpp"

using namespace Ishiko::FileSystem;

namespace Ishiko
{
namespace XML
{

Writer::Writer()
{
}

void Writer::create(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_file.create(path.string(), error);
}

void Writer::writeStartDocument()
{
    m_file.writeLine("<?xml version=\"1.0\"?>");
}

void Writer::writeEndDocument()
{
}

}
}
