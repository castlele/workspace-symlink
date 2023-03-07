#include <cstdio>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "../include/writer.h"

// MARK: - Init

Writer::Writer(std::string configFilePath) {
    this->configPath = configFilePath;
}

// MARK: - Public methods

int Writer::add_symlink(std::string name) {
    std::string alias = create_alias(name);
    return add_alias(alias, name);
}

// MARK: - Private methods

std::string Writer::create_alias(std::string name) {
    return "alias " + name + "=\"cd " + get_current_path() + "\"";
}

std::string Writer::get_current_path() {
    return std::filesystem::current_path();
}

int Writer::add_alias(std::string alias, std::string name) {
    std::string text;
    std::fstream fs (configPath, std::ios::in);

    while (std::getline(fs, text)) {
        if (text.find(name) != std::string::npos) {
            logger.print_usage_error(SYMLINK_IS_ALREADY_USED);
            fs.close();
            return -1;
        }
    }

    fs.close();

#ifndef DEBUG
    fs.open(configPath, std::ios::app);
    fs << std::endl << alias.c_str();
    fs.close();
#endif

    return 0;
}
