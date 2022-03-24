#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	int c;
	
	int space=0;
	int whitespace=0;
	int lowercase=0;
	int uppercase=0;
	int digit=0;
	int bytes=0;
	int case_insensitive=0;
	int word=0;
	int line=0;
	
	int state_word=0;
	int state_line=1;
	
	char tmp_word[100];
	char longest[100];
	int longest_len=0;
	
	int alpha_u[26]={0};
	int alpha_l[26]={0};
	int alpha[26];
	int digit_list[10]={0};
	int i;
	while((c=getchar())!=EOF){
		
		bytes++;
		
		if(state_line==1){
			line++;
			state_line=0;
		}

		if(isspace(c)){
			whitespace++;
			if(c==' '){
				space++;
			}
			else if(c=='\n'){
				state_line=1;
			}
			if(state_word!=0){
				tmp_word[state_word]='\0';	
				if(state_word>longest_len){
					longest_len=state_word;
					strcpy(longest,tmp_word);
				}
				else if(state_word==longest_len){
					if(strcmp(tmp_word,longest)<0){
						strcpy(longest,tmp_word);
					}
				}
				state_word=0;
			}
		}
		else{
			if(state_word==0){
				word++;
				tmp_word[state_word]=c;
				state_word++;
			}
			else{
				tmp_word[state_word]=c;
				state_word++;
			}
			
			if(c>='a' && c<='z'){
				lowercase++;
				alpha_l[c-'a']++;
			}
			else if(c>='A' && c<='Z'){
				uppercase++;
				alpha_u[c-'A']++;
			}
			else if(c>='0' && c<='9'){
				digit++;
				digit_list[c-'0']++;
			}
		}
	}
	
    for(i=0;i<26;i++){
		alpha[i]=alpha_l[i]+alpha_u[i];
	}
	case_insensitive = lowercase + uppercase;
	
	if(state_word!=0){
				tmp_word[state_word]='\0';	
				if(state_word>longest_len){
					longest_len=state_word;
					strcpy(longest,tmp_word);
				}
				else if(state_word==longest_len){
					if(strcmp(tmp_word,longest)<0){
						strcpy(longest,tmp_word);
					}
				}
			}
	
	printf("===\n");
	printf("[0] Overview Stats\n");
	printf("===\n");
	printf("Space Count: %d\n",space);
  	printf("Whitespace Count: %d\n",whitespace);
  	printf("Lowercase Count: %d\n",lowercase);
	printf("Uppercase Count: %d\n",uppercase);
  	printf("Digit Count: %d\n",digit);
  	printf("Case-insensitive Count: %d\n",case_insensitive);
  	printf("Byte Count: %d\n",bytes); 
  	printf("Word Count: %d\n",word); 
  	printf("Total Line: %d\n",line);
	printf("===\n");
  	printf("[1] Longest Word\n");
  	printf("===\n");
  	printf("Word: %s\n",longest);
  	printf("Length: %d\n",longest_len);
  	printf("===\n");
  	printf("[2] Case-Sensitive Stats\n");
  	printf("===\n");
  	for(i='A';i<='Z';i++){
  		printf("%c: %d\t%c: %d\n",i,alpha_u[i-'A'],i+32,alpha_l[i-'A']);
	}
	printf("===\n");
	printf("[3] Case-Insensitive Stats\n");
	printf("===\n");
	for(i='a';i<='z';i++){
		printf("%c: %d\n",i,alpha[i-'a']);
	}
	printf("===\n");
  	printf("[4] Digit Stats\n");
	printf("===\n");
	for(i=0;i<10;i++){
		printf("%d: %d\n",i,digit_list[i]);
	}
  	
  	
	return 0;
}
