#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

#define	R1	729
#define	R2	901
#define	R3	2683
#define	R4	4726
#define	R5	6743
#define	R6	6745
#define	R7	7373
#define	R8	8435
#define	R9	9189
#define	R10	10304
#define	R11	11547
#define	R12	12917
#define	R13	13103
#define	R14	14364
#define	R15	15380
#define	R16	32202
#define	R17	32322
#define	R18	32518
#define	R19	34922
#define	R20	35690
#define	R21	39077
#define	R22	39141
#define	R23	41608
#define	R24	42246
#define	R25	42247
#define	R26	49811
#define	R27	100794
#define	R28	107958
#define	R29	111154
#define	R30	112123
#define	R31	140095
#define	R32	142034
#define	R33	161068
#define	R34	163911
#define	R35	168701
#define	R36	168736
#define	R37	168737
#define	R38	176786
#define	R39	181645
#define	R40	188271
#define	R41	190919
#define	R42	201255
#define	R43	223868
#define	R44	246325
#define	R45	248312
#define	R46	271454
#define	R47	279857
#define	R48	281346
#define	R49	285350
#define	R50	289143
#define	R51	326419
#define	R52	372808
#define	R53	380765
#define	R54	392878
#define	R55	393199
#define	R56	408191
#define	R57	417257
#define	R58	457372
#define	R59	467953
#define	R60	472524
#define	R61	484278
#define	R62	487114
#define	R63	522753
#define	R64	566158
#define	R65	575521
#define	R66	594934
#define	R67	609710
#define	R68	610421
#define	R69	617396
#define	R70	624811
#define	R71	655324
#define	R72	694348
#define	R73	694861
#define	R74	714736
#define	R75	775370
#define	R76	779442
#define	R77	790274
#define	R78	819115
#define	R79	852195
#define	R80	887121
#define	R81	891059
#define	R82	904441
#define	R83	985216
#define	R84	1019159
#define	R85	1073200
#define	R86	1090021
#define	R87	1114581
#define	R88	1149924
#define	R89	1162512
#define	R90	1212348
#define	R91	1331413
#define	R92	1349070
#define	R93	1439212
#define	R94	1454177
#define	R95	1460459
#define	R96	1469230
#define	R97	1473706
#define	R98	1493476
#define	R99	1535723
#define	R100	1537568
#define	R101	1670148
#define	R102	1711938
#define	R103	1864429
#define	R104	1956336
#define	R105	2035731
#define	R106	2229281
#define	R107	2230353
#define	R108	2255167
#define	R109	2260749
#define	R110	2354668
#define	R111	2361379
#define	R112	2370978
#define	R113	2377233
#define	R114	2422723
#define	R115	2483600
#define	R116	2567991
#define	R117	2583597
#define	R118	2651529
#define	R119	2658176
#define	R120	2828780
#define	R121	2832113
#define	R122	2850469
#define	R123	2864310
#define	R124	2880718
#define	R125	2882217
#define	R126	2896740
#define	R127	3055795
#define	R128	3275930
#define	R129	3312277
#define	R130	3536121
#define	R131	3687929
#define	R132	3840864
#define	R133	3894503
#define	R134	3897103
#define	R135	3912553
#define	R136	3952680
#define	R137	4090496
#define	R138	4103878
#define	R139	4106501
#define	R140	4110768
#define	R141	4110792
#define	R142	4111539
#define	R143	4196994
#define	R144	4200038





#define NUMBER_OF_SELECTED 144
#define alpha 0.85
#define eta 0.6
//number of nodes in the whole network - number of selected nodes
#define l 4212349 //=s
#define Max 4212493
# define lines 101611731


/*
// these are my selected nodes
#define R1 1
#define R2 3
//number of seleted nodes
#define NUMBER_OF_SELECTED 2
#define alpha 0.9
#define eta 0.97
//number of nodes in the whole network - number of selected nodes
#define l 4
//number of nodes
#define Max 6
//number of interactions
# define lines 10
*/
//in node list we put Gsr and Grs 
typedef struct node node;
struct node{
	double vector[NUMBER_OF_SELECTED];//hsr
	double vector2[NUMBER_OF_SELECTED];//hrs
	double vector3[NUMBER_OF_SELECTED];//Grs*P
	int count;//nb of outlinks of s all network
	int count2;//nb of outlinks of s to s
	int dang;
	int index;//index of current node from s nodes
	int index2;// 1 to max-nr, rename s
	int *point;//hss
	struct node* next;
};
typedef node* List;
void add(List *liste, int valeur, int value){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->index2=value;
	newnode->index=valeur;
	newnode->count=0;
	newnode->dang=0;
	int *point;
	for(int j=0; j < NUMBER_OF_SELECTED; j++){
		newnode->vector[j]=0;
		newnode->vector2[j]=0;
	}
	newnode->next= *liste;
	*liste=newnode;
}

