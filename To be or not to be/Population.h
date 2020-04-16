/*
Sahej A Singh
https://github.com/sahej-dev

A class which makes a population of DNA objects of a string.

*/

#pragma once

#ifndef POPULATION_H
#define POPULATION_H


#include "Dna.h"
#include <vector>


/*
A class which makes a population of DNA objects of a string.
*/
class Population
{

private:
	// Vector to hold the array of DNA objects.
	std::vector <DNA> population;

	// Target string
	std::string target;
	long double total_fitness;
	long double max_fitness;
	long double mutation_rate;
	std::string best_fit;
	std::vector <long double> probabilities;
	long long generation;


	/**
	*  @brief Calculates probabilities of selection population members in accordance with their respective fitness. Hence creating a mating pool.
	*/
	void get_mating_pool();


	/**
	 *  @brief Choose a random parent from the mating pool.
	 *  @return Random DNA object from the mating pool.
	*/
	DNA& choose_parent();


public:
	void set_gen(DNA a);

	/**
	 *  @brief Population constructor.
	 *  @param _target Target string.
	 *  @param population_size Size of the population.
	 *  @param _mutation_rate Probability of mutation of genes of members of population.
	*/
	Population(const std::string& _target, long long populaion_size, long double _mutation_rate);


	/**
	 *  Default Constructor.
	*/
	Population();


	/**
	 *  Default Destructor.
	*/
	~Population();


	/**
	 *  @brief Calculates fitness of each member of the population.
	 *  @return null.
	*/
	void calc_fitness();


	/**
	 *  @brief Generate new population, favoring the offsprings of
	 *  the DNA objects with high fitness score.
	 *  Rewrites this->population.
	*/
	void generate_new_population();


	/**
	 *  @return Current generation number.
	*/
	long long get_generation();


	/**
	 *  @return Max_fitness.
	*/
	long double get_best_fitness();


	/**
	 *  @return Best fit phrase.
	*/
	std::string get_best_phrase();


	/**
	 *  @brief Mutates the population
	*/
	void mutate_population();


	/**
	 *  @return mean fitness.
	*/
	long double get_mean_fitness();


	/**
	 *  @return mutation rate.
	*/
	long double get_mutation_rate();


	/**
	 *  @return population length.
	*/
	long long get_population();
	
};



#endif