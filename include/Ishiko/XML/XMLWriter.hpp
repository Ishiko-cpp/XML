/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_XML_XMLWRITER_HPP_
#define _ISHIKO_CPP_XML_XMLWRITER_HPP_

#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>

namespace Ishiko
{
namespace XML
{

class Writer
{
public:
    Writer();

    void create(const boost::filesystem::path& path, Ishiko::Error& error);

    void writeStartDocument();
    void writeEndDocument();

private:
    TextFile m_file;
};

}
}

#endif
