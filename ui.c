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

static void printTimeResults(const char *algoName, result_t *results, int n) {
     printf("+------------+--------------------+-------------------+-------------------+--------------------+\n");
    printf("| Size       | Time (s)           | T / log(n)        | T / n             | T / n^2            |\n");
    printf("+------------+--------------------+-------------------+-------------------+--------------------+\n");


    for (int i = 0; i < n; i++) {
        double size = results[i].size;
        double time = results[i].time;

        
        double logn = log(size);
        double t_logn = time / logn;
        double t_n = time / size;
        double t_n2 = pow(size,2);

        
        printf("| %-10d | %-18f | %-17.6e | %-17.6e | %-18.6e |\n",
               (int)size, time, t_logn, t_n, t_n2);
    }
    printf("+------------+--------------------+-------------------+-------------------+--------------------+\n");
}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			case 'a':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
                printTimeResults("Bubble Sort best case",result,RESULT_ROWS);
				break;
            case 'b':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
                printTimeResults("Bubble Sort worst case",result,RESULT_ROWS);
                break;
            case 'c':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
                printTimeResults("Bubble Sort average case",result,RESULT_ROWS);
                break;
            case 'd':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
                break;
            case 'e':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
                break;
            case 'f':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
                break;
            case 'g':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
                break;
            case 'h':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
                break;
            case 'i':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
                break;
            case 'j':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
                break;
            case 'k':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
                break;
            case 'l':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
                break;
            case 'm':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
                break;
            case 'n':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
                break;
            case 'o':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
                break;
            case 'q':
				running = false;
                break;
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
