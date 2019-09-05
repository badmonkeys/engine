#pragma once

#include <memory>
#include <mutex>
#include <thread>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <unordered_map>


namespace Evo {
  enum LogLevel {
    Trace,
    Debug,
    Info,
    Warn,
    Error,
    Critical
  };

  const std::unordered_map<LogLevel, std::string> uncolored
  {
    {LogLevel::Error, "[ERROR]"}, {LogLevel::Warn, "[WARN]"}, {LogLevel::Info, "[INFO]"},
    {LogLevel::Debug, "[DEBUG]"}, {LogLevel::Trace, "[TRACE]"}, {LogLevel::Critical, "[CRITICAL]"}
  };
  const std::unordered_map<LogLevel, std::string> colored
  {
    {LogLevel::Trace, "\u001b[38;5;14mTRC\u001b[0m"}, {LogLevel::Debug, "\u001b[38;5;12mDBG\u001b[0m"},
    {LogLevel::Info, "\u001b[38;5;10mINF\u001b[0m"}, {LogLevel::Warn, "\u001b[38;5;11mWRN\u001b[0m"},
    {LogLevel::Error, "\u001b[38;5;1mERR\u001b[0m"}, {LogLevel::Critical, "\u001b[38;5;9mCRT\u001b[0m"}
  };

  const std::string sep = "|";

  class Logger {
    public:
      Logger(const std::string& name, LogLevel level = LogLevel::Info) {
        _name = name;
        _level = level;
        _msgcount = 0;
      }

      virtual ~Logger() {}

      inline void trace(const std::string& msg) {
        output(msg, LogLevel::Trace);
      }

      inline void debug(const std::string& msg) {
        output(msg, LogLevel::Debug);
      }

      inline void info(const std::string& msg) {
        output(msg, LogLevel::Info);
      }

      inline void warn(const std::string& msg) {
        output(msg, LogLevel::Warn);
      }

      inline void error(const std::string& msg) {
        output(msg, LogLevel::Error);
      }

      inline void critical(const std::string& msg) {
        output(msg, LogLevel::Critical);
      }

    protected:
      std::string _name;
      LogLevel _level;
      long _msgcount;

      void output(const std::string& msg, LogLevel lvl) {
        if (_level > lvl)
          return;


        size_t thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
        std::stringstream out;

        //_msgcount++;
        out << "[" << _name << sep << std::hex << std::setfill('0') << std::setw(6) << (thread_id % 1000000) << sep << std::setfill('0') << std::setw(4) << std::hex << ++_msgcount << "] " << colored.find(lvl)->second << " " << msg << std::endl;

        // std::cout is internally thread safe and we don't really
        // care about interleaving here because we're tagging thread IDs
        std::cout << out.str();
        std::cout.flush();
      }
  };
}
