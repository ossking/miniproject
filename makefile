.SUFFIXES : .c .o
CC = gcc
CFLAGS = -W -Wall
TARGET = Shop
DTARGET = DShop
OBJECTS = main.c product.o manager.o
DFLAG=
ifeq ($(DEBUG),1)
	DFLAG=-DDEBUG
else
	DFLAG=
endif
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
.c.o:
	$(CC) $(CFLAGS) $(DFLAG) -c $< -o $@
clean:
	rm *.o Shop DShop
