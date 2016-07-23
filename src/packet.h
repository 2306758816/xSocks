#ifndef PACKET_H
#define PACKET_H

#include "uv.h"


#define HEADER_BYTES    2
#define PRIMITIVE_BYTES 24
#define OVERHEAD_BYTES  26
#define MAX_PACKET_SIZE 2048

#define PACKET_COMPLETED  0
#define PACKET_INVALID    1
#define PACKET_UNCOMPLETE 2


struct packet {
    int read;
    uint16_t offset;
    uint16_t size;
    uint16_t max;
    uint8_t buf[MAX_PACKET_SIZE];
};

void packet_alloc(struct packet *packet, uv_buf_t *buf);
int packet_filter(struct packet *packet, const char *buf, ssize_t buflen);
void packet_reset(struct packet *packet);

#endif // for #ifndef PACKET_H
