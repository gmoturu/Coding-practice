#include <iostream>
#include <string>
//#include <math>

using namespace std;

long bin2dec(char *s)
{
	long r=0;
	for (; *s; r = (r<<1) | (*s++ - '0'));
	return r;
} 

int hex2int(char *s)
{
	int n = 0, c;

	c = *s++;
	while(c != '\0') {
		if(c >= '0' && c <= '9') {
			n = n * 16 + (c - '0');
		} else {
			tolower(c);
			n = n * 16 + (c - 'a' + 10);
		}
		printf("%c %d \n", c, n);
		c = *s++;
	}

	return n;
}

int HexToInt(char *address,int length)
{
	/*
	int a=length,i=0,b,value=0;
//	int Hex_value[10];
	int var=0;
	int ctr=0;
//	char b;
	
	while(a--){
		b=(int)(address[i]<10)?(address[i]):(10+address[i]-'A');
		value+=b*pow(16,length-1);
	}

	while(decimal >=16)
	{
		Hex_value[ctr]=decimal%16;
		decimal=decimal/16;
		ctr++;
	}
	Hex_value[ctr]=decimal;
	for(int i=ctr;i>=0;i--)
	{
		var=var*0x10+Hex_value[i];
	}
	return var;
	char *hexaddress,*temp;
	int i,k,v;

	hexaddress = new char[length];
	temp = new char[length];
	for (i=0;address>=16;address/=16,i++)
		temp[i]=((v=address%16)<10)?(v+'0'):(v+'A'-10);
	temp[i++]=(address<10)?(address+'0'):(address+'A'-10);

	cout << "temp is...\n" << temp;
	if (i<=length)
	{
		for(k=i;k<length;k++) hexaddress[k-i]='0';
		for(k=length-i,i=i-1;i>=0;i--,k++) hexaddress[k]=temp[i];
	}
	else for(k=0;k<length;k++) hexaddress[k]='F';

//	hexaddress[k]='\0';

	return hexaddress;
*/

}

int main(){

	char *a = new char[4];
	char str[] = "1a";
	int num;

	//a = IntToHex(33,4);
	num = hex2int(str);
	a= "1A";
	//int num = HexToInt(a, 2);
	cout << "\nhex value is...\n" << str;
	cout << "\nvalue is...\n" << num;
//	cout << "the hex value is...\n" << IntToHex(3200,4);
}
