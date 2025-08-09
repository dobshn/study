#include <stdio.h>

char ASCII_table[128] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, ' ', '!', '\"', '#', '$', '%', '&', '\'',
    '(', ')', '*', '+', ',', '-', '.', '/', '0', '1',
    '2', '3', '4', '5', '6', '7', '8', '9',':', ';',
    '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
    'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
    'Z', '[', '\\', ']', '^', '_', '`', 'a' , 'b', 'c',
    'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z', '{', '|', '}', '~', 0};

int bin_to_int(const char *bin_str) {
    int result = 0; // 결과를 저장할 변수

    // 문자열이 끝에 도달하지 않았다면 반복
    while (*bin_str) {
        result <<= 1;

        if (*bin_str == '1')
            result |= 1;
        else if (*bin_str != '0')
            return -1; // 문자가 '1'이 아니고, '0'도 아닌 경우 잘못된 문자이므로 오류 반환
        
        bin_str++;
    }

    return result;
}

void test_bin_to_int(void) {
    const char *tests[] = {
        "0", "1", "10", "101", "11111111", "00001010", "2", "10a01"
    };
    int expected[] = {0, 1, 2, 5, 255, 10, -1, -1};

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        int result = bin_to_int(tests[i]);
        printf("입력: %-10s | 결과: %-4d | 기대값: %-4d %s\n",
               tests[i], result, expected[i],
               (result == expected[i]) ? "✅" : "❌");
    }
}

int main(int argc, char* argv[]) {
    // 인자로 받은 문자열들을 정수로 변환한 뒤,
    // 그에 해당하는 ASCII 값을 테이블에서 조회하여 출력
    int idx;
    for (int i = 1; i < argc; ++i) {
        idx = bin_to_int(argv[i]);
        putchar(ASCII_table[idx]);
    }
    putchar('\n');
    return 0;
}