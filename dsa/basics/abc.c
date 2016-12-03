// my first program in C++

#include <stdio.h>
//using namespace std;

int main ()
{
	int a = ('a' & 0x0f);
	//cout << a;
	char IntString[] = "192";
	char HexString[10];
	int value;

	sscanf(IntString, "%d", &value);
	sprintf(HexString, "%X", value); 
	
	printf("a=%d, hex=%s", a, HexString);
	//cout << HexString;
   return 0;
}
