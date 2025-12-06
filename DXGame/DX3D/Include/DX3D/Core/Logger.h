#pragma once


namespace dx3d
{
	class Logger final
	{
	public:
		enum class LogLevel
		{
			Error = 0,
			Warning,
			Info
		};

		explicit Logger(LogLevel logLevel = LogLevel::Error);

		void log(LogLevel logLevel, const char* message) const;

	private:
		LogLevel m_logLevel = LogLevel::Error;
	};


	#define DX3DLogInfo(msg)\
		getLogger().log((Logger::LogLevel::Info), msg);

	#define DX3DLogWarning(msg)\
		getLogger().log((Logger::LogLevel::Warning), msg);

	#define DX3DLogError(msg)\
		getLogger().log((Logger::LogLevel::Error), msg);


	#define DX3DLogErrorAndThrow(msg)\
		{\
			DX3DLogError(msg);\
			throw std::runtime_error(msg);\
		}
}