void creathss(List *liste, int v[NUMBER_OF_SELECTED], int sum){
	List tmp=*liste;
	int node1,node2;
	int j=0;
	int i=0;
	FILE*fa;
	fa=fopen("enwiki_te_selected_modified_index.txt","r");
	for(i=0;i<sum;i++){
		fscanf(fa,"%d %d",&node1,&node2);
		while(tmp->index2 != node1){
			tmp=tmp->next;
			j=0;
		}
		tmp->point[j]=node2;
		//printf("node %d pointing to node %d and j = %d\n",tmp->index2,node2,j);
		j++;
	}
}
void countnodes(List *liste){
	int ind,i;
	int node11=1;
	int read;
	int v=0;
	int k;
	int sum=0;
	FILE*fr;
	fr=fopen("enwiki_nodes1.txt","r");
	List tmp= *liste;
	while(!feof(fr)){
		fscanf(fr,"%d",&ind);
		read=ind-node11;
		switch(read){
			case 0:
			v++;
			k=v;
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
				//printf("count of node %d = %d\n",tmp->index,v);
				sum=sum+v;
			}
			//k=v;
			v=1;
		}
		node11=ind;
	}
	tmp=tmp->next;
	//tmp=tmp->next;
	//tmp=tmp->next;
	tmp->count=k-1;
	//printf("count of node %d = %d\n",tmp->index,tmp->count);
	sum=sum+tmp->count;
	printf("number of outlinks of S nodes is %d\n",sum);
	fclose(fr);
}
int countnodes2(List *liste, int sum){
	//counting number of nodes between s and s
	int ind,i;
	int node11=1;
	int read;
	int v=0;
	int k;
	FILE*fr;
	fr=fopen("enwiki_te_node1ss.txt","r");
	List tmp= *liste;
	while(!feof(fr)){
		fscanf(fr,"%d",&ind);
		read=ind-node11;
		switch(read){
			case 0:
			v++;
			k=v;
			break;
			default:
			while(tmp->index2 < node11){
				tmp=tmp->next;
			}
			if(tmp->index2==node11){
				tmp->count2=v;
				//printf("count2 of node %d = %d\n",tmp->index2,v);
				sum=sum+v;
				tmp->point=malloc(v*sizeof(int));
				for(i=0;i < v;i++){
					tmp->point[i]=0;
				}
			}
			//k=v;
			v=1;
		}
		node11=ind;
	}
	tmp=tmp->next;
	//tmp=tmp->next;
	//tmp=tmp->next;
	tmp->count2=k-1;
	//printf("count2 of node %d = %d\n",tmp->index2,tmp->count2);
	sum=sum+tmp->count2;
	tmp->point=malloc((tmp->count2)*sizeof(int));
	for(i=0;i < tmp->count2;i++){
		tmp->point[i]=0;
	}
	printf("count done \n");
	fclose(fr);
	return (sum);
}
void dangling(List *liste){
	List tmp= *liste;
	int i =0;
	while(tmp!=NULL){
		if(tmp->count==0){
			tmp->dang=1;
			printf("dang [%d] = %d \n",tmp->index2,tmp->dang);
		}
		tmp=tmp->next;
	}
}
void calcul(List *liste){
	List tmp= *liste;
	while(tmp!=NULL){
		for(int j=0; j < NUMBER_OF_SELECTED; j++){
			tmp->vector[j]=alpha*tmp->vector[j]+(alpha*(double)tmp->dang+(1-alpha))/(double)Max;//gsr
			tmp->vector2[j]=alpha*tmp->vector2[j]+(1-alpha)/(double)Max;//grs
		}
		tmp=tmp->next;
	}
}
void inithsr(List *liste, int vecteur[NUMBER_OF_SELECTED]){
	//vecteur is the vector of selected nodes
	int node1,node2,z,s;
	FILE*fx;
	fx=fopen("enwiki_links_sorted_node1.txt","r");
	List tmp= *liste;
	while(!feof(fx)){
		fscanf(fx,"%d %d",&node1,&node2);
		z=0;
		for(int i=0; i < NUMBER_OF_SELECTED; i++){
			if(vecteur[i]==node1){
				z++;
			}
		}
		for	(int i=0; i < NUMBER_OF_SELECTED; i++){
			if(z==0 && vecteur[i]==node2){
				s=i;
				while(tmp->index!=node1){
					tmp=tmp->next;
				}
				tmp->vector[s]=1/(double)tmp->count;
			}
		}
	}
	fclose(fx);	
}

