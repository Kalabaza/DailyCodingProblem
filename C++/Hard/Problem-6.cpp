#include <gtest/gtest.h>
#include <Node.h>

/**
 * This problem was asked by Google.
 *
 * An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field
 * named both, which is an XOR of the next node and the previous node.
 *
 * Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
 *
 * If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer
 * functions that converts between nodes and memory addresses.
 */

template <typename Value>
class XORLinkedList {
public:
    XORLinkedList(Value val) {
        m_first = new XORNode<Value>(val);
        m_last = m_first;
    }
    ~XORLinkedList() {
        delete m_first;
        delete m_last;
    }
    void add(Value val) {
    }
    Value get(uint32_t index) {
        return 0;
    }

private:
    XORNode<Value> *m_first;
    XORNode<Value> *m_last;
};

// TODO: Problem is still pending

TEST(PROBLEM_6, ValidExample) {
}
