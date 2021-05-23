/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#include "Document.h"
#include <fstream>

namespace Ishiko
{
namespace XML
{

void Document::create(const boost::filesystem::path& path, const std::string& rootElementName, Ishiko::Error& error)
{
    m_path = path;
    pugi::xml_node rootNode = m_document.append_child(rootElementName.c_str());
    if (rootNode)
    {
        std::ofstream file(m_path.string());
        m_document.save(file);
    }
}

void Document::commit()
{
}

}
}
