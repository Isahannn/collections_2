#include "pch.h"
#include "StackManager.h"

StackManager::StackManager(const std::string& loggerName) {
    if (!spdlog::get(loggerName)) {
        logger = spdlog::stdout_color_mt(loggerName);
    }
    else {
        logger = spdlog::get(loggerName);
    }
}

void StackManager::pushToStack1(const std::string& item) {
    stack1.push(item);
    logger->info("Pushed to Stack 1: {}", item);
}

void StackManager::pushToStack2(const std::string& item) {
    stack2.push(item);
    logger->info("Pushed to Stack 2: {}", item);
}

void StackManager::popFromStack1() {
    if (!stack1.empty()) {
        stack1.pop();
        logger->info("Popped from Stack 1.");
    }
}

void StackManager::popFromStack2() {
    if (!stack2.empty()) {
        stack2.pop();
        logger->info("Popped from Stack 2.");
    }
}

void StackManager::swapStacks() {
    std::stack<std::string> temp = stack1;
    stack1 = stack2;
    stack2 = temp;
    logger->info("Stacks swapped.");
}

void StackManager::printStacks() {
    logger->info("Stack 1:");
    printStack(stack1);
    logger->info("Stack 2:");
    printStack(stack2);
}

std::string StackManager::getStack1Top() {
    return stack1.empty() ? "" : stack1.top();
}

std::string StackManager::getStack2Top() {
    return stack2.empty() ? "" : stack2.top();
}

size_t StackManager::getStack1Size() {
    return stack1.size();
}

size_t StackManager::getStack2Size() {
    return stack2.size();
}

void StackManager::printStack(std::stack<std::string> s) {
    while (!s.empty()) {
        logger->info("{}", s.top());
        s.pop();
    }
}