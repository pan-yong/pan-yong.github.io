/************************************************
    Created Time: 二  8/3 01:53:22 2021
    Author: durianpy@icloud.com 
    File Name: myls.c
************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
    {
        printf("argc error");
        exit(0);
    }

    if( (dp = opendir(argv[1])) == NULL){
        printf("can't open %s", argv[1]);
        exit(0);
    }

    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n",dirp->d_name);
    
    closedir(dp);
}
