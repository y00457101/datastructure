#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************************************************************
 392. 判断子序列
 给定字符串 s 和 t, 判断 s 是否为 t 的子序列
 你可以认为 s 和 t 中仅包含英文小写字母.字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）
 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 示例 1: s = "abc", t = "ahbgdc"  返回 true.
 示例 2: s = "axc", t = "ahbgdc"  返回 false.
 示例 3: s = "aec", t = "abcdeg"  返回 false.
 */

/* 双指针解法 */
/* 大循环里能用变量的坚决不用变量表达式，重复计算很耗时 */
bool isSubsequence(char * s, char * t){
    int high = 0, low = 0;
    int lent = strlen(t); /* 字符长度计算放在循环外面 */
    int lens = strlen(s); /* 字符长度计算放在循环外面 */
    while (high < lent && low < lens) {
        if (t[high] == s[low]) {
            low++;
        }
        high++;
    }
    if (low == lens)
        return true;
    return false;
}
/* 
int main()
{
    char *s = "bfg";
    char *t = "abcdefg";
    bool ret = isSubsequence(s, t);
    return ret;
}
 *********************************************************************/
/*
  20. 有效的括号
  给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 */

/* 栈原理解法 */
bool isValid(char * s){
    bool ret = true;
    int len = strlen(s);
    if (!len) 
        return true;
    if (len % 2) 
        return false;

    char* stack = (char*)malloc(sizeof(char)*(len+1));
    memset(stack, 0, sizeof(char)*(len+1));  /* 这里将数字0转换为ASCII码为0的字符(空字符'\0'对应的ASCII码为0) */
    int i = 0, a = 0;
    while (s[i] != '\0') {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            a++;
            stack[a] = s[i];
        } else if (s[i] == stack[a]+1 || s[i] == stack[a]+2) {
            a--;
        } else {
            free (stack);
            return false;
        }
        i++;
    }

    if (a) 
        ret = false;
    free (stack);
    return ret;
}
/* 
int main()
{
    char *s = "()()";
    bool ret = isValid(s);
    return ret;
}
 *********************************************************************/
