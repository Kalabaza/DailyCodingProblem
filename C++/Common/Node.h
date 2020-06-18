#include <string>

template <typename Value>
class Node {
public:
   Node(Value val, Node *left = nullptr, Node *right = nullptr) : m_val(val), m_left(left), m_right(right) {}
   ~Node() = default;
private:
   Value m_val;
   Node<Value> *m_left, *m_right;
};

template <typename Value>
class XORNode {
public:
    XORNode(Value val, XORNode *both = nullptr) : m_val(val), m_both(both) {}
    ~XORNode() = default;
private:
    Value m_val;
    XORNode<Value> *m_both;
};
