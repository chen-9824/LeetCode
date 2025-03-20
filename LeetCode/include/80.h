/*
80. 删除有序数组中的重复项 II
中等
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

示例 1：
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。

示例 2：
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。
 
提示：
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按升序排列

已按顺序排列，即相同元素在一起，那么可用双指针法向前挪动数组元素进行删除操作
快慢指针从0开始向后移动，每次移动一步，并将快指针元素复制给慢指针
当慢指针指向多余的元素时，该次不向后移动，
*/

class Solution_80 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int fast_index = 1;//从1开始方便计算是否多余
        int slow_index = 1;

        int repeat_num = 0;

        for(; fast_index < nums.size(); ++fast_index){
            if(nums[fast_index] == nums[fast_index - 1]){
                repeat_num += 1;
            }
            else repeat_num = 0;

            if(repeat_num < 2){
                nums[slow_index++] = nums[fast_index];
            }
        }

        return slow_index;
    }
};