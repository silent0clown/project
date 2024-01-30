#include <stdio.h>
#include "mem_pool.h"



int main() {
    struct mp_pool_s *p = mp_create_pool(PAGE_SIZE);
    monitor_mp_poll(p, "create memory pool");
#if 0
    printf("mp_align(5, %d): %d, mp_align(17, %d): %d\n", MP_ALIGNMENT, mp_align(5, MP_ALIGNMENT), MP_ALIGNMENT,
           mp_align(17, MP_ALIGNMENT));
    printf("mp_align_ptr(p->current, %d): %p, p->current: %p\n", MP_ALIGNMENT, mp_align_ptr(p->current, MP_ALIGNMENT),
           p->current);
#endif
    void *mp[30];
    int i;
    for (i = 0; i < 30; i++) {
        mp[i] = mp_malloc(p, 512);
    }
    monitor_mp_poll(p, "申请512字节30个");

    for (i = 0; i < 30; i++) {
        mp_free(p, mp[i]);
    }
    monitor_mp_poll(p, "销毁512字节30个");

    int j;
    for (i = 0; i < 50; i++) {
        char *pp = mp_calloc(p, 32);
        for (j = 0; j < 32; j++) {
            if (pp[j]) {
                printf("calloc wrong\n");
                exit(-1);
            }
        }
    }
    monitor_mp_poll(p, "申请32字节50个");

    for (i = 0; i < 50; i++) {
        char *pp = mp_malloc(p, 3);
    }
    monitor_mp_poll(p, "申请3字节50个");


    void *pp[10];
    for (i = 0; i < 10; i++) {
        pp[i] = mp_malloc(p, 5120);
    }
    monitor_mp_poll(p, "申请大内存5120字节10个");

    for (i = 0; i < 10; i++) {
        mp_free(p, pp[i]);
    }
    monitor_mp_poll(p, "销毁大内存5120字节10个");

    mp_reset_pool(p);
    monitor_mp_poll(p, "reset pool");

    for (i = 0; i < 100; i++) {
        void *s = mp_malloc(p, 256);
    }
    monitor_mp_poll(p, "申请256字节100个");

    mp_destroy_pool(p);
    return 0;
}