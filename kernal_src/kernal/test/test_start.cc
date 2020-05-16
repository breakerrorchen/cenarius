
#include "test_start.h"
#include "infrastructure/net/include/io_center.h"
#include "infrastructure/net/include/http_client.h"
#include "infrastructure/net/include/http_downloader.h"
#include "infrastructure/net/include/websocket.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

void _test_network() {
    auto p = std::make_shared<poller_thread>();
    p->start();
    p->post([](poller* _poller) {
        __log("guodong\n");
    });
    //auto c = io_center::get_instance();
    auto _http_client = std::make_shared<
        http_client>("http://www.baidu.com");
    _http_client->start(p);
    // __log("guodong start wait\n");

    // for (int i = 0; i < 10000; ++i) {
    //     auto downloader = std::make_shared<
    //         http_downloader>("https://qd.myapp.com/myapp/qqteam/pcqq/PCQQ2020.exe");
    //     auto cancel = downloader->start(p);
    // }
    for (int i = 0; i < 1; ++i) {
        auto ws = std::make_shared<websocket>("ws://192.168.8.125:9000");
        ws->start(p);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10000000000));
}

void cenarius::kernal::test::_start_test() {
    _test_network();
}