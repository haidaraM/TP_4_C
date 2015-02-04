#ifndef HEURE_H
#define HEURE_H

#include <sys/resource.h>
#include <sys/time.h>

/* Petite interface permettant le calcul du temps que le programme à passé
 dans une suite d'instructions */

inline double give_time()
{
    struct rusage ru;
    struct timeval tim;
    getrusage(RUSAGE_SELF, &ru);

    tim = ru.ru_utime;

    double stime = (double)tim.tv_sec + (double)tim.tv_usec / 1000000.0;

    return stime;
}

#endif