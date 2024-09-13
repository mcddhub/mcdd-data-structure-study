#ifndef MCDD_H
#define MCDD_H

typedef struct Mcdd {
    int id;
    char *name;
    char *img_url;
} Mcdd;

const char* parse_array(const char* json, Mcdd* items, int* count);

#endif
