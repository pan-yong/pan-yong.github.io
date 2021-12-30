#include <stdio.h>

#define MAXSHIT	15		// max length of histogram
#define MAXWORD 11		// max length of a word
#define IN  1		    // inside a word
#define OUT 0		    // outside a word

// print vertical histogram
main()
{
    int c, i, j;
    int nc = 0;
    int state = OUT;
    int maxvalue;		// max value for wl[]
    int ovflow = 0;			// number of overflow words
    int wl[MAXWORD] = {0};	// word length counters
   
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
            	else
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT){
            state = IN;
            nc = 1;
        }
        else
            ++nc;
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];
    
    for (i = MAXSHIT; i > 0; --i){
        for (j = 1; j < MAXWORD; ++j)
            if(wl[j] * MAXSHIT / maxvalue >= i)
                printf("  *  ");
        	else
                printf("     ");
        putchar('\n');
    }
    
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d ", i);
    putchar('\n');
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d ", wl[i]);
    putchar('\n');
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
