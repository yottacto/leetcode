#include <vector>

struct MyCircularDeque
{
    std::vector<int> a;
    int head{};
    int tail{};
    int size{};
    int len;

    // Initialize your data structure here. Set the size of the deque to be k.
    MyCircularDeque(int k) : a(k), len(k)
    {
    }

    int prev(int x) const
    {
        return (x - 1 + len) % len;
    }

    int next(int x) const
    {
        return (x + 1) % len;
    }

    // Adds an item at the front of Deque. Return true if the operation is
    // successful.
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        a[prev(head)] = value;
        head = prev(head);
        size++;
        return true;
    }

    // Adds an item at the rear of Deque. Return true if the operation is
    // successful.
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        a[tail] = value;
        tail = next(tail);
        size++;
        return true;
    }

    // Deletes an item from the front of Deque. Return true if the operation is
    // successful.
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        head = next(head);
        size--;
        return true;
    }

    // Deletes an item from the rear of Deque. Return true if the operation is
    // successful.
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        tail = prev(tail);
        size--;
        return true;
    }

    // Get the front item from the deque.
    int getFront()
    {
        if (isEmpty())
            return -1;
        return a[head];
    }

    // Get the last item from the deque.
    int getRear()
    {
        if (isEmpty())
            return -1;
        return a[prev(tail)];
    }

    // Checks whether the circular deque is empty or not.
    bool isEmpty()
    {
        return !size;
    }

    // Checks whether the circular deque is full or not.
    bool isFull()
    {
        return size == len;
    }
};

