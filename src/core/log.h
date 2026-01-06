#pragma once
#include <iostream>
#include <string>
#include <cstdio>

namespace enigma
{
	enum class LogLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	class Log
	{
	private:
		static LogLevel current_level;

	public:
		static void set_level(LogLevel level);

		// String-only versions
		static void debug(const std::string& message);
		static void info(const std::string& message);
		static void warning(const std::string& message);
		static void error(const std::string& message);

		// Template versions for formatted output with parameters
		template<typename... Args>
		static void debug(const char* format, Args... args)
		{
			if (current_level <= LogLevel::DEBUG)
			{
				std::printf("[DEBUG] ");
				std::printf(format, args...);
				std::printf("\n");
				std::fflush(stdout);
			}
		}

		template<typename... Args>
		static void info(const char* format, Args... args)
		{
			if (current_level <= LogLevel::INFO)
			{
				std::printf("[INFO] ");
				std::printf(format, args...);
				std::printf("\n");
				std::fflush(stdout);
			}
		}

		template<typename... Args>
		static void warning(const char* format, Args... args)
		{
			if (current_level <= LogLevel::WARNING)
			{
				std::printf("[WARNING] ");
				std::printf(format, args...);
				std::printf("\n");
				std::fflush(stdout);
			}
		}

		template<typename... Args>
		static void error(const char* format, Args... args)
		{
			if (current_level <= LogLevel::ERROR)
			{
				std::fprintf(stderr, "[ERROR] ");
				std::fprintf(stderr, format, args...);
				std::fprintf(stderr, "\n");
				std::fflush(stderr);
			}
		}
	};
}