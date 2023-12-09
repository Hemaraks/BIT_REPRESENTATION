#include<stdio.h>

#define max_digit 1000

char carry[max_digit];
char arr[8];
char product[max_digit];

void get_product(char *num,char m);

int main(void)
{
    char num[max_digit]={'0','A','F','4','9'};
    char m = '5';
    get_product(num,m);
    printf("%s",product);
    return 0;
}

int get_int(char c){
    c = (int)c;
    if(c>=48 && c<=57){
        return c-48;
    }
    else if (c>=65 && c<=70){
        return c-55;
    }
}

int get_char(int i){
    if(i>=48 && i<=57){
        return i+48;
    }
    else if (i>=65 && i<=70){
        return i+55;
    }
}

void int_hexa(int num){
    int temp=0,arr_len=0;
    for(int e=0;e<8;e++){
        arr[e]='0';
    }
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

void get_product(char *num,char m){
    int len=0;
    for(int b=0;b<max_digit;b++){
        carry[b]='0';
    }
    // length of the num
    for(int a=0;*(num+a)!='\0';a++){
        len++;
    }
    len = len-1;
    for(int i=len;i>=0;i--){
        int res = (get_int(num[i])*get_int(m))+get_int(carry[i]);
        /*the important thing to remember is that in hexa multiplication the carry is int the form of hexadecimal format only */
        // the res value is in decimal format 

        // change decimal to hexa
        int_hexa(res);
        if(res>=16){
            product[i]=arr[1];
            carry[i-1]=arr[0];
        }
        else {
            product[i]=arr[0];
        }
    }
    
}