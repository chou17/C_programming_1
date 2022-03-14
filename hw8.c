#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *getword(char *,char *);

int main(){
    char *line = malloc(sizeof(char)*1000);
    char *word = malloc(sizeof(char)*20);
    char *d_data = malloc(sizeof(char)*10);
    int *is_delete_data = malloc(sizeof(int)*1000);

    char name[1000][100],math[1000][4],eng[1000][4],prog[1000][4];

    int count=0,char_count=0;
    int word_len;

    while (fgets(line,1000,stdin)){
    	char *ptr=line+2;
        if (*line == 'i'){
            while ((ptr = getword(ptr,word)) != NULL){
            	word_len = strlen(word);
            	
                if (*word == 'n'){
                    for (int i=2;i<word_len;i++){
                        name[count][char_count++]=word[i];
                    }
                }
                else if (*word == 'm'){
                    for (int i=2;i<word_len;i++){
                        math[count][char_count++]=word[i];
                    }
                }
                else if (*word == 'e'){
                    for (int i=2;i<word_len;i++){
                        eng[count][char_count++]=word[i];
                    }
                }
                else if (*word == 'p'){
                    for (int i=2;i<word_len;i++){
                        prog[count][char_count++]=word[i];
                    }
                }
                char_count=0;
            }
            count++;
        }

        else if (*line == 'd'){
            while ((ptr=getword(ptr,word)) != NULL){
            	word_len=strlen(word);
                if (*word == 'n'){
                    for (int i=2;i<word_len;i++){
                        d_data[char_count++]=*(word+i);
                    }
                    for (int i=0;i<count;i++){
                        if (strcmp(d_data,name[i]) == 0){
                            is_delete_data[i]=1;
                        }
                    }
                }
                char_count=0;
            }
        }

        else if(*line == 'u'){
            while ((ptr=getword(ptr,word)) != NULL){
                word_len=strlen(word);
                int u_data_num;
                if (*word == 'n'){
                    for (int i=2;i<word_len;i++){
                        d_data[char_count++]=word[i];
                    }
                    for (int i=0;i<count;i++){
                        if (strcmp(d_data,name[i]) == 0){
                            u_data_num=i;
                        }
                    }  
                }
                else if (*word == 'm'){
                    for (int i=0;i<3;i++){
                      math[u_data_num][i]='\0';
                    }
                    for (int i=2;i<word_len;i++){
                        math[u_data_num][char_count++]=word[i];
                    }
                }
                else if (*word == 'e'){
                    for (int i=0;i<3;i++){
                      eng[u_data_num][i]='\0';
                    }
                    for (int i=2;i<word_len;i++){
                        eng[u_data_num][char_count++]=word[i];
                    }
                }
                else if (*word == 'p'){
                    for (int i=0;i<3;i++){
                      prog[u_data_num][i]='\0';
                    }
                    for (int i=2;i<word_len;i++){
                        prog[u_data_num][char_count++]=word[i];
                    }
                }
                char_count=0;
            }
        }

        else if(*line == 'p'){
            printf("name\tmathscore\tenglishscore\tprogscore\n");
            for (int i=0;i<count;i++){
                if (is_delete_data[i] == 0){
                    printf("%s\t%s\t\t%s\t\t%s\n",name[i],math[i],eng[i],prog[i]);
                }
            }
        }
    }
}

char *getword(char *line,char *word){
    char *ptr=line;
    char *qtr=word;
    *word = '\0';
    while (isspace(*ptr)){
        ptr++;
    }
    while (!isspace(*ptr) && *ptr){
        *qtr++ = *ptr++;
    }
    *qtr='\0';
    if (*word == '\0'){
        return NULL;
    }
    return ptr;
}