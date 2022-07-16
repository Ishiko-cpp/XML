/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_XML_TESTS_HELPERS_XMLPUSHPARSERTESTCALLBACKS_HPP_
#define _ISHIKO_XML_TESTS_HELPERS_XMLPUSHPARSERTESTCALLBACKS_HPP_

#include "Ishiko/XML/XMLPushParser.hpp"
#include <boost/filesystem.hpp>
#include <boost/utility/string_view.hpp>
#include <utility>
#include <vector>

class XMLPushParserTestCallbacks : public Ishiko::XMLPushParser::Callbacks
{
public:
    void onXMLDeclaration() override;
    void onStartTag(boost::string_view name) override;
    void onEndTag() override;
    void onCharacterData(boost::string_view data) override;

    void exportToXML(const boost::filesystem::path& path) const;

private:
    std::vector<std::pair<std::string, std::string>> m_events;
};

#endif
