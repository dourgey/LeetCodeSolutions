#include <string>

// 方法一 字符串判定法
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		std::string str_x = std::to_string(x);
		int len = str_x.length();
		for (int i = 0; i < len / 2; ++i) {
			if (str_x[i] != str_x[len - i - 1])
				return false;
		}
		return true;
	}
};

// 方法二  数字翻转法
class Solution2 {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		long sum = 0;
		int bx = x;
		while (x / 10 != 0) {
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		sum = sum * 10 + x % 10;
		return bx == sum;
	}
};

// 官方题解，只反转一半数字
class Solution3 {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
		int sum = 0;
		while (x > sum) {
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		return sum == x || sum / 10 == x;
	}
};