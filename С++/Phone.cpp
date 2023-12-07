#include <iostream>
#include <string.h>
using namespace std;
	
string Mass[10][6]{
	{"0","8",""},
	{"1","2","4",""},
	{"1","2","3","5",""},
	{"2","3","6",""},
	{"1","4","5","7",""},
	{"2","4","5","6","8",""},
	{"3","5","6","9",""},
	{"4","7","8",""},
	{"5","7","8","9","0",""},
	{"6","8","9",""}
};

int F(string A, int i, string B) {
	string* G = Mass[A[i] - '0'];
	//cout << G[0];
	int j = -1;
	while (G[++j].length() > 0) {
		//cout << B + G[j];
		if (i == A.length() - 1) {
			cout << B + G[j] << " ";
			continue;
		}
		F(A, i + 1, B + G[j]);
	}
	return 0;
}

int main() {
	string S;
	cin >> S;
	F(S, 0, "");

	return 0;
}