void inithrs(List *liste, int vecteur[NUMBER_OF_SELECTED], int outlinks[NUMBER_OF_SELECTED]){
	int node1,node2,z,s;
	FILE*fz;
	fz=fopen("enwiki_links_sorted_node2.txt","r");
	List tmp= *liste;
	while(!feof(fz)){
		fscanf(fz,"%d %d",&node1,&node2);
		z=0;
		for(int i=0; i < NUMBER_OF_SELECTED; i++){
			if(vecteur[i]==node2){
				z++;
			}
		}
		for	(int i=0; i < NUMBER_OF_SELECTED; i++){
			if(z==0 && vecteur[i]==node1){
				s=i;
				while(tmp->index!=node2){
					tmp=tmp->next;
				}
				tmp->vector2[s]=1/(double)outlinks[s];
			}
		}
	}
	fclose(fz);
}
void copyvertical(List *liste, int k, double *v){
	List tmp=*liste;
	while(tmp!=NULL){
		v[tmp->index2-1]=tmp->vector2[k];
		tmp=tmp->next;
	}
}

double modcopy(List *liste, int k, double *v, double *a, double sigma){
	List tmp=*liste;
	while(tmp!=NULL){
		v[tmp->index2-1]=tmp->vector2[k];
		sigma+=v[tmp->index2-1]*a[tmp->index2-1];
		tmp=tmp->next;
	}
	return(sigma);
}


double normsum(double *sum,double v){
	for(int i=0;i<l;i++){
		v+=sum[i];
	}
	return (v);
}
void recopyvertical(List *liste, int k, double *v){
	List tmp=*liste;
	while(tmp!=NULL){
		tmp->vector3[k]=v[tmp->index2-1];
		//printf("vector 3 = %.20f * \n",tmp->vector3[k]);
		//printf("%.20f * \n",v[tmp->index2-1]);
		tmp=tmp->next;
	}
}

void proj(List *liste, double *a, double *b, double **t){
	int i,j;
	List tmp=*liste;
	while(tmp!=NULL){
		for(i=0; i < NUMBER_OF_SELECTED; i++){
			for(j=0;j<l;j++){
				t[i][j]+=tmp->vector2[i]*a[tmp->index2-1]*b[j];
			}
		}
		tmp=tmp->next;
		if (tmp->index2%50000==0 && tmp->index2>0){
			printf("column number %d \n",tmp->index2);
		}
	}
}

void copy_vector(double *v1,double *v2){
	int i;
	for(i=0;i<l;i++){
		v1[i]=v2[i];
		//printf("copy sum to rank %.20f\n",v1[i]);
	}
}
double copy_vector2(double *v1,double *v2,double s){
	int i;
	for(i=0;i<l;i++){
		v1[i]=v2[i];
		s+=v1[i];
	}
	return (s);
}

void display(List *liste){
	List tmp=*liste;
	while(tmp!=NULL){
		for(int i=0; i < NUMBER_OF_SELECTED; i++){
			printf("inv gsr = %.20f\t",tmp->vector3[i]);
		}
		tmp=tmp->next;
		printf("\n");
	}
}

double calcul2(List* liste, double *u, double *v, double x){
	List tmp=*liste;
	while(tmp!=NULL){
		if(tmp->count==0){
			x+=(double)alpha*u[tmp->index2-1];
		}else{
			for(int i=0;i < tmp->count2;i++){
				v[tmp->point[i]-1]+=(double)alpha*u[tmp->index2-1]/(double)(tmp->count);//p=p*g
				//v[tmp->index2-1]+=(double)alpha*u[tmp->point[i]-1]/(double)(tmp->count);//p=g*p
				//printf("v[%d] = %.3f * %.15f(prevp[%d]) / %d = %.15f\n",tmp->index2-1,alpha,u[tmp->point[i]-1],tmp->point[i]-1,tmp->count,v[tmp->index2-1]);
			}
		}
		tmp=tmp->next;
	}
	return (x);
}

