#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
	int l = 0, n = 0;
	scanf("%d %d", &l, &n);
	if (l >= 3 && l <= 1000 && n >= 1 && n <= 30000) {
		int num = 1, pair = 0, f = 0;
		char last[1001] = {}, t[1001] = {}, iit[1001] = {};
		for (int text = 0; text < n + 1; text++) {
			if (f < 1) {
				if (pair == 2) {
					int error = 0;
					for (int k = 0; k < l; k++) {
						if (t[k] != iit[k]) error++;
					}
					if (error > 2) {
						if (num % 2 == 1) {
							strcpy(last, t);
						}
						else if (num % 2 == 0) {
							strcpy(last, iit);
						}
						f++;
					}
					pair = 1;
				}
			}
			if (text != n) {
				if (num % 2 == 1) {
					int length = 0;
					t[1001] = {};
					scanf("%s", &t);
					for (int i = 0; i < l; i++) {
						if (!isupper(t[i])) return 0;
					}
					length = strlen(t);
					if (length != l) return 0;
					num++;
					pair++;
				}
				else if (num % 2 == 0) {
					int iilength = 0;
					iit[1001] = {};
					scanf("%s", &iit);
					for (int i = 0; i < l; i++) {
						if (!isupper(iit[i])) return 0;
					}
					iilength = strlen(iit);
					if (iilength != l) return 0;
					num++;
					pair++;
				}
			}
		}
		printf("%s\n", last);
	}
	return 0;
}