#include <iostream>

inline void error(const char* str) {
    std::cout << str << std::endl;
    exit(1);
}

template<typename T>
class Node {
private:
    T data;
    Node* child;
    Node* sibling;
public:
    Node(T data);
    ~Node();
    void DeleteNode(Node* n);
    void SetData(T data);
    void SetChild(Node* child);
    void SetSibling(Node* sibling);
    T GetData();
    Node* GetChild();
    Node* GetSibling();
};

template<typename T>
class Tree {
private:
    Node<T>* root;
    Node<T>* pn;
public:
    Tree();
    Tree(T data);
    ~Tree();
    void SetRoot(T data);
    void SetPN(Node<T>* n);
    Node<T> *GetRoot();
    Node<T> *GetPN();
    void NodeChangeData(T data);
    void ParentInsertChild(T data);
    void ParentDeleteChild(T data);
    void PrintChild();
};
