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
    append<HeapAllocationErrorsTest>("writeElementStart test 3", WriteElementStartTest3);
    append<HeapAllocationErrorsTest>("writeElementStart test 4", WriteElementStartTest4);
    append<HeapAllocationErrorsTest>("writeElementStart test 5", WriteElementStartTest5);
    append<HeapAllocationErrorsTest>("writeElementStart test 6", WriteElementStartTest6);
    append<HeapAllocationErrorsTest>("writeElementStart test 7", WriteElementStartTest7);
    append<HeapAllocationErrorsTest>("writeAttribute test 1", WriteAttributeTest1);
    append<HeapAllocationErrorsTest>("writeAttribute test 2", WriteAttributeTest2);
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

void XMLWriterTests::WriteElementStartTest3(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest3.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeElementEnd();
    writer.writeElementStart("journal");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest3.xml",
        "XMLWriterTests_WriteElementStartTest3.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteElementStartTest4(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest4.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeText("A book by H.G. Wells");
    writer.writeElementEnd();
    writer.writeElementStart("journal");
    writer.writeText("The Times");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest4.xml",
        "XMLWriterTests_WriteElementStartTest4.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteElementStartTest5(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest5.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeElementStart("title");
    writer.writeElementEnd();
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest5.xml",
        "XMLWriterTests_WriteElementStartTest5.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteElementStartTest6(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest6.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeElementStart("metadata");
    writer.writeElementStart("title");
    writer.writeElementEnd();
    writer.writeElementEnd();
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest6.xml",
        "XMLWriterTests_WriteElementStartTest6.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteElementStartTest7(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteElementStartTest7.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeText("text1");
    writer.writeElementStart("metadata");
    writer.writeText("text2");
    writer.writeElementStart("title");
    writer.writeText("text3");
    writer.writeElementEnd();
    writer.writeText("text4");
    writer.writeElementEnd();
    writer.writeText("text5");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteElementStartTest7.xml",
        "XMLWriterTests_WriteElementStartTest7.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteAttributeTest1(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteAttributeTest1.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeAttribute("title", "War of The Worlds");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteAttributeTest1.xml",
        "XMLWriterTests_WriteAttributeTest1.xml");
    ISHIKO_TEST_PASS();
}

void XMLWriterTests::WriteAttributeTest2(Test& test)
{
    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("XMLWriterTests_WriteAttributeTest2.xml");

    XMLWriter writer;

    Error error;
    writer.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    writer.writeXMLDeclaration();
    writer.writeElementStart("book");
    writer.writeAttribute("title", "War of The Worlds");
    writer.writeText("A book by H.G. Wells");
    writer.writeElementEnd();

    writer.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("XMLWriterTests_WriteAttributeTest2.xml",
        "XMLWriterTests_WriteAttributeTest2.xml");
    ISHIKO_TEST_PASS();
}
