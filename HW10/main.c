/*Furkan Taşkın 200104004072 hw10*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define STACK_BLOCK_SIZE 10
int number_of_disk;

typedef struct {
  int  * array;
  int currentsize;
  int maxsize;
} stack;

int push(stack * s, int d);  /* the stack array will grow STACK_BLOCK_SIZE entries at a time   */
int pop(stack * s);         /* the stack array will shrink STACK_BLOCK_SIZE entries at a time */
stack * init_return();     /* initializes an empty stack                                     */
int init(stack * s);      /* returns 1 if initialization is successful                      */
int move_disks(stack *one,stack *two, stack *three,int number_of_disk);

int main()
{
   printf("Please enter number of disks: ");
   scanf("%d", &number_of_disk);

   stack *one,*two,*three;

   one = init_return();
   two = init_return();
   three = init_return();

   move_disks(one,two,three,number_of_disk);

    return 0;
}

int push(stack * s, int d)
{
     if (s->currentsize >= s->maxsize-1)
     {
         int* temp_array= (int*)calloc((s->maxsize)+STACK_BLOCK_SIZE,sizeof(int));/*increase array size by 10*/
         for (int i = 0; i < s->maxsize; i++)
             temp_array[i] = s->array[i];
         s->array = temp_array;
         s->maxsize+=STACK_BLOCK_SIZE;
     }

     s->array[++s->currentsize]=d;
}

int pop(stack * s)
{
    if(s->currentsize<=s->maxsize/3 && s->maxsize>STACK_BLOCK_SIZE)
    {
         int *array2=(int*)malloc(sizeof(int)*s->maxsize-STACK_BLOCK_SIZE);/*decrease array size by 10*/
         for(int i=0; i<s->maxsize; i++)
            array2[i]=s->array[i];

         free(s->array);
         s->array=array2;
         s->maxsize-=STACK_BLOCK_SIZE;
    }

    return s->array[s->currentsize--];
}

stack * init_return()
{
    stack* s = (stack*)malloc(sizeof(int)*STACK_BLOCK_SIZE);
    s -> maxsize = STACK_BLOCK_SIZE;
    s -> currentsize = -1;
    s -> array =(int*) malloc((s -> maxsize)*sizeof(int));
    return s;
}


int init(stack * s)
{
     if (s== NULL || s->array==NULL)
     {
       printf("Initialization failed\n");
       return 0;
     }
     else
     {
       printf("Initialization successful\n");
       return 1;
     }
}


