/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_XML_WRITER_H_
#define _ISHIKO_XML_WRITER_H_

#include <boost/filesystem.hpp>
#include <Ishiko/Errors.h>
#include <string>

namespace Ishiko
{
namespace XML
{

class Writer
{
public:
    Writer();

    void create(const boost::filesystem::path& path, const std::string& rootElementName, Ishiko::Error& error);
};

}
}

#endif
