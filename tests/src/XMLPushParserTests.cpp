/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLPushParserTests.hpp"
#include "helpers/XMLPushParserTestCallbacks.hpp"
#include "Ishiko/XML/XMLPushParser.hpp"
#include <Ishiko/FileSystem.hpp>

using namespace Ishiko;

XMLPushParserTests::XMLPushParserTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "XMLPushParser tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("onData test 1", OnDataTest1);
}

void XMLPushParserTests::ConstructorTest1(Test& test)
{
    XMLPushParserTestCallbacks callbacks;
    XMLPushParser parser(callbacks);

    ISHIKO_TEST_PASS();
}

void XMLPushParserTests::OnDataTest1(Test& test)
{
    boost::filesystem::path inputPath = test.context().getDataPath("root_only.xml");
    std::string xmlData = FileSystem::ReadFile(inputPath);

    XMLPushParserTestCallbacks callbacks;
    XMLPushParser parser(callbacks);

    bool complete = parser.onData(xmlData, true);

    const char* outputFileName = "XMLPushParserTests_OnDataTest1.xml";
    callbacks.exportToXML(test.context().getOutputPath(outputFileName));

    ISHIKO_TEST_FAIL_IF_NOT(complete);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputFileName);
    ISHIKO_TEST_PASS();
}
