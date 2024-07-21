//#include "../main.cpp"
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//#include <random>
//#include <set>
//#include "../AVL.h"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

//TEST_CASE("Command Test 1", "command-tests") {
//    // bad insert command
//    AVL tree;
//    string result = tree.validateInputTest("insert \"A11y\" 45679999");
//    REQUIRE(result == "unsuccessful");
//}
//
//TEST_CASE("Command Test 2", "command-tests") {
//    // bad function command
//    AVL tree;
//    string result = tree.validateInputTest("woop");
//    REQUIRE(result == "unsuccessful");
//}
//
//TEST_CASE("Command Test 3", "command-tests") {
//    // bad removeInorder command
//    AVL tree;
//    string result = tree.validateInputTest("removeInorder hey");
//    REQUIRE(result == "unsuccessful");
//}
//
//TEST_CASE("Command Test 4", "command-tests") {
//    // bad search command
//    AVL tree;
//    string result = tree.validateInputTest("search 123");
//    REQUIRE(result == "unsuccessful");
//}
//
//TEST_CASE("Command Test 5", "command-tests") {
//    // bad remove command
//    AVL tree;
//    string result = tree.validateInputTest("remove boo!");
//    REQUIRE(result == "unsuccessful");
//}
//
//
//// test cases will just compare vectors of the correct
//// inorder traversal
//TEST_CASE("Edge Case 1", "edge-cases") {
//    // remove a node that doesn't exist
//    AVL test;
//    test.insert("test", "45000000");
//    test.insert("test", "56000000");
//    test.insert("test", "16000000");
//    test.insert("test", "73000000");
//    test.insert("test", "12000000");
//    test.insert("test", "32000000");
//    test.insert("test", "60000000");
//
//    test.remove("12345678");
//    vector<string> correctResult({"12000000", "16000000", "32000000", "45000000", "56000000", "60000000", "73000000"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Edge Case 2", "edge-cases") {
//    // add a node that already exists
//    AVL test;
//    test.insert("test", "45000000");
//    test.insert("test", "56000000");
//    test.insert("test", "16000000");
//    test.insert("test", "73000000");
//    test.insert("test", "12000000");
//    test.insert("test", "32000000");
//    test.insert("test", "60000000");
//
//    test.insert("test", "45000000");
//    vector<string> correctResult({"12000000", "16000000", "32000000", "45000000", "56000000", "60000000", "73000000"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Edge Case 3", "edge-cases") {
//    // run the inorder function with an N that's too high
//    AVL test;
//    test.insert("test", "45000000");
//    test.insert("test", "56000000");
//    test.insert("test", "16000000");
//    test.insert("test", "73000000");
//    test.insert("test", "12000000");
//    test.insert("test", "32000000");
//    test.insert("test", "60000000");
//
//    test.removeInorder(12);
//    vector<string> correctResult({"12000000", "16000000", "32000000", "45000000", "56000000", "60000000", "73000000"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Rotation Case 1", "rotation-cases") {
//    // rotate right test
//    AVL test;
//    test.insert("hey", "5");
//    test.insert("heyy", "4");
//    test.insert("heyy", "3");
//    test.insert("heyy", "2");
//    test.insert("heyy", "1");
//    test.insert("heyy", "0");
//
//    vector<string> correctResult({"0", "1", "2", "3", "4", "5"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//
//TEST_CASE("Rotation Case 2", "rotation-cases") {
//// rotate left test
//    AVL test;
//    test.insert("hey", "1");
//    test.insert("hey", "2");
//    test.insert("hey", "3");
//    test.insert("hey", "4");
//    test.insert("hey", "5");
//    test.insert("hey", "6");
//    test.insert("hey", "7");
//
//    vector<string> correctResult({"1", "2", "3", "4", "5", "6", "7"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Rotation Case 3", "rotation-cases") {
//// left right test
//    AVL test;
//    test.insert("hey", "30");
//    test.insert("heyy", "20");
//    test.insert("heyy", "25");
//    test.insert("heyy", "15");
//    test.insert("heyy", "18");
//    test.insert("heyy", "35");
//    test.insert("heyy", "10");
//    test.insert("heyy", "12");
//
//    vector<string> correctResult({"10", "12", "15", "18", "20", "25", "30", "35"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Rotation Case 4", "rotation-cases") {
//// right left test
//    AVL test;
//    test.insert("hey", "10");
//    test.insert("heyy", "20");
//    test.insert("heyy", "15");
//    test.insert("heyy", "30");
//    test.insert("heyy", "25");
//    test.insert("heyy", "8");
//    test.insert("heyy", "40");
//    test.insert("heyy", "35");
//
//    vector<string> correctResult({"8", "10", "15", "20", "25", "30", "35", "40"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Remove Case 1", "deletion-cases") {
//// remove test two children
//    AVL test;
//    test.insert("apples", "23");
//    test.insert("bananas", "45");
//    test.insert("cherry", "12");
//    test.insert("date", "78");
//    test.insert("elderberry", "34");
//    test.insert("fig", "56");
//    test.insert("grape", "89");
//    test.remove("45");
//
//    vector<string> correctResult({"12", "23", "34", "56", "78", "89"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Remove Case 2", "deletion-cases") {
//// remove test one child
//    AVL test;
//    test.insert("apples", "23");
//    test.insert("bananas", "45");
//    test.insert("cherry", "12");
//    test.insert("date", "78");
//    test.insert("elderberry", "34");
//    test.insert("fig", "56");
//    test.insert("grape", "89");
//    test.insert("grape", "11");
//    test.remove("12");
//
//    vector<string> correctResult({"11", "23", "34", "45", "56", "78", "89"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Remove Case 3", "deletion-cases") {
//// remove test no children
//    AVL test;
//    test.insert("apples", "23");
//    test.insert("bananas", "45");
//    test.insert("cherry", "12");
//    test.insert("date", "78");
//    test.insert("elderberry", "34");
//    test.insert("fig", "56");
//    test.insert("grape", "89");
//    test.remove("89");
//
//    vector<string> correctResult({"12", "23", "34", "45", "56", "78"});
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < correctResult.size(); i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}
//
//TEST_CASE("Large Case", "large-case") {
//// large input
//    AVL test;
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dis(10000000, 99999999);
//    uniform_int_distribution<int> nodeDis(0, 100);
//    set<string> insertedValues;
//    vector<string> correctResult;
//
//    for (int i = 0; i < 100; i++) {
//        string randomID = to_string(dis(gen));
//        while (insertedValues.find(randomID) != insertedValues.end()) {
//            randomID = to_string(dis(gen));
//        }
//        test.insert("test", randomID);
//        insertedValues.insert(randomID);
//        correctResult.push_back(randomID);
//    }
//
//    for (int i = 0; i < 10; i++) {
//        int nodeToRemove = nodeDis(gen);
//        test.removeInorder(nodeToRemove);
//        sort(correctResult.begin(), correctResult.end());
//        correctResult.erase(correctResult.begin() + nodeToRemove);
//    }
//
//    vector<string> givenResult = test.testOutput(givenResult);
//    for (int i = 0; i < 100; i++) {
//        REQUIRE(correctResult[i] == givenResult[i]);
//    }
//}

