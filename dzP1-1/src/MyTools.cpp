#include "include/MyTools.h"
#include "include/Timer.h"

#include <stdint.h>
#include <time.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>

namespace MyTools {

std::ofstream logOut;

IFileLogger& getInternalInstance() {
    static MyTools::FileLoggerSingletone theInstance;
    return theInstance;
}

class FileLoggerSingletoneProxy : public IFileLogger {
public:
    double time_log;

    virtual void OpenLogFile(const std::string& FN) override {
        Timer t;
        getInternalInstance().OpenLogFile(FN);
        time_log+=t.get();
    };

    virtual void CloseLogFile() override {
        Timer t;
        getInternalInstance().CloseLogFile();
        time_log+=t.get();
    };

    virtual void WriteToLog(const std::string& str) override {
        Timer t;
        getInternalInstance().WriteToLog(str);
        //time_log+=t.get();
    };

    virtual void WriteToLog(const std::string& str, int n) override {
        Timer t;
        getInternalInstance().WriteToLog(str,n);
        //time_log+=t.get();
    };

    virtual void WriteToLog(const std::string& str, double d) override {
        Timer t;
        getInternalInstance().WriteToLog(str,d);
        //time_log+=t.get();
    };


    static IFileLogger& getInstance() {
      static FileLoggerSingletoneProxy theInstance;
      return theInstance;
    }

private:

  FileLoggerSingletoneProxy() {
      time_log=0;
  }

  ~FileLoggerSingletoneProxy() {
      std::cout << std::endl;
      std::cout << "Using time: "<< time_log << " ms";
      std::cout << std::endl;
  }

  FileLoggerSingletoneProxy(const FileLoggerSingletoneProxy& root) = delete;
  FileLoggerSingletoneProxy& operator=(const FileLoggerSingletoneProxy&) = delete;
  FileLoggerSingletoneProxy(FileLoggerSingletoneProxy&& root) = delete;
  FileLoggerSingletoneProxy& operator=(FileLoggerSingletoneProxy&&) = delete;
};

// --------
void FileLoggerSingletone::OpenLogFile(const std::string &FN)
 { logOut.open(FN, std::ios_base::out); }

void FileLoggerSingletone::CloseLogFile() {
  if (logOut.is_open()) {
    logOut.close();
  }
}

std::string GetCurDateTime() {
  auto cur = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(cur);
  char* buf = ctime(&time);
  return std::string(buf);
}

void FileLoggerSingletone::WriteToLog(const std::string &str) {
  if (logOut.is_open()) {
    logOut << GetCurDateTime() << " - " << str << std::endl;
  }
}

void FileLoggerSingletone::WriteToLog(const std::string &str, int n) {
  if (logOut.is_open()) {
    logOut << GetCurDateTime() << " - " << str << n << std::endl;
  }
}

void FileLoggerSingletone::WriteToLog(const std::string &str, double d) {
  if (logOut.is_open()) {
    logOut << GetCurDateTime() << " - " << str << d << std::endl;
  }
}

IFileLogger& FileLoggerSingletone::getInstance() {
    return FileLoggerSingletoneProxy::getInstance();
};

} // namespace MyTools
