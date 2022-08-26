#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define n 7
#define alpha 0.85

float getG(int i, int j);
int * getPR();

int main() {
    float g = getG(2,2);
    printf("-- %f --\n", g);
    getPR();
    return 0;
}

float getG(int i, int j) {
    int n_out = 0;
    bool has_link = false;

    int node1, node2;
    FILE* links_file;

    links_file = fopen("test_data.txt", "r");
    while (!feof(links_file)) {
        node1 = -1; node2 = -1;
        fscanf(links_file,"%d %d",&node1,&node2);
        if(node1 != -1 && node2 != -1){
            if (i == node1) {
                n_out++;
                if (j == node2) {
                    has_link = true;
                }
            }
        }else fprintf(stderr, "fscanf failed\n");
    }
    fclose(links_file);

    float s;
    if (n_out)
    {
        if(has_link) {
            s = 1/(float)n_out;
        } else{
            s = (float)0;
        }
    } else {
        s = 1/(float)n;
    }
    float result = alpha * s + (1-alpha)/(float)n;
    return result;
}

int * getPR() {
    float *page_rank;
    page_rank = (float*)malloc(n * sizeof(float));

    float pr;
    float *prev_page_rank;
    prev_page_rank = (float*)malloc(n * sizeof(float));

    int node;
    int i;

    for (int c = 0; c < n;c ++) {
        prev_page_rank[c] = 1/(float)n;
    }
    
    for (int count = 0; count < 200; count++)
    {
        printf("iteration %d \n", count);
        for (int j = 0; j < n; j++)
        {
            pr = 0;
            for (int i = 0; i < n; i++)
            {
                pr += prev_page_rank[i] * getG(i+1, j+1);
            }
            printf("pr[%d] - %f \n", j, pr);
            page_rank[j] = pr;
        }
        prev_page_rank = page_rank;
    }

    for ( i = 0; i < n; i++)
    {
        printf("\nnode - %f", page_rank[i]);
    }
    return 0;
}