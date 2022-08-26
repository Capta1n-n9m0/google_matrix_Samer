#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>


int main(){
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();
    
	FILE*fa;
	FILE*fb;
	FILE*fc;
	fa=fopen("enwiki_te_node1ss.txt","r");
	fb=fopen("enwiki_te_node2ss.txt","r");
	fc=fopen("enwiki_te_selected_modified_index.txt","w");
	int node1,node2;
	while(!feof(fa) && !feof(fb)){
		fscanf(fa,"%d",&node1);
		fscanf(fb,"%d",&node2);
		fprintf(fc,"%d %d\n",node1,node2);
	}
    
    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
}
