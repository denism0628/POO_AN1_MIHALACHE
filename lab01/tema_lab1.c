///1
/*#include <iostream>

int f_atoi(const char *str){
    int rez=0;
    int semn=1;
    int i=0;
    if(str[i]=='-'||str[i]=='+')
      if(str[i]=='-')
        {
            semn=-1;
            i++;
        }
    
    
    while(str[i]>='0'&&str[i]<='9'){
        rez=rez*10+(str[i]-'0');
        i++;
    }
    return semn*rez;
}
int main()
{
    FILE *file;
    long long sum=0;
    char s[256];
    file=fopen("in.txt","r");

    if (file==NULL){
        printf("Eroare:Nu am gasit fisierul in.txt!\n");
        return 1; 
    }

    while(fgets(s,sizeof(s),file)!=NULL)
        sum+=f_atoi(s);

    fclose(file);
    printf("%lld\n",sum);

    return 0;
}*/

///2
/*#include <iostream>
#include <string.h>

int main()
{
    char s[256];
    char cuv[100][50];
    int nrcuv=0;
    if(scanf("%[^\n]",s)!=1)
       return 0;

    int i=0;
    while(s[i]!='\0'){
        while(s[i]==' ')
            i++;
        if(s[i]=='\0')
           break;

        int j=0;
        while(s[i]!=' '&&s[i]!='\0'){
            cuv[nrcuv][j]=s[i];
            i++;
            j++;
        }
        cuv[nrcuv][j]='\0';
        nrcuv++;
    }

    for(int x=0;x<nrcuv-1;x++)
      for(int y=x+1;y<nrcuv;y++){
        int lg_x=strlen(cuv[x]);
        int lg_y=strlen(cuv[y]);

        if(lg_y>lg_x || (lg_x==lg_y && strcmp(cuv[y],cuv[x])<0)){
            char aux[50];
            strcpy(aux,cuv[x]);
            strcpy(cuv[x],cuv[y]);
            strcpy(cuv[y],aux);
        }
      }

    for(int x=0;x<nrcuv;x++)
       printf("%s\n",cuv[x]);
    return 0;
}*/


///3
#include <iostream>
#include <stdbool.h>

bool isPrime(int n)
{
    if(n<=1) return false;
    for (int tr = 2; tr <= n /2; tr++)
        if ((n % tr ) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    if (isPrime(n))
        printf("%d is prime!",n);
    else 
        printf("%d is not prime",n);
    return 0;
}
