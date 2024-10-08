#include <iostream>

using namespace std;

#include <vector>

#include "02_07.h"
#include "1.h"
#include "101.h"
#include "102.h"
#include "104.h"
#include "1047.h"
#include "105.h"
#include "106.h"
#include "107.h"
#include "108.h"
#include "110.h"
#include "111.h"
#include "112.h"
#include "113.h"
#include "1143.h"
#include "116.h"
#include "117.h"
#include "131.h"
#include "142.h"
#include "144.h"
#include "145.h"
#include "15.h"
#include "150.h"
#include "151.h"
#include "17.h"
#include "18.h"
#include "19.h"
#include "199.h"
#include "20.h"
#include "202.h"
#include "203.h"
#include "206.h"
#include "209.h"
#include "216.h"
#include "222.h"
#include "225.h"
#include "226.h"
#include "232.h"
#include "235.h"
#include "236.h"
#include "239.h"
#include "2390.h"
#include "24.h"
#include "2414.h"
#include "242.h"
#include "257.h"
#include "27.h"
#include "2806.h"
#include "2860.h"
#include "300.h"
#include "3142.h"
#include "3153.h"
#include "3174.h"
#include "3176.h"
#include "332.h"
#include "344.h"
#include "347.h"
#include "349.h"
#include "383.h"
#include "39.h"
#include "40.h"
#include "404.h"
#include "429.h"
#include "450.h"
#include "454.h"
#include "46.h"
#include "47.h"
#include "491.h"
#include "501.h"
#include "509.h"
#include "51.h"
#include "513.h"
#include "515.h"
#include "530.h"
#include "538.h"
#include "541.h"
#include "59.h"
#include "617.h"
#include "637.h"
#include "654.h"
#include "669.h"
#include "674.h"
#include "700.h"
#include "701.h"
#include "704.h"
#include "707.h"
#include "718.h"
#include "77.h"
#include "78.h"
#include "90.h"
#include "93.h"
#include "94.h"
#include "977.h"
#include "98.h"
#include "Bian_Li.h"
#include "kama_54.h"
#include "kama_55.h"
#include "1436.h"

using namespace std;

void call_Bian_Li() {}

void call_2414() {
  Solution_2414 test;
  string v_1 = "abcde";
  test.longestContinuousSubstring(v_1);
}

void call_1143() {
  Solution_1143 test;
  string v_1 = "ezupkr";
  string v_2 = "ubmrapg";
  test.longestCommonSubsequence(v_1, v_2);
}

void call_718() {
  Solution_718 test;
  vector<int> v_1 = {1, 2, 3, 2, 1};
  vector<int> v_2 = {3, 2, 1, 4, 7};
  test.findLength(v_1, v_2);
}

void call_509() {
  Solution_509 test;
  test.fib(10);
}

void call_2860() {
  Solution_2860 test;
  vector<int> stu_1{1, 1};
  vector<int> stu_2{9,  48, 57, 45, 21, 8,  60, 36, 11, 54, 13, 58, 77, 51, 28,
                    37, 20, 38, 33, 38, 53, 70, 66, 9,  48, 59, 35, 56, 44, 54,
                    10, 70, 58, 32, 12, 64, 65, 13, 45, 85, 59, 55, 29, 76, 72,
                    57, 89, 46, 10, 42, 34, 44, 80, 41, 87, 61, 30, 49, 50, 63,
                    65, 76, 43, 1,  52, 54, 36, 87, 55, 88, 86, 81, 67, 26, 87,
                    88, 38, 88, 45, 9,  34, 25, 12, 34, 29, 82, 59, 80, 87, 73};
  test.countWays(stu_1);
}

void call_491() {
  Solution_491 test;
  vector<int> path{4, 4, 3, 2, 1};
  test.findSubsequences(path);
}

void call_77() {
  Solution_77 test;
  test.combine(2, 1);
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
    for (auto col : row) std::cout << col << ", ";
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
    for (auto col : row) std::cout << col << ", ";
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
  myLinkedList->addAtIndex(1, 2);        // 链表变为 1->2->3
  cout << myLinkedList->get(1) << ", ";  // 返回 2
  myLinkedList->deleteAtIndex(1);        // 现在，链表变为 1->3
  cout << myLinkedList->get(1);          // 返回 3
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

void call_27() {}

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

  vector<int> test_2{-50, -50, -43, -41, -37, -37, -36, -36, -28, -28,
                     -28, -27, -19, -16, -16, -14, -14, -13, -13, -12,
                     -12, -10, -7,  -3,  -2,  -1,  0,   0,   1,   6,
                     6,   6,   7,   16,  19,  24,  26,  26,  28,  31,
                     33,  34,  37,  37,  38,  38,  42,  44,  44,  45};
  vector<int> t_2 = s.sortedSquares(test_2);
  std::cout << "res:";
  for (auto i : t_2) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}

int main() {
  // call_977();

  // call_707();
  // call_383();
  // call_kama_54();
  // call_151();
  // call_kama_55();
  // call_20();
  // call_239();
  // call_347();
  // call_102();
  // call_107();
  // call_515();
  // call_101();
  // call_77();
  // call_491();
  // call_2860();
  // call_509();
  // call_718();
  // call_1143();
  call_2414();
  cout << "Hello World!" << endl;
  return 0;
}
