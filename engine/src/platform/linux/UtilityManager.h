// This is specifically for Linux!
#ifdef __linux__

#include <cstdlib>
#include <csignal>
#include <string>

#include "build_path.h"

#include "../../include/core/Core.h"

extern const char* build_dir;

namespace Freeze
{
    class UtilityManager
    {
    public:
        UtilityManager() = default;

        void OpenDirectory(const std::string &filepath);
        void PrintCurrentBuildDirectory();

        ~UtilityManager();
    };
};

#else
    #error "Not Running Linux!"

#endif