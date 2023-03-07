#pragma once

#include <string>

enum Error {
    NOT_ENOUGH_ARGUMENTS,
    TOO_MANY_ARGUMENTS,
    CANT_OPEN_FILE,
    SYMLINK_IS_ALREADY_USED,
};

class Logger {
    public:
        Logger() { }

        void print_usage_error(Error err);
        void print_help();
        bool print_help_if_needed(std::string str);

    private:
        std::string get_string_error(Error err);
};           
