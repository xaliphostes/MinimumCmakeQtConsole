#ifndef MFILE
#define MFILE

#include <QObject>
#include <QString>

class QFile ;

class FileOut: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE open)
public:
    FileOut() ;
    FileOut(const QString&, bool append=false) ;
    virtual ~FileOut() ;
    const QString& name() const {return filename_ ;}
    bool open(const QString&, bool append=false) ;
    bool close() ;
    bool write(const QString&) ;
    bool writeln(const QString&) ;
    bool isOpen() const ;
private:
    void privateClose() ;
    QFile* file_ ;
    QString filename_ ;
} ;

#endif
