class Solution_2414 {
 public:
  int longestContinuousSubstring(string s) {
    if (s.empty()) return 0;
    int res = 1;
    int temp = 1;
    char last_char = s.at(0);
    for (char i : s) {
      if (i == last_char + 1) {
        temp += 1;
      } else {
        res = res > temp ? res : temp;
        temp = 1;
      }
      last_char = i;
    }
    return res > temp ? res : temp;
  }
};