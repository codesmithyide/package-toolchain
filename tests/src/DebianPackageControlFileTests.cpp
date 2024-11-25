// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianPackageControlFileTests.hpp"
#include "CodeSmithy/PackageToolchains/DebianPackageControlFile.hpp"

using namespace CodeSmithy;

DebianPackageControlFileTests::DebianPackageControlFileTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "DebianPackageControlFile tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DebianPackageControlFileTests::ConstructorTest1(Ishiko::Test& test)
{
    DebianPackageControlFile control_file;

    ISHIKO_TEST_PASS();
}
