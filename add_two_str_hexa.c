#include<stdio.h>

#define max_digit 1000
int base = 16;

char sum[max_digit];

int cal_hex_sum(char *hex_one,char *hex_two,char *carry);

int main(void)
{
    char carry[max_digit];
    char hex_one[max_digit]= {'0','2','A','9'};
    char hex_two[max_digit]={'0','3','9','F'};
    cal_hex_sum(hex_one,hex_two,carry);
    printf("%s",sum);
    return 0;
}

int get_len(char *n){
    int len=0;
    for(int i=0;*(n+i)!='\0';i++){
        len++;
    }
    return len-1;
}

int get_int(int i){
    if(i>=48 && i<=57){
        return i-48;
    }
    else if(i>=65 && i<=70){
        return i-55;
    }
}

int get_char(int i){
    if(i>=0 && i<=9){
        return i+48;
    }
    else if(i>=10 && i<=15){
        return i+55;
    }
}

int cal_hex_sum(char *hex_one,char *hex_two,char *carry){
    int len=0;
    // initilization of carry
    for(int a=0;a<max_digit;a++){
        carry[a]='0';
    }
    // length factors
    int h1_len = get_len(hex_one);
    int h2_len = get_len(hex_two);

    if(h1_len>h2_len){
        int temp_one=h1_len,temp_two=h2_len;
        while(temp_two>=0){
            hex_two[temp_one]=hex_two[temp_two];
            temp_two--;
            temp_one--;
        }
        // putting zero in empty bits
        for(int i=temp_one;i>=0;i--){
            hex_two[i]='0';
        }
    }

    else if(h1_len<h2_len){
        int temp_one=h1_len,temp_two=h2_len;
        while(temp_one>=0){
            hex_one[temp_two]=hex_one[temp_one];
            temp_two--;
            temp_one--;
        }
        // putting zero in empty bits
        for(int i=temp_two;i>=0;i--){
            hex_one[i]='0';
        }
    }

    else {
        len = h1_len;
    }
    int res=0;
    for(int j=len;j>=0;j--){
        int tmp_one=hex_one[j];
        int tmp_two=hex_two[j];
        int t=0;
        tmp_one=get_int(tmp_one);
        tmp_two=get_int(tmp_two);
        t=get_int(carry[j]);
        res=tmp_one+tmp_two+t;
        
        if(res>=base){
            res=res-base;
            
            res=get_char(res);
            sum[j]=res;
            carry[j-1]='1';
        }
        else {
            res=get_char(res);
            
            sum[j]=res;
            
        }
    }

}