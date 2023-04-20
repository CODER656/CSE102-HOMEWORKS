#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
   int seq_len,first_el,digit;
   int *h;
   int *seq;
   int *loop;

   printf("Please enter the sequence lenght:");
   scanf("%d",&seq_len);
   printf("Please enter the first element:");
   scanf("%d",&first_el);

   seq=(int*)malloc(seq_len*sizeof(int));
   h=(int*)malloc(seq_len*sizeof(int));
   loop=(int*)malloc((seq_len/2)*sizeof(int));

   generate_sequence(first_el, 0, seq_len, seq);

   printf("\n\nSequence:{");
   for (int i = 0; i < seq_len; i++)
   {
       if(i==seq_len-1)
         printf("%d}",seq[i]);
       else
         printf("%d, ",seq[i]);
   }
   int loop_start=seq_len/2;
   check_loop_iterative(&generate_sequence,first_el,seq_len,loop,&loop_start);



   hist_of_firstdigits(&generate_sequence,first_el,seq_len,h,1);
   printf("\n\n");
   printf("Histogram:{");

   for (int i = 0; i < 9; i++)
   {
      if(i==8)
        printf("%d}",h[i]);
      else
        printf("%d, ",h[i]);
   }
   printf("\n\n");

   free(seq);
   free(h);
   free(loop);
  return 0;
}
