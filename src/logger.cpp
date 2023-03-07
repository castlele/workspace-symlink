#include <iostream>

#include "../include/logger.h"

void Logger::print_help() {
    std::cout << "USAGE: symwork <#name_of_the_link#>" << std::endl;
}

bool Logger::print_help_if_needed(std::string str) {
    bool isHelp = str.find("help") != std::string::npos;
    bool isShortHelp = str.find("-h") != std::string::npos;

    if (isHelp || isShortHelp) {
        print_help();
        return true;
    }

    return false;
}

void Logger::print_usage_error(Error err) {
    std::cout << get_string_error(err) << std::endl;
}

// MARK: - Private methods

std::string Logger::get_string_error(Error err) {
    switch (err) {
    case TOO_MANY_ARGUMENTS:
        return "Too many arguments used. Max == 2";

    case NOT_ENOUGH_ARGUMENTS:
        return "Not anought arguments. 2 should be used";

    case CANT_OPEN_FILE:
        return "Can't open file for writing";

    case SYMLINK_IS_ALREADY_USED:
        return "Symlink with the same name is already used";
    }
}
