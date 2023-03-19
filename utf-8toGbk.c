#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // 定义字符串最大长度

char* encode(char* str); // 声明转码函数

int main() {
    char str[MAX_LENGTH];
    printf("请输入需要转码的汉字字符串：\n");
    fgets(str, MAX_LENGTH, stdin); // 从标准输入读取字符串
    char* result = encode(str); // 调用转码函数
    printf("转码后的伪码字符串为：%s\n", result);
    free(result); // 释放动态分配的内存
    return 0;
}

char* encode(char* str) {
    int len = strlen(str);
    char* result = (char*)malloc(len * 6 + 1); // 伪码字符串最多比原字符串长6倍，动态分配内存
    int j = 0; // 记录伪码字符串的下标
    for (int i = 0; i < len; i++) {
        if (str[i] < 0) { // 如果是汉字
            sprintf(&result[j], "%04x", str[i] & 0xffff); // 转为16进制伪码
            j += 4;
        } else { // 如果是ASCII字符
            result[j] = str[i]; // 直接复制
            j++;
        }
    }
    result[j] = '\0'; // 结束字符串
    return result;
}