#ifndef _UTIL_H_
#define _UTIL_H_

#define EXIST 1

void generate_sequence (int xs, int currentlen, int seqlen, int *seq);

void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop,int *looplen);

int has_loop(int *arr, int n, int looplen, int *ls, int *le);

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit);

int equalArrays(int *arr1, int *arr2,int looplen);

#endif /* _UTIL_H_ */
