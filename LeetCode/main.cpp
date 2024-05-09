#include <iostream>

using namespace std;

#include "704.h"
#include "27.h"
#include "977.h"
#include "209.h"
#include "59.h"
#include "24.h"
#include "19.h"
#include "02_07.h"
#include "142.h"
#include "203.h"
#include "707.h"
#include "206.h"
#include "242.h"
#include "349.h"
#include "202.h"
#include "1.h"
#include "454.h"
#include "383.h"
#include "15.h"
#include "18.h"
#include "344.h"
#include "541.h"
#include "kama_54.h"
#include "151.h"
#include "kama_55.h"
#include "232.h"
#include "225.h"
#include "20.h"
#include "1047.h"
#include "150.h"
#include "239.h"
#include "347.h"
#include "Bian_Li.h"
#include "144.h"
#include "94.h"
#include "145.h"
#include "102.h"
#include "107.h"
#include "199.h"
#include "637.h"
#include "429.h"
#include "226.h"
#include "515.h"
#include "116.h"
#include "117.h"
#include "104.h"
#include "111.h"
#include "101.h"
#include "222.h"
#include "110.h"
#include "257.h"
#include "404.h"
#include "513.h"
#include "112.h"
#include "113.h"
#include "106.h"
#include "105.h"
#include "654.h"
#include "617.h"
#include "700.h"
#include "98.h"
#include <vector>

using namespace std;

void call_Bian_Li() {

}

void call_101() {
    Solution_101 test;


    Solution_101::TreeNode t4(3);
    Solution_101::TreeNode t5(3);
    Solution_101::TreeNode t2(2, nullptr, &t5);
    Solution_101::TreeNode t3(2, nullptr, &t4);
    Solution_101::TreeNode t(1, &t2, &t3);
    bool res = test.isSymmetric(&t);
    std::cout << res << ", ";

    std::cout << std::endl;
}

void call_102() {
    Solution_102 test;

    Solution_102::TreeNode t2(9);
    Solution_102::TreeNode t4(15);
    Solution_102::TreeNode t5(7);
    Solution_102::TreeNode t3(20, &t4, &t5);
    Solution_102::TreeNode t(3, &t2, &t3);
    vector<vector<int>> res = test.levelOrder_di_gui(&t);
    for (auto &row : res) {
        for (auto col : row)
            std::cout << col << ", ";
    }
    std::cout << std::endl;
}

void call_515() {
    Solution_515 test;

    Solution_515::TreeNode t4(5);
    Solution_515::TreeNode t6(3);
    Solution_515::TreeNode t2(3, &t4, &t6);
    Solution_515::TreeNode t5(9);
    Solution_515::TreeNode t3(2, nullptr, &t5);
    Solution_515::TreeNode t(1, &t2, &t3);
    vector<int> res = test.largestValues(&t);
    for (auto &row : res) {
        std::cout << row << ", ";
    }
    std::cout << std::endl;
}

void call_107() {
    Solution_107 test;

    Solution_107::TreeNode t2(9);
    Solution_107::TreeNode t4(15);
    Solution_107::TreeNode t5(7);
    Solution_107::TreeNode t3(20, &t4, &t5);
    Solution_107::TreeNode t(3, &t2, &t3);
    vector<vector<int>> res = test.levelOrderBottom(&t);
    for (auto &row : res) {
        for (auto col : row)
            std::cout << col << ", ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void call_704() {
    Solution s;
    vector<int> test{-1, 0, 3, 5, 9, 12};
    int t = s.search(test, 9);
    std::cout << "res:" << t << std::endl;

    vector<int> test_2{-1, 0, 3, 5, 9, 12};
    t = s.search_two_part(test_2, 2);
    std::cout << "res:" << t << std::endl;
}

void call_707() {
    cout << "res: ";
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);    // 链表变为 1->2->3
    cout << myLinkedList->get(1) << ", ";              // 返回 2
    myLinkedList->deleteAtIndex(1);    // 现在，链表变为 1->3
    cout << myLinkedList->get(1);              // 返回 3
    cout << endl;
}

void call_206() {
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtHead(2);
    myLinkedList->addAtHead(3);
    myLinkedList->addAtHead(4);
    myLinkedList->addAtHead(5);
}

void call_383() {

    string a = "aa";
    string b = "aab";
    Solution_383 test;
    test.canConstruct(a, b);
}

void call_kama_54() {
    string s = "a1b2c3";
    Solution_kama_54 test;
    cout << test.replaceNumber(s) << endl;
    cout << test.replaceNumber_double_pionts(s) << endl;
}

void call_kama_55() {
    Solution_kama_55 test;
    string s = "abcdefg";
    string res = test.stringRightReplace(s, 2);
    cout << res << endl;
}

void call_27() {

}

void call_347() {
    Solution_347 test;
    vector<int> s{1, 1, 1, 2, 2, 3};
    vector<int> res = test.topKFrequent(s, 2);
    for (auto i : res) {
        cout << i << ", ";
    }
    cout << endl;
}

void call_239() {
    Solution_239 test;
    vector<int> s{1, -1};
    vector<int> res = test.maxSlidingWindow(s, 1);
    for (auto i : res) {
        cout << i << ", ";
    }
    cout << endl;
}

void call_20() {
    Solution_20 test;
    string s = "()[]{}";
    std::cout << "res: " << test.isValid(s) << std::endl;
}

void call_151() {
    Solution_151 test;
    string s = "the sky is blue";
    std::cout << "res: " << test.reverseWords(s) << std::endl;

    string s2 = "  hello world  ";
    std::cout << "res: " << test.reverseWords(s2) << std::endl;
}

void call_977() {
    Solution_977 s;
    vector<int> test{-4, -1, 0, 3, 10};
    vector<int> t = s.sortedSquares_double_points(test);
    std::cout << "res:";
    for (auto i : t) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    vector<int> test_2
        {-50, -50, -43, -41, -37, -37, -36, -36, -28, -28, -28, -27, -19, -16, -16, -14, -14, -13, -13, -12, -12, -10,
         -7, -3, -2, -1, 0, 0, 1, 6, 6, 6, 7, 16, 19, 24, 26, 26, 28, 31, 33, 34, 37, 37, 38, 38, 42, 44, 44, 45};
    vector<int> t_2 = s.sortedSquares(test_2);
    std::cout << "res:";
    for (auto i : t_2) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int main() {

    //call_977();

    //call_707();
    //call_383();
    //call_kama_54();
    //call_151();
    //call_kama_55();
    //call_20();
    //call_239();
    //call_347();
    //call_102();
    //call_107();
    //call_515();
    call_101();
    cout << "Hello World!" << endl;
    return 0;
}
