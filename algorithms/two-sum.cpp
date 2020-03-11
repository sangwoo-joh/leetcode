class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> answer;
    bool solved = false;
    for (int i1 = 0; i1 < nums.size(); ++i1) {
      for (int i2 = i1 + 1; i2 < nums.size(); ++i2) {
        if (nums[i1] + nums[i2] == target) {
          answer.push_back(i1);
          answer.push_back(i2);
          solved = true;
          break;
        }
      }

      if (solved)
        break;
    }

    return answer;
  }
};
