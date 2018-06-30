#ifndef _SW_H_
#define _SW_H_

#define RELEASED_LEVEL   1
#define PRESSED_LEVEL    0

typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED
}tSW_State;

void SW_Init(void);
void SW_Update(void);
tSW_State SW_GetState(void);

#endif // _SW_H_
