#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_TOPPING 100000

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {

    int left_tops[MAX_TOPPING + 1] = { 0 }; // 철수가 먹는 토핑
    int right_tops[MAX_TOPPING + 1] = { 0 }; // 동생이 먹는 토핑
    int num_left = 0;  // 철수가 먹는 토핑 가지수
    int num_right = 0; // 동생이 먹는 토핑 가지수
    int num_fairs = 0; // 공평한 경우의 수

    // 동생이 모두 먹을 때 초기화
    for (int i = 0; i < topping_len; i++) {
        int top = topping[i];
        if (right_tops[top] == 0) num_right++; // 동생이 먹는 토핑 가지수 증가
        right_tops[top]++;
    }

    // 철수가 왼쪽부터 하나씩 토핑을 가져감
    for (int i = 0; i < topping_len; i++) {
        int top = topping[i];

        // 동생의 토핑 관리
        right_tops[top]--; // 동생이 하나 뺌
        if (right_tops[top] == 0) num_right--; // 동생이 먹는 토핑 가지수 감소

        // 철수의 토핑 관리
        if (left_tops[top] == 0) num_left++; // 철수가 먹는 토핑 가지수 증가
        left_tops[top]++;

        // 공평한 경우인지 확인
        if (num_left == num_right) num_fairs++;
    }

    return num_fairs;
}