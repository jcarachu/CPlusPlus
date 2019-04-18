#include <stdio.h>
#include <iostream>
using namespace std;

void reverse (char *str)
{
	char *end = str;
	char tmp;
	if(str)
	{
        // find end of the string
		while(*end) 
		{
			++end;
		}
		--end; // set one char back, since last char is null

		/*
			swap characters from start of string with the end of the string
			until the pointers meet in the middle
		*/
		while(str < end)
		{
			// tmp is the first value from the string
            tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main(int argc, char const *argv[])
{
    /* code */
    char str [] = "JULIAN";
    printf("%s\n",str);
    reverse(str);
    printf("%s\n",str);
    return 0;
}
