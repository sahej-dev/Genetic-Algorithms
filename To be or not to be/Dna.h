/*
Sahej A Singh
https://github.com/sahej-dev

A class which contains the pseudo-dna of a text string.

*/

#pragma once

#ifndef DNA_H
#define DNA_H

#include <string>


/**
 *  @brief Pseudo-random number generator.
 *  @return Pseudo-random long long in [a, b).
*/
static long long random(long long a, long long b)
{
	return (rand() % (b - a)) + a;
}


/**
 *  @brief Pseudo-random number generator.
 *  @return Pseudo-random long double in [a, b].
*/
static long double random(long double a, long double b)
{
	return (b - a) * ((double)rand() / (double)RAND_MAX) + a;
}




/*******************************************************************/

/*
A class which contains the pseudo-dna of a text string.
*/
class DNA
{
private:
	std::string gene;

public:
	long double fitness;

	/**
	 *  Generates a random string of size ascii characters.

	*/
	DNA(int size);


	/**
	 *  Pre-determined genes.
	 *  @param _genes Genes of this object.
	*/
	DNA(std::string _genes);


	/**
	 *  Default Constructor
	 *  Only declared it because it's mandatory to define the default constructor.
	*/
	DNA();


	// /**
	//  *  Deletes the dna object.
	// */
	//     ~DNA();


	/**
	 *  @brief Assigns fitness of this DNA object to this->fitness.
	 *  @param target The target string.
	*/
	void calc_fitness(std::string& target);


	/**
	 *  @brief Crossover of genes of two DNA objects.
	 *  @param other A DNA object.
	 *  @return A DNA object, resulting from crossover of two DNA
	 *  objects.
	*/
	DNA crossover(DNA& other);


	/**
	 *  @brief Mutates genes.
	 *  @param mutation_rate Probability of mutation of each gene in percentage.
	 *  @return null.
	*/
	void mutate(long double mutation_rate);


	/**
	 *  @return The genes string.
	*/
	std::string get_genes();

};


#endif