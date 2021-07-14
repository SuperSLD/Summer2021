#include "codeviewwidget.h"

#include <QTextBrowser>
#include <qboxlayout.h>
#include <qlabel.h>
#include <stylecontainer.h>
using namespace styles;

CodeViewWidget::CodeViewWidget(QString code, QString lang) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // меняем скобки
    code.replace("<", "$#SB");
    code.replace(">", "$#SM");

    QList<QString> currentKeywords;
    if (lang == "c++") {
        currentKeywords = cppKeywords;
    }

    // делаем все остальное
    for (int i = 0; i < symbols.size(); i++) {
        code.replace(symbols[i], "<font color='"+COLOR_PRIMARY+"'>"+symbols[i]+"</font>");
    }
    for (int i = 0; i < currentKeywords.size(); i++) {
        code.replace(currentKeywords[i]+" ", "<font color='"+COLOR_SECONDARY+"'>"+currentKeywords[i]+" </font>");
        code.replace(" "+currentKeywords[i], "<font color='"+COLOR_SECONDARY+"'> "+currentKeywords[i]+"</font>");
    }
    code.replace("\n", "<br>");

    // находим коментарии
    bool isComment = false;
    for (int i = 0; i < code.length() - 1; i++ ) {
        if (code[i] == "/" && code[i+1] == "/") {
            isComment = true;
            code.insert(i, "<font color='"+COLOR_TEXT_HINT+"'>");
        }
        if (isComment && code[i] == "b" && code[i+1] == "r") {
            isComment = false;
            code.insert(i, "</font>");
        }
    }
    // меняем скобки
    code.replace("$#SB", "&lt;");
    code.replace("$#SM", "&gt;");

    code = "<pre><font color='#FFFFFF'>" + code + "</font></pre>";

    // код
    QLabel *codeLable = new QLabel();
    codeLable->setText(code);
    codeLable->setStyleSheet(CODE_LABLE);
    codeLable->setContentsMargins(16, 16, 16, 12);
    codeLable->setMaximumWidth(874 - 16 - 16);
    codeLable->setWordWrap(true);
    mainLayout->addWidget(codeLable);

    this->setLayout(mainLayout);
    this->setObjectName("sort_item");
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setStyleSheet(SORT_ITEM_WIDGET);
}
