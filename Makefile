# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS =

# Nom de l'exécutable
TARGET = program

# Fichiers sources et objets
SOURCES = main.cpp Point2.cpp Vector2.cpp Segment2.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Point2.hpp Vector2.hpp Segment2.hpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Règle pour compiler les fichiers .cpp en .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJECTS)

# Règle pour nettoyer tout (objets + exécutable)
fclean: clean
	rm -f $(TARGET)

# Règle pour tout recompiler
re: fclean all

# Règle pour exécuter le programme
run: $(TARGET)
	./$(TARGET)

# Indique que ces cibles ne sont pas des fichiers
.PHONY: all clean fclean re run