#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_TOPPING 100000

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {

    int left_tops[MAX_TOPPING + 1] = { 0 };
    int right_tops[MAX_TOPPING + 1] = { 0 }; 
    int num_left = 0; 
    int num_right = 0; 
    int num_fairs = 0;

    for (int i = 0; i < topping_len; i++) {
        int top = topping[i];
        if (right_tops[top] == 0) num_right++;
        right_tops[top]++;
    }

    for (int i = 0; i < topping_len; i++) {
        int top = topping[i];

        right_tops[top]--;
        if (right_tops[top] == 0) num_right--;

        if (left_tops[top] == 0) num_left++;
        left_tops[top]++;

        if (num_left == num_right) num_fairs++;
    }

    return num_fairs;
}