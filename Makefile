input ?= src/main.c
output = $(input:src/%=build/%.bin)

lib := src/uthash.h src/structs.h 
dependences := $(input)
cc := clang

ifeq ($(suffix $(input)), .c)
	dependences += $(lib)
	args := -std=c11
else
	cc := clang++
	args := -std=c++17 -stdlib=libc++
endif

$(output): $(dependences)
	mkdir -p build
	$(cc) $(input) $(args) -o $(output)

run: $(output)
	$(output)
