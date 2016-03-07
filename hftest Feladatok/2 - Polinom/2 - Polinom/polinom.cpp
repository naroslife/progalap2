#include <stdio.h>
#include <math.h>

char myid[] = "Nagy Robert,1MI,0,L4L <robi54321@gmail.com> GLPH8B\n";

char mytask[] = "Feladat = 2\n";

double fv(double x)
{
	if (x>37)
		return x / 105.40;
	else
		return 0.411*x*x*x*x - 0.822*x*x*x + 52.62*x*x + 5 * x - 37;
}

int main()
{
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf(mytask);
	int c;
	double x;

	/* Advance stream to the first number */
	do
	{
		c = getc(stdin);
	} while ((c < '0' || c > '9') && (!(c == '-' || feof(stdin))));
	if (c != '\n')
		ungetc(c, stdin);


	while (fscanf((stdin), "%lf", &x) == 1)
	{
		printf("%f.4\n", fv(x));

		/* Advance stream to next number OR end of line OR end of file. */
		do
		{
			c = getc(stdin);
		} while ((c < '0' || c > '9') && (!(c == '-' || feof(stdin))));   /* Move until next number or end of line */
		if (c != '\n')
			ungetc(c, stdin);
		else
			break;
	}
	return 0;
}
