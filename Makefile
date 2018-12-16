
PROGRAM_NAME=s0_work.linux.64
PROGRAM_PATH=./bin/$(PROGRAM_NAME)


default: build run

full: clean build debug

build:
	scons

clean:
	scons -c
	$(RM) -f src/*/*.o
	$(RM) -f src/*/*.os
	$(RM) -f bin/*.a

debug: build
	valgrind --leak-check=full $(PROGRAM_PATH) --verbose=true

run:
	$(PROGRAM_PATH)
