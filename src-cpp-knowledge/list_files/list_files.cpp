/**
 * Reference:
 *   - http://www.martinbroadhurst.com/list-the-files-in-a-directory-in-c.html
 */

#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void read_directory(const string& name, vector<string>& v) {
    DIR* dirp = opendir(name.c_str());
    struct dirent* dp;
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}

int main() {
    vector<string> files;
    string addr = "/home/yusen/shared_dir/git/pr4/mnt/server/sample-files";
    read_directory(addr, files);
    for (auto file : files) {
        cout << file << "\n";
    }

    return 0;
}