#include <rflpc17xx/rflpc17xx.h>


int wait(int sec){
int i;
for(i=0;i<sec*33333333;i=i+1);
return 0;
}
