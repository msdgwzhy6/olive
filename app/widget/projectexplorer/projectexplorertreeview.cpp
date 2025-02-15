/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "projectexplorertreeview.h"

#include <QMouseEvent>

ProjectExplorerTreeView::ProjectExplorerTreeView(QWidget *parent) :
  QTreeView(parent)
{
  // Set selection mode (allows multiple item selection)
  setSelectionMode(QAbstractItemView::ExtendedSelection);
}

void ProjectExplorerTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
  // Perform default double click functions
  QTreeView::mouseDoubleClickEvent(event);

  // Get the index at whatever position was double clicked
  QModelIndex index = indexAt(event->pos());

  // Emit the signal with this index
  emit DoubleClickedView(index);
}
