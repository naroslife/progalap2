#include <math.h>
#include <string.h>
#include "nem_oo.h"

namespace sajat
{
	int power(int base, int exp)
	{
		int result = 1;
		while (exp)
		{
			if (exp & 1)
				result *= base;
			exp >>= 1;
			base *= base;
		}

		return result;
	}


	int atoi(const char *p, int base)
	{
		int i = 0;
		while (p[i] != '\0' && p[i] != ' ')
		{
			if ((p[i] < '0' || p[i] > '9') || p[i] - '0' >= base)
				throw "GLPH8B";
			else
				i++;
		}
		int NumberOfNumbers;
		NumberOfNumbers = i;

		int result = 0;
		for (i = 0; i<NumberOfNumbers; i++)
		{
			result += (p[i] - '0')*power(base, (NumberOfNumbers - 1 - i));
		}
		return result;


	}
	char *strcat(const char *p1, const char *p2)
	{

		char* uj;
		int len1, len2, i, j;

		len1 = strlen(p1);
		len2 = strlen(p2);

		uj = new char[len1 + len2 + 1];

		i = 0;
		j = 0;

		while (p1[i] != '\0')
		{
			uj[i] = p1[i];
			i++;
		}

		while (p2[j] != '\0')
		{
			uj[i] = p2[j];
			j++;
			i++;
		}
		uj[i] = '\0';

		return uj;
	}

	void swap(int& r1, int& r2)
	{
		int temp;
		temp = r1;
		r1 = r2;
		r2 = temp;
		return;
	}

	char *unique(char *first, char *last)
	{
		int i = 0;
		int j = 0;
		char temp = 'a';
		while (first[i + j] != *last)
		{
			if (first[i + j] == temp && i != 0)
			{
				j++;
			}


			else
			{
				temp = first[i + j];
				first[i] = first[i + j];
				i++;
			}
		}
		return &first[i];
	}
}