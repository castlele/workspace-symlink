#pragma once

#include <string>

#include "logger.h"

class Writer {
    Logger logger;
    std::string configPath;

    public:
        Writer(std::string configFilePath);
        
        int add_symlink(std::string name);

    private:
        std::string create_alias(std::string name);
        int add_alias(std::string alias, std::string name);
        std::string get_current_path();
};
