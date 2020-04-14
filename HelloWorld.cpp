#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
#define MAX_SIZE 8

int sorted[MAX_SIZE];
// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    //합병
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    //남아있는 값들 일괄 복사
    if (i > mid)
    {
        for (l = j; l <= right; l++)
        {
            sorted[k++] = list[l];
        }
    }
    //남아있는 값들 일괄 복사
    else
    {
        for (l = i; l <= mid; l++)
        {
            sorted[k++] = list[l];
        }
    }

    //임시 배열의 값들을 원래 배열로 복사.
    for (l = left; l <= right; l++)
    {
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main()
{
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = {21, 10, 12, 20, 25, 13, 15, 22};

    merge_sort(list, 0, n - 1); //right는 닫힌 구역으로 넘긴다.

    for (i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}