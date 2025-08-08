// Sane Break is a gentle break reminder that helps you avoid mindlessly skipping breaks
// Copyright (C) 2024-2025 Sane Break developers
// SPDX-License-Identifier: GPL-3.0-or-later

#include <windows.h>

#include <QWidget>
#include <iostream>

using namespace std;

bool lockScreen() { return LockWorkStation(); }

bool screenLocked() {
  auto foreground = GetForegroundWindow();
  if (!foreground) return true;
  wchar_t title[255];
  GetWindowText(foreground, title, 255);
  if (wstring(title) == L"Windows-standaardvergrendelingsscherm") return true;
  return false;
}
