/*Furkan Taşkın 200104004072 */
#include <stdio.h>
#include <math.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
 int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}

  char dt1a(float PL, float PW, float SL, float SW)
  {
      /*This program finds the type of Iris flower*/
      /*bunch of if statements for implementing the tree*/
      char ret_a=0; /*return value*/
      if (PL<2.45f)
        ret_a=Setosa;/* returning setosa*/
      else
      {
         if (PW<1.75f)
         {
            if (PL<4.95f)
            {
                if (PW<1.65f)
                  ret_a=Versicolor; /*returning versicolor*/
                else
                  ret_a=Virginica; /*returning virginica*/
            }
            else
              ret_a=Virginica;/*returning virginica*/
         }
         else
            ret_a=Virginica;/*returning virginica*/

      }
  return ret_a;
  }


  char dt1b(float PL, float PW, float SL, float SW)
  {
   char ret_b=0;

    if (PL<2.55f) {
      ret_b=Setosa;/*setosa*/
    }
    else
    {
        if (PW<1.69f)
        {
           if (PL<4.85f)
             ret_b=Versicolor; /*versicolor*/
           else
             ret_b=Virginica; /*virginica*/
        }
        else
            ret_b=Virginica;  /*virginica*/
     }

   return ret_b;
}


  double dt2a(double x1, double x2, double x3, int x4, int x5)
  {

    if(x1<31.5)
    {
         if(x2>-2.5)
           return 5.0;  /*5.0*/
         else
         {
            if((x2-0.1)<=x1 && x1<=(x2+0.1))
              return 2.1;  /*2.1*/
            else
              return -1.1;  /*-1.1*/
         }
    }
    else
    {
         if(x3>=-1 &&  x3<=2)
           return 1.4; /*1.4*/
         else
         {
            if(x4 & x5)
              return -2.23; /*-2.33*/
            else
              return +11.0; /*11.0*/
         }
    }

  }

   double dt2b(double x1, double x2, double x3, int x4, int x5)
   {

       if(x1>12 && x1<22)
        {
           if(x3> (double) 5/3)
             return -2.0; /*-2.0*/
           else
           {
             if((x1-0.1)<=x3 && x3<=(x1+0.1))
               return (double)1.01; /*1.01*/
             else
               return -8; /*-8*/
           }

        }
       else
       {
          if(x4 & x5)
            return -1;  /*-1*/
          else
          {
              if(x2>=-1 && x2<=2)
                return (double)-1/7;  /*-1/7*/
              else
                return sqrt(2)/3; /*kök2/3*/
          }
       }

    }


  int dt3a(int gender,double height,double weight,int eye_color,int zodiac)
  {
    /*virgo=1  sagittarius=2  cancer=3  scorpio=4  capricorn=5*/
    /*hazel=1  blue=2  brown=3  black=4 green=5*/
    /*male=1  female=0*/
    /*All names of characters are defined in util.h*/
    /*Tree implementation by the definition of the tree using if statements*/
     if (gender==1)
     {
         if (zodiac==3)
         {
             if(height<1.85)
               return Nate; /*nate*/
             else
               return Fez; /*fez*/
         }
         else
         {
              if(eye_color==2)
                return Cal; /*cal*/
              else
              {
                 if (weight>65)
                   return Ali; /*ali*/
                 else
                   return Mckay;  /*mckay*/
              }
         }
     }
     else
     {
        if (height<1.78)
        {
            if (weight<70)
            {
                if (zodiac==2)
                {
                    if (eye_color==3)
                      return Maddy; /*maddy*/
                    else
                      return Lexi; /*lexi*/
                }
                else
                    if(height<1.65)
                      return Gia;  /*gia*/
                    else
                      return Cassie;  /*cassie*/
            }
            else
               return Kat; /*kat*/
        }
        else
        {
            if(eye_color==1)
              return Rue; /*rue*/
            else
              return Jules; /*jules*/
        }
     }

  }

  int dt3b(int gender,double height,double weight,int eye_color,int zodiac)
  {
    /*virgo=1  sagittarius=2  cancer=3  scorpio=4  capricorn=5*/
    /*hazel=1  blue=2  brown=3  black=4*/
    /*male=1  female=0*/
    /*Different version of dt3a. It produces different results.*/


       if (weight<65)
       {
          if (height<1.70)
          {
            if(gender==0)
            {
               if (eye_color==3)
                 return Maddy;/*maddy*/
               else
               {
                 if(zodiac==1)
                    return Cassie;/*cassie*/
                 else
                    return Lexi; /*lexi*/
               }
            }
          else
             return Mckay; /*mackay*/
          }
          else
          {
            if(eye_color==3)
              return Gia; /*gia*/
            else
              return Rue; /*rue*/
          }
       }

      else
      {
         if (eye_color==2)
         {
             if (height>1.80)
             {
                if(gender==1)
                  return Fez;/*fez*/
                else
                  return Jules; /*jules*/
             }
             else
                return Cal; /*cal*/
         }
         else
         {
            if(zodiac==2)
            {
              if (weight>85)
               return Kat;/*kat*/
              else
               return Ali;/*ali*/
            }
            else
              return Nate; /*nate*/
         }
      }
}

