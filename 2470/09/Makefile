
all: list-sum print-args

print-args: print-args.c
	gcc -no-pie -g -o print-args print-args.c

list-sum: list-sum.c
	gcc -no-pie -g -o list-sum list-sum.c

clean:
	rm -f list-sum print-args

.PHONY: clean
