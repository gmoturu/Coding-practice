#include <iostream>
#include <string>

using namespace std;

int main () {
	int home_addr, key2;
	unsigned int i;
	int asciival = 0;
	char symbolName[80];
	string key1, tmp;

	cout << "enter a string..\n";
	cin >> key1;
	cout << "enter an int ..\n";
	cin >> tmp;

//	tmp = key2;
	
//	strcpy(symbolName, key);

/*	for(i=0; i <= strlen(key.c_str()); i++)
	{
		asciival = asciival + key[i];
		cout << key[i] << "  " << asciival << "\n";
		
	}
	
	home_addr = asciival % (100);

	cout << "home_adr is.." << home_addr << "\n";
*/	
//	int r = strcmp(key1.c_str(), tmp.c_str());	
	if (key1 == tmp)
	cout << "the result is positive...\n";
	return 1;
}
