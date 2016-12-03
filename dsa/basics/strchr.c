#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a sample string";
	char str1[10], str2[2];
	char * pch;

	strcpy(str1, "abcdef");
	strcat(str2, str1);
	printf("str %s %s \n", str1, str2);
	//strncpy(str2, str1, 5);
	printf("str %s %s \n", str1, str2);
	printf ("Looking for 's' character in \"%s\"...\n",str);
	pch=strchr(str,'s');
	while (pch!=NULL)
	{
		//printf ("found at %d\n",pch-str+1);
		pch=strchr(pch+1,'s');
	}
	return 0;
}
