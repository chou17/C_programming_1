#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXNUM 128

void usage();
void bubble_sort(char **,int);
void bubble_sort_num(char **,int);

int main(int argc, char **argv) {
	char *line = malloc(MAXNUM);
	char **word = malloc(sizeof(char *) * MAXNUM);
	int word_count=0;
	int is_r=0,is_n=0;
	int is_undefined=0;
	
	while(fgets(line,MAXNUM,stdin)){
		int len = strlen(line);
		*(line+len-1)='\0';
		*(word+word_count) = malloc(len);
		strcpy(*(word+word_count++),line);
	}
	if(argc==1){
		bubble_sort(word,word_count);
		for(int i=0;i<word_count;i++)
			printf("%s\n",*(word+i));
	}
	else{
		for(int i=1;i<argc;i++){
		    if(strcmp(*(argv+i),"-h")==0)
		    	usage();
		    else if(strcmp(*(argv+i),"-n")==0){
		    	is_n=1;
                if(word_count>1)
                    bubble_sort_num(word,word_count);
		    }
		    else if(strcmp(*(argv+i),"-r")==0)
                is_r=1;
		    else{
		    	printf("Undefined parameter: %s.\n",*(argv+i));
		    	is_undefined=1;
		  	}
	    }
	    if(is_undefined==1){
            usage();
        }
		if(word_count>1){
    	    if(is_r==1){
    		    if(is_n==0)
    			    bubble_sort(word,word_count);
		        for(int j=(word_count-1);j>=0;j--)
	                printf("%s\n",*(word+j));
		    }
		    else{
			    for(int i=0;i<word_count;i++)
			        printf("%s\n",*(word+i));
		    }
        }
	}
}
void bubble_sort(char **word,int word_count){
	for (int i=0;i<word_count-1;i++){
        for (int j=0;j<word_count-1-i;j++){
        	if (strcmp(*(word+j),*(word+j+1))>0){
                char *tmp = malloc(sizeof(char)*128);
                strcpy(tmp,*(word+j));
                strcpy(*(word+j),*(word+j+1));
                strcpy(*(word+j+1),tmp);
            }
        }
    }
}
void usage(){
	printf("Usage:\n");
    printf("\t-h --help usage\n");
    printf("\t-n numerical\n");
    printf("\t-r reverse\n");
}
void bubble_sort_num(char **word,int word_count){
	int *num = malloc(sizeof(int)*MAXNUM);
		for(int j=0;j<word_count;j++)
		    *(num+j) = atoi(*(word+j)); 
    for (int j=0;j<word_count-1;j++){
        for (int k=0;k<word_count-j-1;k++){
            if (*(num+k)>*(num+k+1)){
                int tmp1;
                tmp1=*(num+k);
                *(num+k)=*(num+k+1);
                *(num+k+1)=tmp1;
                char *tmp2 = malloc(sizeof(char)*MAXNUM);
                strcpy(tmp2,*(word+k));
                strcpy(*(word+k),*(word+k+1));
                strcpy(*(word+k+1),tmp2);
            }
        }
    }
}