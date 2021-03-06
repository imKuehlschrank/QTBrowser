#ifndef TFILETREEVIEWER_H
#define TFILETREEVIEWER_H

#include <QWidget>
#include <QStandardItemModel>
#include <TKey.h>

#include "models/leafsortfilterproxymodel.h"
#include "container/tobjectcontainer.h"

namespace Ui {
class TFileTreeViewer;
}

class TFileTreeViewer : public QWidget
{
    Q_OBJECT

public:
    explicit TFileTreeViewer(QWidget *parent = 0);
    ~TFileTreeViewer();

signals:
    void sendTObjectContainer(TObjectContainer& obj);

public slots:
    void addTFileToTree(QString file_path);

private slots:
    void on_treeView_doubleClicked(const QModelIndex &index);
    void on_filterLineEdit_returnPressed();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

private:
    void visit(TKey* td, QString current_path, QStandardItem* parent, QString file_path);
    void removeTreeItem(QModelIndex idx);
    void previewItem(QModelIndex idx);

    Ui::TFileTreeViewer *ui;
    QStandardItemModel *model;
    LeafSortFilterProxyModel *proxy_model;
};

#endif // TFILETREEVIEWER_H
