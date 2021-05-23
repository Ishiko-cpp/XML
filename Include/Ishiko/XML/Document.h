/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_XML_DOCUMENT_H_
#define _ISHIKO_XML_DOCUMENT_H_

#include <boost/filesystem/path.hpp>
#include <Ishiko/Errors/Error.h>
#include <pugixml.hpp>
#include <string>

namespace Ishiko
{
namespace XML
{

class Document
{
public:
    void create(const boost::filesystem::path& path, const std::string& rootElementName, Ishiko::Error& error);

    void commit();

private:
    boost::filesystem::path m_path;
    pugi::xml_document m_document;
};

}
}

#endif
