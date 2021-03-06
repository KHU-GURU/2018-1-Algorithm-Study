// 백준 3085 사탕 게임
// https://www.acmicpc.net/problem/3085
// 2018.06.05 발표

#include <iostream>
#include <algorithm>
using namespace std;

int cal(char ** candy, int n) 
{
	// 풀이 1에서 가져온 탐색 방법, 배열의 모든 성분에 대해 오른쪽/아래 방향으로 같은 값을 가진 성분의 개수를 파악한다, ppt 참고
	/*int most = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c1 = 0, c2 = 0, x = i, y = j;
			while (x < n && candy[x][j] == candy[i][j]) x++, c1++;
			while (y < n && candy[i][y] == candy[i][j]) y++, c2++;
			most = max(most, max(c1, c2));
		}
	}
	return most;*/

	// 최대 연속 개수 저장
	int most = 0;
	// 열 탐색, 행 탐색 에서의 최대 연속 개수 임시 저장
	int vertemp, hortemp;

	for (int i = 0; i < n; i++) {
		vertemp = 1, hortemp = 1;
		for (int index = 0; index + 1 < n; index++) {
			// 행 기준으로 같은 성분이 연속되어 나타날 경우
			if (candy[i][index] == candy[i][index + 1]) hortemp++;
			// 그렇지 않다면 현재 최댓값과 임시 변수를 비교하여 변수에 저장하고, 행 기준 연속 성분 변수를 1로 초기화한다
			else {
				most = max(most, hortemp);
				hortemp = 1;
			}
			// 열 기준으로 같은 성분이 연속되어 나타날 경우
			if (candy[index][i] == candy[index + 1][i]) vertemp++;
			// 그렇지 않다면 현재 최댓값과 임시 변수를 비교하여 변수에 저장하고, 열 기준 연속 성분 변수를 1로 초기화한다
			else {
				most = max(most, vertemp);
				vertemp = 1;
			}
		}
		// 만일 행 또는 열의 마지막 성분에서 연속으로 같은 값이 나타나 else문을 진입하지 않을 경우 그 값은 최댓값 변수와 비교되지 못하므로 마지막 확인
		most = max(most, max(vertemp, hortemp));
	}

	return most;
}

// 풀이 1+2의 코드 작성을 위해 풀이 2를 참고하여 작성한 배열 탐색 부분
// 교환을 수행한 지점의 좌표와 교환의 수직/수평 여부를 파라미터에 추가하여 구현하였으나 오답, ppt 참고
/*int cal(char ** candy, int n, int i, int j, char mode) 
{
	int most = 0, index;

	if (mode == 'v') {
		int v1 = 0, h1 = 0, h2 = 0;
		int tempv1 = 1, temph1 = 1, temph2 = 1;
		index = 0;
		while (index + 1< n) {
			if (candy[index][j] == candy[index + 1][j]) tempv1++;
			else {
				v1 = max(v1, tempv1);
				tempv1 = 1;
			}
			if (candy[i][index] == candy[i][index + 1]) temph1++;
			else {
				h1 = max(h1, temph1);
				temph1 = 1;
			}
			if (candy[i + 1][index++] == candy[i + 1][index + 1]) temph2++;
			else {
				h2 = max(h2, temph2);
				temph2 = 1;
			}
			v1 = max(v1, tempv1);
			h1 = max(h1, temph1);
			h2 = max(h2, temph2);
		}
		most = max(v1, max(h1, h2));
	}
	else {
		int v1 = 0, v2 = 0, h1 = 0;
		int tempv1 = 1, tempv2 = 1, temph1 = 1;
		index = 0;
		while (index + 1< n) {
			if (candy[index][j] == candy[index + 1][j]) tempv1++;
			else {
				v1 = max(v1, tempv1);
				tempv1 = 1;
			}
			if (candy[index][j + 1] == candy[index + 1][j + 1]) tempv2++;
			else {
				v2 = max(v2, tempv2);
				tempv2 = 1;
			}
			if (candy[i][index++] == candy[i][index + 1]) temph1++;
			else {
				h1 = max(h1, temph1);
				temph1 = 1;
			}
			v1 = max(v1, tempv1);
			v2 = max(v2, tempv2);
			h1 = max(h1, temph1);
		}
		most = max(h1, max(v1, v2));
	}

	return most;
}*/

