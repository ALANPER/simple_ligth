#include <mbed.h>


 
Ticker timer;
DigitalOut led1(PD_12);
DigitalOut led2(PD_13);
DigitalOut led3(PD_14);
InterruptIn   Bt(PA_0);


int led=0;
int flip=0;

void trigger(){
    flip=!flip;
}


void  attime () {
 
if (flip ==1) { 
           if (led <2) {
              led++ ;
           }else{
              led=0;
              
           }
           
}else{
 led=3;
 
}  
    switch(led)
       {
       case 0:
         led1=0;
         led2=0;
         led3=1;
         break;
       case 1:
         led1=1;
         led2=0;
         led3=0;
         break;
        case  2:
         led1=0;
         led2=1;
         led3=0;
         break;
         default:
        led1=0;
         led2=0;
         led3=0;
         
}         
}



int main (){
timer.attach(&attime,3); 
Bt.rise (&trigger);
}
