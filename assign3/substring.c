#include <stdio.h>

int find_substring(const char *haystack, const char *needle){
	int i,j;

	if(needle[0]=='\0') return 0;
	
	for (i = 0; haystack[i] != '\0'; i++){
		j=0;

		while (needle[j] != '\0' && haystack[i+j] == needle[j] ){
			j++;
		}

		if (needle[j] == '\0' )
			return i;
	}
	return -1;
}

int main(){
    char haystack[100];
    char needle[100];

    printf("Enter the main string: ");
    fgets(haystack, sizeof(haystack), stdin);

    printf("Enter the substring: ");
    fgets(needle, sizeof(needle), stdin);

    int index = find_substring(haystack, needle);

    if (index == -1)
        printf("Substring not found\n");
    else
        printf("Substring found at index %d\n", index);

    return 0;
}
