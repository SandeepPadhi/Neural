#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
int i=0,j=0,k=0;
float sum=0.0,z=0.0;
float bias1[20]={4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
float layer1[2][20]={{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};
float features[20]={1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}; 


float arrayneuron[20];
float inputlayer2[20];

for(j=0;j<20;j=j+1)
{

for(i=0;i<2;i=i+1)
{

arrayneuron[i]=layer1[i][j];

}

for(i=0;i<2;i=i+1)
{
sum=sum+features[i]*arrayneuron[i];

}

sum=sum+bias1[0];



sum=1/(1+exp(-sum));

printf(" \ninput to %d: neuron is  %f ",j,sum);

inputlayer2[j]=sum;




}



}
