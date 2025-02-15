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

#ifndef PROBE_H
#define PROBE_H

#include "project/item/footage/footage.h"
#include "task/task.h"

/**
 * @brief The ProbeTask class
 *
 * A background task for probing a certain Footage file for its metadata and determining if we have a viable decoder
 * for it.
 *
 * Currently this function just calls olive::ProbeMedia() which will call Footage::Clear(), clearing the Footage of
 * any previous metadata before passing it through the available decoders until it finds one that can parse it.
 * The ProbeTask mostly functions as a background/multithreaded wrapper for this functionality.
 */
class ProbeTask : public Task
{
  Q_OBJECT
public:
  ProbeTask(Footage* footage);

  virtual bool Action() override;

private:
  Footage* footage_;
};

#endif // PROBE_H
