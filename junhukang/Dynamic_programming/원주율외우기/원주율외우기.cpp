#include <iostream>
#include <algorithm>
#include <string>
#include <cstring> 
using namespace std;

const int INF = 987654321; 
int cache[10000]; 
string num;

int getRank(int start, int end)
{

	//���� ���� ������
	string part = num.substr(start, end - start + 1);

	//ù ���ڸ����� �̷���� ���ڿ��� ������ ���̵� 1
	if (part == string(part.size(), part[0]))
		return 1;

	//�������� ����
	bool progressive = true;

	for (int i = 0; i < part.size() - 1; i++)
		if (part[i + 1] - part[i] != part[1] - part[0])
			progressive = false;

	//���������̰� ������ 1 Ȥ�� -1�̸� ���̵� 2
	if (progressive && abs(part[1] - part[0]) == 1)
		return 2;

	//�� ���� ������ �����ϴ��� Ȯ��
	bool alternate = true;
	for (int i = 0; i < part.size(); i++)
		if (part[i] != part[i % 2])
			alternate = false;

	if (alternate)
		return 4; //�����ư��� �����ϴ� ����
	if (progressive)
		return 5; //���� ������ �̷�� ������ 1 �ƴ�
	return 10; //�� �� ����
}

//���� num[idx..]�� �ܿ�� ��� �� ���̵��� �ּ� �� ���
int memorize(int idx)
{
	//���� ���:������ ���� ������ ���
	if (idx == num.size())
		return 0;
	//������ȹ��
	int &result = cache[idx];
	if (result != -1)
		return result;
	result = INF;
	for (int i = 3; i <= 5; i++) //���̴� 3���� 5 ����
		if (idx + i <= num.size())
			result = min(result, memorize(idx + i) + getRank(idx, idx + i - 1)); //�ش� ���� ���̵�+memorize(idx+i)�� result �� ���� ��
	return result;

}

int main(void)
{
	int test_case;
	cin >> test_case;

	if (test_case < 1 || test_case>50)
		exit(-1);

	for (int i = 0; i < test_case; i++)
	{
		memset(cache, -1, sizeof(cache));
		cin >> num;
		cout << memorize(0) << endl << endl;
	}
	return 0;
}