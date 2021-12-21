#pragma once

#include <string>
#include <cstring>

namespace MyTools {

class IFileLogger {
public:

    virtual ~IFileLogger() = default;
    virtual void OpenLogFile(const std::string& FN) = 0;
    virtual void CloseLogFile() = 0;
    virtual void WriteToLog(const std::string& str) = 0;
    virtual void WriteToLog(const std::string& str, int n) = 0;
    virtual void WriteToLog(const std::string& str, double d) = 0;

};

class FileLoggerSingletone : public IFileLogger{

public:
    static  IFileLogger& getInstance();

/*    {
        static FileLoggerSingletone theFileLoggerSingletone;
        return theFileLoggerSingletone;
    } */

    virtual void OpenLogFile(const std::string& FN) override;

    virtual void CloseLogFile() override;

    virtual void WriteToLog(const std::string& str) override;

    virtual void WriteToLog(const std::string& str, int n) override;

    virtual void WriteToLog(const std::string& str, double d) override;

private:
    friend IFileLogger& getInternalInstance();

    FileLoggerSingletone() = default;
    ~FileLoggerSingletone() = default;
    FileLoggerSingletone(const FileLoggerSingletone& root) = delete;
    FileLoggerSingletone& operator = (const FileLoggerSingletone&) = delete;
    FileLoggerSingletone(const FileLoggerSingletone&& root) = delete;
    FileLoggerSingletone& operator = (const FileLoggerSingletone&&) = delete;
 };
}; // namespace MyTools
