CC = gcc
CFLAGS = -Wall -Wextra
TARGET = myprogram
OBJS = main.o app.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c app.h
	$(CC) $(CFLAGS) -c main.c

app.o: app.c app.h
	$(CC) $(CFLAGS) -c app.c

clean:
	rm -f *.o $(TARGET)
