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
struct node{
	int count; //outlinks
	int index; // id - number of node
	int *point; // array outgoing links
	struct node* next;
};
typedef node* llist;

void add(llist *liste,int value){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->index=value;
	newnode->count=0;
	newnode->next= *liste;
	*liste=newnode;
}
void countnodes(llist *liste){
	int ind,i,read,k;
	int node11=1;
	int v=0;
	FILE*fr;
	fr=fopen("nodes1.txt","r");
	llist tmp= *liste;
	while(!feof(fr)){
		fscanf(fr,"%d",&ind);
		read=ind-node11;
		switch(read){
			case 0:
			v++;
			break;
			default:
			if (node11%100000==0 && node11>0){
				printf("\ncounting %d\n",node11);
			}
			while(tmp->index < node11){
				tmp=tmp->next;
			}
			if(tmp->index==node11){
				tmp->count=v;
				//printf("count[%d] = %d \n",tmp->index,v);
				tmp->point=malloc(v*sizeof(int));
				for(i=0;i < v;i++){
					tmp->point[i]=0;
				}
			}
			k=v;
			v=1;
		}
		node11=ind;
	}
	tmp=tmp->next;
	//tmp=tmp->next; //when before the last node is a dangling node you make two next
	//tmp=tmp->next; //when before the last node there is two dangling node you make another next
	tmp->count=6;
	//printf("count[%d] = %d \n",tmp->index,k);
	tmp->point=malloc(k*sizeof(int));
	for(i=0;i < k;i++){
		tmp->point[i]=0;
	}
	fclose(fr);
}
void creath(llist *liste){
	llist tmp=*liste;
	int node1,node2,j;
	FILE*fa;
	fa=fopen("enwiki_links_sorted_node1.txt","r");
	while(!feof(fa)){
		fscanf(fa,"%d %d",&node1,&node2);
		while(tmp->index != node1){
			tmp=tmp->next;
			j=0;
		}
		tmp->point[j]=node2;
		j++;
	}
}
double calcul(llist* liste,double *u,double *v,double x){
	llist tmp=*liste;
	while(tmp!=NULL){
		if(tmp->count==0){
			x+=(double)alpha*u[tmp->index-1];
		}else{
			for(int i=0;i < tmp->count;i++){
				v[tmp->point[i]-1]+=(double)alpha*u[tmp->index-1]/(double)(tmp->count);
			}
		}
		tmp=tmp->next;
	}
	return (x);
}

int main(){
    
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();
    
	int node1,node2,i;
	int lines =0;
	//calculating number of lines//
	FILE*fs;
	FILE*fm;
	FILE*fk;
	fs=fopen("enwiki_links_sorted_node1.txt","r");
	fm=fopen("nodes1.txt","w");
	fk=fopen("nodes2.txt","w");
	while(!feof(fs)){
		fscanf(fs,"%d %d",&node1,&node2);
		fprintf(fm,"%d\n",node1);
		fprintf(fk,"%d\n",node2);
		lines++;
	}
	lines=lines-1; //it should be lines but while dealing with cambridge it seems there are something ...//
	fclose(fs);
	fclose(fm);
	fclose(fk);
	printf("number of pointers= %d\n",lines);
	//finish calculation//
	//finding number of nodes//
	int Max = 0;
	int No;
	FILE*fp;
	fp=fopen("nodes2.txt","r");
    //find maximum
	for( i = 0; i < lines; i++ )
	{
	   fscanf( fp, "%d", &No );
	   if( No > Max )
		   Max = No;
	}
	fclose(fp);
	FILE*fl;
	fl=fopen("nodes1.txt","r");
	for( i = 0; i < lines; i++ )
	{
	   fscanf( fl, "%d", &No );
	   if( No > Max )
		   Max = No;
	}
	fclose(fl);
    //-----------------------------------
	printf("number of nodes = %d\n", Max );
	double alphapa;
	double parenthese = 0;
	printf("alphapa and parenthese allocated\n");
	double* RANK;
	RANK=malloc(Max*sizeof(double));
	printf("rank allocated\n");
	double nbNodes = Max;
	for(i=0;i<Max;i++){
		RANK[i]=1/nbNodes;			
	}
	double* alphap;
	alphap=malloc(Max*sizeof(double));
	printf("alphap allocated\n");
	double* prevp;
	prevp=malloc(Max*sizeof(double));
	printf("prevp allocated\n");
	printf("allocation done\n");
	llist my_list=NULL;
	for(i=Max;i>0;i--){
		add(&my_list,i);
	}
	printf("counting the number of outputs for each node\n");
	countnodes(&my_list);
	printf("count done\n");
	//done//
	//fill H and calculate our rank vector Pi //
	creath(&my_list);
	printf("H created\n");

	int l=0;
	printf("calculation begins\n");
	while(l<150){ 					
		l++;			
		for(int i = 0; i < Max; i++){ 	//normally we should calculate the rank vector using the equation Pi=Pi*G//
			double val = RANK[i]; 		//so it can be solve by calculating the eigenvector corresponding to the //
			prevp[i] = val;			//eigenvalue=1 or by calculating the stationary vector of the probability// 
			alphap[i] = (double)0;		//vector G which is the markov chain way.These 2 ways are the ideal way  //
		}				//but we consider to solve it using 200 iterations to reach nearly ideal values//
		for(i=0;i<Max;i++){				//Pi(k+1)=alpha*Pi(k)*H+(alpha*Pi(k)*a+1-alpha)e^t/n			//
			RANK[i]=0;					//where Pi(k+1) and Pi(k) are the rank vector at iteration k+1 & k	//
		}						//a is a zero vector and it is equal to one only if we have a dangling node//
		alphapa=0;
		double x = calcul(&my_list,prevp,alphap,alphapa);
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
		parenthese=x+1-(double)alpha;
		for(int i = 0; i < Max; i++){ 
			RANK[i] = alphap[i] + parenthese*1/nbNodes; 
		}
		if (l%10==0 && l>0){
			printf("iteration number : %d\n", l);
		}

	}
	printf("number of iterations = %d\n", l);
	printf("Finish computing\n");
	FILE *fu;
	fu = fopen("Results.txt", "w"); 

	for(int i = 0; i < Max; i++){ 
		fprintf(fu,"%.25f\n",RANK[i]); 
	} 
	fclose(fu);
    
    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
}
