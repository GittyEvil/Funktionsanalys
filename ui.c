#include "ui.h"
#include "io.h"
#include "analyze.h"

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
			// House keeping
            /*
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
            */
			// Bubble sort
			case 'a':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				break;
            case 'b':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
            case 'c':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
            case 'd':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
            case 'e':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
            case 'f':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
            case 'g':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
            case 'h':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
            case 'i':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
            case 'j':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
            case 'k':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
            case 'l':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
            case 'm':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
            case 'n':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
            case 'o':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
