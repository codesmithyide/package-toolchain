// SPDX-FileCopyrightText: 2020-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_DEBIANPACKAGETOOLCHAIN_HPP
#define GUARD_CODESMITHYIDE_PACKAGETOOLCHAINS_DEBIANPACKAGETOOLCHAIN_HPP

#include <string>

namespace CodeSmithy
{
    class DebianPackageToolchain
    {
    public:
        DebianPackageToolchain();

        void build(const std::string& source_path);

    private:
        std::string m_dpkg_path;
    };
}

#endif
