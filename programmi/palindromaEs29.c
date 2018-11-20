#include <stdio.h>
int lunghezza(char *s){
        int l=0;
        while(s[l]!='\0'){
                l++;
        }
        return l;
}

int verifica_palindroma(char *str, int j,int m){
        printf("%c\n",*str);
        printf("%c\n",*(str+j-1));
	if(*str != *(str+j-1)){
		return 0;
	}
	if(j<m){
		return *str == *(str+j-1);
	}else return verifica_palindroma(str+1,j-2,m);

}


int main(){
	char *s = "abcTba";
	int n = lunghezza(s);
	int palindroma = verifica_palindroma(s,n,n/2);
	
	if(palindroma)
		printf("PALINDROMA\n");
	else printf("NON PALINDROMA\n");

}


