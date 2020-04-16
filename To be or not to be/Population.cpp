/*
Sahej A Singh
https://github.com/sahej-dev

A class which makes a population of DNA objects of a string.

*/

#include "Population.h"
#include "Dna.h"


Population::Population(const std::string& _target, long long populaion_size, long double _mutation_rate)
{
	population.resize(populaion_size);
	target = _target;
	target.resize(_target.size());
	total_fitness = 0;
	max_fitness = -1;
	generation = 1;
	probabilities.resize(population.size());
	mutation_rate = _mutation_rate;

	for (int i = 0; i < population.size(); i++)
	{
		population[i] = DNA((long long)target.size());
	}
}


Population::~Population()
{

}


void Population::calc_fitness()
{

	total_fitness = 0;

	for (int i = 0; i < population.size(); i++)
	{
		population[i].calc_fitness(target);
		total_fitness += population[i].fitness;

		// Assign fitness[i] to max_fitness if fitness[i] > max_fitness
		if (max_fitness < population[i].fitness)
		{
			max_fitness = population[i].fitness;
			best_fit = population[i].get_genes();
		}
	}

}


void Population::get_mating_pool()
{

	for (int i = 0; i < population.size(); i++)
	{
		probabilities[i] = population[i].fitness / total_fitness * 100;
	}

}


DNA& Population::choose_parent()
{
	long double net_probability = 0;
	long double r = random(0.0l, 99.99l);

	for (int i = 0; i < population.size(); i++)
	{
		if (r < probabilities[i] + net_probability)
			return population[i];

		net_probability += probabilities[i];
	}
}


void Population::generate_new_population()
{
	get_mating_pool();

	std::vector <DNA> new_population;
	new_population.resize(population.size());

	for (int i = 0; i < population.size(); i++)
	{

		if (max_fitness != 0.0l)
		{
			DNA parent_a = choose_parent();
			DNA parent_b = choose_parent();
			new_population[i] = parent_a.crossover(parent_b);
		}
		else
		{
			new_population[i] = DNA((long long)population[i].get_genes().size());
		}
	}

	population = new_population;
	generation++;

}


long long Population::get_generation()
{
	return generation;
}


long double Population::get_best_fitness()
{
	return max_fitness;
}


std::string Population::get_best_phrase()
{
	return best_fit;
}


void Population::mutate_population()
{
	for (int i = 0; i < population.size(); i++)
	{
		population[i].mutate(mutation_rate);
	}
}

long double Population::get_mean_fitness()
{
	return (long double)total_fitness/population.size();
}

long double Population::get_mutation_rate()
{
	return mutation_rate;
}

long long Population::get_population()
{
	return population.size();
}
