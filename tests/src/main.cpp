/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLEscapedStringTests.hpp"
#include "XMLPushParserTests.hpp"
#include "XMLWriterTests.hpp"
#include "Ishiko/XML/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoXML");

    theTestHarness.context().setDataDirectory("../../data");
    theTestHarness.context().setOutputDirectory("../../output");
    theTestHarness.context().setReferenceDirectory("../../reference");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<XMLEscapedStringTests>();
    theTests.append<XMLWriterTests>();
    theTests.append<XMLPushParserTests>();
    
    return theTestHarness.run();
}
