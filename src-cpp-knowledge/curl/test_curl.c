#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_BUF_SIZE 10

/* 
 * A sample downloadable picture:
 *     https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Nusfjord_road%2C_2010_09.jpg/1280px-Nusfjord_road%2C_2010_09.jpg
 */

struct memory {
    char *response;
    size_t size;
};

static size_t writeCallback(void *data, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)userp;

    char *ptr = realloc(mem->response, mem->size + realsize + 1);

    if(ptr == NULL) {
        printf("writeCallback: realloc() failed, out of memory!\n");
        return 0;  /* out of memory! */
    }
    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;
    printf("[curr size / total size] = %ld/%ld\n", realsize, mem->size);

    return realsize;
}

void testWriteFunc(char* web_url) {
    int res;
    CURL* curl;
    curl = curl_easy_init();
    long total_recv_len;
    long file_len;
    long recv_len;
    curl_easy_setopt(curl, CURLOPT_URL, web_url);
    struct memory chunk;

    /* init chunk */
    chunk.size = 0;
    chunk.response = malloc(INIT_BUF_SIZE * sizeof(int));

    /* get us the resource without a body - use HEAD! */
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // actually, no matter if there's this nobody, the getinfo will always get length

    /* Perform the request */
    res = curl_easy_perform(curl);
    if(!res) {
        /* check the size */
        curl_off_t cl;
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &cl);
        if(!res) {
            printf("Download size: %" CURL_FORMAT_CURL_OFF_T "\n", cl);
            file_len = cl;
        }
    }

    /* reset the NOBODY choice */
    curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);

    /* send all data to this function  */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

    /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

    total_recv_len = 0;
    printf("total_recv_len = %ld, file_len = %ld\n", total_recv_len, file_len);
    while (total_recv_len < file_len) {
        res = curl_easy_perform(curl);
        if (res != 0) {
            printf("perform error\n");
            break;
        }
        recv_len = chunk.size;
        if (recv_len <= 0) {
            printf("recv_len <= 0\n");
            break;
        }

        total_recv_len += recv_len;
        printf("total_recv_len = %ld\n", total_recv_len);
    }

    curl_easy_cleanup(curl);
}

void testNobody(char* file_path, char* web_url) {
    int res;
    CURL* curl;
    // FILE* fp;
    curl = curl_easy_init();
    // fp = fopen(file_path, "wb");
    curl_easy_setopt(curl, CURLOPT_URL, web_url);

    /* get us the resource without a body - use HEAD! */
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // actually, no matter if there's this nobody, the getinfo will always get length
    // curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    /* Perform the request */
    res = curl_easy_perform(curl);
    if(!res) {
        /* check the size */
        curl_off_t cl;
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &cl);
        if(!res) {
            printf("Download size: %" CURL_FORMAT_CURL_OFF_T "\n", cl);
        }
    }

    // fclose(fp);
    curl_easy_cleanup(curl);
}

void testWriteData(char* file_path, char* web_url) {
    CURL* curl;
    FILE* fp;
    int res;

    fp = fopen(file_path, "wb");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, web_url);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    res = curl_easy_perform(curl);

    if (res == CURLE_OK)
        printf("Download successfully!\n");
    else
        printf("Error: %s\n", curl_easy_strerror(res));

    fclose(fp);
    curl_easy_cleanup(curl);
}

int main(int argc, char** argv) {
    // testWriteData(argv[1], argv[2]);
    // testNobody(argv[1], argv[2]);
    testWriteFunc(argv[2]);
    return 0;
}