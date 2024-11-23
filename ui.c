#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>



//
// Private
//

static void ui_invalid_input()
{
    printf("info> bad input\n");
}

static void ui_exit()
{
    printf("info> bye\n");
}

static char ui_get_choice()
{
    char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
    while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
    int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
    const char *options[] = {
		"Bubble sort best case",
        "Bubble sort worst case",
        "Bubble sort avg case\n",
        "Insertion sort best case",
        "Insertion sort worst case",
        "Insertion sort avg case\n",
        "Quick sort best case",
        "Quick sort worst case",
        "Quick sort avg case\n",
        "linear search best case",
        "linear search worst case",
        "linear search avg case\n",
        "Binary search best case",
        "Binary search worst case",
        "Binary search avg case\n",
		"Exit\n",
		// TODO: complete menu
	};

    ui_line('=', MENU_WIDTH);
    ui_menu_options(options, sizeof(options) / sizeof(char *));
    ui_line('-', MENU_WIDTH);
}

static const char *getAlgoName(algorithm_t a) {
    switch (a) {
    case bubble_sort_t: return "Bubble Sort";
    case insertion_sort_t: return "Insertion Sort";
    case quick_sort_t: return "Quick Sort";
    case linear_search_t: return "Linear Search";
    case binary_search_t: return "Binary Search";
    default: return "Unknown Algorithm";
    }
}

static const char *getCaseName(case_t c) {
    switch (c) {
    case best_t: return "Best Case";
    case worst_t: return "Worst Case";
    case average_t: return "Average Case";
    default: return "Unknown Case";
    }
}
//måste göra om denna så att den är dynamisk för alla algoritmer just nu bara anpassad för bubblesort best case
static void printBenchmarkTitle(const algorithm_t algo, const case_t Case) {
    ui_line('*', MENU_WIDTH*2);
    printf("Benchmark: %s (%s)\n", getAlgoName(algo), getCaseName(Case));
    ui_line('~', MENU_WIDTH*2);
    printf("Size\t Time (s)\tT / log(n)\tT / n\tT / n^2\n");
    ui_line('~', MENU_WIDTH*2);
}
//skriver ut resultaten alltså alla värden som läggs in i time buffer, aka *results/buf från benchmark
static void printBenchmarkResults(const result_t *results, int n) {
    for (int i = 0; i < n; i++) {
        double size = results[i].size;
        double time = results[i].time;
        
        printf("%d\t%f\t%e\t%e\t%e\n",(int)size, time,
               time / (log(size) > 0 ? log(size) : 1),
               time / size,
               //pow(time,2)
               time / (size * size));
    }
    ui_line('*', MENU_WIDTH*2);
}

//
// Public
//
void ui_run()
{
    bool running = true, show_menu = true;
    result_t results[RESULT_ROWS];

    while (running) {
        if (show_menu) {
            ui_menu();
            show_menu = false;
        }

        switch (ui_get_choice()) {
        case 'a':
            printBenchmarkTitle(bubble_sort_t, best_t);
            benchmark(bubble_sort_t, best_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'b':
            printBenchmarkTitle(bubble_sort_t, worst_t);
            benchmark(bubble_sort_t, worst_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'c': 
            printBenchmarkTitle(bubble_sort_t, average_t);
            benchmark(bubble_sort_t, average_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'd': 
            printBenchmarkTitle(insertion_sort_t, best_t);
            benchmark(insertion_sort_t, best_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'e':
            printBenchmarkTitle(insertion_sort_t, worst_t);
            benchmark(insertion_sort_t, worst_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'f':
            printBenchmarkTitle(insertion_sort_t, average_t);
            benchmark(insertion_sort_t, average_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'g': 
            printBenchmarkTitle(quick_sort_t, best_t);
            benchmark(quick_sort_t, best_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'h': 
            printBenchmarkTitle(quick_sort_t, worst_t);
            benchmark(quick_sort_t, worst_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'i': 
            printBenchmarkTitle(quick_sort_t, average_t);
            benchmark(quick_sort_t, average_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'j': 
            printBenchmarkTitle(linear_search_t, best_t);
            benchmark(linear_search_t, best_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'k': 
            printBenchmarkTitle(linear_search_t, worst_t);
            benchmark(linear_search_t, worst_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'l': 
            printBenchmarkTitle(linear_search_t, average_t);
            benchmark(linear_search_t, average_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'm': 
            printBenchmarkTitle(binary_search_t, best_t);
            benchmark(binary_search_t, best_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'n': 
            printBenchmarkTitle(binary_search_t, worst_t);
            benchmark(binary_search_t, worst_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'o': 
            printBenchmarkTitle(binary_search_t, average_t);
            benchmark(binary_search_t, average_t, results, RESULT_ROWS);
            printBenchmarkResults(results, RESULT_ROWS);
            break;
        case 'q':
            running = false;
            break;
        default:
            ui_invalid_input();
            break;
        }
    }

    ui_exit();
}
