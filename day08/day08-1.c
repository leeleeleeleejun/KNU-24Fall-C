#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
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

    printf("���ڿ��� �Է��ϼ���: ");
    scanf("%s", s1);
    int len = strlen(s1);

    for (int i = 0; i < len / 2; i++) {
        reverseFunc(&s1[i], &s1[len - 1 - i]);
    }

    printf("������ ���ڿ�: %s\n", s1);

    return 0;
}