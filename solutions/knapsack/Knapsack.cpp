#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include "cpu_timer/CPUTimer.h"

static CPUTimer totalTimer_;
static int numberItems_ = -1;
static int knapsackSize_ = -1;
static bool fractionItem_ = false;

struct item
{
  unsigned int id;
  int value;
  int weight;    
  float rate; //rate between value and weight.
  float fractionItem;
};

struct knapsack
{
  int numberItems;
  int weightItems;
  float valueItems;
  struct item *items;    
};

struct knapsack
*fillKnapsack (struct item *items, int length, int max)
{
  float valueItems = 0;
  int weightItems = 0;
  int count = 0;

  struct knapsack *knapsack = (struct knapsack *) malloc (sizeof (struct knapsack)); 
  knapsack->items = (struct item *) malloc(sizeof(struct item));
   
  for(int i = 0; i < length; i++) /// 0(n)
  {
    if(items[i].weight > max)
    {
      knapsack->items = (struct item *) realloc (knapsack->items, sizeof (struct item) * (count+1));
      knapsack->items[count].id = items[i].id;
      knapsack->items[count].fractionItem = (float) max / items[i].weight;

      valueItems += (float) items[i].value * max / items[i].weight;
      weightItems += max;
      count++;
      fractionItem_ = true;
      break;
    }

    knapsack->items = (struct item *) realloc ( knapsack->items, sizeof (struct item) * (count+1));
    knapsack->items[count].id = items[i].id;
    knapsack->items[count].fractionItem = items[i].fractionItem;

    valueItems += (float) items[i].value;
    weightItems += items[i].weight;

    count++;

    max = max - items[i].weight;

    if (max == 0)
    {
      break;
    }
  }
  
  knapsack->numberItems = count;
  knapsack->valueItems = valueItems;
  knapsack->weightItems = weightItems;
  
  return knapsack;
}

