/*
 * ================================
 * eli960@qq.com
 * http://linuxmail.cn/
 * 2020-02-04
 * ================================
 */

#include <openssl/ssl.h>
#include <openssl/err.h>
#include "zc.h"

typedef void (*cmd_fn_t)(zhttpd_t * httpd);

typedef struct _service_info_t _service_info_t;
struct _service_info_t {
    const char *service_name;
    int fd;
    int fd_type;
    /* int is_ssl; */
    /* ...; */
};

SSL_CTX *var_openssl_server_ctx = 0;

static void httpd_handler(zhttpd_t *httpd)
{
    /* 第一部分, 处理请求数据 */
#if 0
    /* 请求的方法: GET/POST/... */
    const char *zhttpd_request_get_method(zhttpd_t *httpd);

    /* 请求的主机名 */
    const char *zhttpd_request_get_host(zhttpd_t *httpd);

    /* 请求的url路径 */
    const char *zhttpd_request_get_path(zhttpd_t *httpd);

    /* 等等 */

    /* url queries, 解析后 */
    const zdict_t *zhttpd_request_get_query_vars(zhttpd_t *httpd);

    /* post queries, 解析后 */
    const zdict_t *zhttpd_request_get_post_vars(zhttpd_t *httpd);

    /* cookies, 解析后 */
    const zdict_t *zhttpd_request_get_cookies(zhttpd_t *httpd);

    /* 获取全部上传文件的信息 */
    const zvector_t *zhttpd_request_get_uploaded_files(zhttpd_t *httpd); /* zhttpd_uploaded_file * */

    /* 等等 */
#endif



    /* 第二部分, 输出 */
#if 0
    /* 输出, 设置cookie */
    zhttpd_response_header_set_cookie;

    /* 输出, 自定义头 */
    zhttpd_response_header;
#endif
    
    zhttpd_response_200(httpd, "welcome", 7);

#if 0
    /* 或者 */
    zhttpd_response_404(httpd);

    /* 或者 */
    zhttpd_response_304(httpd);
    
    /* 或者 */
    zhttpd_response_500(httpd);
    /* 等等 */
#endif

#if 0
    /* 或者, 输出一个文件 */
    void zhttpd_response_file(zhttpd_t *httpd, const char *pathname, const char *content_type, int max_age);
#endif

#if 0
    /* 或者, 通过API 输出 */
    void zhttpd_response_header;
    void zhttpd_response_header_content_length;
    void zhttpd_response_header_date;
    void zhttpd_response_header_over;
    /* header over 了 */
    void zhttpd_response_write;
#endif

#if 0
    /* 或者, 直接输出原始数据  */
    void zhttpd_response_write(zhttpd_t *httpd, const void *data, int len);
#endif
}

static void *_do_httpd(void *arg)
{
    _service_info_t *info = (_service_info_t *)arg;
    int fd = info->fd;
#if 0
    const char *service_name = info->service_name;
#endif
    zhttpd_t *httpd;
    int is_ssl = 0;

    /* 通过 service_name判定是不是SSL, 或者 */
    /* 在register_service阶段判断, 通过info把结果传过来 */
    if (is_ssl) {
        /* 先用默认的SSL_CTX(如:var_openssl_server_ctx)创建SSL */
#if 0
        /* 如果需要根据域名切换证书(SNI), 则需要提前执行 */
        void zopenssl_SSL_CTX_support_sni(SSL_CTX *ctx, SSL_CTX *(*get_ssl_ctx_by_server_name)(const char *servername));
#endif
        SSL *ssl = zopenssl_SSL_create(var_openssl_server_ctx, fd);
        if (zopenssl_timed_accept(ssl, 10, 10) < 1) {
            /* 如果SSL握手失败 */
            if (1) {
                int ip = 0, port = 0;
                char ipstr[18];
                if (zget_peername(fd, &ip, &port) > 0)  {
                    zget_ipstring(ip, ipstr);
                } else {
                    ipstr[0] = '0';
                    ipstr[1] = 0;
                }
                char error_buf[1024];
                zopenssl_get_error(0, error_buf, 1024);
                zinfo("SSL handshake error with %s:%d, %s", ipstr, port, error_buf);
            }
            zopenssl_SSL_free(ssl);
            return 0; 
        }
        /* 创建 httpd 对象 */
        httpd = zhttpd_open_ssl(ssl);
    } else {
        /* 创建 httpd 对象 */
        httpd = zhttpd_open_fd(fd);
    }

    /* 下面设置httpd处理函数 */

    /* 设置命令GET/POST/PUT的处理函数 */
    zhttpd_set_handler(httpd, httpd_handler);

#if 0
    /* 设置其他命令的处理函数 */
    void zhttpd_set_HEAD_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
    void zhttpd_set_OPTIONS_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
    void zhttpd_set_DELETE_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
    void zhttpd_set_TRACE_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
    void zhttpd_set_PATCH_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
#endif

#if 0
    /* 设置默认的200,304,404,500,501等的处理函数 */
    void zhttpd_set_200_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd, const char *data, int size));
    void zhttpd_set_304_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd, const char *etag));
    void zhttpd_set_404_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
    void zhttpd_set_500_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
    void zhttpd_set_501_handler(zhttpd_t *httpd, void (*handler)(zhttpd_t * httpd));
