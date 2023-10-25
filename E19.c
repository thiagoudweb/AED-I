#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main(){
   
int x,y,i;
scanf("%d", &x);

for (i = 1; i <=10; i++)
{
    y = x*i;
    printf("%d\n",y );
}


return 0;

}

// pegue todos os 10 primeiros múltiplos do número da entrada, sem usar condicional(if)
// um número N, inteiro maior que 0
// todos os 10 primeiro múltiplos de N