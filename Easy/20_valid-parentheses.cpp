#include <map>
#include <set>
#include <stack>
#include <string>

class Solution {
public:
	bool isValid(std::string s) {
		if (s.length() == 0)
			return true;
		if (s.length() % 2 != 0)
			return false;
		std::stack<char> temp{};
		std::set<char> left{ '{', '[', '(' };
		std::map<char, char> brackets{ {'}', '{'},
								 {']', '['},
								 {')', '('} };
		for (auto i = s.begin(); i != s.end(); ++i) {
			if (left.find(*i) != left.end())
				temp.push(*i);
			else {
				if (temp.empty())
					return false;
				else if (temp.top() != brackets[*i])
					return false;
				else
					temp.pop();
			}
		}
		if (temp.empty())
			return true;
		return false;
	}
};
