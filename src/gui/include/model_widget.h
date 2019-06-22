//
// Created by egi on 6/1/19.
//

#ifndef ANYSIM_MODEL_WIDGET_H
#define ANYSIM_MODEL_WIDGET_H

#include <QWidget>
#include <QTreeView>

#include <vector>

#include "core/config/configuration_node.h"

class QModelIndex;
class QStandardItem;
class QStandardItemModel;
class project_manager;

class model_widget : public QWidget
{
  Q_OBJECT

public:
  model_widget () = delete;
  explicit model_widget (project_manager &pm);

signals:
  void configuration_node_selected (configuration_node *node);

private slots:
  void on_tree_view_context_menu (const QPoint &pos);
  void on_tree_view_clicked (const QModelIndex &);

private:
  QTreeView *view = nullptr;
  QStandardItemModel *model = nullptr;
  QStandardItem *sources = nullptr;
  unsigned int last_source_id = 0;

  std::vector<configuration_node*> linearized_tree;
};

#endif //ANYSIM_MODEL_WIDGET_H
