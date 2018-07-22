#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int cache[101][101];
string W, S; //���ϵ�ī�� W, ���� ���ڿ� S

bool matchMemorized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret; //-1�� �ƴϸ� �̹� ��� �ߴ� ����
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) { 
		//���ų� '?'�� ������ �ѱ��ڰ� ���� �� ������ ���������� �Ѿ��.
		++w; ++s;
	}
	if (w = W.size()) return ret = (s == S.size()); 
	//������ ������ �� ���ڿ��� ���� ���� ���̴�.(����)
	if(W[w]=='*')
		for (int skip = 0; s + skip <= S.size(); skip++) {
			if (matchMemorized(w + 1, s + skip)) //*�� �� �����Ƿ� ������ ���� �Ͱ� ���ڿ� ������ �͵��� ��ġ�� �Ǵ� ���� Ȯ���ؾߵȴ�.
				return ret = 1;
		}
	return ret = 0;
}


int main(void) {
	int C=0, n;
	memset(cache, -1, sizeof(cache));
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> W;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> S;
			if (matchMemorized(0, 0))
				cout << S << endl;
		}
		
	}
}

