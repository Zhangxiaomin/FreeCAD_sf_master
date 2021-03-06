/***************************************************************************
 *   Copyright (c) 2015 FreeCAD Developers                                 *
 *   Author: Przemo Firszt <przemo@firszt.eu>                              *
 *   Based on src/Mod/Raytracing/Gui/DlgSettingsRayImp.cpp                 *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"

#include "DlgSettingsFemImp.h"
#include <Gui/PrefWidgets.h>

using namespace FemGui;

DlgSettingsFemImp::DlgSettingsFemImp( QWidget* parent )
  : PreferencePage( parent )
{
    this->setupUi(this);
}

DlgSettingsFemImp::~DlgSettingsFemImp()
{
    // no need to delete child widgets, Qt does it all for us
}

void DlgSettingsFemImp::saveSettings()
{
    cb_int_editor->onSave();
    fc_ext_editor->onSave();
}

void DlgSettingsFemImp::loadSettings()
{
    cb_int_editor->onRestore();
    fc_ext_editor->onRestore();
}

/**
 * Sets the strings of the subwidgets using the current language.
 */
void DlgSettingsFemImp::changeEvent(QEvent *e)
{
    if (e->type() == QEvent::LanguageChange) {
        retranslateUi(this);
    }
    else {
        QWidget::changeEvent(e);
    }
}

#include "moc_DlgSettingsFemImp.cpp"
