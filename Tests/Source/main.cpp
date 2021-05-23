/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/XML/blob/master/LICENSE.txt
*/

#include "DocumentTests.h"
#include <Ishiko/TestFramework/TestFrameworkCore.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoXML");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<DocumentTests>();
    
    return theTestHarness.run();
}
