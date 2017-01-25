CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = subject.o graphicdisplay.o tile.o textdisplay.o Level0.o Level1.o Level2.o Level3.o Level4.o block.o iblock.o jblock.o lblock.o oBlock.o sblock.o tblock.o zblock.o window.o boardmanager.o commandinterface.o main.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = quadris
$EXEC: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}
.PHONY: clean
clean :
	rm ${OBJECTS} ${EXEC}
