// Copyright (C) 2023 JiDe Zhang <zhangjide@deepin.org>.
// SPDX-License-Identifier: Apache-2.0 OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include <WServer>

#include <QObject>

QW_BEGIN_NAMESPACE
class QWBackend;
QW_END_NAMESPACE

WAYLIB_SERVER_BEGIN_NAMESPACE

class WOutput;
class WInputDevice;
class WBackendPrivate;
class WBackend : public QObject, public WObject,  public WServerInterface
{
    Q_OBJECT
    friend class WOutputPrivate;
    W_DECLARE_PRIVATE(WBackend)

public:
    explicit WBackend();

    QW_NAMESPACE::QWBackend *handle() const;

    QVector<WOutput*> outputList() const;
    QVector<WInputDevice*> inputDeviceList() const;

    bool hasDrm() const;
    bool hasX11() const;
    bool hasWayland() const;

Q_SIGNALS:
    void outputAdded(WOutput *output);
    void outputRemoved(WOutput *output);

    void inputAdded(WInputDevice *input);
    void inputRemoved(WInputDevice *input);

protected:
    void create(WServer *server) override;
    void destroy(WServer *server) override;
    wl_global *global() const override;
};

WAYLIB_SERVER_END_NAMESPACE
