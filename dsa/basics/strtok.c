#include <stdio.h>
#include <string.h>

int main ()
{
	char tmp[50], opr, str[] ="This+is-a+sample+string-just+testing";
	char l1[10] = "=X'06'";
	
	char *ch = strtok(l1, "'");
	printf("\nch is...%s", ch);
	ch = strtok(NULL, "'");
	printf("\nch is...%s", ch);

	
	strcpy(tmp, str);
	int i=0, l=0, j;
	char * pch;
	printf ("\nSplitting string \"%s\" in tokens:\n",str);
	pch = strtok (str,"+-");
	j = strlen(tmp);
	while (pch != NULL)
	{
		printf ("\n%s\n",pch);
		l += strlen(pch);
		if(l+i < j)
		{
			opr = tmp[l+i];
			printf ("operator is...%c",opr);
		}
		i++;
		pch = strtok (NULL, "+-");
	}
	return 0;
}
