#pragma once
#include "Client.h"
#include <memory>
#include <string>

namespace SL {
namespace WS_LITE {
    class IWSocket;
}
namespace Input_Lite {
    enum KeyCodes;
    enum class MouseButtons : unsigned char;
} // namespace Input_Lite
namespace Clipboard_Lite {
    class IClipboard_Manager;
}
namespace Screen_Capture {
    struct Monitor;
}
namespace RAT_Lite {
    struct Point;
    struct ClientSettings;
} // namespace RAT_Lite
namespace RAT_Server {
    struct Point;

    struct Client {
        bool ShareClip = false;
        int ImageCompressionSetting = 70;

        bool IgnoreIncomingKeyboardEvents = false;
        bool IgnoreIncomingMouseEvents = false;
        bool EncodeImagesAsGrayScale = false;
        std::vector<Screen_Capture::Monitor> MonitorsToWatch;
        std::vector<Screen_Capture::Monitor> MonitorsNeeded;

        std::shared_ptr<WS_LITE::IWSocket> Socket;
    };

    int GetNewScreenCaptureRate(size_t memoryused, size_t maxmemoryused, int imgcapturerateactual, int imgcaptureraterequested);
    int GetNewImageCompression(size_t memoryused, size_t maxmemoryused, int imagecompressionactual, int imagecompressionrequested);

    void onClientSettingsChanged(WS_LITE::IWSocket *socket, std::vector<std::shared_ptr<Client>> &clients,
                                 const RAT_Lite::ClientSettings &clientsettings);
    void onGetMonitors(std::vector<std::shared_ptr<Client>> &clients, const std::vector<Screen_Capture::Monitor> &monitors);

    void onKeyUp(bool ignoreIncomingKeyboardEvents, const std::shared_ptr<WS_LITE::IWSocket> &socket, const Input_Lite::KeyCodes &keycode);

    void onKeyUp(bool ignoreIncomingKeyboardEvents, const std::shared_ptr<WS_LITE::IWSocket> &socket, const Input_Lite::KeyCodes &keycode);
    void onKeyDown(bool ignoreIncomingKeyboardEvents, const std::shared_ptr<WS_LITE::IWSocket> &socket, const Input_Lite::KeyCodes &keycode);

    void onMouseUp(bool ignoreIncomingMouseEvents, const std::shared_ptr<WS_LITE::IWSocket> &socket, const Input_Lite::MouseButtons &button);
    void onMouseDown(bool ignoreIncomingMouseEvents, const std::shared_ptr<WS_LITE::IWSocket> &socket, const Input_Lite::MouseButtons &button);
    void onMouseScroll(bool ignoreIncomingMouseEvents, const std::shared_ptr<SL::WS_LITE::IWSocket> &socket, int offset);
    void onMousePosition(bool ignoreIncomingMouseEvents, const std::shared_ptr<SL::WS_LITE::IWSocket> &socket, const RAT_Lite::Point &pos);
    void onClipboardChanged(bool shareclipboard, const std::string &str, std::shared_ptr<Clipboard_Lite::IClipboard_Manager> clipboard);
} // namespace RAT_Server
} // namespace SL