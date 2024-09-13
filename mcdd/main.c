#include <stdio.h>
#include <stdlib.h>
#include "mcdd.h"

#define JSON_FILE "mcdd.json"
#define MAX_JSON_SIZE 8192

// 从文件读取 JSON 内容
char* read_json_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("can not open file: %s\n", filename);
        return NULL;
    }

    // 移动到文件末尾获取文件大小
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    // 分配缓冲区以存储文件内容
    char* json_data = (char*)malloc(filesize + 1);
    if (json_data == NULL) {
        printf("malloc failture \n");
        fclose(file);
        return NULL;
    }

    // 读取文件内容到缓冲区
    fread(json_data, 1, filesize, file);
    json_data[filesize] = '\0'; // 确保以 NULL 结尾
    fclose(file);

    return json_data;
}

int main() {
    // 读取JSON文件
    char* json_data = read_json_file(JSON_FILE);
    if (json_data == NULL) {
        return 1;
    }

    Mcdd items[10]; // 假设最多有10个元素
    int count = 0;

    // 解析 JSON
    parse_array(json_data, items, &count);

    // 输出解析后的数据
    for (int i = 0; i < count; i++) {
        printf("id: %d, name: %s, img_url: %s\n", items[i].id, items[i].name, items[i].img_url);
    }

    // 释放动态分配的内存
    for (int i = 0; i < count; i++) {
        free(items[i].name);
        free(items[i].img_url);
    }
    free(json_data);

    return 0;
}
