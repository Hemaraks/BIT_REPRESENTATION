#include<stdio.h>

#define max 8

char arr[max];

void int_hexa(int num);

int main(void)
{
    int num = 16777716;
    int_hexa(num);
    printf("%s",arr);
    return 0;
}

void int_hexa(int num){
    int temp=0,arr_len=0;
    for(int i=0;num>=1;i++){
        temp=num%16;
        if(temp>=0 && temp<=9){
            arr[i] = temp+48;
            arr_len++;
        }
        else if(temp>=10 && temp<=15){
            arr[i]=temp+55;
            arr_len++;
        }
        num=num/16;
    }
    arr_len=arr_len-1;
    for(int a=0;a<=arr_len/2;a++){
        temp=arr[a];
        arr[a]=arr[arr_len];
        arr[arr_len]=temp;
        arr_len--;
    }
}