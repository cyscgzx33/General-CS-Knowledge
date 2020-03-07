#include <iostream>

using namespace std;

int main()
{
    /* Test 1: extraction operator (>>) skils whitespace (blanks, tabks, and newlines) */
    // char ch;
    // while (cin >> ch)
    //     cout << ch;
    /*
     * [Input]
     *  Hello my name is Yusen.
     * 
     * [Output]
     *  HellomynameisYusen.
     */

    /* Test 2: cin.get() */
    // char ch;
    // while (cin.get(ch))
    //     cout << ch;
    /*
     * [Input]
     *  Hello my name is Yusen.
     * 
     * [Output]
     *  Hello my name is Yusen.
     */

    /* Test 3: get() does not read in a newline character! */
    // char strBuf[11];
    // // Read up to 10 characters
    // cin.get(strBuf, 11);
    // cout << strBuf << endl;
 
    // // Read up to 10 more characters
    // cin.get(strBuf, 11);
    // cout << strBuf << endl;

    /*
     * If the user enters:
        Hello!

        The program will print:
        Hello!

        and then terminate! Why didn’t it ask for 10 more characters? 
        The answer is because the first get() read up to the newline and then stopped. The second get() saw there was still input in the cin stream and tried to read it. 
        But the first character was the newline, so it stopped immediately.
     */

    /* Test 4: getline() */

    return 0;
}