/*Furkan Taşkın 200104004072 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"


int main() {
    int select,a,b,x4,x5,e,f,gender,eye_color,zodiac,compare3;
    float PL,PW,SL,SW;
    double x1,x2,x3,c,d,height,weight,compare2;

    printf("Which problem do you want to solve?(Select from 1,2,3)\n");
    scanf("%d",&select); /*getting problem selection from user*/

    if (select!=1 && select!=2 && select!=3)/*checking selection input*/
        printf("Please select from 1,2 or 3.\n");


    switch (select)
    {
      case 1:
          printf("Please enter petal lenght(PL):\n");
          scanf("%f",&PL);
          printf("Please enter petal widht(PW):\n");
          scanf("%f",&PW);
          printf("Please enter sepal lenght(SL):\n");
          scanf("%f",&SL);
          printf("Please enter sepal widht(SW):\n");
          scanf("%f",&SW);

          /*assigning return values to integers*/
          a=dt1a(PL,PW,SL,SW);
          b=dt1b(PL,PW,SL,SW);


          if (a==b) /*checking equality */
            print_frst_one_time(a);/*if equal print just one time*/
          else
            print_first(a,b); /*printning all results*/

          break;


      case 2:
          /*getting numbers from user and checking */
          printf("x1=");
          scanf("%lf",&x1);
          printf("x2=");
          scanf("%lf",&x2);
          printf("x3=");
          scanf("%lf",&x3);
          printf("x4(0 or 1)=");
          scanf("%d",&x4);
          while(x4!=0 && x4!=1)
          {
            printf("x4=");
            scanf("%d",&x4);

          }
          printf("x5(0 or 1)=");
          scanf("%d",&x5);
          while(x5!=0 && x5!=1 )
          {
            printf("x5=");
            scanf("%d",&x5);
          }
          c=dt2a(x1,x2,x3,x4,x5);
          d=dt2b(x1,x2,x3,x4,x5);

          compare2=c-d; /*substracting return values to compare*/
          if (compare2<0) {
            compare2*=-1; /*convert negatif number to pozitif*/
          }

        if (c==d || compare2<=CLOSE_ENOUGH) /*same or close enough to be count same*/
            printf("%.2lf\n",(c+d)/2 ); /*printing average*/
        else
        {
          printf("First tree's result:%.2lf\n",c);
          printf("Second tree's result:%.2lf\n",d);
        }
        break;


      case 3:
      /*I was inspired by great tv series Euphoria. Maybe this can be little bit more interesting.
      Program could ask the user what character he/she looks like in the tv series*/
      /*Tree was implemented according to real data*/
      /*Visualisation of tree and datas of characters will also be submitted*/
      printf("\nThis program helps you to find the great television series Euphoria's characters.\n");
      printf("You can specify physical appearances.\n");

      /*getting inputs and checking them*/
      printf("Gender:\n");
      printf("male=1 female=0\n");
      scanf("%d",&gender);
      while(gender!=0 && gender!=1)
      {
        printf("Gender:");
        scanf("%d",&gender);
      }
      printf("Height:");
      scanf("%lf",&height);
      printf("Weight:");
      scanf("%lf",&weight);
      printf("Eye color:\n");/*hazel=1  blue=2  brown=3  black=4 green=5*/
      printf("hazel=1  blue=2  brown=3  black=4 green=5\n");
      scanf("%d",&eye_color);
      while (eye_color!=1 && eye_color!=2 && eye_color!=3 && eye_color!=4 && eye_color!=5)
      {
        printf("Eye color:");
        scanf("%d",&eye_color);
      }
      printf("Zodiac:\n");
      printf("virgo=1  sagittarius=2  cancer=3  scorpio=4  capricorn=5\n");
      scanf("%d",&zodiac);
      while (zodiac!=1 && zodiac!=2 && zodiac!=3 && zodiac!=4 && zodiac!=5)
      {
        printf("Zodiac:");
        scanf("%d",&zodiac);
      }

      e=dt3a(gender,height,weight,eye_color,zodiac);
      f=dt3b(gender,height,weight,eye_color,zodiac);

      compare3=e-f;
      if (compare3<0) {
        compare3*=-1; /*same as 72nd line*/
      }


      if(e==f || compare3<=CLOSE_ENOUGH)
        print_only_one(e);
      else
        print_third(e,f);

      break;

    default:
       printf("Invalid input\n"); /*default case for wrong input*/

    }

    return 0;
}