void 
heapifyRateMin (struct item *a, int len, int index) /// O(log n)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  struct item aux;

  if (left > len - 1) 
  {
    return;
  }
  else if (right == len)
  {
    if (a[index].rate > a[left].rate)
    {   //swap left with parent
      aux = a[index];
      a[index] = a[left];
      a[left] = aux;
    }
    return;
  }
  else if (a[index].rate > a[left].rate || a[index].rate > a[right].rate) 
  {
    if (a[left].rate > a[right].rate) 
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
    if (a[index].rate < a[left].rate)
    {   //swap left with parent
      aux = a[index];
      a[index] = a[left];
      a[left] = aux;
    }
    return;
  }
  else if (a[index].rate < a[left].rate || a[index].rate < a[right].rate) 
  {
    if (a[left].rate < a[right].rate) 
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
heapsortRate (struct item *list, int length, bool asc) /// O(nlog n)
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
      list[cunrrentLength - 1] = aux;
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

int
median (int left, int right, struct item *items)
{
  struct item aux; 

  for (int i = left; i <= right; i++) 
  {
    for (int j = left; j <= right; j++) 
    {
      if (items[i].rate > items[j].rate)
      {
        aux = items[i];
        items[i] = items[j];
        items[j] = aux;
      }
    }
  }

  int middle = left + ((right - left) / 2);
  return middle;
}

int 
medianOfMedians (struct item *items, int start, int end)
{
  if(end - start < 5)
  {
    return median (start, end, items);
  }

  struct item aux;

  for (int i = 0; i < (end + 1)/5; i++)
  {
    int left = 5 * i;
    int right = left + 4;

    if (right > end)
    {
      right = end;
    }

    int index  = median (left, right, items);
    
    aux = items[index];
    items[index] = items[i];
    items[i] = aux;
  }

  return medianOfMedians (items, 0, end/5);
}

int
partition (struct item *items, int left, int right)
{
  int n = right + 1 - left;
  struct item *auxItems = (struct item *) malloc (sizeof (struct item) * n);
  int auxIndex[n];
  
  for (int i = 0; i < n; i++)
  {
    auxItems[i].rate = items[left+i].rate;
    auxIndex[i] = left + i;
  }

  int indexMedian = medianOfMedians (auxItems, 0, n-1);
  int median = auxIndex[indexMedian];

  float pivot = items[median].rate;
  int posPivot = median;
  int i = left;
  int j = right;
  struct item aux;

  while (1)
  {
    for(; items[i].rate >= pivot && i <= right; i++);
    for(; items[j].rate < pivot && j >= left; j--);
    if (i < j)
    {
      if (items[j].rate == pivot)
      {
        posPivot = i;
      }
      aux = items[i];
      items[i] = items[j];
      items[j] = aux;
    }
    else
    {
      aux = items[posPivot];
      items[posPivot] = items[j];
      items[j] = aux;
      return j;
    }
  }
}

int
kesimo (struct item *items, int left, int right, int usedWeight)
{
  int middle = partition (items, left, right); //Finding the middle item.

  int sum = usedWeight;

  for (int i = left; i <= middle; i++)
  {
    sum += items[i].weight;
  }

  if (sum == knapsackSize_ || middle >= numberItems_ -1)
  {
    return middle;
  }
  else if ( (sum > knapsackSize_) && (sum - items[middle].weight <= knapsackSize_) )
  {
    return middle;
  }
  else if (sum > knapsackSize_)
  {
    return kesimo (items, left, middle - 1, usedWeight);
  }
  else
  {
    return kesimo (items, middle+1, right, sum);
  }
}

float 
findPivot (struct item *items, int start, int end)
{
  int k = end + 1 - start;
  float pivot = 0;

  for (int i = start; i <= end; i++){
    pivot += items[i].rate;
  }

  return (pivot/k);
}

int 
partitionPivot (struct item *items, int left, int right)
{
  float pivot = findPivot (items, left, right);
  int posPivot = -1;
  int i = left;
  int j = right;
  
  struct item aux;

  while (1)
  {
    for (; items[i].rate >= pivot && i <= right; i++);
    for (; items[j].rate < pivot && j >= left; j--);
    if (i < j)
    {
      if (items[j].rate == pivot)
      {
        posPivot = i;
      }   
      aux = items[i];
      items[i] = items[j];
      items[j] = aux;
    }
    else
    {
      if (posPivot == -1){
        posPivot = left;
        for (int z = left; z <= j; z++)
        {
          if(items[posPivot].rate > items[z].rate)
            posPivot = z;
        }
      }

      aux = items[posPivot];
      items[posPivot] = items[j];
      items[j] = aux;
      return j;
    }
  }
}

int 
kesimoPivot (struct item *items, int left, int right, int usedWeight)
{
  int middle = partitionPivot (items, left, right);

  int sum = usedWeight;

  for (int i = left; i <= middle; i++)
  {
    sum += items[i].weight;
  }
  
  if (sum == knapsackSize_ || middle >= numberItems_-1)
  {
    return middle;
  }
  else if ( (sum > knapsackSize_) && (sum - items[middle].weight <= knapsackSize_) )
  {
    return middle;
  }
  else if (sum > knapsackSize_)
  {
    return kesimoPivot (items, left, middle-1, usedWeight);
  }
  else
  {
    return kesimoPivot (items, middle+1, right, sum);
  }
}

void 
detailItens (struct item *a, int length)
{
  printf ("Total of items: %d; Knapsack's capacity: %d\n", numberItems_, knapsackSize_);

  int totalWeight = 0;
  int totalProfit = 0;

  for (int i = 0; i < length; i++)
  {
    printf ("Line %d: ", i + 2);
    printf ("Id: %d ; ", a[i].id);
    printf ("Value: %d ; ", a[i].value);
    printf ("Weight: %d ; ", a[i].weight);
    //printf ("Fraction: %f ;", a[i].fractionItem);
    printf ("Rate: %f ;", a[i].rate);
        
    printf ("\n");

    totalWeight += a[i].weight;
    totalProfit += a[i].value;
  }

  printf ("\nTotal of items: %d; Total of weight: %d; Total of profit: %d\n\n",length,totalWeight,totalProfit);
}

void 
showItens (struct knapsack *knapsack, FILE *file) /// O(n)
{
  printf ("\nNumber of items (N): %d\n", numberItems_);
  printf ("Number of items in the knapsack: %d\nTotal of Items' Weight in the knapsack: %d\nTotal of Items' Value in the knapsack: %f\n\n", knapsack->numberItems, knapsack->weightItems, knapsack->valueItems);
    
  /*for (int i = 0; i < knapsack->numberItems; i++) //Print Itens 
  {
    printf ("Id: %d; Number: %f %%;\n", knapsack->items[i].id, knapsack->items[i].fractionItem*100);
  }*/

  fprintf (file,"Number of items (N): %d\n", numberItems_);
  fprintf (file,"Number of items in the knapsack: %d\nTotal of Items' Weight in the knapsack: %d\nTotal of Items' Value in the knapsack: %f\n\n", knapsack->numberItems, knapsack->weightItems, knapsack->valueItems);

  for (int i = 0; i < knapsack->numberItems; i++) 
  {
    fprintf(file,"Id: %d; Number: %f %%;\n", knapsack->items[i].id, knapsack->items[i].fractionItem*100);
  }

  /*if(fractionItem_){
    printf ("\nThere is a fractional item.\n");
    fprintf(file,"\nThere is a fractional item.\n");
    return;
  }
  
  printf ("\There are no fractional items.\n");
  fprintf(file,"\nThere are no fractional items.\n");*/
}

struct knapsack 
*sortKnapsackFractional (struct item *items, int length, int max) /// O(nlog n)
{
  heapsortRate (items,length,false);  /// O(nlog n)
  //detailItens (items, numberItens_);
  return fillKnapsack (items, length, max);
}

struct knapsack 
*linearKnapsackFractional (struct item *items, int length, int max) /// O(n)
{
  kesimo (items, 0, numberItems_-1, 0); /// O(n)
  //detailItens (items, numberItens_);
  return fillKnapsack (items, length, max);
}

struct knapsack 
*pivotKnapsackFractional (struct item *items, int length, int max) /// O(n²)
{
  kesimoPivot (items, 0, numberItems_-1, 0); /// O(n²)
  //detailItens (items, numberItens_);
  return fillKnapsack (items, length, max);
}

struct item
*duplicateItems (struct item *items)
{
  struct item *auxItems = (struct item *) malloc (sizeof (struct item) * numberItems_);
  
  for (int i = 0; i < numberItems_; i++)
  {
    auxItems[i].id = items[i].id;
    auxItems[i].value = items[i].value;
    auxItems[i].weight = items[i].weight;
    auxItems[i].rate = items[i].rate;
    auxItems[i].fractionItem = items[i].fractionItem;
  }

  return auxItems;
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
      else if ( i >= numberItems_ ) //Get the last line.
      {
        knapsackSize_ = atoi (pch); //Assign capacity to Knapsack.
      }
      else 
      {
        switch (j) 
        {
          case 0: //First string in the line.
            items[i].id = atoi(pch); //Assign id to item.
            items[i].fractionItem = 1;
            break;

          case 1: //Second string in the line.
            items[i].value = atoi(pch); //Assign value to item.
            break;

          case 2: //Third string in the line.
            items[i].weight = atoi(pch); //Assign weight to item.
            items[i].rate = (float)items[i].value/items[i].weight; //Assign rate (value/weight) to item.
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

  //detailItens (items, numberItems_);
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
  
  struct item *baseItems = loadItems (fileIn); // Load instances. // O(n)

  fclose (fileIn);
 
  FILE *fileOut = fopen ("Output.txt", "w"); // Output file.
  if (fileOut == NULL)
  {
    printf ("Error to create output file\n");
    abort ();
  }

  int select = atoi (argv[2]);
    
  struct item *items;
  struct knapsack *knapsackItens;
    
  guint32 k = 1;

  totalTimer_.reset();
    
  while (totalTimer_.getCPUTotalSecs () < 5)
  {
    totalTimer_.start();
    items = duplicateItems (baseItems);

    switch ( select ) // Select question.
    {
      case 1: // O(nlog n)
        knapsackItens = sortKnapsackFractional (items, numberItems_, knapsackSize_);
        break;

      case 2: // O(n)
        knapsackItens = linearKnapsackFractional (items, numberItems_, knapsackSize_);
        break;

      case 3: // O(n²) 
        knapsackItens = pivotKnapsackFractional (items, numberItems_, knapsackSize_);
        break;

      default:
        printf ("Error to select method\n");
        break;
    }
      
    totalTimer_.stop();
    k++;
  }

  showItens (knapsackItens,fileOut);
  //printf (">>>>> After sorting: \n");
  //detailItens (items, numberItems_);
  fclose (fileOut);
    
  printf("Time: %f\nk=%d total: %lf\n\n", totalTimer_.getCPUTotalSecs()/k, k, totalTimer_.getCPUTotalSecs() );

  return 1;
}
