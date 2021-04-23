#ifndef WIDGETCATALOG_H
#define WIDGETCATALOG_H

#include <QWidget>

class QFileSystemModel;
class QVBoxLayout;
class QTreeView;
class QListView;

/* Class implements Directory and File Explorer
 * For details see UML Hierarchy diagram
 * */
class WidgetCatalog : public QWidget
{
    Q_OBJECT

public:
    WidgetCatalog(QWidget *parent = nullptr);

protected:
    bool event(QEvent *event);

private:
    void onTreeViewClicked(const QModelIndex &index);

    QVBoxLayout *catalogLayout {nullptr};

    QFileSystemModel *dirModel {nullptr};
    QFileSystemModel *fileModel {nullptr};

    QTreeView *dirView {nullptr};
    QListView *fileView {nullptr};
};

#endif // WIDGETCATALOG_H
