/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_XML_ELEMENT_H_
#define _ISHIKO_XML_ELEMENT_H_

#include <pugixml.hpp>
#include <string>

namespace Ishiko
{
namespace XML
{

class Element
{
public:
    Element();
    Element(pugi::xml_node node);

    void appendChild(const std::string& name);
};

}
}

#endif
