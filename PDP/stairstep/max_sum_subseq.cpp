#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 1000000

int i, j, a, numbers[MAXN];
int n;
long sum=0;

void Read(){
    for (i=1; i<n+1; i++){
        scanf("%d", &a);
        numbers[i] = a;
    }
}


void custom(){
    for (i=0; i<n; i++){
        /*if (numbers[i+1] == 0)
            break;*/

        if (numbers[i+1] > 0 ) //�� ������� ����� ������
            sum += numbers[i+1];
        else{ // �� ������� ���������
            if (numbers[i+1] > numbers[i+2]) // dodgare ��� ��� ��������
                sum += numbers[i+1];
            else{
                sum += numbers[i+2];
                i++; // ��������� �� ����
            }
        }
    }
        //printf("%d\n", sum); // monitor ��� sequence
}
//}

int main(){
    scanf("%d", &n);
    numbers[0] = 0;
    numbers[n+1] = 0;

    Read();
    custom();

    printf("%d\n", sum);

    return 0;
}
