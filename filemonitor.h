#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QObject>
#include <QVector>
#include "filestate.h"
#include "filestatedelta.h"

class FileMonitor : public QObject
{
    Q_OBJECT
public:
    static FileMonitor& Instance() {
        static FileMonitor s;
        return s;
    }

    bool addFile(QString path);
    bool delFile(QString path);

private:
    explicit FileMonitor(QObject *parent = nullptr);

    QVector<FileState> files;

    FileStateDelta updateFileState(FileState& fileState);

    void displayFileStateDelta(FileStateDelta stateDelta);

signals:

public slots:
    void updateAndDisplayFileInfo();
};

#endif // FILEMONITOR_H
