objects = selection_sort \
			insertion_sort binary_insertion_sort shell_sort \
			merge_sort merge_bu_sort \
			quick_sort quick3way_sort

all: $(objects)

$(objects): utils.c utils.h

selection_sort: selection.c
	gcc -o selection_sort selection.c utils.c

insertion_sort: insertion.c
	gcc -o insertion_sort insertion.c utils.c

binary_insertion_sort: binary_insertion.c
	gcc -o binary_insertion_sort binary_insertion.c utils.c

shell_sort: shell.c
	gcc -o shell_sort shell.c utils.c

merge_sort: merge.c
	gcc -o merge_sort merge.c utils.c

merge_bu_sort: merge_bu.c
	gcc -o merge_bu_sort merge_bu.c utils.c

quick_sort: quick.c
	gcc -o quick_sort quick.c utils.c

quick3way_sort: quick3way.c
	gcc -o quick3way_sort quick3way.c utils.c

.PHONY: clean
clean:
	rm $(objects)