double calcul3(List* liste, double *u, double *v, double x){
	List tmp=*liste;
	while(tmp!=NULL){
		if(tmp->count==0){
			x+=(double)alpha*u[tmp->index2-1];
		}else{
			for(int i=0;i < tmp->count2;i++){
				//v[tmp->point[i]-1]+=(double)alpha*u[tmp->index2-1]/(double)(tmp->count);//p=p*g
				v[tmp->index2-1]+=(double)alpha*u[tmp->point[i]-1]/(double)(tmp->count);//p=g*p
				//printf("v[%d] = %.3f * %.15f(prevp[%d]) / %d = %.15f\n",tmp->index2-1,alpha,u[tmp->point[i]-1],tmp->point[i]-1,tmp->count,v[tmp->index2-1]);
			}
		}
		tmp=tmp->next;
	}
	return (x);
}


void second_part(List* liste, double** z, int k){
	int i,j;
	double* v;
	double* u;
	//double e=0;
	u=malloc(NUMBER_OF_SELECTED * sizeof(double));
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		u[i]=0;
	}
	v=malloc(l*sizeof(double));
	for(i=0;i<l;i++){
		v[i]=0;
	}
	List tmp=*liste;
	List tmp2=*liste;
	for(i=0;i<l;i++){
		v[i]=tmp2->vector3[k];
		tmp2=tmp2->next;
	}
	for(i=0;i<l;i++){
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			u[j]+=v[i]*tmp->vector[j];
			//e+=u[j];
		}
		tmp=tmp->next;
	}
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		z[k][i]=u[i];
	}	
	free(u);
	free(v);
}



void modsecond_part(List* liste, double** z, int k, double** t){
	int i,j;
	double* v;
	double* u;
	u=malloc(NUMBER_OF_SELECTED * sizeof(double));
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		u[i]=0;
	}
	v=malloc(l*sizeof(double));
	for(i=0;i<l;i++){
		v[i]=0;
	}
	List tmp2=*liste;
	for(i=0;i<l;i++){
		v[i]=tmp2->vector[k];
		tmp2=tmp2->next;
	}
	for(i=0;i<l;i++){
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			u[j]+=v[i]*t[j][i];
		}
	}
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		z[k][i]=u[i];
	}	
	free(u);
	free(v);
}

void gqr(List* liste, double** z){
	List tmp=*liste;
	int i;
	while(tmp!=NULL){
		for(i=0; i < NUMBER_OF_SELECTED; i++){
			tmp->vector2[i]=tmp->vector2[i]-z[i][tmp->index2-1];
		}
		tmp=tmp->next;
	}
}

void dumpNode(List *liste){
	List tmp=*liste;
	FILE*fa;
	fa=fopen("display.txt","a");
	fprintf(fa, "----------------------------------------------------------------");
	fprintf(fa, "dump node index 1 = %d; index 2 = %d\n", tmp->index, tmp->index2);
	fprintf(fa, "	--- vector ---\n");
	for(int i=0; i < NUMBER_OF_SELECTED; i++){
		fprintf(fa, "		%.20f\t\n",tmp->vector[i]);
	
	}
	
	fprintf(fa, "	--- vector2 ---\n");
	for(int i=0; i < NUMBER_OF_SELECTED; i++){
		fprintf(fa, "		%.20f\n",tmp->vector2[i]);
	}

	fprintf(fa, "	--- vector3 ---\n");
	for(int i=0; i < NUMBER_OF_SELECTED; i++){
		fprintf(fa, "		%.20f\n",tmp->vector3[i]);
	}

	fprintf(fa, "	--- info ---\n");
	fprintf(fa, "		count = %d, count2 = %d, dang = %d\n", tmp->count, tmp->count2, tmp->dang);

	fprintf(fa, "	--- Point ---\n");
	for(int i=0;i<tmp->count2;i++){
		fprintf(fa, "		%d\n",tmp->point[i]);
	}
	fclose(fa);
}

void dumpAllNode(List *liste){
	List tmp=*liste;
	printf("dumping all node");
	while(tmp!=NULL){
		dumpNode(&tmp);
		tmp=tmp->next;
	}
}

void dumpSomeNodes(List *liste, int numberToDump){
	List tmp=*liste;
	printf("dumping all node");
	int i = 0;
	while(tmp!=NULL && i < numberToDump){
		dumpNode(&tmp);
		tmp=tmp->next;
		i++;
	}
}



