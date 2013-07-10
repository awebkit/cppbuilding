#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <pthread.h>
#include <types.h>
#include <list.h>

#define MAX_SHM_SIZE         (0x00200000)
#define MIN_SHM_SIZE         (0x00100000)
#define MAX_MESSAGE_ENTRY    (32)

struct message;
enum MSG_ID msg;
struct message_core;

typedef int(*msg_handle)(enum MSG_ID msg, struct message *);

enum MSG_ID{
    MSG_ID_DISCV = 0,
    MSG_ID_CONNECT,
    MSG_ID_IMAGE,
    MSG_ID_SYSTEM_INFO,
    MSG_ID_AP_CONFIG,
    MSG_ID_EVENT,
    MSG_ID_END,
};

struct message_discv{
};

struct message_connect{
    u8 name[16];
    u8 ip[16];
    u32 port;
};

struct message_image{
    u32 type; //
    u32 bits;

    u32 x;
    u32 y;
    u32 width;
    u32 height;

    u8 data[0];
};

struct message_system_info{
    u32 xres;
    u32 yres;
};

struct message_ap_config{
    u8 ssid[32];
    u32 wirelessmode;
    u32 channel;
    u32 authmode;
    u8  passwd[32];
};

struct message_event{
};

struct message{
    enum MSG_ID msg;

    u32 msg_len;
    void *payload;
};

struct message_tcb{
    struct list_head head;

    u32 id;
    unsigned long long timestamp;
    struct message *msg;
    void *context;
    int (*notify)(struct message_tcb *, void *);
};

struct message_queue_operation{
};

struct message_queue{
    struct list_head head;
    pthread_mutex_t lock;

    struct message_queue_operation *op;
};

struct message_handle{
    enum MSG_ID msg;
    char *name;
    msg_handle handle;
};

struct message_core{
    u32 running_flags;
    struct message_tcb   msg_tcb_pool[MAX_MESSAGE_ENTRY];
    struct message_queue send_queue;
    struct message_queue recv_queue;
    pthread_t send_pid;
    pthread_t recv_pid;

    struct message_handle *msg_handle;
};

int init_message_core(struct message_core *);
int remove_message_core(struct message_core *);

int register_message_handle(struct message_core *, enum MSG_ID, msg_handle, void *);
int unregister_message_handle(struct message_core *, enum MSG_ID);

#endif //__MESSAGE_H__
