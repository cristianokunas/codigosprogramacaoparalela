#include <sys/time.h>
#include <string.h>
#include <stdio.h>

struct timeval t1, t2;
struct timezone tz1, tz2;

char MSGLOG[200];  // armazena o log no arquivo


void tempo1() {
   gettimeofday(&t1, &tz1);
}

void tempo2() {
   gettimeofday(&t2, &tz2);
}

void tempoFinal(const char *medida, char *nomeArquivo, char *msglog) {
   char tempo[50];
   long int micro = (((t2.tv_sec*1000000)+t2.tv_usec) - ((t1.tv_sec*1000000)+t1.tv_usec));
    if (strcmp(medida,"")==0)
       sprintf(tempo,"%.2f s", micro / 1000000.0);
    if (strcmp(medida,"micro segundos")==0)
       sprintf(tempo,"%ld us", micro);
    if (strcmp(medida,"mili segundos")==0)
       sprintf(tempo,"%.2f ms", micro / 1000.0);
    if (strcmp(medida,"segundos")==0)
       sprintf(tempo,"%.2f s", micro / 1000000.0);
    if (strcmp(medida,"minutos")==0)
       sprintf(tempo,"%.2f min", (micro / 1000000.0) / 60);
    if (strcmp(medida,"horas")==0)
       sprintf(tempo,"%.2f horas", ((micro / 1000000.0) / 60)) / 60;

    printf("%s", tempo);
}