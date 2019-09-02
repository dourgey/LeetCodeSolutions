/*
暴搜法
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<int> result{0, 0};
		for(int i = 0; i < len; i ++){
			for(int j = i + 1; j < len; j ++){
				if(nums[i] + nums[j] == target){
					result[0] = i;
					result[1] = j;
					goto label;
				}
			}
		}
		label:return result;
	}
};
*/

/*
使用Map实现
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int len = nums.size();
		vector<int> result;
		map<int, int> index;
		for(int i = 0;i < nums.size();i ++){
			if(index.find(target - nums[i]) != index.end()){
				result.push_back(index.find(target - nums[i]) -> second);
				result.push_back(i);
			}
			else{
				index.insert(pair<int,int>(nums[i],i));
			}
		}
		return result;
	}
};
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		int len = nums.size();
		std::vector<int> result;
		std::unordered_map<int, int> index;
		for (int i = 0; i < nums.size(); i++) {
			if (index.find(target - nums[i]) != index.end()) {
				result.push_back(index.find(target - nums[i])->second);
				result.push_back(i);
			}
			else {
				index[nums[i]] = i;
			}
		}
		return result;
	}
};
