// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/RealSpaceWidgets/RealSpaceWidget.cpp
//! @brief     Implements class RealSpaceWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "RealSpaceWidget.h"
#include "RealSpaceToolBar.h"
#include "RealSpaceCanvas.h"
#include "RealSpaceActions.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

RealSpaceWidget::RealSpaceWidget(SampleModel *sampleModel,
                                 QItemSelectionModel* selectionModel, QWidget* parent)
    : QWidget(parent)
    , m_actions(new RealSpaceActions)
    , m_toolBar(new RealSpaceToolBar)
    , m_canvas(new RealSpaceCanvas)
    , m_sampleModel(sampleModel)
    , m_selectionModel(selectionModel)
{
    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->setMargin(0);
    hlayout->setSpacing(0);
    hlayout->setContentsMargins(0, 0, 0, 0);
    hlayout->addWidget(m_canvas);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(m_toolBar);
    mainLayout->addLayout(hlayout);

    setLayout(mainLayout);

    connect(m_selectionModel, &QItemSelectionModel::selectionChanged,
            m_canvas, &RealSpaceCanvas::onSelectionChanged);

    //connect(m_toolBar, SIGNAL(defaultViewAction()), m_canvas, SLOT(onDefaultViewAction()));
    connect(m_toolBar, &RealSpaceToolBar::defaultViewAction,
            m_canvas, &RealSpaceCanvas::onDefaultViewAction);

    //connect(m_toolBar, SIGNAL(edgeViewAction()), m_canvas, SLOT(onEdgeViewAction()));
    connect(m_toolBar, &RealSpaceToolBar::edgeViewAction,
            m_canvas, &RealSpaceCanvas::onEdgeViewAction);

    //connect(m_toolBar, SIGNAL(faceViewAction()), m_canvas, SLOT(onFaceViewAction()));
    connect(m_toolBar, &RealSpaceToolBar::faceViewAction,
            m_canvas, &RealSpaceCanvas::onFaceViewAction);
}

void RealSpaceWidget::setModel(SampleModel* sampleModel, QItemSelectionModel *selectionModel)
{
    m_sampleModel = sampleModel;
    m_selectionModel = selectionModel;
    m_canvas->setModel(m_sampleModel, m_selectionModel);
}
