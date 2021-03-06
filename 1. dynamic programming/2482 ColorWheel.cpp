// 2482 ColorWheel.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#define mod 1000000003;
using namespace std;

long color[1001][1001];

int main()
{
	int N, K;
	
	for (int i = 1; i < 1001; i++) {
		for (int j = 1; j < 1001; j++) {
			if (j == 1)
				color[i][j] = i;
			else if (i / 2 >= j)
				color[i][j] = (color[i - 2][j - 1] + color[i - 1][j])%mod;			
		}
	}

	cin >> N >> K;
	cout << color[N][K];

    return 0;
}

