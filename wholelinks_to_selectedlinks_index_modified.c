#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>

#define    SELECTED1    729
#define    SELECTED2    901
#define    SELECTED3    2683
#define    SELECTED4    4726
#define    SELECTED5    6743
#define    SELECTED6    6745
#define    SELECTED7    7373
#define    SELECTED8    8435
#define    SELECTED9    9189
#define    SELECTED10    10304
#define    SELECTED11    11547
#define    SELECTED12    12917
#define    SELECTED13    13103
#define    SELECTED14    14364
#define    SELECTED15    15380
#define    SELECTED16    32202
#define    SELECTED17    32322
#define    SELECTED18    32518
#define    SELECTED19    34922
#define    SELECTED20    35690
#define    SELECTED21    39077
#define    SELECTED22    39141
#define    SELECTED23    41608
#define    SELECTED24    42246
#define    SELECTED25    42247
#define    SELECTED26    49811
#define    SELECTED27    100794
#define    SELECTED28    107958
#define    SELECTED29    111154
#define    SELECTED30    112123
#define    SELECTED31    140095
#define    SELECTED32    142034
#define    SELECTED33    161068
#define    SELECTED34    163911
#define    SELECTED35    168701
#define    SELECTED36    168736
#define    SELECTED37    168737
#define    SELECTED38    176786
#define    SELECTED39    181645
#define    SELECTED40    188271
#define    SELECTED41    190919
#define    SELECTED42    201255
#define    SELECTED43    223868
#define    SELECTED44    246325
#define    SELECTED45    248312
#define    SELECTED46    271454
#define    SELECTED47    279857
#define    SELECTED48    281346
#define    SELECTED49    285350
#define    SELECTED50    289143
#define    SELECTED51    326419
#define    SELECTED52    372808
#define    SELECTED53    380765
#define    SELECTED54    392878
#define    SELECTED55    393199
#define    SELECTED56    408191
#define    SELECTED57    417257
#define    SELECTED58    457372
#define    SELECTED59    467953
#define    SELECTED60    472524
#define    SELECTED61    484278
#define    SELECTED62    487114
#define    SELECTED63    522753
#define    SELECTED64    566158
#define    SELECTED65    575521
#define    SELECTED66    594934
#define    SELECTED67    609710
#define    SELECTED68    610421
#define    SELECTED69    617396
#define    SELECTED70    624811
#define    SELECTED71    655324
#define    SELECTED72    694348
#define    SELECTED73    694861
#define    SELECTED74    714736
#define    SELECTED75    775370
#define    SELECTED76    779442
#define    SELECTED77    790274
#define    SELECTED78    819115
#define    SELECTED79    852195
#define    SELECTED80    887121
#define    SELECTED81    891059
#define    SELECTED82    904441
#define    SELECTED83    985216
#define    SELECTED84    1019159
#define    SELECTED85    1073200
#define    SELECTED86    1090021
#define    SELECTED87    1114581
#define    SELECTED88    1149924
#define    SELECTED89    1162512
#define    SELECTED90    1212348
#define    SELECTED91    1331413
#define    SELECTED92    1349070
#define    SELECTED93    1439212
#define    SELECTED94    1454177
#define    SELECTED95    1460459
#define    SELECTED96    1469230
#define    SELECTED97    1473706
#define    SELECTED98    1493476
#define    SELECTED99    1535723
#define    SELECTED100    1537568
#define    SELECTED101    1670148
#define    SELECTED102    1711938
#define    SELECTED103    1864429
#define    SELECTED104    1956336
#define    SELECTED105    2035731
#define    SELECTED106    2229281
#define    SELECTED107    2230353
#define    SELECTED108    2255167
#define    SELECTED109    2260749
#define    SELECTED110    2354668
#define    SELECTED111    2361379
#define    SELECTED112    2370978
#define    SELECTED113    2377233
#define    SELECTED114    2422723
#define    SELECTED115    2483600
#define    SELECTED116    2567991
#define    SELECTED117    2583597
#define    SELECTED118    2651529
#define    SELECTED119    2658176
#define    SELECTED120    2828780
#define    SELECTED121    2832113
#define    SELECTED122    2850469
#define    SELECTED123    2864310
#define    SELECTED124    2880718
#define    SELECTED125    2882217
#define    SELECTED126    2896740
#define    SELECTED127    3055795
#define    SELECTED128    3275930
#define    SELECTED129    3312277
#define    SELECTED130    3536121
#define    SELECTED131    3687929
#define    SELECTED132    3840864
#define    SELECTED133    3894503
#define    SELECTED134    3897103
#define    SELECTED135    3912553
#define    SELECTED136    3952680
#define    SELECTED137    4090496
#define    SELECTED138    4103878
#define    SELECTED139    4106501
#define    SELECTED140    4110768
#define    SELECTED141    4110792
#define    SELECTED142    4111539
#define    SELECTED143    4196994
#define    SELECTED144    4200038


#define NUMBER_OF_SELECTED 144

