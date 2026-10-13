#pragma once

template <typename T>
void	swap(T& v1, T& v2)
{
	T	tmp(v1);

	v1 = v2;
	v2 = tmp;
}

template <typename T>
T	min(T const& v1, T const& v2)
{
	if (v1 < v2)
		return v1;
	return v2;
}

template <typename T>
T	max(T const& v1, T const& v2)
{
	if (v1 > v2)
		return v1;
	return v2;
}