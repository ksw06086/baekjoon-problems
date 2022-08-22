// #define BASE
// #define CharToInt
// #define BACKJOON_EXAM
// #define REFERENCE_EXAM
// #define BRIDGE
// #define CHAR_STUDY

#ifdef BASE
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	
}
#endif // 프로그래밍 기본 툴

#ifdef BASE
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{

}
#endif // 프로그래밍 기본 툴
#ifdef CHAR_STUDY
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	int sub_result = 0;
	int fin_result = 0;
	int i;
	int alphabet[26] = { 0, };
	cin >> str;

	for (char a : str) {
		i = (a <= 'Z') ? a - 65 : a - 97;
		alphabet[i]++;
		if (alphabet[i] >= alphabet[fin_result]) {
			sub_result = fin_result;
			fin_result = i;
		}
	}

	if (alphabet[sub_result] == alphabet[fin_result] && sub_result != fin_result) {
		cout << '?';
	}
	else {
		cout << (char)(fin_result + 65);
	}
}
#endif // 단어공부
#ifdef BRIDGE
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t_cnt, n, m;				// test_case, 서쪽 개수, 동쪽 개수
	vector<int> res;				// 결과물
	int result, f_m, f_n;

	cin >> t_cnt;

	for (int i = 0; i < t_cnt; i++) {
		cin >> n >> m;
		result = 1;
		f_m = m-n+1;
		f_n = 1;
		while (f_m <= m) {
			result *= f_m;
			if (f_n <= n) {
				result /= f_n;
			}
			f_m++; f_n++;
		}
		
		res.push_back(result);
	}

	for (int r : res) {
		cout << r << endl;
	}
}
// 다리를 만들어야 함
// - 다리 짓기에 가장 적합한 곳
// - 서쪽에 n개, 동쪽에 m개가 있음
// ㄴ n <= m
// - n개의 다리를 만들것인데 다리를 만들 수 있는 경우의 수 구하기 프로그램
//
// ㄴ 수학
// ㄴ 다이나믹 프로그래밍
// ㄴ 조합론
//
// == = > 조합 수학 공식을 사용해야함 = > n!/ (n - k)!k!<k = n, n = m>

#endif // 다리 놓기
#ifdef REFERENCE_EXAM
// 매개변수 탐색 알고리즘
// 일단 나눈것만큼 강의 갯수를 나누고 각 구분의 합에서 왼쪽이 크면 옆으로 하나 넣고 오른쪽이 크면 왼쪽으로 하나 넣기 오 그래서 비교하기 그래서 값구하기 
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n; // 테스트 케이스 수
	int k; // 딜러가 뽑은 카드의 값

	cin >> n; // 테스트 케이스 수 입력

	for (int i = 0; i < n; i++) {	// 테스트 반복문
		cin >> k;					// 딜러 공 값 입력

		while (k > 1) {				// 값을 더이상 나눌 수 없을 때
			if (k % 2 == 1) {		// k값이 홀수로 곱해지는 경우
				cout << "Gazua";
				break;
			}

			k /= 2;					// k가 홀수로 곱해지는지 확인하기 위해 최소 짝수인 2로 나눔
		}

		if (k == 1) {	// k가 홀수로 곱해지지 않는 수라면 "GoHanGang" 저장
			cout << "GoHanGang";
		}
	}

}
#endif // REFERENCE_EXAM
#ifdef BACKJOON_EXAM
// 매개변수 탐색 알고리즘
// 일단 나눈것만큼 강의 갯수를 나누고 각 구분의 합에서 왼쪽이 크면 옆으로 하나 넣고 오른쪽이 크면 왼쪽으로 하나 넣기 오 그래서 비교하기 그래서 값구하기 
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define N 21
int omok_cnt[N][N] = { 0, };	// 판 확인

int r_line(int omok[N][N], int x, int y);
int l_line(int omok[N][N], int x, int y);
int r_diagonal(int omok[N][N], int x, int y);
int l_diagonal(int omok[N][N], int x, int y);

int main()
{
	int omok[N][N] = { 0, };		// 오목판
	int res;						// 승리한 돌 0/1(흑)/2(백)

	// 오목판 입력
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			cin >> omok[i][j];
		}
	}

	// 오목판 검색 스타트
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (omok[i][j] != 0 && omok_cnt[i][j] != 1) {
				// 오른쪽 가로 
				if (j < N - 5) {
					res = r_line(omok, i, j);
					if (res) {
						cout << res << endl << i << " " << j;
						return 0;
					}
				}
				// 아래 세로 
				if (i < N - 5) {
					res = l_line(omok, i, j);
					if (res) {
						cout << res << endl << i << " " << j;
						return 0;
					}
				}

				// 오른쪽 아래 대각선 
				if (j < N - 5 && i < N - 5) {
					res = r_diagonal(omok, i, j);
					if (res) {
						cout << res << endl << i << " " << j;
						return 0;
					}
				}

				// 오른쪽 위 대각선
				if (j < N - 5 && i >= 5) {
					res = l_diagonal(omok, i, j);
					if (res) {
						cout << res << endl << i << " " << j;
						return 0;
					}
				}
			}
		}
	}
	// endl은 안쓰는게 좋다 차라리 '\n'이 좋다 시간 초과된다

	cout << res << endl;

}

