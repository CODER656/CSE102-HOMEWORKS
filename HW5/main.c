/*Furkan TAŞKIN 200104004072 HW5cd*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14
enum {Exit,Triangle,Quadrilateral,Circle,Pyramid,Cylinder};/*declarin enum for use in switch */
enum {Exit2,Area,Perimeter,Volume};

int calc_triangle(int);
int calc_quadrilateral(int);
int calc_circle(int);
int calc_pyramid(int);
int calc_cylinder(int);
int select_shape ();
int select_calc ();
int calculate (int (), int ());
void my_fflush();

int main()
{

  calculate(&select_shape,&select_calc);
  return 0;
}


  int select_shape ()
  {
       int select,flag=0,i;

       printf("\nWelcome to the geometric calculator!\n\n");
       printf("Select a shape to calculate:\n");
       printf("----------------------------\n");
       printf("1. Triangle\n");
       printf("2. Quadrilateral\n");
       printf("3. Circle\n");
       printf("4. Pyramid\n");
       printf("5. Cylinder\n");
       printf("0. Exit\n");
       printf("---------------------------\n");
       printf("Input:");

       scanf("%d",&select);
       my_fflush();

       while (flag!=1)
       {
           if (select>=0 && select<=5)/*checking if input is true*/
           {
               flag=1; /*change flag to exti loop*/
               return select;
           }
           else
           {
               printf("ERROR! Please enter a valid input.\n");
               scanf("%d",&select);
               my_fflush();
           }
       }
       my_fflush();
    printf("\n\n");

}

   int select_calc ()
   {
      int calculator,flag=0;

      printf("\nSelect calculator:\n");
      printf("---------------------------\n");
      printf("1. Area\n");
      printf("2. Perimeter\n");
      printf("3. Volume\n");
      printf("0. Exit\n");
      printf("---------------------------\n");
      printf("Input: ");


      scanf("%d",&calculator);
      my_fflush();

      while (flag!=1)
      {
          if (calculator>=0 && calculator<=3)
          {
              flag=1;
              return calculator;
          }
          else
          {
              printf("ERROR! Please enter a valid input.\n");
              scanf("%d",&calculator);
              my_fflush();
          }
      }
      my_fflush();
  printf("\n\n");
}


  int calculate (int (*shape)(), int (*cal)())
  {
      int ret_shape,ret_calc,flag=0;


     do {
         ret_shape=(*shape)(); /*gettin return values each time*/
         ret_calc=(*cal)();
         switch (ret_shape)
         {
             case Triangle:
               calc_triangle(ret_calc);
             break;

             case Quadrilateral:
               calc_quadrilateral(ret_calc);
             break;

             case Circle:
               calc_circle(ret_calc);
             break;

             case Pyramid:
                calc_pyramid(ret_calc);
             break;

             case Cylinder:
                calc_cylinder(ret_calc);
             break;

             case Exit:
               flag=1;
             break;
           }

         } while(flag!=1 && ret_calc!=0 );
      }


