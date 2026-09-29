#include <stdio.h>
#include<string.h>

int main(){
   
    char names[5][20] = {"Abubokkor", "Farjin", "Rafit", "Sazzad", "Srabon"};

    char item[20];

    int index = 5;
    
    printf("Enter Name to Push: ");
    scanf("%s", item);

    for(int i=0; i<5; i++){

        if(strcmp(names[i], item) > 0){
            index = i;
            break;
        }
        
        else if(strcmp(names[i], item) == 0){
            index = i+1;
            break;
        }

    }

    printf("Index : %d", index);

    return 0;

}