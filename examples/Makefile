CC = gcc
CXXFLAGS = -O2 -std=c++14
CFLAGS = -O2
LDFLAGS = -lstdc++
OUT = exchange_example
OBJDIR = obj
BUILDDIR = build

all: directories $(OUT)

directories: $(OBJDIR) $(BUILDDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(OUT):  exchange_example.o money.o currency.o
	$(CC) $(OBJDIR)/money.o $(OBJDIR)/exchange_example.o $(OBJDIR)/currency.o -o $(BUILDDIR)/$(OUT) $(LDFLAGS)

money.o: ../money.cpp
	$(CC) -c ../money.cpp $(CXXFLAGS) -o $(OBJDIR)/money.o

currency.o: ../currency.cpp
	$(CC) -c ../currency.cpp $(CXXFLAGS) -o $(OBJDIR)/currency.o

exchange_example.o: exchange_example.cpp
	$(CC) -c exchange_example.cpp $(CXXFLAGS) -o $(OBJDIR)/exchange_example.o