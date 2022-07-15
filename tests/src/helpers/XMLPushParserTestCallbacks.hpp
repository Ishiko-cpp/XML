/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_HELPERS_XMLPUSHPARSERTESTCALLBACKS_HPP_
#define _ISHIKO_XML_TESTS_HELPERS_XMLPUSHPARSERTESTCALLBACKS_HPP_

#include "Ishiko/XML/XMLPushParser.hpp"
#include <boost/filesystem.hpp>

class XMLPushParserTestCallbacks : public Ishiko::XMLPushParser::Callbacks
{
public:
    void exportToXML(const boost::filesystem::path& path) const;
};

#endif
