#include "DX3D/Core/Logger.h"
#include <iostream>

dx3d::Logger::Logger(LogLevel logLevel):
	m_logLevel(logLevel)
{
	std::clog << "| MoonRock Studios - C++ 3D Game Test |" << "\n";
	std::clog << "---------------------------------------" << "\n";
}

void dx3d::Logger::log(LogLevel logLevel, const char* message) const
{
	auto logLevelToString = [](LogLevel level)
		{
			switch (level)
			{
			case LogLevel::Info: return "Info";
			case LogLevel::Warning: return "Warning";
			case LogLevel::Error: return "Error";
			default: return "Unknown";
			}
		};

	if (logLevel > m_logLevel)
		return;

	std::clog << "[DX3D " << logLevelToString(logLevel) << "]: " << message << "\n";
}