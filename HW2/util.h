/*Furkan Taşkın 200104004072 */
#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001
#define Versicolor 2
#define Setosa 1
#define Virginica 3

#define Nate 1
#define Fez 2
#define Cal 3
#define Ali 4
#define Mckay 5
#define Maddy 6
#define Lexi 7
#define Gia 8
#define Cassie 9
#define Kat 10
#define Rue 11
#define Jules 12

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(float PL, float PW, float SL, float SW);
char dt1b(float PL, float PW, float SL, float SW);

double dt2a(double x1, double x2, double x3, int x4, int x5);
double dt2b(double x1, double x2, double x3, int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(int gender,double height,double weight,int eye_color,int zodiac);
int dt3b(int gender,double height,double weight,int eye_color,int zodiac);


void print_third(int e,int f);
void print_only_one(int e);
void print_first(int a ,int b);
void print_frst_one_time(int a);
#endif /* _UTIL_H_ */
