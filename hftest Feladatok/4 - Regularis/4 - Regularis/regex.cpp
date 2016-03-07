#include <stdio.h>

char myid[] = "Nagy Robert,1MI,0,L4L <robi54321@gmail.com> GLPH8B\n";

char mytask[] = "Feladat = 4\n";


int main()
{
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf(mytask);

	printf("A___023520W6pkkk8TRJhgd45mmeseB\n");
	printf("B___023520W6pkkk8TRJhgd4kk5mmeseB\n");
	printf("C___023520W6pkkk8TRJhgd4krhr5mmeseB\n");
	printf("D___023520665W6pkkk8TRJhgd45mmesea\n");
	printf("E___023520665W6pkkk8TRJhgd45mmesea\n");
	printf("F__023520665W6pkkk8TRJhgd45mmesea\n");
	printf("G___0235206W6pkkk8TRJhgd45mmesea\n");
	printf("H___02352065W6pkkk8TRJhgd45mmesea\n");
	printf("I____02352065W6pkkk8TRJhgd45mmeseB\n");
	int i;
	for (i = 0; i < 205; i++)
		printf("asdasd %d\n", i);

	return 0;
}