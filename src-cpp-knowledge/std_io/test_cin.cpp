#include <iostream>
using namespace std;
int main() {
	// char ch;
	// cout << "\nplease type in something: will use cin to process\n";
	// while (cin >> ch) {
	// 	cout << ch;
	// }

	// cout << "\nplease type in something: will use cin.get() to process\n";
	// while (cin.get(ch)) {
	// 	cout << ch;
	// }

	// char strBuf[11];
	// cin.get(strBuf, 11);
	// cout << strBuf << endl;

	// cin.get(strBuf, 11);
	// cout << strBuf << endl;

	// cin.getline(strBuf, 11);
	// cout << strBuf << endl;

	// cin.getline(strBuf, 11);
	// cout << strBuf << endl;

	// char strBuf[100];
	// cin.getline(strBuf, 100);
	// cout << strBuf << endl;
	// cout << cin.gcount() << " characters were read\n";

	string strBuf;
	getline(cin, strBuf);
	cout << strBuf << endl;

	return 0;
}