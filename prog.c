#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[1000];
	int a[1000], n[1000];

	scanf("%s", str);
	for(int i=0; i<strlen(str); i++){
		a[i] = toascii(str[i]);
	}
	int len=strlen(str), j=0, k=0;
	while(k<len){
		while(a[k]<=57 && a[k]>=48){
			n[j] = a[k] - 48;
			j++;
			k++;
		}
		if(a[k]== 43){
			n[j-2] = n[j-2] + n[j-1];
			k++;
			j=j-1;
		} else if(a[k] == 45){
			n[j-2] = n[j-2] - n[j-1];
			k++;
			j=j-1;
		} else if(a[k]== 42){
			n[j-2] = n[j-2]*n[j-1];
			k++;
			j=j-1;
		} else if(a[k]== 47){
			n[j-2] = n[j-2]/n[j-1];
			k++;
			j=j-1;
		} else if(a[k] == 37){
			n[j-2] = n[j-2]%n[j-1];
			k++;
			j=j-1;
		} else if(a[k]==126){
			n[j-1] = -1*n[j-1];
			k++;
		} else {
			printf("Error");
			k = len;
		}

	}
	
	printf("%d", n[0]);
	
	return 0;
}
