#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ncurses.h>
#include <panel.h>
#include <ctype.h>

// Re-used constants
enum header_t {
	FILE_H = 0x0,
	DIR_H = 0x1
};

enum system_t {
	NORMAL = 0x0,
	QUIT = 0x1
};

enum privacy_t {
	ALL = 0x0,
	ADMIN = 0x1
};

enum limits_t {
	LINE_BUF_SIZE = 0x1000,
	NAME_BUF_SIZE = 0x1000
};

// Data structures
struct date {
    __uint8_t year;
    __uint8_t month;
    __uint8_t day;
    __uint8_t hour;
    __uint8_t min;
    __uint8_t sec;
};

struct item {
    size_t size;
    size_t nitem;
    char *name;
    char *path;
    char *contents;
    __uint8_t header;
    __uint8_t pstatus;
    struct date created;
    struct date modded;
    struct list *items;
    struct item *parent;
};

struct args {
	char **flags;
	int argc;
};

struct list {
    struct item *curr;
    struct list *next;
};

// System status variables
extern __uint8_t status;
extern WINDOW *window;

// parser.c functions
extern struct item *parser(char *);
extern struct args *flags(char *);

// window.c functions
extern void setup();
extern char *get();

// list.c functions
extern void sort(struct list *);
extern struct list *init(struct item *);
extern void append(struct list *, struct list *);

// dir.c functions
extern struct item *mkdir (struct item *, struct list *, char *);

#endif