int main() {

    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    int selectedNodes[NUMBER_OF_SELECTED] = {SELECTED1, SELECTED2, SELECTED3, SELECTED4, SELECTED5, SELECTED6, SELECTED7, SELECTED8, SELECTED9, SELECTED10, SELECTED11, SELECTED12, SELECTED13, SELECTED14, SELECTED15, SELECTED16, SELECTED17, SELECTED18, SELECTED19, SELECTED20,
                                             SELECTED21, SELECTED22, SELECTED23, SELECTED24, SELECTED25, SELECTED26, SELECTED27, SELECTED28, SELECTED29, SELECTED30, SELECTED31, SELECTED32, SELECTED33, SELECTED34, SELECTED35, SELECTED36, SELECTED37, SELECTED38,
                                             SELECTED39, SELECTED40, SELECTED41, SELECTED42, SELECTED43, SELECTED44, SELECTED45, SELECTED46, SELECTED47, SELECTED48, SELECTED49, SELECTED50, SELECTED51, SELECTED52, SELECTED53, SELECTED54, SELECTED55, SELECTED56,
                                             SELECTED57, SELECTED58, SELECTED59, SELECTED60, SELECTED61, SELECTED62, SELECTED63, SELECTED64, SELECTED65, SELECTED66, SELECTED67, SELECTED68, SELECTED69, SELECTED70, SELECTED71, SELECTED72, SELECTED73, SELECTED74,
                                             SELECTED75, SELECTED76, SELECTED77, SELECTED78, SELECTED79, SELECTED80, SELECTED81, SELECTED82, SELECTED83, SELECTED84, SELECTED85, SELECTED86, SELECTED87, SELECTED88, SELECTED89, SELECTED90, SELECTED91, SELECTED92,
                                             SELECTED93, SELECTED94, SELECTED95, SELECTED96, SELECTED97, SELECTED98, SELECTED99, SELECTED100, SELECTED101, SELECTED102, SELECTED103, SELECTED104, SELECTED105, SELECTED106, SELECTED107, SELECTED108,
                                             SELECTED109, SELECTED110, SELECTED111, SELECTED112, SELECTED113, SELECTED114, SELECTED115, SELECTED116, SELECTED117, SELECTED118, SELECTED119, SELECTED120, SELECTED121, SELECTED122, SELECTED123,
                                             SELECTED124, SELECTED125, SELECTED126, SELECTED127, SELECTED128, SELECTED129, SELECTED130, SELECTED131, SELECTED132, SELECTED133, SELECTED134, SELECTED135, SELECTED136, SELECTED137, SELECTED138,
                                             SELECTED139, SELECTED140, SELECTED141, SELECTED142, SELECTED143, SELECTED144};
    int node1, node2, NodeSS1Counter, NodeSS2Counter, k, i;
    FILE *fIn = fopen("enwiki_links_sorted_node1.txt", "r");
    FILE *fOutSS2node = fopen("enwiki_te_node2ss.txt", "w");
    FILE *fOutSS1node = fopen("enwiki_te_node1ss.txt", "w");
    while (!feof(fIn)) {
        node1 = -1; node2 = -1;
        fscanf(fIn, "%d %d", &node1, &node2);
        if(node1 != -1 && node2 != -1){
            NodeSS1Counter = 0;
            NodeSS2Counter = 0;
            for (i = 0; i < NUMBER_OF_SELECTED; i++) {
                if (selectedNodes[i] == node1) {
                    NodeSS1Counter++;
                }
            }
            for (i = 0; i < NUMBER_OF_SELECTED; i++) {
                if (selectedNodes[i] == node2) {
                    NodeSS2Counter++;
                }
            }
            // If there are no node
            if (NodeSS1Counter == 0 && NodeSS2Counter == 0) {
                if (node1 < selectedNodes[0]) {
                    fprintf(fOutSS1node, "%d\n", node1);
                }
                if (node1 > SELECTED144) {
                    fprintf(fOutSS1node, "%d\n", node1 - NUMBER_OF_SELECTED);
                }
                for (k = 0; k < NUMBER_OF_SELECTED - 1; k++) {
                    if (node1 < selectedNodes[k + 1] && node1 > selectedNodes[k]) {
                        fprintf(fOutSS1node, "%d\n", node1 - k - 1);
                    }
                }

                if (node2 < selectedNodes[0]) {
                    fprintf(fOutSS2node, "%d\n", node2);
                }
                if (node2 > SELECTED144) {
                    fprintf(fOutSS2node, "%d\n", node2 - NUMBER_OF_SELECTED);
                }
                for (k = 0; k < NUMBER_OF_SELECTED - 1; k++) {
                    if (node2 < selectedNodes[k + 1] && node2 > selectedNodes[k]) {
                        fprintf(fOutSS2node, "%d\n", node2 - k - 1);
                    }
                }
            }
        }else fprintf(stderr, "fscanf failed\n");
    }
    fclose(fOutSS2node);
    fclose(fOutSS1node);
    fclose(fIn);

    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);
}
