/*
 * Original Copyright (c) 2026 PolybiusExtreme
 *
 * Licensed under the GNU GPLv3.
 */

#ifndef SDLCTRLMODULE_H
#define SDLCTRLMODULE_H

#include <QObject>
#include <QLibrary>
#include <QTimer>
#include <QMap>
#include <QSet>

#include "SDL3/SDL.h"

#include "../Global.h"

class SdlCtrlModule : public QObject
{
    Q_OBJECT

public:
    explicit SdlCtrlModule(QObject *parent = nullptr);
    ~SdlCtrlModule();

public slots:
    // Collect SDL data
    void collectSdlData();

    // Process SDL events
    void processEvents();

    // Set gamecontroller rumble
    void setRumble(int id, bool state, uint16_t leftStrength, uint16_t rightStrength, uint32_t duration);

    // Update devices
    void updateDevices();

signals:
    // Send SDL device list to DeviceWindow
    void sdlDeviceList(const QList<SdlCtrlData> &devices);

    // Show error message in main thread
    void showErrorMessage(const QString &title, const QString &message);

private:
    // QMap - SDL gamepad
    QMap<int, SDL_Gamepad*> m_gamepads;
};

#endif // SDLCTRLMODULE_H
