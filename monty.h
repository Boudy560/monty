#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct st_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct st_s
{
        int n;
        struct st_s *prev;
        struct st_s *next;
} st_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(st_t **stack, unsigned int line_number);
} instruction_t;

extern st_t *head;
typedef void (*op_func)(st_t **, unsigned int);

/* file operations */
void op_f(char *file_name);
int pa_l(char *buffer, int line_number, int format);
void re_f(FILE *);
int len_ch(FILE *);
void fi_fu(char *, char *, int, int);

/* Stack operations */
st_t *cr_no(int n);
void fr_no(void);
void pr_st(st_t **, unsigned int);
void add_to_st(st_t **, unsigned int);
void add_to_qu(st_t **, unsigned int);

void ca_f(op_func, char *, char *, int, int);

void pr_to(st_t **, unsigned int);
void po_to(st_t **, unsigned int);
void nop(st_t **, unsigned int);
void sw_no(st_t **, unsigned int);

/* Math operations with nodes */
void add_no(st_t **, unsigned int);
void su_no(st_t **, unsigned int);
void di_no(st_t **, unsigned int);
void mul_no(st_t **, unsigned int);
void mo_no(st_t **, unsigned int);

/* String operations */
void pri_ch(st_t **, unsigned int);
void pri_str(st_t **, unsigned int);
void rotl(st_t **, unsigned int);

/* Error handling */
void err(int error_code, ...);
void mo_er(int error_code, ...);
void str_err(int error_code, ...);
void rotr(st_t **, unsigned int);

#endif
