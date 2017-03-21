// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InstrumentView.h
//! @brief     Defines class InstrumentView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef INSTRUMENTVIEW_H
#define INSTRUMENTVIEW_H

#include "WinDllMacros.h"
#include "ItemStackPresenter.h"
#include <QMap>
#include <QWidget>

class MainWindow;
class InstrumentSelectorWidget;
class InstrumentEditorWidget;
class InstrumentModel;
class QItemSelection;
class SessionItem;
class QToolButton;
class DetectorItem;
class ShowEvent;

class BA_CORE_API_ InstrumentView : public QWidget
{
    Q_OBJECT

public:
    InstrumentView(MainWindow *mainWindow);

public slots:
    void onAddInstrument();
    void onRemoveInstrument();
    void onExtendedDetectorEditorRequest(DetectorItem *detectorItem);

private slots:
    void onItemSelectionChanged(SessionItem* instrumentItem);

protected:
    void showEvent(QShowEvent*);

private:
    void setupActions();
    QString getNewInstrumentName(const QString &name);
    void updateMapOfNames();

    InstrumentModel *m_instrumentModel;
    class StyledToolBar *m_toolBar;
    InstrumentSelectorWidget *m_instrumentSelector;

//    InstrumentEditorWidget* m_instrumentEditor;
    ItemStackPresenter<InstrumentEditorWidget> *m_instrumentEditor;

    QAction *m_addInstrumentAction;
    QAction *m_removeInstrumentAction;
    QToolButton *m_addInstrumentButton;
    QToolButton *m_removeInstrumentButton;

    QMap<QString, int> m_name_to_copy;
};


#endif // INSTRUMENTVIEW_H
