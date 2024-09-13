#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mcdd.h"

// 跳过空白字符
const char* skip_whitespace(const char* json) {
    while (*json == ' ' || *json == '\n' || *json == '\t' || *json == '\r') {
        json++;
    }
    return json;
}

// 获取字符串
const char* get_string_value(const char* json, char* buffer) {
    json = skip_whitespace(json);
    if (*json != '"') return NULL; // 错误：不是字符串
    json++;

    while (*json != '"') {
        *buffer = *json;
        buffer++;
        json++;
    }
    *buffer = '\0'; // 终止符
    json++; // 跳过末尾的引号
    return json;
}

// 获取数字值
const char* get_int_value(const char* json, int* value) {
    json = skip_whitespace(json);
    *value = atoi(json); // 转换为整数
    while (*json >= '0' && *json <= '9') {
        json++;
    }
    return json;
}

// 解析单个对象
const char* parse_object(const char* json, Mcdd* item) {
    json = skip_whitespace(json);
    if (*json != '{') return NULL; // 错误：不是对象
    json++; // 跳过左大括号

    char key[100];
    char value[1024];

    while (*json && *json != '}') {
        json = skip_whitespace(json);
        json = get_string_value(json, key);
        json = skip_whitespace(json);
        if (*json != ':') return NULL; // 错误：缺少冒号
        json++; // 跳过冒号

        if (strcmp(key, "id") == 0) {
            json = get_int_value(json, &(item->id));
        } else if (strcmp(key, "name") == 0) {
            json = get_string_value(json, value);
            item->name = strdup(value);
        } else if (strcmp(key, "img_url") == 0) {
            json = get_string_value(json, value);
            item->img_url = strdup(value);
        }

        json = skip_whitespace(json);
        if (*json == ',') json++; // 跳过逗号
    }

    json++; // 跳过右大括号
    return json;
}

// 解析数组
const char* parse_array(const char* json, Mcdd* items, int* count) {
    json = skip_whitespace(json);
    if (*json != '[') return NULL; // 错误：不是数组
    json++; // 跳过左方括号

    int idx = 0;
    while (*json && *json != ']') {
        json = parse_object(json, &items[idx]);
        idx++;
        json = skip_whitespace(json);
        if (*json == ',') json++; // 跳过逗号
    }

    json++; // 跳过右方括号
    *count = idx;
    return json;
}
