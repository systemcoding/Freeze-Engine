#include "UtilityManager.h"

namespace Freeze
{
    void UtilityManager::OpenDirectory(const std::string &filepath)
    {
        const std::string &command = "xdg-open " + filepath;
        if (filepath.size() == 0 || filepath == "")
        {
            FZ_ASSERT("Filepath Not Provided");
        }
        system(command.c_str());
    }

    void UtilityManager::PrintCurrentBuildDirectory()
    {
        FZ_INFO("Current Working Directory {}", build_dir);
    }

    UtilityManager::~UtilityManager()
    {
    }
};