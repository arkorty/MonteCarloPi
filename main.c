#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEED time(NULL)

/* find the value of Pi only using a randomizer function that always gives a
 * value between 0 and 1 inclusively
 */

double drand() {
    /* RAND_MAX = 2147483647 [On Modern Systems]
     * rand() = [0..RAND_MAX]
     * rand() / RAND_MAX = [0..1]
     *
     * Example:-
     *
     *   RAND_MAX = 2147483647
     *   rand() = 982347928
     *   rand() / RAND_MAX -> 982347928 / 2147483647 -> 0.457..
     */

    double ran = (double)rand();   // converting to double for more precision
    double max = (double)RAND_MAX; // converting to double for more precision

    double rfin = ran / max;

    return rfin;
}

double get_pi(int n) {
    /* Algorithm:-
     *
     *   1. get two random numbers between 0 and 1 inclusively and use them as
     *      coordinates for a point
     *   2. repeat the last step n number of times to get n number of points
     *   3. count all the points inside the circle using the distance formula
     *   4. isolate the value of Pi using the special formula below
     *
     * Formula of a circle of radius r:-
     *
     *   r = x^2 + y^2
     *
     * Special formula:-
     *
     *   Pi ~= 4 * number of points inside the circle / total number of points
     */

    int acir = 0; // number of points inside the circle

    // calculate the number of points inside the circle
    for (int i = 0; i < n; ++i) {
        double xcor = drand(); // x coordinate
        double ycor = drand(); // y coordinate
        printf("[ %lf, %lf ]\n", xcor, ycor);

        double dist = xcor * xcor + ycor * ycor; // distance from origin

        if (dist <= 1)
            ++acir; // increment if radius is less than or equal to 1
    }
    double pi = 4 * (double)acir / (double)n; // isolating the value of Pi

    return pi;
}

int main() {
    srand(SEED); // use Unix time as the seed for the randomizer

    int n = 1000000;       // number of points used to estimate the value of Pi
    double pi = get_pi(n); // estimate the value of Pi
    printf("\nPi = %lf\n", pi); // print the result

    return 0;
}
