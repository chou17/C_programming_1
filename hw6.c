#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int c;
	
    int word_count=0;
    int word_char_count=0;
    int line_count=0;
    int line_char_count=0;
    int re_line_count=0;
    int longest_word_len=0;
    int longest_word_count=0;
    int cmp_word_position=0;

    int state;
    int re_longest_state=0;
	
    char article[1000][1000];
    char word[1000][100];
    char longest_word[1000][100];

    int re_flag[1000]={0};
    
	while ((c=getchar()) != EOF){
        if(c!='\n'){
            article[line_count][line_char_count]=c;
            line_char_count++;
        }
        if(isspace(c) || c==',' || c=='.' || c=='"' || c==':' || c=='!' || c=='?' || c=='(' || c==')'){
            if(state!=0){
                word_char_count++;
                word[word_count][word_char_count]='\0'; 
                if(state>longest_word_len){
                    longest_word_len=state;
                    longest_word_count=0;
                    strcpy(longest_word[0],word[word_count]);
                }
                else if(state==longest_word_len){
                    for(int i=0;i<=longest_word_count;i++){
                        if(strcmp(longest_word[i],word[word_count])==0){
                            re_longest_state=1;
                            break;
                        }
                    }
                    if(re_longest_state==0){
                        longest_word_count++;
                        strcpy(longest_word[longest_word_count],word[word_count]);
                    }
                    re_longest_state=0;	
                }
                word_count++;
                state=0;
            }
            if(c=='\n'){
                for(int i=(cmp_word_position+1);i<word_count;i++){
                    if(strcmp(word[cmp_word_position],word[i])==0){
                        re_flag[line_count]=1;
                        re_line_count++;
                        break;
                    }
                }
                cmp_word_position=word_count;
                article[line_count][line_char_count]='\0';
                line_count++;
                line_char_count=0;
            }
        }
        else{
            if(state==0){
                word_char_count=0;
            }
            else{
                word_char_count++;
            }
            word[word_count][word_char_count]=c;
            state++;
        }
    }
    if(state!=0){
        word_char_count++;
        word[word_count][word_char_count]='\0'; 
        if(state>longest_word_len){
            longest_word_len=state;
            longest_word_count=0;
            strcpy(longest_word[0],word[word_count]);
        }
        else if(state==longest_word_len){
            for(int i=0;i<=longest_word_count;i++){
                if(strcmp(longest_word[i],word[word_count])==0){
                    re_longest_state=1;
                    break;
                }
            }
            if(re_longest_state==0){
                longest_word_count++;
                strcpy(longest_word[longest_word_count],word[word_count]);
            }
            re_longest_state=0;
        }
        word_count++;
        state=0;
    }
    for(int i=(cmp_word_position+1);i<word_count;i++){
        if(strcmp(word[cmp_word_position],word[i])==0){
            re_flag[line_count]=1;
            re_line_count++;
            break;
        }
    }
    cmp_word_position=word_count;
    article[line_count][line_char_count]='\0';
    line_count++;
    line_char_count=0;

    printf("--- [0] The line that the first word occurs more than twice in the line ---\n");
    if(re_line_count==0){
        printf("It is not exist!\n");
    }
    else{
        printf("Repeated line count: %d\n",re_line_count);
        int num=0;
        for(int i=0;i<=line_count;i++){
            if(re_flag[i]==1){
                printf("[%d]: %s\n",num,article[i]);
                num++;
            }
        }
    }
	
    printf("--- [1] The longest words and their length ---\n");
    printf("Word length: %d\n",longest_word_len);
       for(int i=0;i<=longest_word_count;i++){
            printf("[%d]: %s\n",i,longest_word[i]);
        }
    printf("--- [2] The words appear in the article ---\n");
    printf("Total words: %d\n",word_count);
    for(int i=0;i<word_count;i++){
        if(word[i][0]=='\0'){
        	break;
		}
        if((i%10)!=9){
        	printf("%s ",word[i]);
        }
        else{
            printf("%s\n",word[i]);
        }
    }  
    return 0;
}
