#include <string>

class Node {
   Node(std::string val, Node *left = nullptr, Node *right = nullptr) : m_val(val), m_left(left), m_right(right) {}
   ~Node() { delete m_left; delete m_right; }
private:
   std::string m_val;
   Node *m_left, *m_right;
};
