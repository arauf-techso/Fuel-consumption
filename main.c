#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void clrscr()
{
    system ("cls");
}

char charYorN()
{
    int loop = 1;
    char input = 0;
    while (loop != 0)
    {
        input = getch();
        if (input >= 97 || input <= 122)
        {
            if(input == 'y' || input == 'n')
            {
                printf("%c",input);
                return input;
            }
        }
    }
}

void main()
{
    int times = 0, i = 1;
    float traveled_km[2], fuel[2], added_fuel = 0, average = 0,total_fuel = 0,total_mileage = 0;
    char yorn = 0;

    printf("\n\t\t\t============================================================");
    printf("\n\t\t\t\t    *** Your Journey Fuel Details ***");
    printf("\n\t\t\t============================================================\n\n");

    do
    {
        if (i != 1)
        {
            printf(" Ending mileage can't be less than starting mileage!");
            printf("\n Again enter details of your journey.\n");
        }
        printf(" Enter mileage at the start of journey (kilometers): ");
        scanf("%f",&traveled_km[0]);
        printf(" -|Enter mileage at the end of journey (kilometers): ");
        scanf("%f",&traveled_km[1]);
        i++;
    }
    while(traveled_km[0] > traveled_km[1]);

    for (;;)
    {
        printf(" --------------|Enter fuel level at start (litters): ");
        scanf("%f",&fuel[0]);
        total_fuel += fuel[0];
        printf(" ------------|Enter fuel level at the end (litters): ");
        scanf("%f",&fuel[1]);
        printf("\n Have you refilled your fuel tank anywhere?\n ---------|Press Y for yes and N for no: ");
        yorn = charYorN();
        if (yorn == 'y')
            goto refilling;
        if (fuel[0] < fuel[1])
        {
            printf("\n\n Your fuel at the end of journey is more then when you started!");
            printf("\n Have you refilled your fuel tank anywhere?\n --------|Press Y for yes and N for no : ");
            yorn = charYorN();
            if (yorn == 'n')
            {
                printf("\n Then your input is wrong...\n\n Again enter fuel input.\n");
                continue;
            }
            else if (yorn == 'y');
            {
                refilling:
                printf("\n How many times: ");
                scanf("%d",&times);
                if (times <= 0)
                    break;
                for (int i = 1; i <= times; i++)
                {
                    printf(" How much for %d%s time: ",i,(i == 1)?"st":(i == 2)?"nd":(i == 3)?"rd":(i > 3)?"th":" ");
                    scanf("%f",&added_fuel);
                    total_fuel += added_fuel;
                }
                break;
            }
        }
        break;
    }
    printf("\n\n****************************************************");
    total_mileage = traveled_km[1] - traveled_km [0];
    printf("\n Total mileage: %.3f km%c",total_mileage,(total_mileage == 1)?' ':'s');
    printf("\n Total fuel: %.3f litter%c",total_fuel,(total_fuel == 1)?' ':'s');
    total_fuel -= fuel[1];
    printf("\n Total used fuel: %.3f litter%c",total_fuel,(total_fuel == 1)?' ':'s');
    average = total_mileage / total_fuel;
    printf("\n Average (km/l): %.3f",average);
    printf("\n****************************************************");

    getch();
}