// 오른쪽 가로
int r_line(int omok[N][N], int x, int y) {
	int cnt = 0;
	int i = 0;
	if (omok[x][y] == 1) {			// 흑일 때
		omok_cnt[x][y] = 1;
		while (omok[x][y + i] == 1) {				// 가로줄 가면서 흑이 계속 나오는지 확인
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x][y - 1] != 1) {		// 이전에 흑이 없었고 가로줄로 쭉 5개면 1 출력하고 끝냄
			return 1;
		}
		else {										// 아니면 다시금
			return 0;
		}
	}
	else if (omok[x][y] == 2) {		// 백일 때
		omok_cnt[x][y] = 1;
		while (omok[x][y + i] == 2) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x][y - 1] != 2) {
			return 2;
		}
		else {
			return 0;
		}
	}

}
// 아래 세로
int l_line(int omok[N][N], int x, int y) {
	int cnt = 0;
	int i = 0;
	if (omok[x][y] == 1) {
		omok_cnt[x][y] = 1;
		while (omok[x + i][y] == 1) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x - 1][y] != 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (omok[x][y] == 2) {
		omok_cnt[x][y] = 1;
		while (omok[x + i][y] == 2) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x - 1][y] != 2) {
			return 2;
		}
		else {
			return 0;
		}
	}

}
// 오른쪽 아래 대각선
int r_diagonal(int omok[N][N], int x, int y) {
	int cnt = 0;
	int i = 0;
	if (omok[x][y] == 1) {
		omok_cnt[x][y] = 1;
		while (omok[x + i][y + i] == 1) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x - 1][y - 1] != 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (omok[x][y] == 2) {
		omok_cnt[x][y] = 1;
		while (omok[x + i][y + i] == 2) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x - 1][y - 1] != 2) {
			return 2;
		}
		else {
			return 0;
		}
	}

}
// 오른쪽 위 대각선
int l_diagonal(int omok[N][N], int x, int y) {
	int cnt = 0;
	int i = 0;
	if (omok[x][y] == 1) {
		omok_cnt[x][y] = 1;
		while (omok[x - i][y + i] == 1) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x + 1][y - 1] != 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (omok[x][y] == 2) {
		omok_cnt[x][y] = 1;
		while (omok[x - i][y + i] == 2) {
			cnt++;
			i++;
		}
		if (cnt == 5 && omok[x + 1][y - 1] != 2) {
			return 2;
		}
		else {
			return 0;
		}
	}

}

// vector 중복값 제거 소스
/*
* #include <algorithm>
* #include <string>
* sort(arr.begin(), arr.end());
* arr.erase(unique(arr.begin(), arr.end()), s.end());
*/
#endif // BACKJOON_EXAM
#ifdef CharToInt
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#include <vector>

int main()
{
	string line;
	vector<int> sum;
	int n1, n2;

	for (int i = 0; ; i++) {
		getline(cin, line);

		if (!line[0]) {
			break;
		}

		// 첫 번째 수가 음수일 때
		if (line[0] == '-') {
			n1 = (line[1] - '0') * -1;
		}
		else {
			n1 = line[0] - '0';
		}

		// 두 번째 수가 음수일 때
		if (line[2] == '-') {
			n2 = (line[3] - '0') * -1;
		}
		else if (line[3] == '-') {
			n2 = (line[4] - '0') * -1;
		}
		else {
			n2 = line[2] - '0';
		}

		sum.push_back(n1 + n2);
	}

	for (int i : sum) {
		cout << i << endl;
	}
	/*cout << *min_element(arr.begin(), arr.end());
	cout << " " << *max_element(arr.begin(), arr.end());*/
	/*
	* ******* 엔터키 받는 방법 ********
	* 엔터키를 받으려면 문자열을 받는 cin.getline을 써야한다
	* 변수선언도 string으로 하고
	* 한글자만 하려면 cin.get으로 받아도 되고 변수는 char로 하고
	*/
	/*
	* ******* 최댓값, 최솟값 구하는 것 ***********
	* #include <algorithm>
	int max = *max_element(v.begin(), v.end());
	cout << "가장 큰 수 : " << max << "\n";
	int max_index = max_element(v.begin(), v.end()) - v.begin();
	cout << "가장 큰 수의 인덱스 : " << max_index;
	cout << "\n==============================\n";

	int min = *min_element(v.begin(), v.end());
	cout << "가장 작은 수 : " << min << "\n";
	int min_index = min_element(v.begin(), v.end()) - v.begin();
	cout << "가장 작은 수의 인덱스 : " << min_index << "\n\n";
	*/
}
#endif // CharToInt
