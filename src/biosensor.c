#include "biosensor.h"
#include<stdio.h>
void TempAlert(int TempInCel){
    if(TempInCel>=40){
    printf("High is Temperature= %d\n",TempInCel);
    }
    else
    {
    printf("low is Temperature= %d\n",TempInCel);
    }
}
void PulseAleart(int pulse){
    if(pulse>65){
        printf("pulse is high %d ",pulse);
       }
       else
       printf("pulse is low %d ",pulse);
}
void BloodPressureAlert(int sis, int dis){
if(sis>=130 || dis>=89)
    printf("Blood pressure is high sis=%d and dis=%d",sis,dis);
else
   printf("Blood pressure is low sis=%d and dis=%d",sis,dis);
}
void BaudRateAlert(int baudrate){
    if(baudrate<9600){
    printf("Baudrate is less than 9600");
}
else if(baudrate>9600){
  printf("Baudrate is Greater than 9600");
}
else if(baudrate<0){
  printf("Baudrate cannot be negative");
}
}
void disp(int pulse,int sis,int dia,int TempInFar, long int baudrate){
      printf("%d %d %d %d %ld",pulse,sis,dia,TempInFar,baudrate);
}
int TemperatureInFar(int TempInCel ){
    if(TempInCel>=34 && TempInCel<=44){
       int far=((TempInCel/5)*9)+32;
       return far;
       }
    else if(TempInCel<33 ||TempInCel>44 )
        {
        TempAlert(TempInCel);
        return 0;
        }
    else
        return 0;
}
void pulsecheck(int pulse){
if(pulse>=62 && pulse<=65){}
else
    PulseAleart(pulse);
}
void BloodPressureCheck(int sis,int dia){
if((sis<120 && sis >=60) &&(dia< 80 && dia>=45)){}
else if(sis >=120 || dia >=80)
 BloodPressureAlert(sis,dia);
}
int biosensor(int pulse,int sis,int dia,int TempInCel, long int baudrate )
{
 //printf("%d %d %d %d %d",pulse,sis,dia,temp,baudrate);
  if(baudrate==9600)
  {
     int TemInFar=TemperatureInFar(TempInCel);
     pulsecheck(pulse);
     BloodPressureCheck(sis,dia);
     disp(pulse,sis,dia,TemInFar,baudrate);
     return 1;
   }
else if(baudrate<9600 ){
      BaudRateAlert(baudrate);
      return 0;
}
else if(baudrate>9600 ){
    BaudRateAlert(baudrate);
    return 0;
}
else if(baudrate<0){
    BaudRateAlert(baudrate);
}
return 0;
}
