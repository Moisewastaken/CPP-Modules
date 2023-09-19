#include "PMergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}
	PMergeMe	merge;

	merge.mergeSort(argv);
}