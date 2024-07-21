#include "AVL.h"


void AVL::insert(const string &name, const string &ufid) {
    insertHelper(this->root, name, ufid);
}

Node* AVL::insertHelper(Node* node, const string &name, const string &ufid) {
    // base case
    if (node == nullptr) {
        Node* newNode = new Node(name, ufid);
        if (this->size == 0) {
            this->root = newNode;
        }
        this->size++;
        cout << "successful" << endl;
        return newNode;
    }

    // maintaining BST identity
    if (stoi(ufid) < stoi(node->ufid)) {
        node->leftChild = insertHelper(node->leftChild, name, ufid);
    }
    else if (stoi(ufid) > stoi(node->ufid)) {
        node->rightChild = insertHelper(node->rightChild, name, ufid);
    } else {
        cout << "unsuccessful" << endl;
    }

    // update height - using one-based
    node->height = height(node);

    // update balance factor
    node->balanceFactor = height(node->leftChild) - height(node->rightChild);

    // rotations
    // right-heavy
    if (node->balanceFactor == -2) {
        // check right subtree
        // right heavy
        if (node->rightChild->balanceFactor < 0) {
            // changing root edge case
            if (this->root == node) {
                this->root = leftRotate(this->root);
                updateRotatedNodes(this->root);
            } else {
                node = leftRotate(node);
                updateRotatedNodes(node);
            }
        }
        // left heavy
        else if (node->rightChild->balanceFactor > 0) {
            if (this->root == node) {
                this->root->rightChild = rightRotate(this->root->rightChild);
                this->root = leftRotate(this->root);
                updateRotatedNodes(this->root);
            } else {
                node->rightChild = rightRotate(node->rightChild);
                node = leftRotate(node);
                updateRotatedNodes(node);
            }
        }
    }

    // left-heavy
    if (node->balanceFactor == 2) {
        // check left subtree
        // left heavy
        if (node->leftChild->balanceFactor > 0) {
            if (this->root == node) {
                this->root = rightRotate(node);
                updateRotatedNodes(this->root);
            } else {
                node = rightRotate(node);
                updateRotatedNodes(node);
            }
        }
        // right heavy
        else if (node->leftChild->balanceFactor < 0) {
            if (this->root == node) {
                this->root->leftChild = leftRotate(this->root->leftChild);
                this->root = rightRotate(this->root);
                updateRotatedNodes(this->root);
            } else {
                node->leftChild = leftRotate((node->leftChild));
                node = rightRotate(node);
                updateRotatedNodes(node);
            }
        }
    }

    return node;
}

void AVL::treeVisualizerHelper(Node* node, const string &prefix, bool isLeft) {
    if (node == nullptr) {
        return;
    }

    if (node->rightChild != nullptr) {
        treeVisualizerHelper(node->rightChild, prefix + (isLeft ? "   " : "    "), false);
    }

    cout << prefix << (isLeft ? "--> " : ">-- ") << node->ufid << endl;

    if (node->leftChild != nullptr) {
        treeVisualizerHelper(node->leftChild, prefix + (isLeft ? "   " : "    "), true);
    }
}

void AVL::treeVisualizer() {
    treeVisualizerHelper(this->root);
}

void AVL::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    // post order deletion
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    delete node;
}

int AVL::height(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + max(height(node->leftChild), height(node->rightChild));
}

Node *AVL::rightRotate(Node* node) {
    Node* grandChild = node->leftChild->rightChild;
    Node* newParent = node->leftChild;
    newParent->rightChild = node;
    node->leftChild = grandChild;
    return newParent;
}

Node *AVL::leftRotate(Node* node) {
    Node* grandChild = node->rightChild->leftChild;
    Node* newParent = node->rightChild;
    newParent->leftChild = node;
    node->rightChild = grandChild;
    return newParent;
}


void AVL::updateRotatedNodes(Node* node) {
    node->height = height(node);
    node->balanceFactor = height(node->leftChild) - height(node->rightChild);
    node->leftChild->height = height(node->leftChild);
    node->leftChild->balanceFactor = height(node->leftChild->leftChild) - height(node->leftChild->rightChild);
    node->rightChild->height = height(node->rightChild);
    node->rightChild->balanceFactor = height(node->rightChild->leftChild) - height(node->rightChild->rightChild);
}

void AVL::printInorder() {
    bool first = true;
    inorderHelper(this->root, first);
    cout << endl;
}

void AVL::inorderHelper(Node* node, bool &first) {
    // left, data, right
    if (node == nullptr) {
        return;
    }

    inorderHelper(node->leftChild, first);

    if (first) {
        cout << node->name;
        first = false;
    } else {
        cout << ", " << node->name;
    }
    inorderHelper(node->rightChild, first);
}

void AVL::printPreorder() {
    bool first = true;
    preorderHelper(this->root, first);
    cout << endl;
}

void AVL::preorderHelper(Node* node, bool &first) {
    // data, left, right
    if (node == nullptr) {
        return;
    }

    if (first) {
        cout << node->name;
        first = false;
    } else {
        cout << ", " << node->name;
    }

    preorderHelper(node->leftChild, first);
    preorderHelper(node->rightChild, first);
}

void AVL::printPostorder() {
    bool first = true;
    postorderHelper(this->root, first);
    cout << endl;
}

void AVL::postorderHelper(Node* node, bool &first) {
    // left, right, data
    if (node == nullptr) {
        return;
    }

    postorderHelper(node->leftChild, first);
    postorderHelper(node->rightChild, first);
    if (first) {
        cout << node->name;
        first = false;
    } else {
        cout << ", " << node->name;
    }
}

void AVL::searchID(const string &ufid) {
    searchIDHelper(this->root, ufid);
}

