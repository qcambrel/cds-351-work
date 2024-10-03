CC=gcc
CXX=g++
RM=rm -f
RMR=rm -rf

COPT = -O0
CXXFLAGS_BASE = -g -std=c++20 $(COPT) \
	  -Wall \
	  -Wextra \
	  -Wpedantic \
          -Wformat=2 \
	  -Wshadow \
	  # -Wno-unused-parameter \
          -Wwrite-strings \
	  -Werror \
          -Wredundant-decls \
	  -Wmissing-include-dirs

ifndef ARCH
  ARCH := $(shell uname -s)
endif

# The following may be needed on Macs running on Intel chips
#ifeq ($(ARCH), Darwin)
#  LDFLAGS = -L/usr/lib -lSystem
#endif

ifeq ($(ARCH), Darwin)
  CXXFLAGS_BASE += -Wl,-w
endif

CXXFLAGS = $(STDCXX11) $(CXXFLAGS_BASE)

ifeq ($(CXX),g++)
    CXXFLAGS += -Wlogical-op
endif

BIN_DIR = bin

SRCS = $(shell find . -name '*.cpp' | sort -k 1nr | cut -f2-)
EXE = $(subst .cpp,.x,$(SRCS))

all:  $(EXE)
	mkdir -p $(BIN_DIR)
	echo 'Installing...'$(EXE)
	cp $(EXE) $(BIN_DIR)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

.PHONY: clean distclean binclean all

clean:
	$(RM) *.o

distclean: clean
	$(RMR) $(BIN_DIR) *.dSYM *.[dox] *~
