//add include statements
#include "func.h"

#include <cctype>

//add function code here
double get_gc_content(const std::string& dna)
{
	if (dna.empty())
	{
		return 0.0;
	}

	int gc_count = 0;

	for (char nucleotide : dna)
	{
		char upper = static_cast<char>(std::toupper(static_cast<unsigned char>(nucleotide)));
		if (upper == 'G' || upper == 'C')
		{
			++gc_count;
		}
	}

	return static_cast<double>(gc_count) / dna.size();
}

std::string get_reverse_string(std::string dna)
{
	std::string reversed;
	reversed.reserve(dna.size());

	for (auto it = dna.rbegin(); it != dna.rend(); ++it)
	{
		reversed.push_back(*it);
	}

	return reversed;
}

std::string get_dna_complement(std::string dna)
{
	std::string reversed = get_reverse_string(dna);

	for (char& nucleotide : reversed)
	{
		char upper = static_cast<char>(std::toupper(static_cast<unsigned char>(nucleotide)));
		switch (upper)
		{
		case 'A':
			nucleotide = 'T';
			break;
		case 'T':
			nucleotide = 'A';
			break;
		case 'C':
			nucleotide = 'G';
			break;
		case 'G':
			nucleotide = 'C';
			break;
		default:
			nucleotide = upper;
			break;
		}
	}

	return reversed;
}