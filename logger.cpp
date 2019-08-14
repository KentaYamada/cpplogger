#include "logger.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

// initialize logger object
Logger* Logger::_myself = nullptr;


Logger::Logger(){}

Logger::~Logger(){}

std::stringstream* Logger::_format(const char* text) {
    // タイムスタンプ生成
    time_t today = time(nullptr);
    const tm* local_time = localtime(&today);

    // ストリーム生成
    auto *ss = new std::stringstream();
    *ss << local_time->tm_year + 1900 << "-"
        << std::setfill('0') << std::right << std::setw(2) << local_time->tm_mon + 1 << "-"
        << std::setfill('0') << std::right << std::setw(2) << local_time->tm_mday << " "
        << std::setfill('0') << std::right << std::setw(2) << local_time->tm_hour << ":"
        << std::setfill('0') << std::right << std::setw(2) << local_time->tm_min << ":"
        << std::setfill('0') << std::right << std::setw(2) << local_time->tm_sec << " "
        << text << std::endl;

    return ss;
}

void Logger::_write(const char* text, const char* filename) {
    if (!this->_config->is_enable) {
        return;
    }

    auto *ofs = new std::ofstream(filename, std::ofstream::app);
    auto *ss = this->_format(text);

    *ofs << text << std::endl;
    ofs->close();

    delete ss;
    delete ofs;
    ss = nullptr;
    ofs = nullptr;
}

Logger* Logger::get_instance() {
    if (Logger::_myself == nullptr) {
        Logger::_myself = new Logger();
    }

    return Logger::_myself;
}

void Logger::initialize(logger_config_t* config) {
    this->_config = config;
}

void Logger::trace(const char* text) {
    this->_write(text, this->_config->log_filename);
}

void Logger::error(const char* text) {
    this->_write(text, this->_config->error_log_file_name);
}