void AVL::searchIDHelper(Node* node, const string &ufid) {
    // base case
    if (node == nullptr) {
        cout << "unsuccessful" << endl;
        return;
    }

    if (node->ufid == ufid) {
        cout << node->name << endl;
        return;
    }

    // bst search
    if (stoi(ufid) < stoi(node->ufid)) {
        searchIDHelper(node->leftChild, ufid);
    } else {
        searchIDHelper(node->rightChild, ufid);
    }
}

void AVL::searchName(const string &name) {
    bool found = false;
    searchNameHelper(this->root, name, found);
    if (!found) {
        cout << "unsuccessful" << endl;
    }
}

bool AVL::searchNameHelper(Node *node, const string &name, bool &found) {
    // multiple IDs can have the same name
    // using preorder to traverse the whole tree
    if (node == nullptr) {
        return node;
    }

    // data, left, right
    if (node->name == name) {
        found = true;
        cout << node->ufid << endl;
    }

    searchNameHelper(node->leftChild, name, found);
    searchNameHelper(node->rightChild, name, found);

    return found;
}

void AVL::remove(const string &ufid) {
    removeHelper(this->root, ufid);
}

Node* AVL::removeHelper(Node* node, const string &ufid, bool firstRun) {
    if (node == nullptr) {
        cout << "unsuccessful" << endl;
        firstRun = false;
        return nullptr;
    }

    // recursing to find the node
    if (stoi(ufid) < stoi(node->ufid)) {
        node->leftChild = removeHelper(node->leftChild, ufid, firstRun);
    }

    else if (stoi(ufid) > stoi(node->ufid)) {
        node->rightChild = removeHelper(node->rightChild, ufid, firstRun);
    }

    else {
        // found the node
        if (firstRun) {
            cout << "successful" << endl;
            firstRun = false;
        }

        // leaf nodes
        if (node->leftChild == nullptr && node->rightChild == nullptr) {
            delete node;
            return nullptr;
        }
        // single child nodes
        else if (node->rightChild == nullptr) {
            Node* temp = node->leftChild;
            delete node;
            return temp;
        }

        else if (node->leftChild == nullptr) {
            Node* temp = node->rightChild;
            delete node;
            return temp;
        }

        // doubly child nodes
        else {
            if (node == this->root) {
                Node* inorderSuccesor = findInorderSuccessor(this->root->rightChild);
                this->root->ufid = inorderSuccesor->ufid;
                this->root->name = inorderSuccesor->name;
                this->root->rightChild = removeHelper(this->root->rightChild, this->root->ufid, firstRun);
            } else {
                Node* inorderSuccesor = findInorderSuccessor(node->rightChild);
                node->ufid = inorderSuccesor->ufid;
                node->name = inorderSuccesor->name;
                node->rightChild = removeHelper(node->rightChild, node->ufid, firstRun);
            }
        }
    }


    return node;
}

Node *AVL::findInorderSuccessor(Node *node) {
    // base case
    if (node->leftChild == nullptr) {
        return node;
    }

    return findInorderSuccessor(node->leftChild);
}

void AVL::printLevelCount() {
    if (this->root == nullptr) {
        cout << 0 << endl;
    } else {
        cout << this->root->height << endl;
    }
}

void AVL::removeInorder(const int &iterations) {
    int count = -1;
    removeInorderHelper(this->root, iterations, count);
}

void AVL::removeInorderHelper(Node *node, const int &iterations, int &count) {
    if (iterations > this->size - 1 || iterations < 0) {
        cout << "unsuccessful" << endl;
        return;
    }

    if (node == nullptr) {
        return;
    }

    // left, data, right
    removeInorderHelper(node->leftChild, iterations, count);
    count++;
    if (count == iterations) {
        remove(node->ufid);
        return;
    }
    removeInorderHelper(node->rightChild, iterations, count);
}

string AVL::validateInputTest(const string &input) {

    istringstream parseInput(input);

    string function;
    getline(parseInput, function, ' ');

    if (function == "insert") {
        // name and ufid should be expected
        string temp;
        getline(parseInput, temp, '"');

        string name;
        getline(parseInput, name, '"');

        string temp2;
        getline(parseInput, temp2, ' ');

        string ufid;
        getline(parseInput, ufid, ' ');

        // validate inputs

        if (name.empty() || ufid.empty()) {
            return "unsuccessful";
        }

        if (!regex_match(name, regex("[A-Za-z\\s]+$"))) {
            return "unsuccessful";
        }

        if (!regex_match(ufid, regex("[0-9]{8}"))) {
            return "unsuccessful";
        }
    }

    else if (function == "printInorder") {}

    else if (function == "printPreorder") {}

    else if (function == "printPostorder") {}

    else if (function == "printLevelCount") {}

    else if (function == "removeInorder") {
        // should expect number
        string num;
        getline(parseInput, num, ' ');

        // validate input

        if (!regex_match(num, regex("[0-9]+"))) {
            return "unsuccessful";
        }
    }

    else if (function == "remove") {
        // should expect id
        string ufid;
        getline(parseInput, ufid, ' ');

        // validate input

        if (!regex_match(ufid, regex("[0-9]{8}"))) {
            return "unsuccessful";
        }
    }

    else if (function == "search") {
        // expect id or name, test for either one
        bool isName = false;
        string input;
        getline(parseInput, input, ' ');

        try {
            stoi(input);
        } catch (...) {
            isName = true;
        }

        // validate input
        if (!isName) {
            if (!regex_match(input, regex("[0-9]{8}"))) {
                return "unsuccessful";
            } else {
                // do nothing
            }
        } else {
            // get rid of quotations
            input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());
            if (!regex_match(input, regex("[A-Za-z\\s]+$"))) {
                return "unsuccessful";
            } else {
                // do nothing
            }
        }
    }
    else {
        return "unsuccessful";
    }
}





