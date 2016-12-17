#include <bits/stdc++.h>
using namespace std;

int pas;
char ins[1010];

int main() {
	freopen("input.yo","r",stdin);
	freopen("input.in","w",stdout);
	while (true) {
		string s = "";
		char ch;
		do {
			ch = getchar();
			if (ch == '\n' || ch == -1) break;
			s += ch;
		} while (true);
		if (ch == -1) break;
		int k = 0;
		for (; s[k] != '|'; k++);
		s.erase(s.begin() + k, s.end());
		while (s.length() && s.back() == ' ') s.erase(s.end() - 1);
		while (s.length() && s.front() == ' ') s.erase(s.begin());
		if (s == "") continue;
		int u;
		memset(ins,0,sizeof(ins));
		sscanf(s.c_str(),"0x%x: %s",&u,ins + 1);
		if (pas < u) {
			for (int i = pas; i < u; i++) printf("00 ");
			putchar('\n');
		}
		int n = strlen(ins + 1);
		for (int i = 1; i < n; i += 2) {
			printf("%c%c ",ins[i],ins[i + 1]);
		}
		putchar('\n');
		pas = u + n / 2;
	}
	return 0;
}
