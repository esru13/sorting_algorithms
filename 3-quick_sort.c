#include "sort.h"
/**
 *change_position - function that changes the position of the numbers
 *@array: array
 *@number1: first number
 *@number2: second number
 *@size: size of the array
 **/
void change_position(int *array, int *number1, int *number2, size_t size)
{
	int exchange_position = *number1;

	*number1 = *number2;
	*number2 = exchange_position;
	print_array(array, size);
}
/**
 *partition - partition function for the array
 *@array: array
 *@low: low
 *@high: high
 *@size: size of the array
 *Return: numero de cambios realizados
 **/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int Index = low;
	int i = 0;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (Index != i)
				change_position(array, &array[i], &array[Index], size);
			Index++;
		}
	}
	if (Index != high)
		change_position(array, &array[high], &array[Index], size);
	return (Index);
}
/**
 *quickSort - function to quicksort
 *@array: array
 *@low: low
 *@high: high
 *@size: size of the array
 **/
void quickSort(int *array, int low, int high, size_t size)
{
	int changes = 0;

	if (low < high)
	{
		changes = partition(array, low, high, size);
		quickSort(array, low, changes - 1, size);
		quickSort(array, changes + 1, high, size);
	}
}
/**
 *quick_sort - sorts an array of integers in ascending order
 *@array: array
 *@size: size of the array
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
