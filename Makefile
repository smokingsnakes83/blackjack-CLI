TARGET=tblack-jack
CPP=g++
OPT=-O3
WARN=-Wall
OBJS=tblack-jack.cpp
all:$(OBJS)
	$(CPP) $(OBJS) $(WARN) $(OPT) -o $(TARGET) 
install:
	@install $(TARGET) /usr/local/bin/$(TARGET)
unistall:
	@rm /usr/local/bin/$(TARGET)
clean:
	@rm -rf $(TARGET)	
	@echo "Desinstalação concluida."
