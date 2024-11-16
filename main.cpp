class Solution {
public:
    long long minimalKSum(std::vector<int>& nums, int k) {
        // Use an unordered_set to remove duplicates
        std::unordered_set<int> nums_set(nums.begin(), nums.end());

        // Convert set back to a sorted vector for efficient iteration
        std::vector<int> unique_nums(nums_set.begin(), nums_set.end());
        std::sort(unique_nums.begin(), unique_nums.end());

        long long sum = 0;
        int next = 1; // Start from the smallest positive integer
        for (int num : unique_nums) {
            // Add all missing numbers between `next` and `num`
            while (next < num && k > 0) {
                sum += next;
                next++;
                k--;
            }
            // Move `next` beyond the current number
            next = num + 1;
        }

        // Add remaining numbers after the largest element in the set
        while (k > 0) {
            sum += next;
            next++;
            k--;
        }

        return sum;
    }
};
