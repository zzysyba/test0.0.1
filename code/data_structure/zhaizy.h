#ifndef _ZHAIZY_H_
#define _ZHAIZY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define HASHSIZE                   12
#define NULLKEY                    -32768
#define MaxSize                    1024
#define TRUE                       1
#define FALSE                      0
#define OK                         1
#define ERROR                      0
#define INFEASIBLE                 -1
#define OVERKLOW                   -2
#define MAXSIZE                    100
#define ElemType                   int
#define LIST_INIT_SIZE             20       //线性表存储空间的初始分配量
#define LISTINCREMENT              10		 //线性表存储空间的分配增量
#define RED                        0    // 红色节点
#define BLACK                      1    // 黑色节点 
#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)




typedef int Type;
typedef int Status;
typedef int DataType;

#endif


