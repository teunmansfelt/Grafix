
#include "Grafix/Logger.hpp"

namespace Grafix
{
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    void Logger::Init()
    {
        spdlog::set_pattern("[%T] %-7n: {%l} %^%v%$");
        s_CoreLogger = spdlog::stdout_color_mt("GRAFIX");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}