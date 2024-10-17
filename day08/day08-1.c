#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>

void reverseFunc(char* pnum1, char* pnum2) {
    char temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
}

int main() {
    char s1[100]; 
    int *p = s1;

    printf("문자열을 입력하세요: ");
    scanf("%s", s1);
    int len = strlen(s1);

    for (int i = 0; i < len / 2; i++) {
        reverseFunc(&s1[i], &s1[len - 1 - i]);
    }

    printf("뒤집힌 문자열: %s\n", s1);

    return 0;
}