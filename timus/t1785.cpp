#include<iostream>
#define FEW cout<<"few\n"
#define SEV cout<<"several\n"
#define PCK cout<<"pack\n"
#define LOT cout<<"lots\n"
#define HOR cout<<"horde\n"
#define THR cout<<"throng\n"
#define SWR cout<<"swarm\n"
#define ZND cout<<"zounds\n"
#define LEG cout<<"legion\n"
using namespace std;
int main()
{
    int n;
    cin>>n;

    (n<5)?FEW:(n<10)?SEV:(n<20)?PCK:(n<50)?LOT:(n<100)?HOR:(n<250)?THR:(n<500)?SWR:(n<1000)?ZND:LEG;
    return 0;
}
