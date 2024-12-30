#ifndef STACKMANAGER_H
#define STACKMANAGER_H

#include <stack>
#include <string>
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class StackManager {
private:
    std::stack<std::string> stack1;
    std::stack<std::string> stack2;

public:
    std::shared_ptr<spdlog::logger> logger;

    StackManager(const std::string& loggerName = "stack_logger");

    void pushToStack1(const std::string& item);
    void pushToStack2(const std::string& item);
    void popFromStack1();
    void popFromStack2();
    void swapStacks();
    void printStacks();
    std::string getStack1Top();
    std::string getStack2Top();
    size_t getStack1Size();
    size_t getStack2Size();
     
private:
    void printStack(std::stack<std::string> s);
};

#endif // STACKMANAGER_H