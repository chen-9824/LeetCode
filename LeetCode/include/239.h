//
// Created by cfan on 2024/4/15.
//

#ifndef LEETCODE_INCLUDE_239_H_
#define LEETCODE_INCLUDE_239_H_

/*239. 滑动窗口最大值
困难
    提示
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]

提示：
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length*/

class Solution_239 {
 public:
  /*
   * 时间复杂度太高，超时了
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
      vector<int> max_num;
      for (int i = 0; i <= nums.size() - k; ++i) {
          int current_max_num = INT32_MIN;
          for (int j = 0; j < k; ++j) {
              if (nums[i + j] > current_max_num)
                  current_max_num = nums[i + j];
          }
          max_num.push_back(current_max_num);
      }
      return max_num;
  }

  /*
   * 单调队列维护窗口，队列内始终保持单调递减，保证队列头始终最大
   */
  vector<int> maxSlidingWindow_deque(vector<int> &nums, int k) {
      MyDeque record;
      vector<int> res;
      for (int i = 0; i < k; ++i) {//将第一个窗口独立出来，避免for循环条件不好确定
          record.push(nums[i]);
      }
      res.push_back(record.get_max_value());

      for (int i = k; i < nums.size(); ++i) {
          record.pop(nums[i - k]);
          record.push(nums[i]);
          res.push_back(record.get_max_value());
      }

      return res;
  }

 private:
  class MyDeque {
   public:
    deque<int> m_deque;
    void pop(int val) {
        if (val == m_deque.front())
            m_deque.pop_front();
    }

    void push(int x) {
        while (!m_deque.empty() && x > m_deque.back())//要维护队列的单调性，所以从队尾开始比较大小
            m_deque.pop_back();//队尾弹出
        m_deque.push_back(x);
    }

    int get_max_value() {
        return m_deque.front();
    }
  };
};

#endif //LEETCODE_INCLUDE_239_H_
