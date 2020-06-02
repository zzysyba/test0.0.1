#ifndef __INC_RT_STUB_H__
#define __INC_RT_STUB_H__



#endif 

extern int rtstub_create2(void *func, void *stub, int *index);
extern int rtstub_destroy2(int index);

extern int rtstub_create(void *func, void *stub);
extern int rtstub_destroy(void *func);

extern int rtstub_begin(void);
extern int rtstub_end(void);







