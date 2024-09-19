//
// Created by mcdd2024 on 2024/9/18.
//


#include <stdio.h>

/**
 ?* 统计一行字符中单词的个数 [其中单词之间用空格分开]
 ?* e.g. [在主函数中输入一行字符] 然后调用 [自定义函数],输出统计结果(即字符中单词的个数)
 *
 !* 分析：
 !* 1. 主函数内读取一行字符串(即字符串)并保存到变量中
 !* 2. 调用自定义函数
         参数列表 --> 字符串
         函数名 --> word_count (见名知意)
         返回值 int --> 字符串中单词的个数
    对应函数 int word_count(char* str)
    函数逻辑 因为单词之间是通过空格分开 --> 统计传入字符串中的空格个数 + 1 即为单词个数
 */

int word_count(char str[]);
int main() {
    char str[80];
    // 1. 读取一行字符串(即字符串)并保存到变量中
    printf("input:");
    fgets(str,sizeof(str),stdin);
    // 2. 调用自定义函数
    printf("%d",word_count(str));
    return 0;
}

/**
 * i am a student   \0
 * 统计 str 中单词的个数 (传入字符串中的空格个数 + 1 即为单词个数)
 * @param str 传入字符串
 * @return str 中单词的个数
 */
int word_count(char str[]) {
    int count = 0;
    int flag = 0;
    for (int i = 0; str[i] != '\0' ; i++) {
        if (str[i] == ' ') {
            flag = 0;
        }else if (flag == 0) {
            flag = 1;
            count++;
        }
    }
    return count;
}