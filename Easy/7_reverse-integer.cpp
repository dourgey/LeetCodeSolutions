/*
class Solution {
public:
	int reverse(int x) {
		long int sum = 0;
		bool isPositive = (x > 0);
		long int x2 = x;
		if(x2 < 0)
			x2 = -x2;
		while(x2 / 10 != 0){
			sum = 10 * sum + x2 % 10;
			x2 = x2 / 10;
		}
		sum = 10 * sum + x2 % 10;
		if(!isPositive)
			sum = -1 * sum;
		if(sum > 2147483647 || sum < -2147483648)
			return 0;
		return sum;
	}
};
*/


#include <climits>

class Solution {
public:
	int reverse(int x) {
		int sum{ 0 };
		while (x / 10 != 0) {
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		/*
		 * �ж�sum�ڼ���������Ƿ�����
		 * ������������
		 * 1) ��sum * 10 > INT_MAX����sum*10 < INT_MINʱ���
		 * 2����sum * 10 == INT_MAX�Һ���Ҫ�ӵ���>7��sum * 10 == INT_MIN�Һ���ӵ���<-8ʱ�������
		 */
		
		if (sum > INT_MAX / 10 || sum < INT_MIN / 10) {
			return 0;
		}
		else if ((sum == INT_MAX / 10 && x % 10 > 7) || (sum == INT_MIN / 10 && x % 10 < -8)) {
			return 0;
		}
		return sum * 10 + x;
	}
};
