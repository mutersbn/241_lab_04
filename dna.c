#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 5

char* strnsub (char *p, int n);

int main()
{
    char line[] = "His textbook was bought from that bookstore";
    char *p1, *p2;
	int count_in=0, count_out=0;

    p1 = strnsub(line, LEN);
	
    while ( strlen(p1) == 4 ) 	
    {
        // set p2 to the position immediately after p1
		p2 = strnsub((line + LEN + count_out), LEN);
		count_in=0;
        while ( strlen(p2) == 4 )	
        {
            if(!strcmp(p1, p2)) // use strncmp() to compare
            {
                printf("The original string is:\n%s\n", line);
                printf("The first substring:  %s\n", strnsub(p1, LEN));
                printf("The second substring: %s\n", strnsub(p2, LEN));
                return 0;
            }
			
			count_in++;
            p2 = strnsub((line+LEN+count_out+count_in), LEN);
        }
		
		count_out++;
        p1 = strnsub((line+count_out), LEN ); 
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);

    return 0;
}


// returns a string with the first n characters of string p

char* strnsub (char *p, int n)
{
	char * str = (char*)malloc(sizeof(char) * (LEN+1));
	strncpy(str, p, n);
	
	return str;
}
