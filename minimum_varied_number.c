/*       Question:
Find the minimum number with the given sum of digits s such that all digits in it are distinct (i.e. all digits are unique).

For example, if s=20, then the answer is 389. This is the minimum number in which all digits are different and the sum of the digits is 20 (3+8+9=20).

For the given s print the required number.

Input
The first line contains an integer t (1≤t≤45) — the number of test cases.

Each test case is specified by a line that contains the only integer s (1≤s≤45).

Output
Print t integers — the answers to the given test cases.


example:
input:
    -4
    -20
    -8
    -45
    -10

output:
    -389
    -8
    -123456789
    -19
*/


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





/*   The python version of this code:


from replit import clear
import random


def solve(num):
    sum = 0
    digit = 0
    for i in range(9, 0, -1):
        sum += i
        digit += 1
        if sum >= num:
            break

    return find(digit, 1, 0, num, 1)


def find(border, track, sum, expected, start):

    for i in range(start, 10):
        sum += i
        if track < border:
            x = find(border, track + 1, sum, expected, i + 1)
            if x >= 1:
                return (powTen(border - track) * i) + x
        else:
            if sum == expected:
                return i
        sum -= i

    return 0


def powTen(x):
    result = 1
    for i in range(0, x):
        result *= 10
    return result


testCases = int(input())

results = []

for i in range(0, testCases):
    num = int(input())
    results.append(solve(num))

clear()

for result in results:
    print(result)

*/



