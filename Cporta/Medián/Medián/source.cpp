#include <stdio.h>
#include <stdlib.h>

void kozvetlen(int *t, int db) {
	int i, j, minindex;

	for (i = 0; i < db - 1; ++i) {
		minindex = i;
		for (j = i + 1; j < db; ++j)
			if (t[j] < t[minindex])
				minindex = j;
		if (minindex != i) {
			int temp = t[minindex];
			t[minindex] = t[i];
			t[i] = temp;
		}
	}
}

int main()
{
	int i, a, szamok[3] = { 0 };
	for (i = 0; i < 3; i++)
		scanf("%d ", &szamok[i]);
	kozvetlen(szamok, 3);
	printf("%d", szamok[1]);
	return 0;
}