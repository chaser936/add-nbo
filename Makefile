TARGET=add-nbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGET): add_nbo.o
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o