void print_third(int e,int f){
/*This function prints the names from dt3a and dt3b*/
   if(e==Nate)
     printf("Nate\n");
   if(e==Fez)
     printf("Fez\n");
   if(e==Cal)
     printf("Cal\n");
   if(e==Ali)
     printf("Ali\n");
   if(e==Mckay)
     printf("Mckay\n");
   if(e==Maddy)
     printf("Maddy\n");
   if(e==Lexi)
     printf("Lexi\n");
   if(e==Gia)
     printf("Gia\n");
   if(e==Cassie)
     printf("Cassie\n");
   if(e==Kat)
     printf("Kat\n");
   if(e==Rue)
     printf("Rue\n");
   if(e==Jules)
     printf("Jules\n");

       if(f==Nate)
         printf("Nate\n");
       if(f==Fez)
         printf("Fez\n");
       if(f==Cal)
         printf("Cal\n");
       if(f==Ali)
         printf("Ali\n");
       if(f==Mckay)
         printf("Mckay\n");
       if(f==Maddy)
         printf("Maddy\n");
       if(f==Lexi)
         printf("Lexi\n");
       if(f==Gia)
         printf("Gia\n");
       if(f==Cassie)
         printf("Cassie\n");
       if(f==Kat)
         printf("Kat\n");
       if(f==Rue)
         printf("Rue\n");
       if(f==Jules)
           printf("Jules\n");
}


void print_only_one(int e)
{
  /*This function prints third tree's results just one time if results are same*/
  if(e==Nate)
    printf("Nate\n");
  if(e==Fez)
    printf("Fez\n");
  if(e==Cal)
    printf("Cal\n");
  if(e==Ali)
    printf("Ali\n");
  if(e==Mckay)
    printf("Mckay\n");
  if(e==Maddy)
    printf("Maddy\n");
  if(e==Lexi)
    printf("Lexi\n");
  if(e==Gia)
    printf("Gia\n");
  if(e==Cassie)
    printf("Cassie\n");
  if(e==Kat)
    printf("Kat\n");
  if(e==Rue)
    printf("Rue\n");
  if(e==Jules)
    printf("Jules\n");
}

void print_first(int a ,int b){
/*Print both results from dt1a and dt1b*/
  if(a==1)
    printf("Setosa\n");
  if(a==2)
    printf("Versicolor\n");
  if(a==3)
    printf("Virginica\n");

  if(b==1)
    printf("Setosa\n");
  if(b==2)
    printf("Versicolor\n");
  if(b==3)
    printf("Virginica\n");
}


void print_frst_one_time(int a){
 /*This function prints first tree's results just one time if results are same*/
  if(a==1)
    printf("Both tree:Setosa\n");
  if(a==2)
    printf("Both tree:Versicolor\n");
  if(a==3)
    printf("Both tree:Virginica\n");


}