int main()
{
	int n, most = 0;
	char ** candy;

	cin >> n;
	candy = new char*[n];
	// 사탕 배열에서 종류를 입력하는 부분, 사탕의 종류가 정해져 있지만 어차피 테스트 케이스에서 다른 값은 입력하지 않을거라 예상하여 코드 작성에서 생략하고 char로 포괄하였다
	for (int i = 0; i < n; i++){
		candy[i] = new char[n];
		cin >> candy[i];
	}

	// 교환을 수행하지 않은 그 자체의 배열에서 연속되는 최댓값을 확인하는 부분
	// 문제에 직접적으로 명시되어 있지는 않지만 교환 없이는 개수를 파악하지 않는다고 판단하여 생략
	// most = cal(candy, n);

	// 풀이 1에 기초하여 작성한 교환 조건 부분, 모든 배열 성분에 대해 오른쪽/앞 방향의 인접한 성분이 다른 값이면 무조건 교환을 수행하고 최댓값을 갱신한다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 배열 범위를 넘어선 접근에 대한 예외처리 && 아래쪽의 성분과 값이 같은가?
			if (i + 1 < n && candy[i][j] != candy[i + 1][j]) {
				swap(candy[i][j], candy[i + 1][j]);
				most = max(most, cal(candy, n));
				swap(candy[i][j], candy[i + 1][j]);
			}
			// 배열 범위를 넘어선 접근에 대한 예외처리 && 오른쪽의 성분과 값이 같은가?
			if (j + 1 < n && candy[i][j] != candy[i][j + 1]) {
				swap(candy[i][j], candy[i][j + 1]);
				most = max(most, cal(candy, n));
				swap(candy[i][j], candy[i][j + 1]);
			}
		}
	}

	// 1st~3rd try 까지 작성한 교환 조건 부분, 모든 조건이 작성되어 있지는 않으나 오답을 예상하고 여기서 중단
	/*most = cal(candy, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 < n && j + 1 < n && candy[i][j] == candy[i + 1][j + 1]) {
				if (candy[i][j + 1] != candy[i + 1][j + 1]) {
					swap(candy[i][j + 1], candy[i + 1][j + 1]);
					most = max(most, cal(candy, n));
					swap(candy[i][j + 1], candy[i + 1][j + 1]);
				}
				if (candy[i + 1][j] != candy[i + 1][j + 1]) {
					swap(candy[i + 1][j], candy[i + 1][j + 1]);
					most = max(most, cal(candy, n));
					swap(candy[i + 1][j], candy[i + 1][j + 1]);
				}
			}
			if (i + 1 < n && j - 1 > 0 && candy[i][j] == candy[i + 1][j - 1]) {
				if (candy[i + 1][j] != candy[i + 1][j - 1]) {
					swap(candy[i + 1][j], candy[i + 1][j - 1]);
					most = max(most, cal(candy, n));
					swap(candy[i + 1][j], candy[i + 1][j - 1]);
				}
			}
			if (i - 1 > 0 && j + 1 < n && candy[i][j] == candy[i - 1][j + 1]) {
				if (candy[i][j + 1] != candy[i - 1][j + 1]) {
					swap(candy[i][j + 1], candy[i - 1][j + 1]);
					most = max(most, cal(candy, n));
					swap(candy[i][j + 1], candy[i - 1][j + 1]);
				}
			}
			if (i + 2 < n && candy[i][j] == candy[i + 2][j]) {
				if (candy[i + 1][j] != candy[i + 2][j]) {
					swap(candy[i + 1][j], candy[i + 2][j]);
					most = max(most, cal(candy, n));
					swap(candy[i + 1][j], candy[i + 2][j]);
				}
			}
			if (j + 2 < n && candy[i][j] == candy[i][j + 2]) {
				if (candy[i][j + 1] != candy[i][j + 2]) {
					swap(candy[i][j + 1], candy[i][j + 2]);
					most = max(most, cal(candy, n));
					swap(candy[i][j + 1], candy[i][j + 2]);
				}
			}
		}
	}*/

	cout << most << endl;
}