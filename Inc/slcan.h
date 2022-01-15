#ifndef _SLCAN_H
#define _SLCAN_H

void slcan_processbuffer();
int8_t slcan_parse_frame(uint8_t *buf, CanRxMsgTypeDef *frame);
int8_t slcan_parse_str(uint8_t *buf, uint8_t len);

/* maximum rx buffer len: extended CAN frame with timestamp */
#define SLCAN_MTU 30// (sizeof("T1111222281122334455667788EA5F\r")+1)

#define serialbuffersize 100

#define SLCAN_STD_ID_LEN 3
#define SLCAN_EXT_ID_LEN 8

extern uint8_t serialbuffer[];
extern volatile uint8_t serialbufferstart;
extern volatile uint8_t serialbufferend;

#endif // _SLCAN_H
