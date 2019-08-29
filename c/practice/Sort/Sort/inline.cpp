#include"stdafx.h"
#include <iostream>  
#include <map>

using namespace std;
class Base
{
public:
	inline virtual void who()
	{
		cout << "I am Base\n";
	}
	virtual ~Base() {
		cout << "delete base" << endl;
	}
};
class Derived : public Base
{
public:
	inline virtual void who()  // 不写inline时隐式内联
	{
		cout << "I am Derived\n";
	}

	~Derived()
	{
		cout << "delete Derived" << endl;

	}
};

class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		bool lastEle = 0;
		map<char, int> luomab;

		luomab.insert(map<char, int>::value_type('I', 1));
		luomab.insert(map<char, int>::value_type('V', 5));
		luomab.insert(map<char, int>::value_type('X', 10));
		luomab.insert(map<char, int>::value_type('L', 50));
		luomab.insert(map<char, int>::value_type('C', 100));
		luomab.insert(map<char, int>::value_type('D', 500));
		luomab.insert(map<char, int>::value_type('M', 1000));
		for (int i = 0; i<s.length()-1; i++)
		{
			if (luomab[s[i]] >= luomab[s[i + 1]])
			{
				result += luomab[s[i]];
				lastEle = 0;
			}
			else
			{
				result += (luomab[s[i + 1]] - luomab[s[i]]);
				i++;
				if (i == s.length() - 1)
				{
					lastEle = 1;
				}
			}
		}
		if (0 == lastEle) {
			result += luomab[s[s.length() - 1]];
		}

		return result;
	}
};


int reverse(int x) {
	int cmp, ori, rt = 0, tmp[10] = { 0 }, i, j;
	for (i = 0; i < 10 && x != 0; i++)
	{
		tmp[i] = x % 10;
		x = x / 10;
	}
	for (j = 0; j < i; j++) {
		ori = rt;
		rt = 10 * rt + tmp[j];
		cmp = rt / 10;
		if (ori != cmp)//判断整形溢出 操作后除以10看和操作前是否相等 不相等就溢出了
			return 0;
	}
	return rt;
}

int main()
{
	// 此处的虚函数 who()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。 
	//Base b;
	//b.who();

	//// 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。  
	//Base *ptr = new Derived();
	//ptr->who();

	//// 因为Base有虚析构函数（virtual ~Base() {}），所以 delete 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
	//delete ptr;
	//ptr = nullptr;


	/*Solution roma;

	cout << roma.romanToInt("III") << endl;

	cout << roma.romanToInt("MCMXCIV") << endl;*/

	cout << reverse(354543543) << endl;

	system("pause");
	return 0;
}