#include <stdio.h>
#include <string.h>
#include <time.h>


int main(){
    int node1, node2, i;
    int lines = 0;
    double time_spent = 0.0;
    FILE *fIn = fopen("nodes1.txt", "r");

    fseek(fIn, 866117212-9*3, SEEK_CUR);
    puts("Test!");
    char buf[256] = {0};
    while (!feof(fIn)){
        fgets(buf, 255, fIn);
        printf(buf);
        memset(buf, 0, 1);
    }

    fclose(fIn);
}