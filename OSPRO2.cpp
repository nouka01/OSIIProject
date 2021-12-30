
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int memoryBlocks[], int pSize[], 

void
bestF (int memoryBlocks[], int x, int pSize[], int y)
{
  
  int memAlloc[y];

 
  memset(memAlloc, -1, sizeof (memAlloc));

 
  for (int i = 0; i < y; i++)
    {
      
      int bIndex = -1;
      for (int j = 0; j < x; j++)
	{
	  if (memoryBlocks[j] >= pSize[i])
	    {
	      if (bIndex == -1)
		bIndex = j;
	      else if (memoryBlocks[bIndex] > memoryBlocks[j])
		bIndex = j;
	    }
	}

   
      if (bIndex != -1)
	{
	 
	  memAlloc[i] = bIndex;

	 
	  memoryBlocks[bIndex] -= pSize[i];
	}
    }

  cout << "\nProc.\tProc Size\tBlock number\n";
  for (int i = 0; i < y; i++)
    {
      cout << "   " << i + 1 << "\t\t" << pSize[i] << "\t\t";
      if (memAlloc[i] != -1)
	cout << memAlloc[i] + 1;
      else
	cout << "This process has no block to be memAllocated to in memory";
      cout << endl;
    }
}


void
worstF (int memoryBlocks[], int x, int pSize[], int y)
{

  int memAlloc[y];


  memset(memAlloc, -1, sizeof (memAlloc));


  for (int i = 0; i < y; i++)
    {
      
      int wIndex = -1;
      for (int j = 0; j < x; j++)
	{
	  if (memoryBlocks[j] >= pSize[i])
	    {
	      if (wIndex == -1)
		wIndex = j;
	      else if (memoryBlocks[wIndex] < memoryBlocks[j])
		wIndex = j;
	    }
	}

      
      if (wIndex != -1)
	{
	  
	  memAlloc[i] = wIndex;

	  
	  memoryBlocks[wIndex] -= pSize[i];
	}
    }

  cout << "\nProc\tProc Size\tBlock number\n";
  for (int i = 0; i < y; i++)
    {
      cout << "   " << i + 1 << "\t\t\t\t" << pSize[i] << "t\\t\t\t";
      if (memAlloc[i] != -1)
	cout << memAlloc[i] + 1;
      else
	cout << "This process has no block to be memAllocated to in memory";
      cout << endl;
    }
}


#include<bits/stdc++.h>
using namespace std;


void firstF(int memoryBlocks[], int x, int pSize[], int y)
{

  int memAlloc[y];

 
  memset(memAlloc, -1, sizeof (memAlloc));

 
  for (int i = 0; i < y; i++)
    {
      for (int j = 0; j < x; j++)
	{
	  if (memoryBlocks[j] >= pSize[i])
	    {
	     
	      memAlloc[i] = j;

	     
	      memoryBlocks[j] -= pSize[i];

	      break;
	    }
	}
    }

  cout << "\nProcess\t\tProcess Size\tBlock number\n";
  for (int i = 0; i < y; i++)
    {
      cout << " " << i + 1 << "\t\t" << pSize[i] << "\t\t";
      if (memAlloc[i] != -1)
	cout << memAlloc[i] + 1;
      else
	cout << "This process has no block in memory to be memAllocated to";
      cout << endl;
    }
}


// Driver
int
main ()
{
  int memoryBlocks[] = { 3900, 2100, 12500, 16000, 25000};
  int pSize[] = { 23952, 3151, 15823, 7258 };
  int x = sizeof (memoryBlocks) / sizeof (memoryBlocks[0]);
  int y = sizeof (pSize) / sizeof (pSize[0]);

  first(memoryBlocks, x, pSize, y);

  return 0;
}
