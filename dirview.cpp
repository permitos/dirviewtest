#include "dirview.h"

DirView::DirView(const QString path): QWidget() {

    _fileModel = new QFileSystemModel(this);
    _fileModel->setRootPath(path);
    _fileModel->setFilter(QDir::AllEntries | QDir::Hidden | QDir::NoDotAndDotDot);
    _fileModel->setNameFilterDisables(true);

    _treeView = new QTreeView(this);
    _treeView->setModel(_fileModel);
    _treeView->setSortingEnabled(true);

    _lineEdit = new QLineEdit(this);
    _lineEdit->setPlaceholderText("Enter file or directory name");

    connect(_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(changeFilter(QString)));

    _vbox = new QVBoxLayout(this);
    _vbox->addWidget(_lineEdit);
    _vbox->addWidget(_treeView);

    resize(QApplication::desktop()->availableGeometry(_treeView).size() / 2);
    setWindowTitle("DirView");
}

void DirView::changeFilter(const QString filter) {

    const QString allFilesAndDirectories = "*";

    if(filter.isEmpty())
        _fileModel->setNameFilters(QStringList(allFilesAndDirectories));
    else
        _fileModel->setNameFilters(QStringList(QString(filter + allFilesAndDirectories)));
}
