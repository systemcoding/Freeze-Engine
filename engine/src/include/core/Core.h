#pragma once

#include <spdlog/spdlog.h>

#include <string>

#define FZ_INFO(x, ...) spdlog::info(x, ##__VA_ARGS__)
#define FZ_WARN(x, ...) spdlog::warn(x, ##__VA_ARGS__)
#define FZ_ERROR(x, ...) spdlog::error(x, ##__VA_ARGS__)

#ifdef __linux__
    #include <csignal>
    #define FZ_ASSERT(x, ...) {FZ_ERROR(x, ##__VA_ARGS__); raise(SIGTRAP);}
#else
    // For MSVC
    #define FZ_ASSERT(x, ...) {FZ_ERROR(x, ##__VA_ARGS__); __debugbreak();}
#endif