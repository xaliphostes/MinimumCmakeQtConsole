#include "file.h"
#include <QFile>
#include <QTextStream>

FileOut::FileOut(): file_(NULL) {
}

FileOut::FileOut(const QString& f, bool append): QObject(), file_(NULL) {
    open(f, append) ;
}

FileOut::~FileOut() {
    privateClose() ;
}

void FileOut::privateClose() {
    if (file_) {
        file_->close() ;
        delete file_ ;
        file_ = NULL ;
        filename_ = "" ;
    }
}

bool FileOut::open(const QString& name, bool append) {
    privateClose() ;

    file_ = new QFile(name) ;
    filename_ = name ;

    if (append == true) {
        if (!file_->open(QIODevice::Append | QIODevice::Text)) {
            privateClose() ;
            return false ;
        }
    }
    else {
        if (!file_->open(QIODevice::WriteOnly | QIODevice::Text)) {
            privateClose() ;
            return false ;
        }
    }

    return true ;
}

bool FileOut::isOpen() const {
    return file_ != NULL ;
}

bool FileOut::close() {
    if (!file_) {
        return false ;
    }
    privateClose() ;
    return true ;
}

bool FileOut::write(const QString& s) {
    if (!file_) {
        return false ;
    }

    QTextStream out(file_) ;
    out << s ;
    return true ;
}

bool FileOut::writeln(const QString& s) {
    if (!file_) {
        return false ;
    }

    QTextStream out(file_) ;
    out << s << "\n" ;
    return true ;
}