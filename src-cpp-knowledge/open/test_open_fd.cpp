#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;

int main() {
    string filename = "text.txt";
    string filename1 = ".";
    string filename2 = "..";
    string filename_wrong = "text1.txt";
    int fd;
    fd = open(filename_wrong.c_str(), O_RDONLY, 0);

    if (fd < 0) {
        printf("open() error: key is not found.\n");
        exit(1);
    }


    struct stat file_info;
    int status;
    status = fstat(fd, &file_info);
    if (status == 0) {
        cout << "read stat of file" << filename_wrong << "successfully.\n";
        size_t file_len = file_info.st_size;
        time_t file_mtime = file_info.st_mtime;

        cout << "file len: " << file_len 
             << ", modified time: " << (intmax_t)file_mtime << endl;
    }

    return 0;
}