#include <stdio.h>

#define MAXSHIT 15
#define MAXCHAR	128

// print horizotal histogram freq. of different characters
main()
{
	int cc[MAXCHAR] = {0};		// character counters
    int maxvalue = 0;			// maximum value of cc[]
    char ch;
    int i, len;
    
    while ((ch = getchar()) != EOF) {
        ++cc[ch];
    }
        
    for (i = 1; i < MAXCHAR; ++i) {
        if(cc[i] > maxvalue){
            maxvalue = cc[i];
        }
    }
        
    for (i = 1; i < MAXCHAR; ++i) {
    	if(cc[i] <= 0)
			continue;
			 
        if (isprint(i))
            printf("%5d - %c - %5d : ", i, i, cc[i]);
        else 
            printf("%5d -   - %5d : ", i, cc[i]);
        if (cc[i] > 0) {
            if ((len = cc[i] * MAXSHIT / maxvalue) <= 0)
                len = 1;
        }
        else {
            len = 0;
        }
        while (len > 0){
            putchar('*');
            --len;
        }
        putchar('\n');
    }
   
}
