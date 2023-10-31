#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{

    int port, mat, contador = 0;
    float red;

    while (1)
    {

        scanf("%d", &port);
        scanf("%d", &mat);
        scanf("%f", &red);

        if (port < 0)
        {
            break;
        }
        else
        {
            if (port >= 40 && mat >= 21 && red >= 7)
            {
                contador++;
            }
        }
    }

    printf("%d\n", contador);

    return 0;
}
