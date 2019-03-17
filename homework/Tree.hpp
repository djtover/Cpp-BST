#include <iostream>
using namespace std;



class Tree {

    typedef struct Node{
    int key;
    Node *right;
    Node *left;
}Node;

Node *start;
int amount;   

Node* createNode(int value)
{
    Node *newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

public:
    Tree(Node *first){
        Tree::start= first
        size=1;
        
    }
    bool insert(int value);
    bool remove(int value);
    int size();
    bool contains(int value);
    Node* root();
    int parent(int value);
    int left(int value);
    int right(int value);
    void print();

};