#ifndef SEARCHCLASS_H
#define SEARCHCLASS_H

#include <QObject>
#include <QStringList>
#include <QDebug>

class SearchClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList model MEMBER m_model NOTIFY modelChanged)

public:    
    explicit SearchClass(QObject *parent = 0);

    QStringList getFileName();
    QStringList getFilenameAndInput(QString inputString);
    QString CompareInputAndFilename(QString inputString, QString filename);

signals:
    void modelChanged();

public slots:
    void setModel(QString txt)
    {
        m_model = getFilenameAndInput(txt);
        modelChanged();
    }
private:
    QStringList m_resultList;
    QStringList m_model;
};

#endif // SEARCHCLASS_H
