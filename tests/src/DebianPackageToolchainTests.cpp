// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "DebianPackageToolchainTests.hpp"
#include "CodeSmithy/PackageToolchains/DebianPackageToolchain.hpp"
#include <boost/filesystem.hpp>

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
#if ISHIKO_OS == ISHIKO_OS_WINDOWS
    test.skip();
#endif

    const boost::filesystem::path& package_source_path = test.context().getOutputPath("debian-package-1");
    test.utils().copyFile("${context.data}/debian-package-1/DEBIAN/control", "${context.output}/debian-package-1/DEBIAN/control");
    test.utils().copyFile("${context.data}/debian-package-1/usr/bin/dummy_executable", "${context.output}/debian-package-1/usr/bin/dummy_executable");

    DebianPackageToolchain toolchain;
    toolchain.build(package_source_path.string());

    ISHIKO_TEST_PASS();
}
