#include <stdio.h>
#include <stdlib.h>
#define Neww(x) (x*)malloc(sizeof(x))

typedef struct Job {
    char id;
    int dead;
    int profit;
} Job;

void print_slot(char time_slot[], int dmax) {
    printf("slot: \t");
    for (int i = 0; i < dmax; i++) {
        printf("%c", time_slot[i]);
        if (i < dmax - 1)
            printf("->");
    }
    printf("\n");
}

void swap(Job* j1, Job* j2) {
    Job tmp = *j1;
    *j1 = *j2;
    *j2 = tmp;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

void print_seq(Job arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c %d %d\n", arr[i].id, arr[i].dead, arr[i].profit);
}

int get_dmax(Job job[], int n) {
    int max = job[0].dead;
    for (int i = 1; i < n; i++)
        if (max < job[i].dead)
            max = job[i].dead;
    return max;
}

void sort(Job arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_idx].profit < arr[j].profit)
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void find_seq(Job job[], int n) {
    int dmax = get_dmax(job, n);
    int cost = 0;
    sort(job, n);

    char time_slot[dmax];
    for (int i = 0; i < dmax; i++)
        time_slot[i] = '\0';

    for (int i = 0; i < n; i++) {
        int k = min(dmax, job[i].dead - 1);
        while (k >= 0) {
            if (time_slot[k] == '\0') {
                time_slot[k] = job[i].id;
                cost += job[i].profit;
                break;
            } else
                k--;
        }
    }
    print_slot(time_slot, dmax);
    printf("cost: \t%d\n", cost);
}

int main() {
    Job jobs[] = {{'a', 2, 100},
                  {'d', 1, 27},
                  {'c', 2, 15},
                  {'b', 1, 10}};

    int n = sizeof jobs / sizeof jobs[0];
    // print_seq(jobs, 4);
    find_seq(jobs, n);
}
