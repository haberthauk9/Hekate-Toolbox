#pragma once

#include <switch.h>

#include <functional>
#include <vector>

#include "gui.hpp"

class Button {
public:
  static inline std::vector<Button*> g_buttons;

  Button(u16 x, u16 y, u16 w, u16 h, std::function<void(Gui*, u16, u16, bool*)> drawAction, std::function<void(u32, bool*)> inputAction);

  void draw(Gui *gui);
  void onInput(u32 kdown);

  static inline void select(u16 buttonIndex) {
    for(Button *btn : Button::g_buttons)
      btn->m_isSelected = false;

    Button::g_buttons[buttonIndex]->m_isSelected = true;
  }

private:

  u16 m_x, m_y, m_w, m_h;

  std::function<void(Gui*, u16, u16, bool*)> m_drawAction;
  std::function<void(u32, bool*)> m_inputAction;

  bool m_isActivated;
  bool m_isSelected;
};
