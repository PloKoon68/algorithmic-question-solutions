#include <stdio.h>


int solve(int num);
int find(int border, int track, int sum, int expected, int start);
int powTen(int x);


void main()
{


    int testCases = 0;
    scanf("%d", &testCases);
    int results[testCases];

    for(int i = 0; i < testCases; i++) {
        int input;
        scanf("%d", &input);
        results[i] = solve(input);
    }

    for(int i = 0; i < testCases; i++)
        printf("%d\n", results[i]);

}

int solve(int num) {
    int sum = 0;
    int digit = 0;
    for(int i = 9; i > 0; i--) {
        sum += i;
        digit++;
        if(sum >= num)
            break;
    }

    return find(digit, 1, 0, num, 1);
}

                          //1      //0
int find(int border, int track, int sum, int expected, int start) {

    for(int i = start; i <= 9; i++) {
        sum += i;
        if(track < border) {
            int x = find(border, track + 1, sum, expected, i + 1);
            if(x >= 1)
                return (powTen(border - track) * i) + x;
        }
        else{
            if(sum == expected)
                return i;
        }

        sum -= i;
    }
    return 0;

}

int powTen(int x) {
    int result = 1;
    for(int i = 0; i < x; i++)
        result *= 10;
    return result;
}





