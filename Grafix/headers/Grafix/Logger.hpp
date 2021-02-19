#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Grafix
{
    class Logger
    {
    public:
        static void Init();

        static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define GF_CORE_FATAL(...)  ::Grafix::Logger::GetCoreLogger()->critical(__VA_ARGS__)
#define GF_CORE_ERROR(...)  ::Grafix::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define GF_CORE_WARN(...)   ::Grafix::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define GF_CORE_INFO(...)   ::Grafix::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define GF_CORE_TRACE(...)  ::Grafix::Logger::GetCoreLogger()->trace(__VA_ARGS__)

#define GF_FATAL(...)       ::Grafix::Logger::GetClientLogger()->critical(__VA_ARGS__)
#define GF_ERROR(...)       ::Grafix::Logger::GetClientLogger()->error(__VA_ARGS__)
#define GF_WARN(...)        ::Grafix::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define GF_INFO(...)        ::Grafix::Logger::GetClientLogger()->info(__VA_ARGS__)
#define GF_TRACE(...)       ::Grafix::Logger::GetClientLogger()->trace(__VA_ARGS__)
