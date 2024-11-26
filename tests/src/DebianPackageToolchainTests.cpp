// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianPackageToolchainTests.hpp"
#include "CodeSmithy/PackageToolchains/DebianPackageToolchain.hpp"

using namespace CodeSmithy;

DebianPackageToolchainTests::DebianPackageToolchainTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "DebianPackageToolchain tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("build test 1", BuildTest1);
}

void DebianPackageToolchainTests::ConstructorTest1(Ishiko::Test& test)
{
    DebianPackageToolchain toolchain;

    ISHIKO_TEST_PASS();
}

void DebianPackageToolchainTests::BuildTest1(Ishiko::Test& test)
{
    DebianPackageToolchain toolchain;
    toolchain.build();

    ISHIKO_TEST_PASS();
}
