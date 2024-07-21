#ifndef PROJECT_1_AVL_H
#define PROJECT_1_AVL_H
#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

struct Node {
    string name;
    string ufid;
    Node* leftChild;
    Node* rightChild;
    int balanceFactor;
    int height;

    Node(const string &name, const string &ufid) {
        this->name = name;
        this->ufid = ufid;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->balanceFactor = 0;
        this->height = 0;
    }
};

class AVL {
private:
    Node* root;
    int size;
    Node* insertHelper(Node* node, const string &name, const string &ufid);
    void treeVisualizerHelper(Node* node, const string &prefix = "", bool isLeft = true);
    int height(Node* node);
    void deleteTree(Node* node);
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    void updateRotatedNodes(Node* node);
    void inorderHelper(Node* node, bool &first);
    void preorderHelper(Node* node, bool &first);
    void postorderHelper(Node* node, bool &first);
    void searchIDHelper(Node* node, const string &ufid);
    bool searchNameHelper(Node* node, const string &name, bool &found);
    Node* removeHelper(Node* node, const string &ufid, bool firstRun = true);
    Node* findInorderSuccessor(Node* node);
    void removeInorderHelper(Node* node, const int &iterations, int &count);

    // Unit Test Helpers
    void testOutputHelper(vector<string> &nodes, Node* node) {
        // left, data, right
        if (node == nullptr) {
            return;
        }

        testOutputHelper(nodes, node->leftChild);
        nodes.push_back(node->ufid);
        testOutputHelper(nodes, node->rightChild);
    }

public:
   // function used to aid development
   void treeVisualizer();
   void insert(const string &name, const string &ufid);
   void printInorder();
   void printPreorder();
   void printPostorder();
   void searchID(const string &ufid);
   void searchName(const string &name);
   void remove(const string &ufid);
   void printLevelCount();
   void removeInorder(const int &iterations);

   // Unit Tests
   string validateInputTest(const string &input);

   vector<string> testOutput(vector<string> &nodes) {
       vector<string> result;
       testOutputHelper(result, this->root);
       return result;
   }


   AVL() {
       this->root = nullptr;
       this->size = 0;
   }

   ~AVL() {
       deleteTree(this->root);
   }
};


#endif //PROJECT_1_AVL_H