#endif

#if 0
    /* 是否支持 multipart/form-data */
    zhttpd_enable_form_data(httpd);
#endif

    /* httpd 协议处理 */
    zhttpd_run(httpd);

    /* httpd协议终止, close */
    zhttpd_close(httpd, 1);

    zfree(info);

    return 0;
}

static void *_do_accept(void *arg)
{
    _service_info_t *info = (_service_info_t *)arg;
    int sock = info->fd;

    while (1) {
        /* 等待 socket(sock) 可读 */
        ztimed_read_wait(sock, 10);

        /* accept */
        int fd = zaccept(sock, info->fd_type);
        if (fd < 0) {
            if (errno == EAGAIN) {
                continue;
            }
            zfatal("accept: %m");
        }

        _service_info_t *new_info = (_service_info_t *)zcalloc(1, sizeof(_service_info_t));
        new_info->service_name = info->service_name;
        new_info->fd = fd;
        new_info->fd_type = fd;
#if 1
        /* 在本线程启用协程做处理 */
        zcoroutine_go(_do_httpd, new_info, -1);
#else 
        /* 也可以考虑在其他线程的协程环境处理 */
        zcoroutine_advanced_go(other_coroutine_base, _do_httpd, new_info, -1);
#endif
    }

    zfree(info->service_name);
    zfree(info);
    return arg;
}


static void ___before_service()
{
    /* 具体服务启动前, 需要执行的代码 */
    /* 这个时候服务器框架已经加载好了配置*/

    /* 一般情况,是做一些准备工作 */
    /* 如: 可以处理配置 */
    /* 如: 初始化SSL, var_openssl_server_ctx */
    /* 如: 可以启动几个线程, 每个线程都启动线程环境, 做线程池使用 */
}

static void ___before_softstop()
{
    /* 服务管理器(master)通知本进程软退出后, 需要执行的代码 */
}

static void ___service_register(const char *service_name, int fd, int fd_type)
{
    /* 根据 service_name启动相应的具体服务 */

#if 1
    /* 如果service_name是httpd类型, 则 */
    _service_info_t *info = (_service_info_t *)zcalloc(1, sizeof(_service_info_t));
    info->service_name = zstrdup(service_name);
    info->fd = fd;
    info->fd_type = fd_type;
    /* 在本线程启用一个新的协程 */
    zcoroutine_go(_do_accept, info, -1);
#else 
    /* 如果 service_name是其他服务类型(不是httpd), 则启用相关的代码 */
#endif
}

int main(int argc, char **argv)
{
#if 1
    /* 如果启用 zcoroutine_server_main 架构 */
    zcoroutine_server_before_service = ___before_service;
    zcoroutine_server_before_softstop = ___before_softstop;
    zcoroutine_server_service_register = ___service_register;
    zcoroutine_server_main(argc, argv);
    return 0;
#endif

#if 0
    /* 一般的协程环境服务器 */

    signal(SIGPIPE, SIG_IGN);

    /* 初始化 */
    /* ... */

    /* 协程环境初始化*/
    zcoroutine_base_init();

    int fd_type, type;
    const char *listen_address;
    fd = zlisten(listen_address, &fd_type, 5);

    _service_info_t *info = (_service_info_t *)zcalloc(1, sizeof(_service_info_t));
    info->service_name = "";
    info->fd = fd;
    info->fd_type = fd_type;

    zcoroutine_go(_do_accept, info, -1);

    /* 协程环境运行 */
    zcoroutine_base_run(0);

    zclose(fd);

    /* 协程环境完毕 */
    zcoroutine_base_fini();

    return 0;
#endif
}
