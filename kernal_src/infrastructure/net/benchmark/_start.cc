
#include <iostream>
#include "poller.h"
#include "poller_thread.h"
#include "io_center.h"
#include "http_client.h"
#include "http_downloader.h"
#include "websocket.h"
#include <thread>
#include <vector>
#include "curl.h"
#include <stdio.h>
using namespace std;
using namespace cenarius;
using namespace infrastructure;
using namespace net;

class base {
public:
    virtual ~base() = 0;
};

class a1 : public base {

};

class a2 : public base {

};

class d : public a1, public a2 {

};

class s {
public:
    s() {
        printf("1\n");
    }

    s(s&&) {
        printf("1\n");
    }

    ~s() {
        printf("2\n");
    }
};

int main() {
    auto p = std::make_shared<poller_thread>();
    p->start();
    printf("%s %d\n", __FILE__, __LINE__);
    p->post([](poller* _poller) {
        printf("guodong \n");
    });

    
    auto _http_client = std::make_shared<
        http_client>("http://www.baidu.com");
    _http_client->start(p);
    
    for (int i = 0; i < 1; ++i) {
        auto ws = std::make_shared<websocket>("ws://10.90.182.72:9000");
        ws->start(p);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10000000000));

    printf("%s %d\n", __FILE__, __LINE__);
    return 0;
}



// size_t process_data(void *buffer, size_t size, size_t nmemb, void *user_p)
// {
// FILE *fp = (FILE *)user_p;
// size_t return_size = fwrite(buffer, size, nmemb, fp);
// cout << (char *)buffer << endl;
// return return_size;
// }
// int main(int argc, char **argv)
// {
// // 初始化libcurl
// CURLcode return_code;
// return_code = curl_global_init(CURL_GLOBAL_WIN32);
// if (CURLE_OK != return_code)
// {
// cerr << "init libcurl failed." << endl;
// return -1;
// }
// // 获取easy handle
// CURL *easy_handle = curl_easy_init();
// if (NULL == easy_handle)
// {
// cerr << "get a easy handle failed." << endl;
// curl_global_cleanup();
// return -1;
// }
// FILE *fp = fopen("data.html", "ab+"); //
// // 设置easy handle属性
// curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYPEER, 0L);//忽略证书检查
// curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYHOST, 0L);
// curl_easy_setopt(easy_handle, CURLOPT_URL, "https://www.qq.com/");
// curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &process_data);
// curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, fp);
// // 执行数据请求
// curl_easy_perform(easy_handle);
// printf("guodong \n");
// // 释放资源
// fclose(fp);
// curl_easy_cleanup(easy_handle);
// curl_global_cleanup();
// return 0;
// }