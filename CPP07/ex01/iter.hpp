#pragma once

template <typename T, typename TT>
void	iter(T *arr, long const arrLength, TT *funct)
{
	if (!arr || !funct)
		return ;
	for (long i = 0; i < arrLength; i++)
		funct(arr[i]);
}