int calc_triangle(int geo_spec)
{
    float k1,k2,k3,area,semi_per,perimeter,flag=0,end=0;

    switch (geo_spec)
    {
      case Area:
          int ret_scan;
          printf("Please enter three sides of triangle:\n");

          semi_per=(k1+k2+k3)/2; /*find semi perimeter of the triangle*/

         do
         {
            ret_scan=scanf("%f%f%f", &k1,&k2,&k3); /*getting the input from user*/
            my_fflush();
            if (ret_scan != 3)
            {
                printf("Please enter a valid input\n");
                end=1; /*keeps asking until input is true*/

            }

            else
            {
                end=0; /*finishes the loop*/
            }

          }while(end==1 );
          /*doing neccesary calculations according to formula*/
          semi_per=(k1+k2+k3)/2;
          area=sqrt(semi_per*(semi_per-k1)*(semi_per-k2)*(semi_per-k3));
          printf("Area of the triangle:%.2f\n",area);


      break;

      case Perimeter:
          int cont_scan,stop=0;
          printf("Please enter three sides of triangle:\n");
          cont_scan=scanf("%f%f%f", &k1,&k2,&k3);
          my_fflush();

          semi_per=(k1+k2+k3)/2;

       while(stop!=1)
       {

         if (cont_scan!=3)
         {

              printf("ERROR! Please enter a valid entry.\n");
              scanf("%f%f%f", &k1,&k2,&k3);
              my_fflush();
         }
         else if ((k1<=0 || k2<=0 || k3<=0) || (k1+k2)<k3 || (k2+k3)<k1 || (k1+k3)<k2 || semi_per<k1 || semi_per<k2 || semi_per<k3)
         {

              printf("ERROR! Please enter a valid entry.ff\n");
              scanf("%f%f%f", &k1,&k2,&k3);
              my_fflush();
         }
          else
          {
            perimeter=k1+k2+k3;
            printf("Perimeter of triangle:%.2f\n",perimeter);
            stop=1;
          }

       }


      break;

      case Volume:
          printf("You can't calculate volume for triangle. Try again.\n");

      break;

      case Exit2:
         exit(0);
         break;
       }

    }



 int calc_quadrilateral(int geo_spec)
 {
      float k1,k2,k3,k4,s_per,area,perimeter,done=0,scan_ret;


      switch (geo_spec)
      {
        case Area:
          printf("Please enter four sides of quadrilateral:\n");

     do {
          scan_ret=scanf("%f%f%f%f", &k1,&k2,&k3,&k4);
          my_fflush();
          if (scan_ret!=4 || (k1<=0 || k2<=0 || k3<=0 || k4<=0))
          {
             printf("Please enter a valid input\n");
             done=1;
          }

          else
          {
             done=0;
          }

        } while(done==1);

        s_per=(k1+k2+k3+k4)/2;
        area=sqrt((s_per-k1) * (s_per-k2) * (s_per-k3) * (s_per-k4));
        printf("Area of quadrilateral:%.2f\n",area);


        break;

      case Perimeter:

        printf("Please enter four sides of quadrilateral:\n");


        do {
             scan_ret=scanf("%f%f%f%f", &k1,&k2,&k3,&k4);
             my_fflush();
             if (scan_ret!=4 || (k1<=0 || k2<=0 || k3<=0 || k4<=0))
             {
                printf("Please enter a valid input\n");
                done=1;
             }

             else
             {
                done=0;
             }

           } while(done==1);



           perimeter=k1+k2+k3+k4;
           printf("Perimeter of quadrilateral:%.2f\n",perimeter);
           done=1;




      break;

      case Volume:
         printf("You can't calculate volume for quadrilateral. Try again\n");
         return 0;
      break;

      case Exit2:
        return 0;
      break;
    }
}

  int calc_circle(int geo_spec)
{
      float circumference,area,radius,scan_ret,done=0;
      switch (geo_spec)
      {
        case Area:
             printf("Please enter the radius of circle:\n");
             scan_ret=scanf("%f",&radius);

         while(done!=1)
         {
            scan_ret=scanf("%f",&radius);
            my_fflush();
            if (scan_ret!=1 || radius<=0)
            {
               printf("ERROR! Please enter a valid entry.\n");
               scanf("%f", &radius);
               my_fflush();
            }
            else
            {
               area=PI*radius*radius;
               printf("Area of circle:%.2f\n",area);
               done=1;
            }
        }

        break;

        case Perimeter:
            printf("Please enter the radius of circle:\n");
            scan_ret=scanf("%f",&radius);

            while(done!=1)
            {
               if (scan_ret!=1 || radius<=0)
               {
                  printf("ERROR! Please enter a valid entry.\n");
                  scanf("%f", &radius);
                  my_fflush();
               }
              else
              {
                 circumference=2*PI*radius;
                 printf("Perimeter of circle:%.2f\n",circumference);
                 done=1;
              }
            }
        break;

        case Volume:
            printf("You can't calculate volume of circle.\n");

        break;

        case Exit2:
           return 0;
        break;
      }
}

  int calc_pyramid(int geo_spec)
{
    float base,height,volume,slant_height,base_area,lat_sur_area,sur_area,perimeter,scan_ret,done=0;
    switch (geo_spec)
    {
      case Area:
          printf("Please enter the base and slant height of a pyramid:\n");

          do {
               scan_ret=scanf("%f%f",&base,&slant_height);
               my_fflush();
               if (scan_ret!=2 || base<0 || slant_height<0)
               {
                  printf("Please enter a valid input\n");
                  done=1;
               }

               else
               {
                  done=0;
               }

             } while(done==1);


              base_area = base * base;
              lat_sur_area = 2 * base * slant_height;
              sur_area = base_area + lat_sur_area;

              printf("Base surface area of a pyramid:%.2f\n",base_area);
              printf("Lateral surface area of a pyramid:%.2f\n",lat_sur_area);
              printf("Surface area of a pyramid:%.2f\n",sur_area);



      break;

      case Perimeter:
          printf("Please enter the base side of pyramid\n");

          do {
               scan_ret=scanf("%f",&base);
               my_fflush();
               if (scan_ret!=2 || base<0 || slant_height<0)
               {
                  printf("Please enter a valid input\n");
                  done=1;
               }

               else
               {
                  done=0;
               }

             } while(done==1);

                perimeter=4*base;
                printf("Perimeter of pyramid is:%.2f\n",perimeter);
                done=1;



      break;

      case Volume:
          printf("Please enter the base side and height of a pyramid:\n");

          do {
               scan_ret=scanf("%f%f",&base,&height);;
               my_fflush();
               if (scan_ret!=2 || base<0 || height<0)
               {
                  printf("Please enter a valid input\n");
                  done=1;
               }

               else
               {
                  done=0;
               }

             } while(done==1);

                volume=(base*base*height)/3;
                printf("Volume of pyramid:%.2f\n",volume);




      break;

      case Exit2:
         return 0;
      break;
    }
}


  int calc_cylinder(int geo_spec)
  {
      float radius,height,volume,base_sur,lat_sur,surface,perimeter,scan_ret,done=0;
      switch (geo_spec)
      {
        case Area:
           printf("Please enter the radius and height of the cylinder:\n");

           do {
                scan_ret=scanf("%f%f",&radius,&height);;
                my_fflush();
                if (scan_ret!=2 || radius<0 || height<0)
                {
                   printf("Please enter a valid input\n");
                   done=1;
                }

                else
                {
                   done=0;
                }

              } while(done==1);

                 base_sur=PI*radius*radius;
                 lat_sur=2*PI*radius*height;
                 surface=2*PI*radius*(radius+height);

                 printf("Base surface area of cylinder:%.2f\n",base_sur);
                 printf("Lateral surface area of cylinder:%.2f\n",lat_sur);
                 printf("Surface area of cylinder:%.2f\n",surface);




        break;
        case Perimeter:
           printf("Please enter radius of cylinder:\n");

           do {
                scan_ret=scanf("%f",&radius);;
                my_fflush();
                if (scan_ret!=1 || radius<0)
                {
                   printf("Please enter a valid input\n");
                   done=1;
                }

                else
                {
                   done=0;
                }

              } while(done==1);


                 perimeter=2*PI*radius;
                 printf("Base surface area of a cylinder:%f\n",perimeter);
                 done=1;


        break;

        case Volume:
          printf("Please enter the radius and height of the cylinder:\n");

          do {
               scan_ret=scanf("%f%f",&radius,&height);;
               my_fflush();
               if (scan_ret!=2 || radius<0 || height<0)
               {
                  printf("Please enter a valid input\n");
                  done=1;
               }

               else
               {
                  done=0;
               }

             } while(done==1);

                volume=PI*radius*radius*height;
                printf("Volume of a cylinder:%.2f\n",volume);





        break;

        case Exit2:
           return 0;
        break;
      }
}

  void my_fflush()
  {
      while ( getchar() != '\n' );
}
