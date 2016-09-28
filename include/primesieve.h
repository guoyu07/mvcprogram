#ifndef __PRIMESIEVE_H__
#define __PRIMESIEVE_H__

#include <stdio.h> /* Achim Flammenkamp, Bielefeld, D, achim@uni-bielefeld.de */
#include <malloc.h>/* ifdefs:  LONG=uns64  _ANSI_EXTENSION  true_64bit_words  */
#include <stdlib.h>/* SUM_{p<x} 1/p= ln(ln(x))+0.5772156649015-0.315718451893 */
#include <math.h>  /* extern double sqrt(double), log(double), floor(double); */
#ifndef  uns32              /*  Version 1.0a 1998-05-19  source availible     */
#define  uns32  unsigned    /*  Version 2.0a 1998-05-23  5 years in the WWW   */
#endif                      /*  Version 2.0b 2003-06-03  0-1-typo fixed Argh! */
#ifndef  uns64              /*  Version 2.0c 2003-06-04  works up to 2^64-1   */
# ifdef   _ANSI_EXTENSION   /*  uses < 1938 MB for minimal sieve size to 2^64 */
#  define  uns64  unsigned long long
# else
#  define  uns64  unsigned long
# endif
#endif
#ifdef   LONG
# ifdef   _ANSI_EXTENSION
#  define  UL  "%llu"
# else
#  define  UL  "%lu"
# endif
# define  HALF  uns32
#else
# define  LONG  uns32
# define  UL  "%u"
# define  HALF  unsigned short
#endif

#define  BITS  8
#define  LCM  (2*3*5)
#define  SIEVE_SIZE  (16<<10)

#ifdef  DEBUG
#define  use(x)  printf(UL"\n",x),  anz++;
#elif defined(TEST)
#define  use(x)  anz++;
#else
#define  use(x)  do { /*  if(max<=x-last)printf(UL" "UL"\n",x,max=x-last);  */ \
	/* sum += 1.0/x, */ printf(UL"\n",x), last=x; anz++; } while(0);
extern double  sum;
extern LONG  max, last;
#endif

extern int primesieve(unsigned argc, char* argv[]);

#endif
