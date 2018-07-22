#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int cache[101][101];
string W, S; //와일드카드 W, 비교할 문자열 S

bool matchMemorized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret; //-1이 아니면 이미 계산 했던 것임
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) { 
		//같거나 '?'를 만나면 한글자가 같을 수 있으면 다음것으로 넘어간다.
		++w; ++s;
	}
	if (w = W.size()) return ret = (s == S.size()); 
	//패턴이 끝났을 때 문자열도 끝이 나야 참이다.(기저)
	if(W[w]=='*')
		for (int skip = 0; s + skip <= S.size(); skip++) {
			if (matchMemorized(w + 1, s + skip)) //*가 들어가 있으므로 패턴의 다음 것과 문자열 나머지 것들이 매치가 되는 지를 확인해야된다.
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

