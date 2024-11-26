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

        void build();

    private:
        std::string m_dpkg_path;
    };
}

#endif
