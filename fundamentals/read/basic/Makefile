GCC := g++

OUTPUT := Reading
SOURCES := $(wildcard *.cpp)
CCFLAGS :=

all: $(OUTPUT)

$(OUTPUT):
	$(GCC) -o $(OUTPUT) $(CCFLAGS) $(SOURCES)

clean:
	rm $(OUTPUT)

.PHONY:
	all