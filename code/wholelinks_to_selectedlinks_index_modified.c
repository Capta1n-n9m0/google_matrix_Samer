#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>

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




#define NR 144

int main(){
    
    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

	int vect[NR]={R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12,R13,R14,R15,R16,R17,R18,R19,R20,R21,R22,R23,R24,R25,R26,R27,R28,R29,R30,R31,R32,R33,R34,R35,R36,R37,R38,R39,R40,R41,R42,R43,R44,R45,R46,R47,R48,R49,R50,R51,R52,R53,R54,R55,R56,R57,R58,R59,R60,R61,R62,R63,R64,R65,R66,R67,R68,R69,R70,R71,R72,R73,R74,R75,R76,R77,R78,R79,R80,R81,R82,R83,R84,R85,R86,R87,R88,R89,R90,R91,R92,R93,R94,R95,R96,R97,R98,R99,R100,R101,R102,R103,R104,R105,R106,R107,R108,R109,R110,R111,R112,R113,R114,R115,R116,R117,R118,R119,R120,R121,R122,R123,R124,R125,R126,R127,R128,R129,R130,R131,R132,R133,R134,R135,R136,R137,R138,R139,R140,R141,R142,R143,R144};
	int node1,node2,z,s,k,i;
	FILE*fb;
	fb=fopen("enwiki_te_node2ss.txt","w");
	FILE*fa;
	fa=fopen("enwiki_te_node1ss.txt","w");
	FILE*fx;
	fx=fopen("enwiki_links_sorted_node1.txt","r");
	while(!feof(fx)){
		fscanf(fx,"%d %d",&node1,&node2);
		z=0;
		s=0;
		for(i=0;i<NR;i++){
			if(vect[i]==node1){
				z++;
			}
		}
		for	(i=0;i<NR;i++){
			if(vect[i]==node2){
				s++;
			}
		}	
		if (z==0 && s==0){
			if(node1<vect[0]){
				fprintf(fa,"%d\n",node1);
			}
			if(node1>R144){
				fprintf(fa,"%d\n",node1-NR);
			}
			for(k=0;k<NR-1;k++){
				if(node1<vect[k+1] && node1>vect[k]){
					fprintf(fa,"%d\n",node1-k-1);
				}
			}
			
			if(node2<vect[0]){
				fprintf(fb,"%d\n",node2);
			}
			if(node2>R144){
				fprintf(fb,"%d\n",node2-NR);
			}
			for(k=0;k<NR-1;k++){
				if(node2<vect[k+1] && node2>vect[k]){
					fprintf(fb,"%d\n",node2-k-1);
				}
			}
		}
	}
	fclose(fb);
	fclose(fa);
	fclose(fx);
    
    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
}