int main(){
	double prem=1/(double)NUMBER_OF_SELECTED ;
	printf("%.20f\n",prem);
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int i=0;
	int j=0;
	int count[NUMBER_OF_SELECTED];
	//double H[NUMBER_OF_SELECTED][NUMBER_OF_SELECTED];
	double **H;
	H=malloc(NUMBER_OF_SELECTED * sizeof(double *));
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		H[i]=malloc(NUMBER_OF_SELECTED * sizeof(double));
	}
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		count[i]=0;
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			H[i][j]=0;
		}
	}
	int vect[NUMBER_OF_SELECTED]={R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31, R32, R33, R34, R35, R36, R37, R38, R39, R40, R41, R42, R43, R44, R45, R46, R47, R48, R49, R50, R51, R52, R53, R54, R55, R56, R57, R58, R59, R60, R61, R62, R63, R64, R65, R66, R67, R68, R69, R70, R71, R72, R73, R74, R75, R76, R77, R78, R79, R80, R81, R82, R83, R84, R85, R86, R87, R88, R89, R90, R91, R92, R93, R94, R95, R96, R97, R98, R99, R100, R101, R102, R103, R104, R105, R106, R107, R108, R109, R110, R111, R112, R113, R114, R115, R116, R117, R118, R119, R120, R121, R122, R123, R124, R125, R126, R127, R128, R129, R130, R131, R132, R133, R134, R135, R136, R137, R138, R139, R140, R141, R142, R143, R144};
	int node1,node2,z,s;
	/*int lines=0;
	FILE*fs;
	FILE*fm;
	FILE*fk;
	fs=fopen("demo.txt","r");
	fm=fopen("nodes1.txt","w");
	fk=fopen("nodes2.txt","w");
	while(!feof(fs)){
	fscanf(fs,"%d %d",&node1,&node2);
	fprintf(fm,"%d\n",node1);
	fprintf(fk,"%d\n",node2);
	lines++;
	}
	lines=lines-1; //it should be lines but ...//
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
	for( int i = 0; i < lines; i++ )
	{
	   fscanf( fp, "%d", &No );
	   if( No > Max )
		   Max = No;
	}
	fclose(fp);
	FILE*fl;
	fl=fopen("nodes1.txt","r");
	for( int i = 0; i < lines; i++ )
	{
	   fscanf( fl, "%d", &No );
	   if( No > Max )
		   Max = No;
	}
	fclose(fl);*/
	printf("number of nodes = %d\n", Max );
	FILE*fa;
	fa=fopen("enwiki_links_sorted_node1.txt","r");
	FILE*fb;
	fb=fopen("enwiki_links_sorted_node1.txt","r");
	FILE*fh;
	fh=fopen("red.txt","w");
	//counting nodes of vect[NUMBER_OF_SELECTED]
	while(!feof(fa)){
		fscanf(fa,"%d %d",&node1,&node2);
		for(i=0; i < NUMBER_OF_SELECTED; i++){
			if(node1==vect[i])
				count[i]++;
		}
	}
	fclose(fa);
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		printf("count[%d] = %d \n",i+1,count[i]); 	
	}
	//calculation of HRR
	while(!feof(fb)){
		fscanf(fb,"%d %d",&node1,&node2);
		z=0;
		for(i=0; i < NUMBER_OF_SELECTED; i++){
			if(vect[i]==node1){
				z=i+1;
			}
		}
		for	(i=0; i < NUMBER_OF_SELECTED; i++){
			if(z!=0 && vect[i]==node2){
				s=i;
				H[z-1][s]=1/(double)count[z-1];
				printf("H[%d][%d] = %.20f\n",z-1,s,H[z-1][s]);
				fprintf(fh,"%d\t%d\n",z,s+1);
			}
		}
	}
	fclose(fb);
	fclose(fh);
	//calculation of GRR
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		if(count[i]==0){
			for(j=0; j < NUMBER_OF_SELECTED; j++){
				H[i][j]=1/(double)Max;
			}
		}else{
			for(j=0; j < NUMBER_OF_SELECTED; j++){
				H[i][j]=(double)alpha*H[i][j]+(1-(double)alpha)/(double)Max; //which is Grr
			}
		}
	}
	//print Grr
	FILE*ft;
	ft=fopen("GRR.txt","w");
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			fprintf(ft,"%.20f\t",H[i][j]);
		}
		fprintf(ft,"\n");
	}
	fclose(ft);
	//************************************************************//
	printf("initializing list\n");
	double alphapa;
	double parenthese = 0;
	double norm=0;
	double* psil;
	psil=malloc(l*sizeof(double));
	double* psir;
	psir=malloc(l*sizeof(double));
	double* RANK;
	RANK=malloc(l*sizeof(double));
	double* sum;
	sum=malloc(l*sizeof(double));
	double nbNodes = Max;
	double* alphap;
	alphap=malloc(l*sizeof(double));
	double* prevp;
	prevp=malloc(l*sizeof(double));
	double* gsrp;
	gsrp=malloc(NUMBER_OF_SELECTED * sizeof(double));
	for(int i = 0; i < l; i++){
		psir[i]=0;
		psil[i]=0;
		RANK[i]=0;
		sum[i]=0;
		alphap[i]=0;
		prevp[i]=0;
	}
	//creation of linked list with all indexes from 1 to max unless the Rs
	List my_list=NULL;
	int f= Max - NUMBER_OF_SELECTED;
	for(i=Max;i>0;i--){
		z=0;
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			if(i==vect[j]){
				z++;
			}
		}
		if(z==0){
			add(&my_list,i,f);
			f--;
		}
	}
	//************************************//
	printf("counting nodes\n");
	//count outlinks of each node
	countnodes(&my_list);
	int spoints=0;
	spoints=countnodes2(&my_list,spoints);
	//find dangling nodes
	dangling(&my_list);
	printf("initializing H[s][r]\n");
	inithsr(&my_list,vect);
	printf("initializing H[r][s]\n");
	inithrs(&my_list,vect,count);
	printf("calculation of Gsr and Grs\n");
	calcul(&my_list);
	printf("calculation of Gsr and Grs done\n");
	//************************************************//
	printf("initializing H[s][s]\n");
	printf("hss done\n");
	creathss(&my_list,vect,spoints);
	//***********************************************//
	/*double alphapa;
	double parenthese = 0;
	double norm=0;
	double* RANK;
	RANK=malloc(l*sizeof(double));
	double* sum;
	sum=malloc(l*sizeof(double));
	double nbNodes = Max;
	double* alphap;
	alphap=malloc(l*sizeof(double));
	double* prevp;
	prevp=malloc(l*sizeof(double));
	for(int i = 0; i < l; i++){
		RANK[i]=0;
		sum[i]=0;
		alphap[i]=0;
		prevp[i]=0;
	}*/
	
	
	//calculation of eigenvector left and lambda c//
	int c=0;
	int t=0;
	double b;
	
	for(c=0;c<l;c++){
		psil[c]=1/l;	
	}
	
	while(t<100){ 					
		t++;
		b=0;
		copy_vector(sum,psil);
		//s=copy_vector2(prevp,RANK,s);
		for(int i = 0; i < l; i++){ 	
			alphap[i] = (double)0;		
		}							
		alphapa=0;
		double x = calcul2(&my_list,prevp,alphap,alphapa);
		parenthese=x+(1-(double)alpha);
		parenthese=parenthese/nbNodes;
		for(int i = 0; i < l; i++){ 
			psil[i] = alphap[i] + parenthese;//rank 
			b+=psil[i];
		}
		//printf("iteration number : %d done and lambda = %.20f \n", t,b);
		//sleep(2);
		for(int i = 0; i < l; i++){ 
			psil[i] = psil[i]/b;
		}
		copy_vector(prevp,psil);
		if (t%50==0 && t>0){
			printf("iteration number : %d done and lambda = %.20f \n", t,b);
		}
	}
	double d=0;
	for(int i = 0; i < l; i++){ 
		d+=psil[i];
	}
	for(int i = 0; i < l; i++){ 
		psil[i]=psil[i]/d;
	}
	printf("d= %.20f\n",d);
	
	//calculation of eigenvector right and lambda c//
	double a=0;
	double w;
	t=0;
	for(c=0;c<l;c++){
		psir[c]=1/(double)l;
		//printf("psir init = %.20f\n",psir[c]);
		prevp[i]=0;
		sum[i]=0;	
	}
	
	while(t<100){ 					
		t++;
		w=0;
		copy_vector(sum,psir);
		a=0;
		a=copy_vector2(prevp,psir,a);
		//printf("a = %.20f\n",a);
		for(int i = 0; i < l; i++){ 	
			alphap[i] = (double)0;		
		}							
		alphapa=0;
		double x = calcul3(&my_list,prevp,alphap,alphapa);
		parenthese=x+(1-(double)alpha)*a;
		parenthese=parenthese/nbNodes;
		for(int i = 0; i < l; i++){ 
			psir[i] = alphap[i] + parenthese;//rank 
			w+=psir[i];
		}
		for(int i = 0; i < l; i++){ 
			psir[i] = psir[i]/w;
		}
		//copy_vector(prevp,psir);
		if (t%50==0 && t>0){
			printf("iteration number : %d done and lambda = %.20f \n", t,w);
		}
	}
	
	double r=0;
	for(c=0;c<l;c++){
		r+=psil[c]*psir[c];
	}
	printf("first sum = %.20f\n",r);
	for(c=0;c<l;c++){
		psir[c]=psir[c]/r;
		//psir[c]=psir[c]/psil[c];
	}
	r=0;
	for(c=0;c<l;c++){
		r+=psil[c]*psir[c];
	}
	printf("second sum = %.20f\n",r);
	
	double **third;
	third=malloc(NUMBER_OF_SELECTED * sizeof(double *));
	for(int i = 0 ; i < NUMBER_OF_SELECTED ; i++){
        third[i] = malloc(l*sizeof(double));
	}
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		for(j=0;j<l;j++){
			third[i][j]=0;
		}
	}
	printf("third allocated\n");
	/*proj(&my_list,psir,psil,third);
	printf("proj done \n");
	*/
	
	double sigma;
	for(c=0; c < NUMBER_OF_SELECTED; c++){
		printf("****** dealing with vector %d out of %d number******\n", c+1, NUMBER_OF_SELECTED);
		sigma=0;
		sigma=modcopy(&my_list,c,prevp,psir,sigma);
		for(i=0;i<l;i++){
			third[c][i]=psil[i]*sigma;
		}
	}
	printf("proj done \n");
	
	
	
	
	gqr(&my_list,third);
	//calcul de Gqr
	t=0;
	//Grs*[(1-Gss)^-1]
	for(c=0; c < NUMBER_OF_SELECTED; c++){
		printf("****** dealing with vector %d out of %d number******\n", c+1, NUMBER_OF_SELECTED);
		double s=0;
		copyvertical(&my_list,c,sum);
		//printf("s=%.20f\n",s);
		copy_vector(RANK,sum);
		t=0;
		while(t<150){ 					
			t++;
			//printf("iteration number : %d\n", t);
			s=0;
			s=copy_vector2(prevp,RANK,s);
			//printf("s=%.20f\n",s);			
			for(int i = 0; i < l; i++){ 	//normally we should calculate the rank vector using the equation Pi=Pi*G//
				//double val = RANK[i]; 		//so it can be solve by calculating the eigenvector corresponding to the //
				//prevp[i] = val;			//eigenvalue=1 or by calculating the stationary vector of the probability// 
				alphap[i] = (double)0;		//vector G which is the markov chain way.These 2 ways are the ideal way  //
				//printf("prevp[%d]= %.20f\n",i,prevp[i]);
			}							//but we consider to solve it using 200 iterations to reach nearly ideal values//
		//	for(i=0;i<l;i++){				//Pi(k+1)=alpha*Pi(k)*H+(alpha*Pi(k)*a+1-alpha)e^t/n			//
			//	RANK[i]=0;					//where Pi(k+1) and Pi(k) are the rank vector at iteration k+1 & k	//
			//}						//a is a zero vector and it is equal to one only if we have a dangling node//
			alphapa=0;
			double x = calcul2(&my_list,prevp,alphap,alphapa);
			//printf("X = %.20f \n",x);
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
			parenthese=x+(1-(double)alpha)*s;
			parenthese=parenthese/nbNodes;
			//printf("parenthese=%.20f\n",parenthese);
			for(int i = 0; i < l; i++){ 
				RANK[i] = alphap[i] + parenthese;//rank 
				//printf("alphap[%d] = %.20f \n",i,alphap[i]);
				//printf("RANK[%d] = %.20f \n",i,RANK[i]);
			}
			if (t%150==0 && t>0){
				printf("iteration number : %d done\n", t);
			}
			double SumPlusRank=0;
			for(int i = 0; i < l; i++){ 
				SumPlusRank=sum[i]+RANK[i];
				sum[i]=SumPlusRank;
				//if (sum[i]>1){
				//	sleep(10);
				//}
				//printf("sum[%d] = %.20f\n",i,sum[i]);  
			}		 
		}
		//norm=0;
		//double norm1=normsum(sum,norm);
		recopyvertical(&my_list,c,sum);
		//sleep(10);
	}
	
	double **second;
	second=malloc(NUMBER_OF_SELECTED * sizeof(double *));
	for(int i = 0 ; i < NUMBER_OF_SELECTED ; i++){
        second[i] = malloc(NUMBER_OF_SELECTED * sizeof(double));
	}
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		count[i]=0;
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			second[i][j]=0;
		}
	}
	printf("second allocated\n");
	for(int k=0; k < NUMBER_OF_SELECTED; k++){
		printf("k=%d\n",k);
		second_part(&my_list,second,k);
	}
	printf("second part done\n");
	//print GI
	FILE*fw;
	fw=fopen("en_te_Gqr.txt","w");
	for(i=0; i < NUMBER_OF_SELECTED; i++){
		for(j=0; j < NUMBER_OF_SELECTED; j++){
			fprintf(fw,"%.20f\t",second[i][j]);
		}
		fprintf(fw,"\n");
	}
	fclose(fw);	
	
	
	//display(&my_list);
	
	/*
	 //calcul de Gpr//
	double **second;
	second=malloc(NUMBER_OF_SELECTED*sizeof(double *));
	for(int i = 0 ; i < NUMBER_OF_SELECTED ; i++){
        second[i] = malloc(NUMBER_OF_SELECTED*sizeof(double));
	}
	for(i=0;i<NUMBER_OF_SELECTED;i++){
		count[i]=0;
		for(j=0;j<NUMBER_OF_SELECTED;j++){
			second[i][j]=0;
		}
	}
	printf("second allocated\n");
	for(int k=0;k<NUMBER_OF_SELECTED;k++){
		printf("k=%d\n",k);
		modsecond_part(&my_list,second,k,third);
		//second_part(&my_list,second,k);
	}
	printf("second part done\n");
	//print GI
	FILE*fw;
	fw=fopen("Gpr.txt","w");
	for(i=0;i<NUMBER_OF_SELECTED;i++){
		for(j=0;j<NUMBER_OF_SELECTED;j++){
			fprintf(fw,"%.20f\t",second[i][j]/(1-b));
		}
		fprintf(fw,"\n");
	}
	fclose(fw);
	*/
	
	
	
	/*	
	//GR=Grr+GI
	//print GR
	FILE*fj;
	fj=fopen("GR.txt","w");
	double HPlusSecond = 0;
	for(i=0;i<NUMBER_OF_SELECTED;i++){
		for(j=0;j<NUMBER_OF_SELECTED;j++){
			HPlusSecond = H[i][j]+second[i][j];
			fprintf(fj,"%.20f\t",HPlusSecond);
			H[i][j]=HPlusSecond;
			printf("HPlusSecond = %.20f\n",HPlusSecond);
			printf("H[i][j] = %.20f\n",H[i][j]);
		}
		fprintf(fj,"\n");
	}
	fclose(fj);
	free(second);
	dumpSomeNodes(&my_list,100);
	*/
	//************************************************//
	
	
	/*
	//pagerank calculation
	printf("calculation of pagerank\n");
	double mult=0;
	double* pi;
	double* prevpi;
	pi=malloc(NUMBER_OF_SELECTED*sizeof(double));
	prevpi=malloc(NUMBER_OF_SELECTED*sizeof(double));
	for(i=0;i<NUMBER_OF_SELECTED;i++){
		pi[i]=0;
		prevpi[i]=0;
	}
	norm=0;
	int q=0;
	//double prem=1/(double)NUMBER_OF_SELECTED ;
	while(q<200){
		q++;	
		for(i=0;i<NUMBER_OF_SELECTED;i++){
			if(q==1){
				prevpi[i]=prem;
			}
			else {
				prevpi[i] = pi[i];
			}
			//pi[i]=0;	
		}

		for(i=0;i<NUMBER_OF_SELECTED;i++){
			mult=0;
			for(j=0;j<NUMBER_OF_SELECTED;j++){
				mult+=H[j][i]*prevpi[j];
			}	
			pi[i]=mult;
			//printf("Pi + mult  %.20f - %.20f \n",pi[i], prevpi[i]);
		}
	}
	//for(j=0;j<NUMBER_OF_SELECTED;j++){
	//	norm+=pi[j];
	//} 
	FILE*fi;
	fi=fopen("reduced pagerank.txt","w")	;				
	for(i=0;i<NUMBER_OF_SELECTED;i++){
		printf("%.20f\n",pi[i]);
		fprintf(fi,"%.20f\n",pi[i]);
	}
	fclose(fi);
	*/
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("time spent= %.20f\n",time_spent);
}
