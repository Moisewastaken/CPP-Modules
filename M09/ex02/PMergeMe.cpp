#include "PMergeMe.hpp"

PMergeMe::PMergeMe( void )
{
	return ;
}

PMergeMe::PMergeMe( PMergeMe const &copy)
{
	*this = copy;
}

PMergeMe  &PMergeMe::operator=( PMergeMe const &rhs)
{
	(void)rhs;
	return *this;
}

PMergeMe::~PMergeMe( void )
{
	return ;
}


//			--------------------Vector -----------------

static void	insertSortVec(std::vector<int> &vec)
{
	for (std::vector<int>::iterator it = vec.begin();it != vec.end();it++)
	{
		std::vector<int>::iterator insert = std::upper_bound(vec.begin(), it, *it);
		std::rotate(insert, it, it + 1);
	}
}

static void	mergeVec(std::vector<int> &vec, std::vector<int> &fHalf, std::vector<int> &sHalf)
{
	std::vector<int>::iterator	fHalfIt = fHalf.begin();
	std::vector<int>::iterator	sHalfIt = sHalf.begin();

	while (fHalfIt < fHalf.end() && sHalfIt < sHalf.end())
	{
		if (*fHalfIt < *sHalfIt)
			vec.push_back(*fHalfIt++);
		else
			vec.push_back(*sHalfIt++);
	}
	while (fHalfIt < fHalf.end())
		vec.push_back(*fHalfIt++);
	while (sHalfIt < sHalf.end())
		vec.push_back(*sHalfIt++);
}

static void	mergeSortVec(std::vector<int> &vec)
{
	if (vec.size() <= 4)
	{
		insertSortVec(vec);
		return ;
	}
	std::vector<int>::iterator	middleIt = vec.begin();
	std::advance(middleIt, vec.size() / 2);
	std::vector<int>	fHalf(vec.begin(), middleIt);
	std::vector<int>	sHalf(middleIt, vec.end());

	mergeSortVec(fHalf);
	mergeSortVec(sHalf);
	vec.clear();
	mergeVec(vec, fHalf, sHalf);
}

//			--------------------List-----------------

static void	insertSortLst(std::list<int> &lst)
{
	if (lst.size() < 2)
		return ;
	for(std::list<int>::iterator it = ++lst.begin();it != lst.end();it++)
	{
		std::list<int>::iterator n1 = it;
		std::list<int>::iterator n2 = it;
		n2--;
		while (n1 != lst.begin() && *n1 < *n2)
		{
			std::swap(*n1, *n2);
			n1--;
			n2--;
		}
	}
}

static void	mergeLst(std::list<int> &lst, std::list<int> &fHalf, std::list<int> &sHalf)
{
	std::list<int>::iterator	fHalfIt = fHalf.begin();
	std::list<int>::iterator	sHalfIt = sHalf.begin();

	while (fHalfIt != fHalf.end() && sHalfIt != sHalf.end())
	{
		if (*fHalfIt < *sHalfIt)
			lst.push_back(*fHalfIt++);
		else
			lst.push_back(*sHalfIt++);
	}
	while (fHalfIt != fHalf.end())
		lst.push_back(*fHalfIt++);
	while (sHalfIt != sHalf.end())
		lst.push_back(*sHalfIt++);
}

static void	mergeSortLst(std::list<int> &lst)
{
	if (lst.size() <= 4)
	{
		insertSortLst(lst);
		return ;
	}
	std::list<int>::iterator	middleIt = lst.begin();
	std::advance(middleIt, lst.size() / 2);
	std::list<int>	fHalf(lst.begin(), middleIt);
	std::list<int>	sHalf(middleIt, lst.end());

	mergeSortLst(fHalf);
	mergeSortLst(sHalf);
	lst.clear();
	mergeLst(lst, fHalf, sHalf);
}

//			--------------------MainSort-----------------

static bool	checkSort(std::vector<int> vec)
{
	std::vector<int>	tmp(vec);

	std::sort(tmp.begin(), tmp.end());
	if (std::unique(tmp.begin(), tmp.end()) != tmp.end()
		|| std::equal(tmp.begin(), tmp.end(), vec.begin()))
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	return true;
}

void	PMergeMe::mergeSort( char **input)
{
	std::vector<int> vec;
	std::list<int>	lst;
	clock_t	start, stopVec, stopLst;
	double	lstTime, vecTime;
	long	value;

	// parsing
	for(int i = 1;input[i];i++)
	{
		value = std::strtol(input[i], NULL, 10);
		if (value < 0 || value > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		vec.push_back(value);
		lst.push_back(value);
	}
	if (!checkSort(vec))
		return ;

	// printing
	std::cout << "Before :   " << std::flush;
	for (std::vector<int>::iterator it = vec.begin();it != vec.end();it++)
		std::cout << *it << " " << std::flush;
	std::cout << std::endl;

	// sorting...
	start = clock();
	mergeSortVec(vec);
	stopVec = clock();
	mergeSortLst(lst);
	stopLst = clock();

	//printing again
	std::cout << "After :   " << std::flush;
	for (std::vector<int>::iterator it = vec.begin();it != vec.end();it++)
		std::cout << *it << " " << std::flush;
	std::cout << std::endl;
	lstTime = (stopLst - stopVec) / (double)CLOCKS_PER_SEC;
	vecTime = (stopVec - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to process a range of "<< vec.size() << std::flush;
	std::cout << " elements with std::vector : " << std::fixed << std::setprecision(6) << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of "<< vec.size() << std::flush;
	std::cout << " elements with std::list : " << std::fixed << std::setprecision(6) << lstTime << " us" << std::endl;
}
