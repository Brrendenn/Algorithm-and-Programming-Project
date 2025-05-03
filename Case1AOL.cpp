#include <stdio.h>
#include <string.h>

void revstring(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        } else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] += 'A' - 'a';
        }
    }
}

int main() {
    char str[101];
    int length = 0;
    int valid;
    do{
    	valid = 0;
  		scanf("%[^\n]", str);getchar();
  		length = strlen(str);
  		for(int i = 0;i < length;i++){
  			if((!(str[i] >= 'a' && str[i] <= 'z') && (!(str[i] >= 'A' && str[i] <= 'Z'))) && str[i] != ' '){
  				valid = 1;
  				break;
			  }
		  }
	}while(length < 1 || length > 100 || valid);
    revstring(str);
    printf("%s\n", str);
    return 0;
}

