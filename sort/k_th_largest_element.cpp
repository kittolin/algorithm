/*
* 名称：Kth Largest Element in an Array

* 链接：https://leetcode.com/problems/kth-largest-element-in-an-array/
* 难度：中等
*/

#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSort(nums, 0, n - 1, n - k);
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = left + rand() % (right - left + 1);
        swap(nums[left], nums[pivot]);
        while (left < right) {
            while (left < right && nums[left] <= nums[right]) {
                right --;
            }
            swap(nums[left], nums[right]);
            while (left < right && nums[left] <= nums[right]) {
                left ++;
            }
            swap(nums[left], nums[right]);
        }
        return left;
    }

    int quickSort(vector<int>& nums, int left, int right, int index) {
        int pos = partition(nums, left, right);
        if (pos > index) {
            return quickSort(nums, left, pos - 1, index);
        } else if (pos < index) {
            return quickSort(nums, pos + 1, right, index);
        } else {
            return nums[pos];
        }
    }    
};
