CC = gcc
CFLAGS = -W -Wall
Target = shopping_mall
DTARGET = shopping_mall_debug
OBJECTS =  manager.o product.txt main.c  
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o

