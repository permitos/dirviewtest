#ifndef DIRVIEW_H
#define DIRVIEW_H

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QApplication>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QVBoxLayout>

class DirView: public QWidget {
Q_OBJECT

    QFileSystemModel* _fileModel;
    QTreeView* _treeView;
    QLineEdit* _lineEdit;
    QVBoxLayout* _vbox;

public:

    explicit DirView(const QString path = QDir::homePath());
    virtual ~DirView() = default;

public slots:

    void changeFilter(const QString filter);
};

#endif // DIRVIEW_H
