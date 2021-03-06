//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Param/Node/IterationStrategy.h
//! @brief     Defines class IterationStrategy and children.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_PARAM_NODE_ITERATIONSTRATEGY_H
#define BORNAGAIN_PARAM_NODE_ITERATIONSTRATEGY_H

class INode;
class IteratorMemento;

//! Abstract base class for tree traversal strategies, for use in INodeVisitor.
//!
//! For definition of different strategies see https://en.wikipedia.org/wiki/Tree_traversal.

class IterationStrategy {
public:
    virtual IterationStrategy* clone() const = 0;

    virtual IteratorMemento first(const INode* p_root) = 0;
    virtual void next(IteratorMemento& iterator_stack) const = 0;
    virtual bool isDone(IteratorMemento& iterator_stack) const = 0;
};

//! Traverse tree; visit parents before their children.
class PreorderStrategy : public IterationStrategy {
public:
    PreorderStrategy();

    virtual PreorderStrategy* clone() const;

    virtual IteratorMemento first(const INode* p_root);
    virtual void next(IteratorMemento& iterator_stack) const;
    virtual bool isDone(IteratorMemento& iterator_stack) const;
};

#endif // BORNAGAIN_PARAM_NODE_ITERATIONSTRATEGY_H
