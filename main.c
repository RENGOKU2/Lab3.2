#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double dividi(double a, double b, double c, double eps, double f(double x), int num, int var, int display); // !!!ПРОТОТИП функции
double secant(double a, double b, double c, double eps, double f(double x), int num, int var, int display);
double f(double x);

int main()
{

    int var, display, num = 0;
    double a, b, eps, c = 0, sTime, eTime, tTime;

    printf("\nChoose a variant: \n\t 1 - Bisection \n\t 2 - Secant");
    printf("\n\tOption: ");
    scanf("%d", &var);

    while (var != 1 && var != 2)
        {
        printf("\nInvalid option, try again.");
        printf("\n\tOption: ");
        scanf("%d", &var);
         }

    printf("\nChoose display mode: \n\t 1 - Default\n\t 2 - Show results on each iteration");
    printf("\n\tOption: ");
    scanf("%d", &display);

    while (display != 1 && display != 2)
        {
        printf("\nInvalid option, try again.");
        printf("\n\tOption: ");
        scanf("%d", &display);
        }

    if (display == 2)
        {
        printf("\nEnter the number of iterations: ");
        scanf("%d", &num);

        while (num <= 0)
              {
            printf("\nInvalid option, try again.");
            printf("\nEnter the number of iterations: ");
            scanf("%d", &num);
              }
          }

    printf("\nEnter a: ");
    scanf("%lf", &a);

    printf("\nEnter b: ");
    scanf("%lf", &b);

    while (a * b > 0)
        {
        printf("\nIncorrect values entered, try again.\n");

        printf("\n\tEnter a: ");
        scanf("%lf", &a);

        printf("\n\tEnter b: ");
        scanf("%lf", &b);
         }

    printf("\nEnter the accuracy (eps): ");
    scanf("%lf", &eps);

    sTime = clock();

    if (var == 1)
        {

       system("cls");

       printf("\nChosen variant: Bisection\n");
       c = dividi(a, b, c, eps, f, num, var, display);
       printf("\nRoot: %lf", c);
          }
    else if (var == 2)
        {

        system("cls");

        printf("\nChosen variant: Secant\n");
        c = secant(a, b, c, eps, f, num, var, display);
        printf("\nRoot: %lf", c);
         }



    eTime = clock();
    tTime = (eTime - sTime) / 1000;

    printf("\nTime passed: %.2lf seconds\n", tTime);

    return 0;
}


double dividi(double a, double b, double c, double eps, double f(double x), int num, int var, int display) {

    int iter = 1, doNext = 1;

    if (display == 2)
        {

        printf("----------------------------------------------------\n");
        printf("iter\ta\t\tb\t\tc\n");
        printf("----------------------------------------------------\n");

        do {

            c = (a + b) / 2;

            printf("\n%d.\t%lf\t%lf\t%lf\n", iter, a, b, c);

            if (f(a) * f(c) > 0)
                {
                a = c;
                  }
            else if (f(a) * f(c) < 0)
             {
                b = c;
               }

            iter++;

            if (iter >= num && doNext == 1)
                {

                printf("\nThe amount of iterations > chosen iteration steps.\nWhat to do next?\n");
                printf("\n\t[1] - Continue\n\t[2] - Continue until root were found\n\t[3] - Show current results and exit the program");
                printf("\n\tOption: ");
                scanf("%d", &doNext);

                if (doNext == 1)
                    {
                    num += iter;
                     }

                else if (doNext == 2)
                    {
                    num *= 0;
                     }

                else if (doNext == 3)
                    {
                    break;
                      }

                while (doNext != 1 && doNext != 2 && doNext !=3)
                    {
                    printf("\nInvalid option, try again.");
                    printf("\n\tOption: ");
                    scanf("%d", &doNext);
                     }
              }

        } while (fabs(a - b) >= eps);
      }
    else
        {

        do {

            c = (a + b) / 2;

            if (f(a) * f(c) > 0)
                {
                a = c;
                 }
            else if (f(a) * f(c) < 0)
             {
                b = c;
               }

            iter++;

        } while (fabs(a - b) >= eps);
       }

    return c;
}

double secant(double a, double b, double c, double eps, double f(double x), int num, int var, int display)
 {

    int iter = 1, doNext = 1;

    if (display == 2)
        {

        printf("----------------------------------------------------\n");
        printf("iter\ta\t\tb\t\tc\n");
        printf("----------------------------------------------------\n");

        do {

            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            a = b;
            b = c;

            printf("\n%d.\t%lf\t%lf\t%lf\n", iter, a, b, c);

            iter++;

            if (iter >= num && doNext == 1)
                {

                printf("\nThe amount of iterations > chosen iteration steps.\nWhat to do next?\n");
                printf("\n\t[1] - Continue\n\t[2] - Continue until root were found\n\t[3] - Show current results and exit the program");
                printf("\n\tOption: ");
                scanf("%d", &doNext);

                if (doNext == 1)
                    {
                    num += iter;
                     }

                else if (doNext == 2)
                    {
                    num *= 0;
                    }

                else if (doNext == 3)
                    {
                    break;
                     }

                while (doNext != 1 && doNext != 2 && doNext != 3)
                    {
                    printf("\nInvalid option, try again.");
                    printf("\n\tOption: ");
                    scanf("%d", &doNext);
                    }
            }

        } while (fabs(f(c)) > eps);
    }

    else
        {
        do {

            c = (a * f(b) - b * f(a)) / (f(b) - f(a));

            a = b;
            b = c;

            iter++;

        } while (fabs(f(c)) > eps);
    }

        return c;
}


double f(double x) {
    return  pow(x + 50, 5) * sin((x-5)/60) - pow(x-15, 3) - 3 * pow(x, 2) - 20;
}
