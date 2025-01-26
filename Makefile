TARGET = lab1
CXX = g++
SRCS = main.cpp lab1.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $@ $^

clean:
	rm -f $(TARGET)
	rm -f selection*.txt
	rm -f insertion*.txt
	rm -f heap*.txt
	rm -f stdSort*.txt