/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLWriterTests.hpp"
#include "Ishiko/XML/XMLWriter.hpp"
#include <boost/filesystem.hpp>

using namespace Ishiko;

XMLWriterTests::XMLWriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "XMLWriter tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("create test 1", CreateTest1);
    append<FileComparisonTest>("writeXMLDeclaration test 1", WriteXMLDeclarationTest1);
    append<HeapAllocationErrorsTest>("writeElementStart test 1", WriteElementStartTest1);
    append<HeapAllocationErrorsTest>("writeElementStart test 2", WriteElementStartTest2);
}

void XMLWriterTests::ConstructorTest1(Test& test)
{
    XMLWriter writer;

    ISHIKO_TEST_PASS();
}

void XMLWriterTests::CreateTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath = test.context().getTestOutputPath("XMLWriterTests_CreateTest1.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.close();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("XMLWriterTests_CreateTest1.xml"));

    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteXMLDeclarationTest1(FileComparisonTest& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteXMLDeclarationTest1.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();

    writer.close();

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("XMLWriterTests_WriteXMLDeclarationTest1.xml"));

    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteElementStartTest1(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest1.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest1.xml",
        "XMLWriterTests_WriteElementStartTest1.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteElementStartTest2(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest2.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeText("A book by H.G. Wells");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest2.xml",
        "XMLWriterTests_WriteElementStartTest2.xml");
    ISHIKO_TEST_PASS();
}
