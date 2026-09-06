#include <gtest/gtest.h>

// ============================================================================
// ИНТЕРФЕЙСЫ КЛАССОВ (заглушки для компиляции тестов)
// ============================================================================

class Queue {
public:
    void push(int value);
    void pop();
    int front() const;
    bool empty() const;
    size_size size() const;
};

class Heap {
public:
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    size_size size() const;
};

class BinaryTree {
public:
    void push(int value);
    void pop(int value);
    bool search(int value) const;
    bool empty() const;
};

// ============================================================================
// ЮНИТ-ТЕСТЫ ДЛЯ КЛАССА ОЧЕРЕДИ (Queue)
// Поведение: FIFO (First In, First Out)
// ============================================================================

class QueueTest : public ::testing::Test {
protected:
    Queue q;
};

TEST_F(QueueTest, IsEmptyInitially) {
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0);
}

TEST_F(QueueTest, PushIncreasesSize) {
    q.push(10);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.size(), 1);
}

TEST_F(QueueTest, PopDecreasesSize) {
    q.push(10);
    q.pop();
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0);
}

TEST_F(QueueTest, FIFOOrder) {
    q.push(1);
    q.push(2);
    q.push(3);

    EXPECT_EQ(q.front(), 1);
    q.pop();
    EXPECT_EQ(q.front(), 2);
    q.pop();
    EXPECT_EQ(q.front(), 3);
}


// ============================================================================
// ЮНИТ-ТЕСТЫ ДЛЯ КЛАССА КУЧИ (Heap)
// Поведение: Приоритетное извлечение (например, Max-Heap)
// ============================================================================

class HeapTest : public ::testing::Test {
protected:
    Heap h;
};

TEST_F(HeapTest, IsEmptyInitially) {
    EXPECT_TRUE(h.empty());
    EXPECT_EQ(h.size(), 0);
}

TEST_F(HeapTest, PushIncreasesSize) {
    h.push(42);
    EXPECT_FALSE(h.empty());
    EXPECT_EQ(h.size(), 1);
}

TEST_F(HeapTest, PopDecreasesSize) {
    h.push(42);
    h.pop();
    EXPECT_TRUE(h.empty());
}

TEST_F(HeapTest, OrdersElementsCorrectly) {
    h.push(10);
    h.push(30);
    h.push(20);

    // Предполагаем Max-Heap (корень — максимальный элемент)
    EXPECT_EQ(h.top(), 30);
    h.pop();
    EXPECT_EQ(h.top(), 20);
    h.pop();
    EXPECT_EQ(h.top(), 10);
}


// ============================================================================
// ЮНИТ-ТЕСТЫ ДЛЯ КЛАССА БИНАРНОГО ДЕРЕВА (BinaryTree)
// Поведение: Хранение структуры, поиск и удаление конкретных значений
// ============================================================================

class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree tree;
};

TEST_F(BinaryTreeTest, IsEmptyInitially) {
    EXPECT_TRUE(tree.empty());
}

TEST_F(BinaryTreeTest, SearchReturnsFalseForMissingElement) {
    EXPECT_FALSE(tree.search(5));
}

TEST_F(BinaryTreeTest, PushAddsElementToTree) {
    tree.push(5);
    EXPECT_FALSE(tree.empty());
    EXPECT_TRUE(tree.search(5));
}

TEST_F(BinaryTreeTest, PopRemovesSpecificElement) {
    tree.push(10);
    tree.push(20);

    tree.pop(10);
    EXPECT_FALSE(tree.search(10));
    EXPECT_TRUE(tree.search(20)); // Другой элемент должен остаться
}

TEST_F(BinaryTreeTest, SearchWorksForMultipleElements) {
    tree.push(8);
    tree.push(3);
    tree.push(10);

    EXPECT_TRUE(tree.search(8));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(10));
    EXPECT_FALSE(tree.search(5));
}

// ============================================================================
// ТОЧКА ВХОДА ДЛЯ ЗАПУСКА ТЕСТОВ
// ============================================================================

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
