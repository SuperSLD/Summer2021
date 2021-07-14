#ifndef STYLECONTAINER_H
#define STYLECONTAINER_H

#include <QColor>
#include <QString>

namespace styles{
    /** объявления цветов */
    static const QString COLOR_WINDOW_BACKGROUND = "#171717";
    static const QString COLOR_BACKGROUND = "#2C2C2C";
    static const QString COLOR_TEXT_PRIMARY = "#FFFFFF";
    static const QString COLOR_TEXT_HINT= "#A6A6A6";
    static const QString COLOR_PRIMARY = "#72B8F9";
    static const QString COLOR_SECONDARY= "#F99272";
    static const QString COLOR_BORDER = "#393939";
    static const QString COLOR_TEXT_RED = "#FF6262";
    static const QString COLOR_BUTTON_HOVER = "#BBDEFF";
    static const QString COLOR_BUTTON_PRESSED = "#2988E0";
    static const QString COLOR_SECONDARY_HOVER= "#FF9F81";
    static const QString COLOR_SECONDARY_PRESSED= "#AE4524";

    static const QColor QT_COLOR_PRIMARY = QColor(72, 129, 183);

    /** объявления стилей */
    static const QString GLOBAL_BACK_WHITE =
            "QWidget#container {"
            "   background-color:"+COLOR_BACKGROUND+";"
            "}";

    static const QString FRAME_8PX_WHITE =
            "QFrame {"
            "   background-color:"+COLOR_BACKGROUND+";"
            "   border-radius:8px;"
            "   height:392px;"
            "   width:804px;"
            "}";

    static const QString SPLASH_ICON =
            "   height:274px;"
            "   width:325px;";

    static const QString START_ICON =
            "   height:210px;"
            "   width:210px;";

    static const QString TITLE_LABLE =
            "color:" + COLOR_TEXT_PRIMARY + ";"
            "font-size:24px;";
    static const QString BIG_TITLE_LABLE =
            "color:" + COLOR_TEXT_PRIMARY + ";"
            "font-size:36px;";
    static const QString HINT_LABLE =
            "color:" + COLOR_TEXT_HINT + ";"
            "font-size:14px;";
    static const QString CODE_LABLE =
            "font-size:14px;"
            "background-color:"+COLOR_BACKGROUND+";"
            "border:none;";

    static const QString BUTTON_SOLID =
            "QPushButton {"
            "color: "+COLOR_BACKGROUND+";"
            "background-color:"+COLOR_PRIMARY+";"
            "border:none;"
            "padding:8px;"
            "border-radius:8px;"
            "font-size:16px;"
            "}"
            "QPushButton:hover {"
            "background-color:"+COLOR_BUTTON_PRESSED+";"
            "}";

    static const QString BUTTON_EMPTY =
            "QPushButton {"
            "color: "+COLOR_SECONDARY+";"
            "background-color:"+COLOR_BACKGROUND+";"
            "border:1px solid "+COLOR_SECONDARY+";"
            "padding:8px;"
            "border-radius:8px;"
            "font-size:16px;"
            "}"
            "QPushButton:hover {"
            "color: "+COLOR_SECONDARY_PRESSED+";"
            "background-color:"+COLOR_BACKGROUND+";"
            "border:1px solid "+COLOR_SECONDARY_PRESSED+";"
            "}";

    static const QString MENU_ICON =
            "   height:57px;"
            "   width:57px;";

    static const QString SCROL_BAR =
            "QWidget#container {"
            "   background-color:"+COLOR_WINDOW_BACKGROUND+";"
            "}"
            "QScrollBar:vertical {"
            "   border: 0px solid "+COLOR_WINDOW_BACKGROUND+";"//COLOR_BORDER+";"
            "   background-color: "+COLOR_WINDOW_BACKGROUND+";"
            "   width: 4px;"
            "   margin: 0px 0px 0px 0px;"
            "}"
            "QScrollBar:horizontal {"
            "   border: 0px solid "+COLOR_WINDOW_BACKGROUND+";"//COLOR_BORDER+";"
            "   background-color: "+COLOR_WINDOW_BACKGROUND+";"
            "   height: 0px;"
            "   margin: 0px 0px 0px 0px;"
            "}"
            "QScrollBar::handle {"
            "   background-color: "+COLOR_WINDOW_BACKGROUND+";"//COLOR_TEXT_HINT+";"
            "   border: 3px solid "+COLOR_WINDOW_BACKGROUND+";"
            "   border-radius: 6px;"
            "}"
            "QScrollBar::add-line:vertical {"
            "   height: 0px;"
            "   subcontrol-position: bottom;"
            "   subcontrol-origin: margin;"
            "}"
            "QScrollBar::sub-line:vertical {"
            "   height: 0 px;"
            "   subcontrol-position: top;"
            "   subcontrol-origin: margin;"
            "}"
            "QScrollBar::add-line:horizontal {"
            "   width: 0px;"
            "   subcontrol-position: right;"
            "   subcontrol-origin: margin;"
            "}"
            "QScrollBar::sub-line:horizontal {"
            "   width: 0 px;"
            "   subcontrol-position: left;"
            "   subcontrol-origin: margin;"
            "}";

    static const QString SORT_ITEM_WIDGET =
            "QFrame#sort_item {"
            "background-color:"+COLOR_BACKGROUND+";"
            "font-size:16px;"
            "padding: 0px;"
            "border-radius:8px;"
            "}";

    static const QString CARD_BLUE_LABLE =
            "QLabel {"
            "   background-color:#3F3F3F;"
            "   font-size:16px;"
            "   padding: 8px;"
            "   border-radius:8px;"
            "   color:"+COLOR_PRIMARY+";"
            "}";
    static const QString CARD_RED_LABLE =
            "QLabel {"
            "   background-color:#3F3F3F;"
            "   font-size:16px;"
            "   padding: 8px;"
            "   border-radius:8px;"
            "   color:"+COLOR_SECONDARY+";"
            "}";
};

class StyleContainer
{
public:
    StyleContainer();
};

#endif // STYLECONTAINER_H
