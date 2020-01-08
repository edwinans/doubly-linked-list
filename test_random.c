#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

#include "projet2019.h"

int main()
{   //srand110  seq500  500000
    const int SEQ_NB = 100000 , K=7; // 6 fois plus d'insertion que de suppression
    head *hd = ld_create(2000000);
    align_data data1[4];
    create_data(4,1,data1);
    ld_insert_first(hd, sizeof(data1), data1);

    srand(0);

    int time1 = time(0);

    for(int i=0;i<= SEQ_NB;i++){
        int oper = rand(); 
        int pos=0;
        if(hd->nb_elem <=0)
            pos=0;
        else
            pos= rand() % (hd->nb_elem);

        int compact = 0; // compactify dans 1% des cas
        int data_size = (rand() % 10) + 1; //taille du data entre (1-10)
        int data_first = (rand() % 1000) + 1; //data commence entre (1 - 1000)
        align_data data[data_size];


        node* node_at_pos = get_node_at(hd, pos);

        if(pos==0){
            ld_insert_first(hd, sizeof(data), data);
            continue;
        }
        

        if(compact == 1){
            ld_compactify(hd);
        }
        else if((oper % K) != 0){ //c'est une insertion
            create_data(data_size, data_first, data);
            //ld_insert_first(hd,sizeof(data),data);
            ld_insert_before(hd, node_at_pos, sizeof(data), data);
        }
        // else{ //c'est une suppression
            
        //     ld_delete_node(hd, node_at_pos);
        // }
    }

    int time2 = time(0);
    
    //print_list(hd);

    printf("\n temps total d'execution: %ds \n", time2 - time1);

    ld_destroy(hd);

    return 0;
}
