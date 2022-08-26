#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
/***
 * author:samer
 * domain: google matrix
 * calculation of pagerank
 * we need only the txt of the network
 * it works with all datasets
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>

#define alpha 0.85


typedef struct node node;
struct node {
    int count; //outlinks
    int index; // id - number of node
    int *point; // array outgoing links
    struct node *next;
};
typedef node *List;

void add(List *list, int value) {
    node *newnode = (node *) malloc(sizeof(node));
    newnode->index = value;
    newnode->count = 0;
    newnode->next = *list;
    *list = newnode;
}

void countnodes(List *list) {
    int index, i, read, oldNodeCount;
    int node11 = 1;
    int nodeCount = 0;
    FILE *fInNodes;
    fInNodes = fopen("nodes1.txt", "r");
    List tmp = *list;
    while (!feof(fInNodes)) {
        fscanf(fInNodes, "%d", &index);
        if(index != -1) {
            read = index - node11;
            switch (read) {
                // index and node11 are equal
                case 0:
                    nodeCount++;
                    break;
                    // index and node11 are different
                default:
                    //progress tracker
                    if (node11 % 100000 == 0 && node11 > 0) {
                        printf("\ncounting %d\n", node11);
                    }
                    // find the that we were counting for
                    while (tmp->index < node11) {
                        tmp = tmp->next;
                    }
                    // when we find it, set the count for it and allocate memory for all the outgoing nodes
                    if (tmp->index == node11) {
                        tmp->count = nodeCount;
                        //printf("count[%d] = %d \n",tmp->index,nodeCount);
                        tmp->point = malloc(nodeCount * sizeof(int));
                        for (i = 0; i < nodeCount; i++) {
                            tmp->point[i] = 0;
                        }
                    }
                    // save the old node count and set new one to 1
                    oldNodeCount = nodeCount;
                    nodeCount = 1;
            }
        } else fprintf(stderr, "fscanf failed!\n");
        // if node11 and index were different, node11 will take new value
        node11 = index;
        index = -1;
    }
    tmp = tmp->next;
    //tmp=tmp->next; //when before the last node11 is a dangling node11 you make two next
    //tmp=tmp->next; //when before the last node11 there is two dangling node11 you make another next
    tmp->count = nodeCount;
    //printf("count[%d] = %d \n",tmp->index,oldNodeCount);
    tmp->point = malloc(nodeCount * sizeof(int));
    for (i = 0; i < nodeCount; i++) {
        tmp->point[i] = 0;
    }
    fclose(fInNodes);
}

void creath(List *liste) {
    List tmp = *liste;
    int node1, node2, j;
    FILE *fa;
    fa = fopen("test_data.txt", "r");
    while (!feof(fa)) {
        fscanf(fa, "%d %d", &node1, &node2);
        if(node1 != -1 && node2 != -1) {
            while (tmp->index != node1) {
                tmp = tmp->next;
                j = 0;
            }
            tmp->point[j] = node2;
            j++;
        } else fprintf(stderr, "fscanf failed\n");
        node1 = -1; node2 = -1;
    }
}

double calcul(List *liste, double *u, double *v, double x) {
    List tmp = *liste;
    while (tmp != NULL) {
        if (tmp->count == 0) {
            x += (double) alpha * u[tmp->index - 1];
        } else {
            for (int i = 0; i < tmp->count; i++) {
                v[tmp->point[i] - 1] += (double) alpha * u[tmp->index - 1] / (double) (tmp->count);
            }
        }
        tmp = tmp->next;
    }
    return (x);
}

int main() {

    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    int node1, node2, i;
    int lines = 0;
    const int lines_threshold = 200000;
    //calculating number of lines//
    // TODO: <counting lines>
    puts("<counting lines>");
    {
        FILE *fIn;
        FILE *fOut1;
        FILE *fOut2;
        fIn = fopen("test_data.txt", "r");
        fOut1 = fopen("nodes1.txt", "w");
        fOut2 = fopen("nodes2.txt", "w");
        clock_t counting_lines_clock_s = clock();
        clock_t counting_lines_clock_l = clock();
        while (!feof(fIn)) {
            fscanf(fIn, "%d %d", &node1, &node2);
            if(node1 != -1 && node2 != -1) {
                fprintf(fOut1, "%d\n", node1);
                fprintf(fOut2, "%d\n", node2);
                lines++;
                if (lines % lines_threshold == 0 && lines != 0) {
                    double ms = ((double) (clock() - counting_lines_clock_s) / CLOCKS_PER_SEC) * 1000;
                    printf("%d: %d %d; %d lines in %g ms\n", lines, node1, node2, lines_threshold, ms);
                    counting_lines_clock_s = clock();
                }
            } else fprintf(stderr, "fscanf failed!");
            node1 = -1; node2 = -1;
        }
        lines = lines - 1; //it should be lines but while dealing with cambridge it seems there are something ...//
        fclose(fIn);
        fclose(fOut1);
        fclose(fOut2);
        double ms = ((double) (clock() - counting_lines_clock_l) / CLOCKS_PER_SEC) * 1000;
        printf("number of pointers = %d; done in %g ms\n", lines, ms);
        //finish calculation//
    }
    puts("</counting lines>");
    // TODO: </counting lines>

    //finding number of nodes/
    // TODO: <finding number of nodes>
    puts("<finding number of nodes>");
    int Max = 0;
    {
        int No;
        FILE *fInLinks;
        puts("in nodes2.txt");
        fInLinks = fopen("nodes2.txt", "r");
        //find maximum
        // it does not matter if fscanf fails here
        for (i = 0; i < lines; i++) {
            fscanf(fInLinks, "%d", &No);
            if (No > Max)
                Max = No;
            if (i % lines_threshold == 0 && i != 0){
                printf("%d: No = %d, Max = %d\n", i, No, Max);
            }
        }
        printf("Maximum in nodes2.txt: %d\n", Max);
        fclose(fInLinks);
        FILE *fInNodes;
        puts("in nodes1.txt");
        fInNodes = fopen("nodes1.txt", "r");
        for (i = 0; i < lines; i++) {
            fscanf(fInNodes, "%d", &No);
            if (No > Max)
                Max = No;
            if (i % lines_threshold == 0 && i != 0){
                printf("%d: No = %d, Max = %d\n", i, No, Max);
            }
        }
        printf("Maximum in nodes1.txt: %d\n", Max);
        fclose(fInNodes);
        //-----------------------------------
        printf("number of nodes = %d\n", Max);
    }
    puts("</finding number of nodes>");
    // TODO: </finding number of nodes>


    double alphapa;
    double parenthese = 0;
    printf("alphapa and parenthese allocated\n");
    double *RANK;
    RANK = malloc(Max * sizeof(double));
    printf("rank allocated\n");
    double nbNodes = (double )Max;
    for (i = 0; i < Max; i++) {
        RANK[i] = 1.0 / nbNodes;
    }
    double *alphap;
    alphap = malloc(Max * sizeof(double));
    printf("alphap allocated\n");
    double *prevp;
    prevp = malloc(Max * sizeof(double));
    printf("prevp allocated\n");
    printf("allocation done\n");
    List my_list = NULL;
    for (i = Max; i > 0; i--) {
        add(&my_list, i);
    }
    printf("counting the number of outputs for each node\n");
    countnodes(&my_list);
    printf("count done\n");
    //done//
    //fill H and calculate our rank vector Pi //
    creath(&my_list);
    printf("H created\n");
//    FILE *listJSON = fopen("list.json", "w");
//    fprintf(listJSON, "{\n");
//    fprintf(listJSON, "\t\"data\": [\n");
//    List tmp = my_list;
//    while (tmp){
//        fprintf(listJSON, "\t\t{\"%d\": [", tmp->index);
//        for(int i = 0; i < tmp->count; i++){
//            fprintf(listJSON, "%d", tmp->point[i]);
//            if(i != tmp->count - 1){
//                fprintf(listJSON, ", ");
//            }
//        }
//        fprintf(listJSON, "]},\n");
//        tmp = tmp->next;
//    }
//    fprintf(listJSON, "\t]\n");
//    fprintf(listJSON, "}\n");
//    fclose(listJSON);
    int l = 0;
    printf("calculation begins\n");
    while (l < 200) {
        l++;
        for (int i = 0; i < Max; i++) {    //normally we should calculate the rank vector using the equation Pi=Pi*G//
            double val = RANK[i];        //so it can be solve by calculating the eigenvector corresponding to the //
            prevp[i] = val;            //eigenvalue=1 or by calculating the stationary vector of the probability//
            alphap[i] = (double) 0;        //vector G which is the markov chain way.These 2 ways are the ideal way  //
        }                //but we consider to solve it using 200 iterations to reach nearly ideal values//
        for (i = 0; i < Max; i++) {                //Pi(k+1)=alpha*Pi(k)*H+(alpha*Pi(k)*a+1-alpha)e^t/n			//
            RANK[i] = 0;                    //where Pi(k+1) and Pi(k) are the rank vector at iteration k+1 & k	//
        }                        //a is a zero vector and it is equal to one only if we have a dangling node//
        alphapa = 0;
        double x = calcul(&my_list, prevp, alphap, alphapa);
        //the way the data in our file is presented is very important to make our calculation//
        //here what we are doing is to search any number in the second column of our data //
        //which presented the nodes we are pointing to them. then search the line of this //
        //number is in which node range, this search is done by using our count of each node//
        //in each line we find a node we divide the corresponding term of previous rank vector//
        //by the count of the node which we are in its range(e.g.count of 1s is count[0] in c).//
        //we are doing that because H is a matrix having a very large amount of zeros//
        //so when we don't divide by any count it means that this cell of H is zero(i.e. has no load)//
        //only if count is zero or in another word when we have a dangling node //
        //a is equal to one and the value of alpha*Pi(k)*a is diffrent from zero//
        //as known Pi(K) is a row vector and a is a column vector so their mult-//
        //-plication results a number.//
        parenthese = x + 1 - (double) alpha;
        for (int i = 0; i < Max; i++) {
            RANK[i] = alphap[i] + parenthese * 1 / nbNodes;
        }
        if (l % 10 == 0 && l > 0) {
            printf("iteration number : %d\n", l);
        }

    } // End of While loop
    printf("number of iterations = %d\n", l);
    printf("Finish computing\n");
    FILE *fu;
    fu = fopen("Results.txt", "w");

    for (int i = 0; i < Max; i++) {
        fprintf(fu, "%.25f\n", RANK[i]);
    }
    fclose(fu);

    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
}

#pragma clang diagnostic pop