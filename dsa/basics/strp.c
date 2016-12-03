#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Combinations(char string[],int stack[],int combLength,int leftIndex);
void ComputeCombinations(char string[]);
void DisplayStack(int stack[],int stringLength,char string[]);
 
int main()
{
    char *string;
    printf("\nEnter the string ..\n");
    string = (char *)malloc(100 * sizeof(char));
    if(!string)
    {
        printf("\nmemory allocation for string failed exiting ..\n");
        exit(1);                              
    }            
    gets(string);
    ComputeCombinations(string);
    return 0;
}

void ComputeCombinations(char string[])
{
    int stringLength = 0;
    int *stack;
    int index = 0;
    int combLength = 0;
    int combIndex = 0;
    stringLength = (int)strlen(string); 
   
    stack = (int *)calloc(stringLength,sizeof(int));
    if(!stack)
    {
        printf("\nmemory allocation for stack failed exiting ..\n\n");
        exit(1);                              
    }

    for(combIndex = 1;combIndex <= stringLength;combIndex++)
    {
        printf("\n %d letter combinations ...\n\n",combIndex);
        for(index = 0; index < stringLength;index++)
        {
            stack[0] = index;
            Combinations(string,stack,combIndex,index);       
        }
    }
 
    return;     
}
void Combinations(char string[],int stack[],int combLength,int leftIndex)
{
    int stringLength = (int)strlen(string);
    int riteIndex = stringLength;
    static int level = 0;

    //Initialiaze the left index	
    if(level == 0)
    {
        leftIndex = stack[0]+1;
    }
    
    //if the current depth of tree = combinations length then print & return
    if(level == combLength - 1)
    {
        DisplayStack(stack,combLength,string);
        return;
    }
    level++;

    //recurse from current index to end of string
    for(;leftIndex < riteIndex;)
    {
        stack[level] = leftIndex;
        leftIndex++;
        Combinations(string,stack,combLength,leftIndex);
    }
    level--;
}

void DisplayStack(int stack[],int stringLength,char string[])
{
    int index = 0;
    for(index = 0; index < stringLength;index++)
    {
        printf(" %c ",string[stack[index]]);
    }
    printf("\n");
}
