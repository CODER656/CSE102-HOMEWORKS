#include <stdio.h>
#include <stdlib.h>
#include "util.h"


void generate_sequence (int xs, int currentlen, int seqlen, int *seq)
{
   if(currentlen<seqlen) /*recursive step, for current lenght */
   {
      seq[currentlen]=xs;/*equalizing first element to sequence array recursively*/
      if(xs%2==0)  /*if xs is even*/
        generate_sequence(xs/2, currentlen+1, seqlen, seq);/*recursive call according to collatz conjecture*/
      else
        generate_sequence(xs*3+1, currentlen+1, seqlen, seq);
   }
}


void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop,int *looplen)
{
    int a,j,i;
    int last_index,first_index,*sequence_array;
    sequence_array=(int *)malloc(seqlen*sizeof(int));

    f(xs, 0, seqlen, sequence_array);

    if (*looplen==2)/*base condition*/
    {
       if (has_loop(sequence_array, seqlen, *looplen, &first_index, &last_index)==EXIST)/*if loop exist*/
       {
           *looplen= last_index-first_index +1;/*finding looplen*/

        for ( a = 0; a < *looplen; a++)
           loop[a] = sequence_array[a+first_index];/*equalizing loop to seq array*/

          printf("Loop detected with a length of %d\n\n", *looplen);
          printf("The indexes of the loop's first occurance : %d (first digit), %d (last digit)\n\n", first_index, last_index);
       }
       else
       {
         printf("\nChecking if there's a loop of length %d\n", *looplen);
         printf("No loop found.\n");
         *looplen = 0; /*if no loop, equalize looplen to 0*/
       }
    }
    else
    {
      printf("\nChecking if there's a loop of length %d\n", *looplen);

      if (has_loop(sequence_array, seqlen, *looplen, &first_index, &last_index) == EXIST)
      {
          for (j = 0; j < *looplen; j++)
              loop[j] = sequence_array[j+first_index];

          printf("Loop detected with a length of %d.\n", *looplen);
          printf("The indexes of the loop's first occurance : %d (first digit), %d (last digit)\n", first_index, last_index);

      }
      else
      {
          (*looplen)=(*looplen)-1; /*reducing looplen to 1 */
          check_loop_iterative(f, xs, seqlen, loop, looplen);
      }
    }
 free(sequence_array);

}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
  int is_there_loop = 0,counter=0;
  int array_check[looplen], array_equal[looplen];/*two arrays for comparing */
  int first_index, search_index;

  first_index = 0;
  while(first_index <= n - looplen+1 && is_there_loop == 0) { /*first index goes to lenght - looplen*/

    for(int i = 0; i < looplen; ++i)
      array_check[i] = arr[first_index + i];/*equalizing array to array check*/

    search_index = first_index+looplen; /*for not to overlap two array*/

    while(search_index <= n -looplen) {
      for(int i = 0; i < looplen; ++i)
        array_equal[i] = arr[search_index + i];/*equalizing array to array check*/

      if(equalArrays(array_check, array_equal,looplen) == 1){
         is_there_loop = 1;
         *ls = first_index ;/*loop first index is first of when find the loop*/
         *le = first_index + looplen-1; /*adding first + loop lenght*/
         break;
       }
      search_index++;
    }
    first_index++;


  }

  return is_there_loop;


}

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit)
{
    int counter=0,*seq,i;
    if(digit<=9)/*until digit 9*/
    {
       seq=(int*)malloc(seqlen*sizeof(int));
       (*f)(xs,0,seqlen,seq);

           for (i = 0; i < seqlen; i++)
           {
              while (seq[i]>=10) /*for finding first digit of number*/
                seq[i]/=10;

              if (seq[i]==digit)
                counter++;
           }

       free(seq);
       h[digit-1]=counter;/*writing counter to h array*/
       hist_of_firstdigits(f, xs, seqlen, h, digit+1);
    }
}

/*this function checks if two array is equal*/
int equalArrays(int *arr1, int *arr2,int looplen)
{
  int is_equal = 1; /* Initially assume they're equal*/
    for(int i = 0; i < looplen; ++i)
    {
       if(arr1[i] != arr2[i]) {
         is_equal = 0;
         break;
       }
    }

    if(is_equal == 1)
      return 1;
    else
      return 0;
}
