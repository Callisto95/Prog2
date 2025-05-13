# TODO Aufgabe 1:
#  Fügt dem Projekt die Anwendung `Battleship` hinzu, mit den Dateien im Verzeichnis src/app/ und der Bibliothek `GameObjects`.
add_executable(blatt3 main.cpp game.cpp game.h init.cpp init.h test.cpp test.h)
target_link_libraries(blatt3 GameObjects)
