// Copyright (C) 2023 rewine <luhongxu@deepin.org>.
// SPDX-License-Identifier: Apache-2.0 OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include <WServer>

#include <QObject>

QW_BEGIN_NAMESPACE
class QWCursorShapeManagerV1;
QW_END_NAMESPACE

WAYLIB_SERVER_BEGIN_NAMESPACE

class WCursor;

class WCursorShapeManagerV1Private;
class WCursorShapeManagerV1 : public QObject, public WObject,  public WServerInterface
{
    Q_OBJECT
    W_DECLARE_PRIVATE(WCursorShapeManagerV1)

public:
    explicit WCursorShapeManagerV1();

    QW_NAMESPACE::QWCursorShapeManagerV1 *handle() const;

protected:
    void create(WServer *server) override;
    wl_global *global() const override;
};

WAYLIB_SERVER_END_NAMESPACE
