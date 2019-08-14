#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>


typedef struct {
    const char* log_filename;
    const char* error_log_file_name;
    bool is_enable;
} logger_config_t;


class Logger {
    private:
        static Logger* _myself;
        logger_config_t* _config;

        Logger();
        ~Logger();

        /**
         * ログファイルへ出力用にストリームをフォーマット
         */
        std::stringstream* _format(const char* text);

        /**
         * ファイル書き込み
         */
        void _write(const char* text, const char* filename);
    public:
        /**
         * Loggerオブジェクト取得
         */
        static Logger* get_instance();

        /**
         * 初期化設定
         */
        void initialize(logger_config_t* config);

        /**
         * ログ出力
         */
        void trace(const char* text);

        /**
         * エラーログ出力
         */
        void error(const char* text);
};

#endif /* LOGGER_H_ */
