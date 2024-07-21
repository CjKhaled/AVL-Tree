#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>
#include "AVL.h"
using namespace std;



int main() {
    AVL tree;
    string userInput;
    getline(cin, userInput);

    istringstream parseInput(userInput);

    string commands;
    getline(parseInput, commands);

    bool validNum = true;
    try {
        stoi(commands);
    } catch (...) {
        validNum = false;
        cout << "unsuccessful" << endl;
    }

    int commandCount = validNum ? stoi(commands) : 0;
    int count = 0;

    while (count != commandCount) {
        count++;
        string userInput2;
        getline(cin, userInput2);

        istringstream parseInput2(userInput2);

        string function;
        getline(parseInput2, function, ' ');

        if (function == "insert") {
            // name and ufid should be expected
            string temp;
            getline(parseInput2, temp, '"');

            string name;
            getline(parseInput2, name, '"');

            string temp2;
            getline(parseInput2, temp2, ' ');

            string ufid;
            getline(parseInput2, ufid, ' ');

            // validate inputs
            bool validInput = true;

            if (name.empty() || ufid.empty()) {
                cout << "unsuccessful" << endl;
                validInput = false;
            }

            if (!regex_match(name, regex("[A-Za-z\\s]+$"))) {
                cout << "unsuccessful" << endl;
                validInput = false;
            }

            if (!regex_match(ufid, regex("[0-9]{8}"))) {
                cout << "unsuccessful" << endl;
                validInput = false;
            }

            if (validInput) {
                tree.insert(name, ufid);
            }
        }

        else if (function == "printInorder") {
            tree.printInorder();
        }

        else if (function == "printPreorder") {
            tree.printPreorder();
        }

        else if (function == "printPostorder") {
            tree.printPostorder();
        }

        else if (function == "printLevelCount") {
            tree.printLevelCount();
        }

        else if (function == "removeInorder") {
            // should expect number
            string num;
            getline(parseInput2, num, ' ');

            // validate input
            bool validInput = true;

            if (!regex_match(num, regex("[0-9]+"))) {
                cout << "unsuccessful" << endl;
                validInput = false;
            }

            if (validInput) {
                tree.removeInorder(stoi(num));
            }
        }

        else if (function == "remove") {
            // should expect id
            string ufid;
            getline(parseInput2, ufid, ' ');

            // validate input
            bool validInput = true;

            if (!regex_match(ufid, regex("[0-9]{8}"))) {
                cout << "unsuccessful" << endl;
                validInput = false;
            }

            if (validInput) {
                tree.remove(ufid);
            }
        }

        else if (function == "search") {
            // expect id or name, test for either one
            bool isName = false;
            string input;
            getline(parseInput2, input, ' ');

            try {
                stoi(input);
            } catch (...) {
                isName = true;
            }

            // validate input
            bool validInput = true;
            if (!isName) {
                if (!regex_match(input, regex("[0-9]{8}"))) {
                    cout << "unsuccessful" << endl;
                    validInput = false;
                } else {
                    tree.searchID(input);
                }
            } else {
                // get rid of quotations
                input.erase(remove(input.begin(), input.end(), '\"'), input.end());
                if (!regex_match(input, regex("[A-Za-z\\s]+$"))) {
                    cout << "unsuccessful" << endl;
                    validInput = false;
                } else {
                    tree.searchName(input);
                }
            }
        }

        else {
            cout << "unsuccessful" << endl;
        }
    }

    return 0;
}