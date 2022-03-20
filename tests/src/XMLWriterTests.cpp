/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLWriterTests.hpp"
#include "Ishiko/XML/XMLWriter.hpp"
#include <boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace Ishiko;

XMLWriterTests::XMLWriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "XMLWriter tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("writeStartDocument test 1", WriteStartDocumentTest1);
}

void XMLWriterTests::ConstructorTest1(Test& test)
{
    XMLWriter writer;

    ISHIKO_TEST_PASS();
}

void XMLWriterTests::CreateTest1(FileComparisonTest& test)
{
    path outputPath = test.context().getTestOutputPath("XMLWriterTests_CreateTest1.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("XMLWriterTests_CreateTest1.xml"));

    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteStartDocumentTest1(FileComparisonTest& test)
{
    path outputPath = test.context().getTestOutputPath("XMLWriterTests_WriteStartDocumentTest1.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeStartDocument();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("XMLWriterTests_WriteStartDocumentTest1.xml"));

    ISHIKO_TEST_PASS();
}
