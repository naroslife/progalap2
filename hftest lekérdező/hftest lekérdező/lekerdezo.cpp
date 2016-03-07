#include <stdio.h>

char myid[] = "Nagy Robert,1MI,0,L4L <robi54321@gmail.com> GLPH8B\n";

int main(int argc, char* argv[])
{
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf("Feladat = ");
	int fsorszam;
	if (argc - 1 != 1)
	{
		fprintf(stderr, "%s: Csak a feladat sorszamat add meg!\n", argv[0]);
		return 1;   /* nem egy parameter van: 1-es hibakod */
	}

	if (sscanf(argv[1], "%d", &fsorszam) != 1)
	{
		fprintf(stderr, "Hibas parameter: %s!\n", argv[1]);
		return 2;   /* 2-es hibakod: hibas parameter */
	}
	printf("%d\nMAIL\n", fsorszam);
	return 0;
}