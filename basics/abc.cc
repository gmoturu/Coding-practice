// my first program in C++

#include <iostream>
using namespace std;

int main ()
{
	int a = ('a' & 0x0f);
	cout << a;
	char IntString[] = "192";
	char HexString[10];
	int value;
	
	cout << value;
	sscanf(IntString, "%d", &value);
	cout << value;
	sprintf(HexString, "%X", value); 
	cout << value;
   	cout << HexString;
	cout << a;
   return 0;
}
