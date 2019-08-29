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
	inline virtual void who()  // ��дinlineʱ��ʽ����
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
		if (ori != cmp)//�ж�������� ���������10���Ͳ���ǰ�Ƿ���� ����Ⱦ������
			return 0;
	}
	return rt;
}

int main()
{
	// �˴����麯�� who()����ͨ���ࣨBase���ľ������b�������õģ������ڼ����ȷ���ˣ������������������ģ��������Ƿ�����ȡ���ڱ������� 
	//Base b;
	//b.who();

	//// �˴����麯����ͨ��ָ����õģ����ֶ�̬�ԣ���Ҫ������ʱ�ڼ����ȷ�������Բ���Ϊ������  
	//Base *ptr = new Derived();
	//ptr->who();

	//// ��ΪBase��������������virtual ~Base() {}�������� delete ʱ�����ȵ��������ࣨDerived�������������ٵ��û��ࣨBase��������������ֹ�ڴ�й©��
	//delete ptr;
	//ptr = nullptr;


	/*Solution roma;

	cout << roma.romanToInt("III") << endl;

	cout << roma.romanToInt("MCMXCIV") << endl;*/

	cout << reverse(354543543) << endl;

	system("pause");
	return 0;
}