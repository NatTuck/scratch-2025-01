
lines3: lines3.c myopen.S
	gcc -g -no-pie -z noexecstack -o lines3 lines3.c myopen.S

hello: hello.S
	gcc -g -no-pie -z noexecstack -o hello hello.S

clean:
	rm -f hello lines3

.PHONY: clean
