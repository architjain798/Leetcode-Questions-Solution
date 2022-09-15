class Solution
{
    int helper(vector<int> nums, int start, int end, int target)
    {
        if (start > end) return -1;

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) return mid;

        else if (nums[start] <= nums[mid])
        {
            if (target >= nums[start] && target <= nums[mid])
            {
                return helper(nums, start, mid - 1, target);
               	// end=mid-1;
            }
            else
            {
                return helper(nums, mid + 1, end, target);
               	// start=mid+1;
            }
        }
        else if (nums[mid] <= nums[end])
        {
            if (target >= nums[mid] && target <= nums[end])
            {
                return helper(nums, mid + 1, end, target);
               	//start=mid+1;
            }
            else
            {
                return helper(nums, start, mid - 1, target);
               	// end=mid-1;
            }
        }
        return -1;
    }
    public:
        int search(vector<int> &nums, int target)
        {
            return helper(nums, 0, nums.size() - 1, target);
        }
};