/* longjmp example */
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

main()
{
  jmp_buf env;
  int val = 2;

  printf ("val is %d\n",val);
  val=setjmp(env);

  printf ("val is %d\n",val);

  if (!val) longjmp(env, 1);
  //printf ("val is %d\n",val);

  //if (!val) longjmp(env, 3);
  //printf ("val is %d\n",val);
  return 0;
}
