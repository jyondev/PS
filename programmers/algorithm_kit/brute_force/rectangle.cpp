// Level 1, 최소직사각형
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int max = 0; int min = 0;
    for (size_t i = 0; i < sizes_rows; ++i) {
        int r = sizes[i][0];
        int c = sizes[i][1];
        if (r > c) {
            if (max < r) max = r;
            if (min < c) min = c;
        } else {
            if (max < c) max = c;
            if (min < r) min = r;
        }
    }
    int answer = min*max;
    return answer;
}