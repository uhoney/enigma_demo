#include "log.h"

namespace enigma
{
	// Initialize static member
	LogLevel Log::current_level = LogLevel::DEBUG;

	void Log::set_level(LogLevel level)
	{
		current_level = level;
	}

	void Log::debug(const std::string& message)
	{
		if (current_level <= LogLevel::DEBUG)
		{
			std::printf("[DEBUG] %s\n", message.c_str());
			std::fflush(stdout);
		}
	}

	void Log::info(const std::string& message)
	{
		if (current_level <= LogLevel::INFO)
		{
			std::printf("[INFO] %s\n", message.c_str());
			std::fflush(stdout);
		}
	}

	void Log::warning(const std::string& message)
	{
		if (current_level <= LogLevel::WARNING)
		{
			std::printf("[WARNING] %s\n", message.c_str());
			std::fflush(stdout);
		}
	}

	void Log::error(const std::string& message)
	{
		if (current_level <= LogLevel::ERROR)
		{
			std::fprintf(stderr, "[ERROR] %s\n", message.c_str());
			std::fflush(stderr);
		}
	}
}