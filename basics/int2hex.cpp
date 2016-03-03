#include <iostream>
using namespace std;

int convert_Integer(long int decimal)
{
	int Hex_value[10];
	int var=0;
	int ctr=0;

	        while(decimal >=16)
	        {
			cout << "in while loop\n";
	                Hex_value[ctr]=decimal%16;
	                decimal=decimal/16;
			cout << Hex_value[ctr] << "   " << decimal ;
		        ctr++;
		}
		Hex_value[ctr]=decimal;
			cout << Hex_value[ctr] << "   " << decimal << "  " << Hex_value;
			cout << "\n";
		for(int i=ctr;i>=0;i--)
		{
			cout << "in for loop ...\n";
		     //var=var*0x10+Hex_value[i];
		     var=var*10+Hex_value[i];
		     cout << Hex_value[i] << "   " << var;
		}
		return var;
}

int main() {

	int a = convert_Integer(64876984);

	cout << "the hex value is ..\n" << a;


    return 1;	
}
#include <iostream>
using namespace std;

char *IntToHex(int address,char length)
{
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

}

int main(){

	char *a = new char[10];
	a = IntToHex(64876984,10);
	cout << "\nhex value is..." << a;
//	cout << "the hex value is...\n" << IntToHex(3200,4);
}
