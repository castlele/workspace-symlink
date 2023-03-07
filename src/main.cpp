#include "../include/logger.h"
#include "../include/writer.h"

static std::string ZSH_RC_FILE = "/Users/castlelecs/.zshrc";

/*
 * Usage: symwork <sym_name>
 *  -> if  : <sym_name> is in .zshrc throw error
 *  -> else: appendes alias <sym_name>="~/path/to/current/folder"
 */
int main(int argc, char *argv[]) {
    Logger logger;

    if (argc < 2) {
        logger.print_usage_error(NOT_ENOUGH_ARGUMENTS);
        return -1;
    }

    if (argc > 2) {
        logger.print_usage_error(TOO_MANY_ARGUMENTS);
        return -1;
    }

    std::string arg;
    arg.append(*(++argv));

    if (logger.print_help_if_needed(arg))
        return 0;

    Writer writer (ZSH_RC_FILE);

    return writer.add_symlink(arg);
}
