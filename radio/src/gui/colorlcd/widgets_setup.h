/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "form.h"
#include "button.h"

class ScreenMenu;
class WidgetsContainer;

class SetupWidgetsPage : public FormWindow
{
 public:
  SetupWidgetsPage(ScreenMenu* menu, uint8_t customScreenIdx);

#if defined(DEBUG_WINDOWS)
  std::string getName() const override
  {
    return "SetupWidgetsPage(idx=" + std::to_string(customScreenIdx) + ")";
  }
#endif

  void deleteLater(bool detach = true, bool trash = true) override;

#if defined(HARDWARE_TOUCH)
  bool onTouchSlide(coord_t x, coord_t y, coord_t startX, coord_t startY,
                    coord_t slideX, coord_t slideY) override;
  bool onTouchEnd(coord_t x, coord_t y) override;
#endif

#if defined(HARDWARE_KEYS)
  void onEvent(event_t event) override;
#endif

 protected:
  ScreenMenu* menu;
  uint8_t customScreenIdx;
  unsigned savedView = 0;
};

class SetupWidgetsPageSlot : public Button
{
 public:
  SetupWidgetsPageSlot(FormGroup* parent, const rect_t& rect,
                       WidgetsContainer* container, uint8_t slotIndex);

  void paint(BitmapBuffer* dc) override;
};