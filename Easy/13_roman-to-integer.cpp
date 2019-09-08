#include <unordered_map>

class Solution {
public:
	int romanToInt(std::string s) {
		int sum = 0;
		std::unordered_map<char, int> singleRoman;
		singleRoman['I'] = 1;
		singleRoman['V'] = 5;
		singleRoman['X'] = 10;
		singleRoman['L'] = 50;
		singleRoman['C'] = 100;
		singleRoman['D'] = 500;
		singleRoman['M'] = 1000;

		int i = 0;
		for (; i < s.length() - 1; i++) {
			if (singleRoman[s[i]] < singleRoman[s[i + 1]])
				sum -= singleRoman[s[i]];
			else sum += singleRoman[s[i]];
		}
		sum += singleRoman[s[i]];
		return sum;
	}
};