/*it doesn't properly work but at least it is original and i put so much effort*/
int move_disks(stack *one,stack *two, stack *three,int number_of_disk)
{
  int total_exchange_number = pow(2, number_of_disk) - 1;

  for (int i = number_of_disk; i >= 1; i--)
    push(one, number_of_disk-i);

    if(number_of_disk % 2 == 0)
    {
        for (int i = 0; i < total_exchange_number; i++)
        {
            if(one && !two)
            {
               int disk = pop(one);
               pop(one);
               push(two,disk);
               printf("Moved %d from 1 to 2.\n",disk);
            }

            else if(!one && two)
            {
                int disk = pop(two);
                pop(two);
                push(one,disk);

                printf("Moved %d from 2 to 1.\n",disk);
              }

            else if( one->array[one->maxsize -1] < two->array[two->maxsize -1])
            {
                int disk =pop(one);
                pop(one);
                push(two,disk);

                printf("Moved %d from 1 to 2.\n",disk);
              }

            else if( one->array[one->maxsize -1] > two->array[two->maxsize -1])
            {
                int disk = pop(two);;
                pop(two);
                push(one,disk);

                printf("Moved %d from 2 to 1.\n",disk);
              }



            //#make the legal move between pegs 1 && 3 (in either direction)
            if (one && ! three)
            {
                int disk = pop(one);
                pop(one);
                push(three,disk);

                printf("Moved %d from 1 to 3.\n",disk);
              }

            else if( !one && three)
            {
                int disk = pop(three);
                pop(three);
                push(one,disk);

                printf("Moved %d from 3 to 1.\n",disk);
              }

            else if( one->array[one->maxsize-1] < three->array[three->maxsize-1])
            {
                int disk = pop(one);
                pop(one);
                push(three,disk);

                printf("Moved %d from 1 to 3.\n",disk);
              }

            else if( one->array[one->maxsize-1] > three->array[three->maxsize-1])
            {
                int disk = pop(three);
                pop(three);
                push(one,disk);

                printf("Moved %d from 3 to 1.\n",disk);
              }

          // make the legal move between pegs 2 && 3 (in either direction)
            if (two && ! three)
            {
                int disk = pop(two);
                pop(two);
                push(three,disk);

                printf("Moved %d from 2 to 3.\n",disk);
              }

            else if(!two && three)
            {
               int disk = pop(three);
                pop(three);
                push(two,disk);

                printf("Moved %d from 3 to 2.\n",disk);
              }

            else if( two->array[two->maxsize-1] < three->array[three->maxsize-1])
            {
                int disk = pop(two);
                pop(two);
                push(three,disk);

                printf("Moved %d from 2 to 3.\n",disk);
              }

            else if( two->array[two->maxsize-1] > three->array[three->maxsize-1])
            {
                int disk = pop(three);
                pop(three);
                push(two,disk);

                printf("Moved %d from 3 to 2.\n",disk);
              }

              }
        }

    else
    {
        for (int i = 0; i < total_exchange_number; i++)
        {
            //make the legal move between pegs 1 && 3 (in either direction)
            if (one && !three){
                int disk = pop(one);
                pop(one);
                push(three,disk);
                printf("Moved %d from 1 to 3.\n",disk);
              }

            else if( !one && three)
            {
                int disk = pop(three);
                pop(three);
                push(one,disk);

                printf("Moved %d from 3 to 1.\n",disk);
              }

            else if( one->array[one->maxsize-1] < three->array[three->maxsize-1])
            {
                int disk = pop(one);
                pop(one);
                push(three,disk);

                printf("Moved %d from 1 to 3.\n",disk);
              }

            else if( one->array[one->maxsize-1] > three->array[three->maxsize-1])
             {
                int disk = pop(three);
                pop(three);
                push(one,disk);

                printf("Moved %d from 3 to 1.\n",disk);
              }


            //#make the legal move between pegs 1 && 2 (in either direction)
            if(one && ! two)
            {
                int disk = pop(one);
                pop(one);
                push(two,disk);

                printf("Moved %d from 1 to 2.\n",disk);
              }

            else if(!one && two)
            {
                int disk = pop(two);
                pop(two);
                push(one,disk);

                printf("Moved %d from 2 to 1.\n",disk);
              }

            else if( one->array[one->maxsize-1] < two->array[two->maxsize-1])
            {
                int disk = pop(one);
                pop(one);
                push(two,disk);

                printf("Moved %d from 1 to 2.\n",disk);
              }

            else if( one->array[one->maxsize] > two->array[two->maxsize])
            {
                int disk = pop(two);
                pop(two);
                push(one,disk);

                printf("Moved %d from 2 to 1.\n",disk);
              }

            //#make the legal move between pegs 2 && 3 (in either direction)
            if (two && !three){
                int disk = pop(two);
                pop(two);
                push(three,disk);

                printf("Moved %d from 2 to 3.\n",disk);
              }

            else if(!two && three)
            {
                int disk = three->array[three->maxsize];
                pop(three);
                push(two,disk);

                printf("Moved %d from 3 to 2.\n",disk);
              }

            else if(two->array[two->maxsize-1] < three->array[three->maxsize-1])
            {
                int disk = two->array[two->maxsize];
                pop(two);
                push(three,disk);

                printf("Moved %d from 2 to 3.\n",disk);
              }

            else if( two->array[two->maxsize-1] > three->array[three->maxsize-1])
            {
                int disk = three->array[three->maxsize];
                pop(three);
                push(two,disk);

                printf("Moved %d from 3 to 2.\n",disk);
              }

        }

    }


}
