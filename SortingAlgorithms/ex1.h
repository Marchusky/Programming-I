#pragma once

// INSTRUCTIONS:
// - Press 'b' to call the bubblesort function
// - Press 'm' to call the mergesort function
// - Press 'q' to call the quicksort function
// - Press space to randomize the tile set
// - Press <esc> to exit

// Change these numbers to resize the tile grid dimensions
#define GRID_WIDTH 100
#define GRID_HEIGHT 100


// Bubblesort functions ////////////////////////////////////////////////

void bubblesort(uint32 * array, int size)
{
	// TODO: Insert your code here
	int numSwaps = 1; //Tiene que ser diferente a 0.
	int temp = 0;
	while (numSwaps != 0)
	{
		numSwaps = 0;
		for (int i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				numSwaps++;
			}
		}
	}



}


// Mergesort functions /////////////////////////////////////////////////

void merge(uint32 *array, int begin, int mid, int end)
{
	// Create the two subarrays
	// TODO
	int s1 = mid - begin + 1;
	int s2 = end - mid;

	/* create temp arrays */

	int * temp1 = new int[s1]; 	//array de begin a mid y copias del array original a este(memoria dinamica)
	int * temp2 = new int[s2];		//array de mid + 1 a end y copias del array original a este(memoria dinamica);
	// Copy array parts into the subarrays
	// TODO
	for (int i = 0; i < s1; i++)
	{
		temp1[i] = array[begin + i];
	}
	for (int i = 0; i < s2; i++)
	{
		temp2[i] = array[mid + 1 + i];
	}
	// Initialize indices for tmp1, tmp2, and array, respectively
	int i = 0; //array 1
	int j = 0; //array 2
	int k = begin;//original

	// Merge tmp1 and tmp2 into array
	// TODO
	while (i < s1 && j < s2)
	{
		if (temp1[i] <= temp2[j])
		{
			array[k] = temp1[i];
			i++;
		}
		else
		{
			array[k] = temp2[j];
			j++;
		}
		k++;
	}
	while (i < s1)
	{
		array[k] = temp1[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < s2)
	{
		array[k] = temp2[j];
		j++;
		k++;
	}
}
	//comparas i vs j y el mas pequeño lo copias en k y incrementas el mas pequeño de i o j y k.
	// Delete tmp arrays
	// TODO


void mergesort(uint32 *array, int begin, int end)
{
	// TODO: Insert your code here
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergesort(array, begin, mid);
		mergesort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}
}


// Quicksort functions /////////////////////////////////////////////////

int partition(uint32 *array, int begin, int end)
{
	// Take the last value (for example) as the pivot
	//int pivotIndex = 0;
	// Could be any other value in the array
	uint32 pivot = array[end];

	// Initialize the pivot index at the beginning
	int pivotIndex = begin;

	// Traversing the array:
	// Each value we find that is less than the pivot we push
	// it to the left (swap) and increase the pivot index
	// TODO

	// Put the pivot in its position
	// TODO

	return pivotIndex;
}

void quicksort(uint32 *array, int begin, int end)
{

	// TODO: Insert your code here
	if (begin < end)
	{
		int pivotIndex = partition(array, begin, end);
		quicksort(array, begin, pivotIndex - 1);
		quicksort(array, pivotIndex + 1, end);

	}

}
