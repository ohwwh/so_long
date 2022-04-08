#include "so_long.h"

void sort(int list[], int n, t_character_vars **objs){
    int i, j, key;

    for(i=1; i<n; i++){
        key = list[i]; 
            for(j=i-1; j>=0 && objs[list[j]]->y > objs[key]->y; j--){
                list[j+1] = list[j];
            }
        list[j+1] = key;
    }
}