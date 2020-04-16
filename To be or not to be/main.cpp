/*
Sahej A Singh
https://github.com/sahej-dev

Project to evolve a string genetically, from random characters.

*/
#include <iostream>
#include <random>
#include <ctime>
#include "Population.h"
#include "Dna.h"


void clearscr();

int main()
{
	time_t T = time(NULL);
	srand(T);

	// setup
	std::string target = "To be or not to be, that is the question.";
	Population pop(target, 500, 0.02l);


	std::string phrase = "";


	//draw
	while(phrase != target)
	{
		clearscr();
		std::cout << std::endl;
		std::cout << "Seed = " << T << std::endl;
		std::cout << std::endl;

		pop.calc_fitness();

		std::cout << "Generation:      " << pop.get_generation() << std::endl;
		std::cout << "Population:      " << pop.get_population() << std::endl;
		std::cout << "Average Fitness: " << pop.get_mean_fitness()  * 100 << "%" << std::endl;
		std::cout << "Best Fitness:    " << pop.get_best_fitness()  * 100 << "%" << std::endl;
		std::cout << "Mutation Rate:   " << pop.get_mutation_rate() * 100 << "%" << std::endl;


		std::cout << std::endl << std::endl;
		std::cout << "Phrase:          " << pop.get_best_phrase() << std::endl;

		pop.generate_new_population();
		pop.mutate_population();

		std::cout << std::endl;

		phrase = pop.get_best_phrase();
	}


	return 0;
}


void clearscr()
{
	std::cout << "\033[2J\033[1;1H";
}