#include "widgetcatalog.h"

#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QTreeView>
#include <QListView>

WidgetCatalog::WidgetCatalog(QWidget *parent) : QWidget(parent)
{
    catalogLayout = new QVBoxLayout(this);

    dirView = new QTreeView(this);

    dirModel = new QFileSystemModel(dirView);
    dirModel->setRootPath(QDir::currentPath());
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    dirView->setModel(dirModel);

    fileView = new QListView(this);

    fileModel = new QFileSystemModel(fileView);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    QString mPath = "";
    fileModel->setRootPath(mPath);

    fileView->setModel(fileModel);

    catalogLayout->addWidget(dirView);
    catalogLayout->addWidget(fileView);
    catalogLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(catalogLayout);

    connect(dirView, &QTreeView::clicked, this, &WidgetCatalog::onTreeViewClicked);
    connect(dirView, &QTreeView::expanded, this, &WidgetCatalog::onTreeViewClicked);
}

void WidgetCatalog::onTreeViewClicked(const QModelIndex &index)
{
    qDebug() << "onTreeViewClicked";

    QString mPath = dirModel->fileInfo(index).absoluteFilePath();
    qDebug() << "mPath" << mPath;
    fileView->setRootIndex(fileModel->setRootPath(mPath));
}
