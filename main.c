/* Parallel Computing Project: Maze Generation and Algorithmic Solving Efficiency Analysis 
	Team Members:  Danilo Baledio, Naomi Nunis, Katya Sheth, Mark Fraser */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "maze.h"

#define MAX_THREADS 256
#define MAX_SIZE    100

/* declaration of functions used in main() */
void processCommandLineArgs(int argc 	 			/* in */,
							char* argv[] 			/* in */,
							long* num_threads 		/* out */,
							long* maze_size   		/* out */,
							long* algorithm_choice 	/* out */
							);

/* main takes the command line arguments and calls upon the functions in maze.c */
int main(int argc, char* argv[])
{
	long num_threads, maze_size, algorithm_choice;
	processCommandLineArgs( argc,
							argv,
							&num_threads,
							&maze_size,
							&algorithm_choice
						  );

	/* TODO:  call the appropriate function to generate and return a maze (using pointer reference in argument)
	i.e.
	      MAZE maze;
	      generateMaze(&maze, num_threads, maze_size); */

	/* TODO:  call appropriate function to solve maze and generate output .csv file */

	return 0;
}

void processCommandLineArgs(int argc, char* argv[], long* num_threads, long* maze_size, long* algorithm_choice)
{
	/* parse out parameters for maze generation and solving */
	if (argc != 4)
		fprintf(stderr, "Incorrect usage of program.  Proper usage is:\n    ./maze <num_threads> <maze_size> <algorithm_choice>\nexiting...\n");

	*num_threads      = strtol(argv[1], 10);
	*maze_size        = strtol(argv[2], 10);
	*algorithm_choice = strtol(argv[3], 10);

	if (num_threads < 1 || num_threads > MAX_THREADS)
		fprint(stderr, "Invalid input for number of threads. Number must be between 1 and %d", MAX_THREADS);
	if (maze_size < 2 || maze_size > MAX_SIZE)
		fprintf(stderr, "Invalid input for size of maze. Number must be between 2 and %d", MAX_SIZE);
	if (algorithm_choice < 0 || algorithm_choice > 3)
		fprintf(stderr, "Invalid input for algorithm choice. Algorithm choices are as follows:\n    0: Random Mouse Algorithm\n    1: DFS\n    2: BFS\n    3: Randomized Kruskal's Algorithm\nexiting...\n");
}