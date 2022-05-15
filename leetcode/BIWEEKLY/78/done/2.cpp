class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> nums_;
        nums_.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            nums_.push_back(nums[i] + nums_[i - 1]);
        }
        int val_split = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums_[i] >= nums_[n - 1] - nums_[i])
            {
                val_split++;
            }
        }

        return val_split;
    }
};