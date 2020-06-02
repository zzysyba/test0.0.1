#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>

#define STUBCMD_SIZE 5
#define STUBFUN_MAX  0x10000

typedef struct stubitem
{
	void *org_funaddr;
	unsigned char org_cmdbuf[STUBCMD_SIZE];
}stubitem_t;

enum
{
	RT_STUB_FALSE = 0,
	RT_STUB_TRUE = 1,
};


enum
{
	RT_STUB_OK = 0,
	RT_STUB_ERR_NOT_INIT = 1,
	RT_STUB_ERR_NO_SPACE = 2,
	RT_STUB_ERR_INVAILD_PARAM = 3,
	RT_STUB_ERR_DUP_FUNC = 4,
	RT_STUB_ERR_DUP_INIT = 5,
	RT_STUB_NO_DESTRIY_BY_ORDER = 6,
};

static stubitem_t g_stubitems[STUBFUN_MAX];

static int is_module_init = RT_STUB_FALSE;


int rtstub_create2(void *func, void *stub, int *index)
{
	int i = 0;
	stubitem_t* p_stubitem = NULL;
	int pagesize = 0;
	unsigned long pfunaddr = 0;
	int offset = 0;
	int jmp_ilen = 5;
	int err = 0;

	if (is_module_init == RT_STUB_FALSE)
	{
		err = -RT_STUB_ERR_NOT_INIT;
		goto l_end;
	}
	if (func == stub)
	{
		goto l_end;
	}

	for(i = 0; i < STUBFUN_MAX; i++)
	{	
		if (NULL == g_stubitems[i].org_funaddr)
		{
			p_stubitem = &g_stubitems[i];
			p_stubitem->org_funaddr = func;
			*index = i;
			break;
		}
	}

	if(NULL == p_stubitem)
	{
		err = -RT_STUB_ERR_NO_SPACE;
		goto l_end;
	}

	memcpy(p_stubitem->org_cmdbuf, func, STUBCMD_SIZE);

	pagesize = sysconf(_SC_PAGE_SIZE);
	pfunaddr = (((unsigned long)func)/pagesize)*pagesize;
	mprotect((void*)pfunaddr, 2*pagesize, PROT_WRITE |PROT_READ |PROT_EXEC);
	offset = (unsigned char *)stub - (unsigned char*)func - jmp_ilen;
	((unsigned char*)func)[0] = 0xE9;
	memcpy(((unsigned char*)func) +1, &offset, jmp_ilen - 1);

l_end:
	assert(err == 0);
	return err;
}

int rtstub_destroy2(int index)
{
	int err = 0;

	if(is_module_init == RT_STUB_FALSE)
	{
		err = -RT_STUB_ERR_NOT_INIT;
		goto l_out;
	}

	if (index < 0 || index >= STUBFUN_MAX)
	{
		err = -RT_STUB_ERR_INVAILD_PARAM;
		goto l_out;
	}

	memcpy(g_stubitems[index].org_funaddr, g_stubitems[index].org_cmdbuf, STUBCMD_SIZE);
	memset(&g_stubitems[index], 0, sizeof(g_stubitems[index]));

l_out:
	assert(err == 0);
	return err;
}


int rtstub_create(void *func, void *stub)
{
	int index = 0;
	int i = 0;
	int err = 0;

	if(is_module_init == RT_STUB_FALSE)
	{
		err = -RT_STUB_ERR_NOT_INIT;
		goto l_out;
	}

	for(i = 0;i < STUBFUN_MAX; i++)
	{
		if(func == g_stubitems[i].org_funaddr)
		{
			err = -RT_STUB_ERR_DUP_INIT;
			goto l_out;
		}
	}
	err = rtstub_create2(func, stub, &index);

l_out:
	assert(err == 0);
	return err;

}



int rtstub_destroy(void *func)
{
	int i = 0;
	int err = 0;
	int count = 0;

	if(is_module_init == RT_STUB_FALSE)
	{
		err = -RT_STUB_ERR_DUP_INIT;
		goto l_end;
	}

	if(NULL == func)
	{
		goto l_end;
	}

	for(i = 0; i < STUBFUN_MAX; i++)
	{	

		if(func == g_stubitems[i].org_funaddr)
		{
			count++;


		}
	}

	assert(count  == 1);

	if(count > 1)
	{	
		printf("%d\n",count );
		err = -RT_STUB_NO_DESTRIY_BY_ORDER;
		goto l_end;
	}

	for(i = 0; i < STUBFUN_MAX; i++)
	{
		if(func != g_stubitems[i].org_funaddr)
		{
			continue;
		}
		err = rtstub_destroy2(i);
		break;
	}


l_end:
	assert(err == 0);

	return err;
}




int rtstub_begin(void)
{
	int err = 0;

	if(is_module_init == RT_STUB_TRUE)
	{
		err = -RT_STUB_ERR_DUP_INIT;
		goto l_out;
	}
	memset(g_stubitems, 0, sizeof(g_stubitems));
	is_module_init = RT_STUB_TRUE;

l_out:
	assert(err == 0);
	return 0;
}


int rtstub_end(void)
{
	int i = 0;
	int err = 0;

	if(is_module_init !=RT_STUB_TRUE)
	{
		err = -RT_STUB_ERR_NOT_INIT;
		goto l_out;
	}
	for (i = 0;i < STUBFUN_MAX; i++)
	{
		if (NULL == g_stubitems[i].org_funaddr)
		{
			continue;
		}
		printf("dsetroyed\n");
		memcpy(g_stubitems[i].org_funaddr,g_stubitems[i].org_cmdbuf, STUBCMD_SIZE);
		memset(&g_stubitems[i], 0, sizeof(g_stubitems[i]));
	}
	memset(g_stubitems, 0, sizeof(g_stubitems));
	is_module_init = RT_STUB_FALSE;

l_out:
	assert(err == 0);
	return err;
}
