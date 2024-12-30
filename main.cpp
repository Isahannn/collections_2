#include "pch.h"
#include "StackManager.h"
#include <gtest/gtest.h>

// Тесты для класса StackManager
class StackManagerTest : public ::testing::Test {
protected:
    StackManager manager;

    void SetUp() override {
        if (!spdlog::get("console")) {
            manager.logger = spdlog::stdout_color_mt("console");
        }
        else {
            manager.logger = spdlog::get("console");
        }
    }
};

TEST_F(StackManagerTest, PushToStack1) {
    manager.pushToStack1("A");
    EXPECT_EQ(manager.getStack1Size(), 1);
    manager.logger->info("Test PushToStack1 passed: Size of Stack 1 is {}", manager.getStack1Size());
}

TEST_F(StackManagerTest, PushToStack2) {
    manager.pushToStack2("1");
    EXPECT_EQ(manager.getStack2Size(), 1);
    manager.logger->info("Test PushToStack2 passed: Size of Stack 2 is {}", manager.getStack2Size());
}

TEST_F(StackManagerTest, SwapStacks) {
    manager.pushToStack1("A");
    manager.pushToStack2("1");
    manager.swapStacks();
    EXPECT_EQ(manager.getStack1Top(), "1");
    EXPECT_EQ(manager.getStack2Top(), "A");
    manager.logger->info("Test SwapStacks passed: Stacks swapped successfully.");
}

TEST_F(StackManagerTest, MultiplePushToStack1) {
    manager.pushToStack1("A");
    manager.pushToStack1("B");
    manager.pushToStack1("C");
    EXPECT_EQ(manager.getStack1Size(), 3);
    manager.logger->info("Test MultiplePushToStack1 passed: Size of Stack 1 is {}", manager.getStack1Size());
}

TEST_F(StackManagerTest, MultiplePushToStack2) {
    manager.pushToStack2("1");
    manager.pushToStack2("2");
    manager.pushToStack2("3");
    EXPECT_EQ(manager.getStack2Size(), 3);
    manager.logger->info("Test MultiplePushToStack2 passed: Size of Stack 2 is {}", manager.getStack2Size());
}

// Новый тест для проверки обмена стеков
TEST(StackSwapTest, BasicSwap) {
    StackManager manager;

    manager.pushToStack1("1");
    manager.pushToStack1("2");
    manager.pushToStack1("3");

    manager.pushToStack2("4");
    manager.pushToStack2("5");
    manager.pushToStack2("6");

    manager.swapStacks();

    EXPECT_EQ(manager.getStack1Top(), "6");
    EXPECT_EQ(manager.getStack1Size(), 3);
    EXPECT_EQ(manager.getStack2Top(), "3");
    EXPECT_EQ(manager.getStack2Size(), 3);
}

// Новый тест: Проверка вершины стека
TEST_F(StackManagerTest, TopOfStack1) {
    manager.pushToStack1("A");
    manager.pushToStack1("B");
    EXPECT_EQ(manager.getStack1Top(), "B");
    manager.logger->info("Test TopOfStack1 passed: Top of Stack 1 is {}", manager.getStack1Top());
}

TEST_F(StackManagerTest, TopOfStack2) {
    manager.pushToStack2("1");
    manager.pushToStack2("2");
    EXPECT_EQ(manager.getStack2Top(), "2");
    manager.logger->info("Test TopOfStack2 passed: Top of Stack 2 is {}", manager.getStack2Top());
}

// Новый тест: Проверка пустоты стека
TEST_F(StackManagerTest, IsStack1Empty) {
    EXPECT_TRUE(manager.getStack1Size() == 0);
    manager.logger->info("Test IsStack1Empty passed: Stack 1 is empty.");
}

TEST_F(StackManagerTest, IsStack2Empty) {
    EXPECT_TRUE(manager.getStack2Size() == 0);
    manager.logger->info("Test IsStack2Empty passed: Stack 2 is empty.");
}

// Новый тест: Проверка размера стека после операций
TEST_F(StackManagerTest, SizeAfterPushAndPop) {
    manager.pushToStack1("A");
    manager.pushToStack1("B");
    manager.pushToStack1("C");
    EXPECT_EQ(manager.getStack1Size(), 3);
    manager.logger->info("Test SizeAfterPushAndPop passed: Size of Stack 1 is {}", manager.getStack1Size());

    manager.popFromStack1(); // Предполагается, что у вас есть метод pop
    EXPECT_EQ(manager.getStack1Size(), 2);
    manager.logger->info("Size of Stack 1 after pop is {}", manager.getStack1Size());
}

// Новый тест: Проверка на наличие элементов после обмена
TEST(StackSwapTest, CheckElementsAfterSwap) {
    StackManager manager;

    manager.pushToStack1("A");
    manager.pushToStack1("B");
    manager.pushToStack1("C");

    manager.pushToStack2("1");
    manager.pushToStack2("2");
    manager.pushToStack2("3");

    manager.swapStacks();

    EXPECT_EQ(manager.getStack1Top(), "3");
    EXPECT_EQ(manager.getStack2Top(), "C");
}

// Главная функция для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    auto console = spdlog::stdout_color_mt("console");
    console->info("Starting the Stack Manager program...");

    int result = RUN_ALL_TESTS();

    if (result == 0) {
        StackManager manager;
        manager.pushToStack1("A");
        manager.pushToStack1("B");
        manager.pushToStack1("C");
        manager.pushToStack2("1");
        manager.pushToStack2("2");
        manager.pushToStack2("3");
        manager.printStacks();
        manager.swapStacks();
        manager.printStacks();
        console->info("Program finished.");
    }
    else {
        console->error("Some tests failed!");
    }

    return result;
}