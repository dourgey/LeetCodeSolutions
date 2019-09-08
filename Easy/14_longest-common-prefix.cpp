// 还有二分查找法和分治法没有实现，困了，改天再说
// 横向扫描法
#include <string>
#include <vector>

class Solution {
public:
	std::string findLongestCommonPrefix2(std::string str1, std::string str2){
		int maxLen = str1.length()>str2.length()?str2.length():str1.length();
		std::string result{""};
		for(int i = 0;i < maxLen; ++ i){
			if(str1[i] != str2[i])
				return result;
			result += str1[i];
		}
		return result;
	}

	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if(strs.size() == 0)
			return "";
		else if(strs.size() == 1)
			return strs[0];
		auto beg = strs.begin();
		std::string result;
		result = findLongestCommonPrefix2(*beg, *(beg + 1));
		beg += 2;
		while(beg != strs.end()){
			result = findLongestCommonPrefix2(result, *beg);
			beg ++;
		}
		return result;
	}
};

// 纵向扫描法
class Solution2 {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if(strs.size()==0)
			return std::string{""};
		int minLen{INT_MAX};
		auto beg = strs.begin();
		while(beg != strs.end()){
			minLen = minLen < (*beg).length()? minLen : (*beg).length();
			++ beg;
		}
		std::string result{""};
		for(int i = 0;i < minLen; ++i){
			auto beg = strs.begin();
			auto tag = (*beg)[i];
			while(beg != strs.end()){
				if((*beg)[i] != tag)
					return result;
				++ beg;
			}
			result += tag;
		}
		return result;
	}
};
