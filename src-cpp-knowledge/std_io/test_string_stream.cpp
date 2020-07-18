#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
	// stringstream os;
	// os << "en garde!\n";
	// cout << os.str();

	// stringstream os2;
	// os2.str("en garde2!");
	// cout << os2.str() << endl;

	// stringstream os;
	// os << "12345 67.89" << '\n';
	// cout << os.str();

	// stringstream os;
	// os << "12345 67.89";

	// string strValue;
	// os >> strValue;

	// string strValue2;
	// os >> strValue2;

	// cout << strValue << "---" << strValue2 << endl;

	/* Conversion from strings to numbers */
	// stringstream os;
	// int nValue{ 12345 };
	// double dValue{ 67.89 };
	// os << nValue << ' ' << dValue;

	// string strValue1, strValue2, strValue3;
	// os >> strValue1 >> strValue2; // equivalent to: os >> strValue1; os >> strValue2;
	// strValue3 = os.str(); // str() returns the whole value of the stream, even if the >> has already been used on the stream
	// cout << strValue1 << "---" << strValue2 << "---" << strValue3 << endl;


	/* Conversion from numbers to strings */
	// stringstream os;
	// os << "12345 67.89";
	// int nValue;
	// double dValue;

	// os >> nValue >> dValue; // os >> nValue; os >> dValue;

	// cout << nValue << "---" << dValue << endl;

	/* Clearing a stringstream */
	
	stringstream os;
	os << "Hello ";
	// method (1)
	// os.str(""); // erase the buffer using str() with a blank C-style string
	// method (2)
	os.str(string{}); // erase the buffer using str() with a blank std::string object
	
	// when clearing out a stringstream, it is also generally a good idea to call the clear() function
	os.clear(); // reset error flags
				// Note: clear resets any error flags that may have been set and returns the stream back to the ok state

	os << "World!\n";
	cout << os.str();

	return 0;
}