#include <stdio.h>
#include <math.h>

void zbrak(float (*fx)(float), float x1, float x2, int n, float xb1[], float xb2[], int *nb);
float rtbis(float (*func)(float), float x1, float x2, float xacc);
float rtflsp(float (*func)(float), float x1, float x2, float xacc);
float rtsec(float (*func)(float), float x1, float x2, float xacc);
float rtnewt(void (*funcd)(float, float *, float *), float x1, float x2, float xacc);
float rtsafe(void (*funcd)(float, float *, float *), float x1, float x2, float xacc);
float muller(float (*func)(float), float x1, float x2, float xacc);
float function3_1(float x);
void func_final3(float x, float *y, float *dy);

void part3()
{
    const float x1 = -1300;
    const float x2 = 1200;
    const int diff = 10000000;
    const int max_roots = 10;
    const float xacc1 = 1e-4;
    const float xacc2 = 1e-6;

    int i;
    int nb = max_roots;
    float xb1[max_roots], xb2[max_roots], root;
    zbrak(function3_1, x1, x2, diff, xb1, xb2, &nb);
    printf("\n--------------------------------------------------------\n");
    printf("Solving problem 8.36\n\n");
    printf("==================Bisection(rtbis.c)==================\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtbis(function3_1, xb1[i], xb2[i], xacc1);
        printf("%dth root with 1e-4: %f\n", i, root);
    }
    printf("\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtbis(function3_1, xb1[i], xb2[i], xacc2);
        printf("%dth root with 1e-6: %f\n", i, root);
    }

    printf("\n");

    printf("==================Linear interpolation(rtflsp.c)==================\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtflsp(function3_1, xb1[i], xb2[i], xacc1);
        printf("%dth root with 1e-4: %f\n", i, root);
    }
    printf("\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtflsp(function3_1, xb1[i], xb2[i], xacc2);
        printf("%dth root with 1e-6: %f\n", i, root);
    }

    printf("\n");

    printf("==================Secant(rtsec.c)==================\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtsec(function3_1, xb1[i], xb2[i], xacc1);
        printf("%dth root with 1e-4: %f\n", i, root);
    }
    printf("\n");
   /* for (i = 1; i <= nb; i++)
    {
        root = rtsec(function3_1, xb1[i], xb2[i], xacc2);
        printf("%dth root with 1e-6: %f\n", i, root);
    }
*/
    printf("\n");

    printf("==================Newton-Rhpason(rtnewt.c)===================\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtnewt(func_final3, xb1[i], xb2[i], xacc1);
        printf("%dth root with 1e-4: %f\n", i, root);
    }
    printf("\n");
    /*for (i = 1; i <= nb; i++)
    {
        root = rtnewt(func_final3, xb1[i], xb2[i], xacc2);
        printf("%dth root with 1e-6: %f\n", i, root);
    }
*/
    printf("\n");

    printf("==================Newton with bracketing(rtsafe.c)==================\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtsafe(func_final3, xb1[i], xb2[i], xacc1);
        printf("%dth root with 1e-4: %f\n", i, root);
    }
    printf("\n");
    for (i = 1; i <= nb; i++)
    {
        root = rtsafe(func_final3, xb1[i], xb2[i], xacc2);
        printf("%dth root with 1e-6: %f\n", i, root);
    }

    printf("\n");

    printf("==================Muller Method==================\n");
    for (i = 1; i <= nb; i++)
    {
        root = muller(function3_1, xb1[i], xb2[i], xacc1);
        printf("%dth root with 1e-4: %f\n", i, root);
    }
    printf("\n");
    for (i = 1; i <= nb; i++)
    {
        root = muller(function3_1, xb1[i], xb2[i], xacc2);
        printf("%dth root with 1e-6: %f\n", i, root);
    }
}