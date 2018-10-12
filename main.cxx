#include <QCoreApplication>
#include "file.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv) ;

    FileOut f("out.txt") ;
    f.writeln("Coucou") ;
    f.write  ("Hello ") ;
    f.writeln("world") ;
    f.close() ;

    return 0 ;
}
