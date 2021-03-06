/*
 * ================================
 * eli960@163.com
 * http://www.mailhonor.com/
 * 2015-10-20
 * ================================
 */

#include "zc.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void alarm_cb_normal(zalarm_t * alarm)
{
    zinfo("alarm_cb normal: %zd", time(0));
    zalarm_free(alarm);
}

void alarm_cb_ignore_free(zalarm_t * alarm)
{
    zinfo("alarm_cb ignore: %zd", time(0));
}

void alarm_cb_direct(zalarm_t * alarm)
{
    zinfo("alarm_cb direct: %zd", time(0));
}

void test_normal(void)
{
    zalarm_t *alarm;
    ztype_convert_t ct;
    int i;

    for (i = 0; i < 3; i++) {
        alarm = zalarm_create();
        ct.i_int = i;
        zalarm_set_context(alarm, ct.ptr_void);
        zalarm_set(alarm, alarm_cb_normal, (i + 1) * 5 * 1000);
    }
}

void ___env_fini(void)
{
    zalarm_env_fini();
}

int main(int argc, char **argv)
{
#if 0
    zalarm_set_lock();
#endif

#if 0
    zalarm_set_signal();
#endif
    zalarm_env_init();
    atexit(___env_fini);

    /* */
    zinfo("            now: %zd", time(0));

    /* */
    test_normal();

    /* */
    zalarm_t alarm_buf;
    zalarm_init(&alarm_buf);
    zalarm_set(&alarm_buf, alarm_cb_ignore_free, 5 * 1000);

    /* */
    zalarm(alarm_cb_direct, 0, 13 * 1000);

    while (1) {
        sleep(10);
    }

    return 0;
}
