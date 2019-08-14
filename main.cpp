#include "logger.hpp"


int main() {
    logger_config_t config = {
        "./logs/debug.log",
        "./logs/error.log",
        true
    };
    Logger *logger = Logger::get_instance();
    logger->initialize(&config);

    // debug
    logger->trace("this is test");

    // error log
    logger->error("this is error");

    return 0;
}
