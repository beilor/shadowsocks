#include <stdio.h>

int checkExpression(char *sExp);
int infixToSuffix(char *sExp);
int calculateSuffix(char *sExp);


/* 
检查输入的合法性。
    1. 数字前面带负号，负号和数字一起当作负数
    2. 数字后面一定接符号或者右括号
    3. 符号后面接数字或者左括号
    4，左右括号需要配对
*/
int checkExpression(char *sExp)
{

}
