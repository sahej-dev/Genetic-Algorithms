/*
Sahej A Singh
https://github.com/sahej-dev

A class which contains the pseudo-dna of a text string.

*/

#include "Dna.h"
#include <random>


DNA::DNA(int size)
{
	gene.resize(size);
	fitness = -1;

	for (int i = 0; i < gene.size(); i++)
	{
		gene[i] = char(random(32ll, 127ll));
	}
}


DNA::DNA(std::string _genes)
{
	gene = _genes;
	gene.resize(_genes.size());
}


DNA::DNA()
{
	fitness = -1;
}


void DNA::calc_fitness(std::string& target)
{
	long long score = 0;
	for (int i = 0; i < gene.size(); i++)
	{
		if (gene[i] == target[i])
			score++;
	}

	fitness = pow((long double)score / target.size(), 4);
}


DNA DNA::crossover(DNA& other)
{
	long long midpoint = random(0ll, gene.size());
	std::string res;
	for (int i = 0; i < gene.size(); i++)
	{
		if (i < midpoint)
			res.push_back(this->gene[i]);
		else
			res.push_back(other.gene[i]);
	}

	return DNA(res);
}


void DNA::mutate(long double mutation_rate)
{
	for (int i = 0; i < gene.size(); i++)
	{
		if (random(0.0l, 100.0l) < mutation_rate * 100)
			gene[i] = char(random(32ll, 127ll));
	}
}


std::string DNA::get_genes()
{
	return gene;
}
