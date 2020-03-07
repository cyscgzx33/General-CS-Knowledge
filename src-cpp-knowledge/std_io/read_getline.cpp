#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> str_vec;
    // for (std::string line; std::getline(std::cin, line);) {
    //     str_vec.push_back(line);
    // }

    string line;
    while (std::getline(std::cin, line)) 
        str_vec.push_back(line);

    // type in 'EOF' by keyboard: (Mac/linux) Ctrl + D
    //                            (Windows) Ctrl + Z

    cout << "Cout whatever the user has typed in: \n";
    for (auto str : str_vec)
        cout << str << "\n";

    return 0;
}