//
// Created by mcdd2024 on 2024/9/13.
//

#ifndef MCDD_H
#define MCDD_H

typedef struct Mcdd {
    int id;
    char *name;
    char *img_url;
}Mcdd;

void show_info(Mcdd mcdd);

Mcdd insert(Mcdd mcdd);

#endif //MCDD_H
