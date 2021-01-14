#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int numberItems_ = -1;

struct item
{
  unsigned int id;
  int value;
};

void 
heapifyRateMin (struct item *a, int len, int index) /// O(log n)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  struct item aux;

  if (left > len-1) 
  {
    return;
  }
  else if (right == len)
  {
    if (a[index].value > a[left].value)
    {   //swap left with parent
      aux = a[index];
      a[index] = a[left];
      a[left] = aux;
    }
    return;
  }
  else if (a[index].value > a[left].value || a[index].value > a[right].value) 
  {
    if (a[left].value > a[right].value) 
    {   //swap right with parent
      aux = a[index];
      a[index] = a[right];
      a[right] = aux;
      heapifyRateMin (a,len,right);
    }
    else
    {   //swap left with parent
      aux = a[index];
      a[index] = a[left];
      a[left] = aux;
      heapifyRateMin (a,len,left);
    }
  }
}

void 
heapifyRateMax (struct item *a, int len,  int index) /// O(log n)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  struct item aux;

  if (left > len-1) 
  {
    return;
  }
  else if (right==len)
  {
    if (a[index].value < a[left].value)
    {   //swap left with parent
      aux = a[index];
      a[index] = a[left];
      a[left] = aux;
    }
    return;
  }
  else if (a[index].value < a[left].value || a[index].value < a[right].value) 
  {
    if (a[left].value < a[right].value) 
    {   //swap right with parent
      aux = a[index];
      a[index] = a[right];
      a[right] = aux;
      heapifyRateMax (a,len,right);
    }
    else
    {   //swap left with parent
      aux = a[index];
      a[index] = a[left];
      a[left] = aux;
      heapifyRateMax (a,len,left);
    }
  }
}

void 
buildHeapRate (struct item *a, int length, bool asc) /// O(n)
{
  int i;

  if (asc)
  {
    for (i = length - 1; i >= 0; i--) 
    {
      if ( 2 * i + 1 > length - 1)
      {
        continue;
      }

      heapifyRateMax (a,length,i);
    }
  }
  else 
  {
    for (i = length - 1; i>= 0; i--) 
    {
      if (2 * i  + 1 > length - 1)
      {
        continue;
      }

      heapifyRateMin (a,length,i);
    }
  }

  return;
}

void 
heapsort (struct item *list, int length, bool asc) /// O(nlog n)
{
  struct item aux;
  int cunrrentLength = length;

  buildHeapRate (list,length,asc);

  if (asc)
  { //Ordem crescente.
    while (cunrrentLength > 1)
    {   //swap first with last
      aux = list[0];
      list[0] = list[cunrrentLength - 1];
      list[cunrrentLength-1] = aux;
      cunrrentLength--;

      //heapify new heap
      heapifyRateMax (list,cunrrentLength,0);
    }

  }
  else 
  { //Ordem decrescente.
    while (cunrrentLength > 1)
    {   //swap first with last
      aux = list[0];
      list[0] = list[cunrrentLength - 1];
      list[cunrrentLength-1] = aux;
      cunrrentLength--;

      //heapify new heap
      heapifyRateMin (list,cunrrentLength,0);
    }
  }
  return;
}

void 
showItens (struct item *list, FILE *file) /// O(n)
{
  printf ("\nNumber of items (N): %d\n", numberItems_);
    
  /*for (int i = 0; i < list->numberItems; i++) //Print Itens 
  {
    printf ("Id: %d; Number: %d \n", list[i].id, list[i].value);
  }*/

  for (int i = 0; i < numberItems_; i++) 
  {
    fprintf(file,"Id: %d; Value: %d \n", list[i].id, list[i].value);
  }
}

struct item 
*loadItems (FILE *file) ///O(n)
{
  char line[1000];
  char *result;
  char *pch;

  int i = 0;
  int j = 0;

  result = fgets(line, 1000, file); //Get the first line.
  sscanf(result, "%d", &numberItems_);

  struct item *items = (struct item *) malloc (sizeof (struct item) * numberItems_); //Instantiate itens struct.
  
  while (!feof (file)) ///O(n)
  { 
    result = fgets(line, 1000, file); //Get the next line.
    pch = strtok(result," ");
        
    j = 0;

    while (pch != NULL) //Get the next string.
    {
      if (strpbrk(pch, "0123456789") == NULL) //Checking whether the string contains some number.
      { 
        //printf("String: %s\n",pch);
      }
      else 
      {
        switch (j) 
        {
          case 0: //First string in the line.
            items[i].id = atoi(pch); //Assign id to item.
            break;

          case 1: //Second string in the line.
            items[i].value = atoi(pch); //Assign value to item.
            break;

          default: 
          break;
        }

        j++;
      }
      pch = strtok (NULL," ");
    }        
        
    i++;
  }

  return items;
}

int 
main (int argc, char **argv)
{
  if (argc == 1)
  {
    printf ("No input\n");
    return 0;
  }

  FILE *fileIn = fopen (argv[1], "r"); // Input file.
  if (fileIn == NULL)
  {
    printf ("Error to open the file input\n");
    return 0;
  }
  
  struct item *items = loadItems (fileIn); // Load instances. // O(n)

  fclose (fileIn);
 
  FILE *fileOut = fopen ("Output.txt", "w"); // Output file.
  if (fileOut == NULL)
  {
    printf ("Error to create output file\n");
    abort ();
  }
  
  heapsort (items,numberItems_,true);
  
  showItens (items,fileOut);
  
  fclose (fileOut);

  return 1;
}