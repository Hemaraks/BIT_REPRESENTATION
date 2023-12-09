#include<stdio.h>

#define max_digit 1000

char sum[max_digit];

int cal_sum(char *num_one,char* num_two,char *carry,int base);
int check_get_len(char *n,int b);

int main(void)
{
    char carry[max_digit];
    int base=2;

    char num_one[max_digit]={'0','1','1','1','0'}; // 0 is import at the first digit as a default
    char num_two[max_digit]={'0','1','1','0','0'};

    cal_sum(num_one,num_two,carry,base);
    printf("%s",sum);
    // check_get_len(num_one,base);
    return 0;
}

int check_get_len(char *n,int b){
    int t=0,len=0;
    for(int i=0;*(n+i)!='\0';i++){
        t=((int)*(n+i))-48; // 48 would convert asci into actual int value
        if(t>=b){
            return -1;
        }
        else{
            len++;
        }
        // printf("%i\n",t);    
    }
    return len-1; 
}

int cal_sum(char *num_one,char* num_two,char *carry,int base){
    int len=0,res=0;
    // for initilization of carry 
    for(int a=0;a<max_digit;a++){
            carry[a]='0';
        }
    // num one len:
    int n1_len = check_get_len(num_one,base);
    if(n1_len<0){
        printf("Invalid Base Given For NUM 1\n");
        return -1;
    }
    // num two len:
    int n2_len = check_get_len(num_two,base);
    if(n2_len<0){
        printf("Invalid Base Given For NUM 2\n");
        return -1;
    }
    // digit systamization
    if(n2_len<n1_len){
        int temp_one=n1_len,temp_two=n2_len;
        while(temp_two>=0){
            num_two[temp_one]=num_two[temp_two];
            temp_one--;
            temp_two--;
        }
        for(int j=temp_one;j>=0;j--){
            num_two[j]='0';
        }
        len=n1_len;
    }
    else if(n2_len>n1_len){
        int temp_one=n1_len,temp_two=n2_len;
        while(temp_one>=0){
            num_one[temp_two]=num_one[temp_one];
            temp_one--;
            temp_two--;
        }
        for(int j=temp_two;j>=0;j--){
            num_one[j]='0';
        }
        len=n2_len;
    }
    else len = n1_len;

    printf("%s",num_one);
    printf("\n");
    printf("%s",num_two);
    printf("\n");
    for(int i=len;i>=0;i--){
        res=(((int)num_one[i])-48)+(((int)num_two[i])-48)+(((int)carry[i])-48);
        // printf("%i\n",res);
        if(res>=base){
            sum[i]=(res-base)+48;
            carry[i-1]='1';
        }
        else {
            sum[i]=res+48;
        }
    }
    
}